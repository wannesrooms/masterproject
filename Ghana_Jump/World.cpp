#include "World.h"
#include <memory>

void GhanaJump::GameLogic::World::generateInitialPlatforms() {
    // Startpositie van de speler
    float startY = 400.f;

    // Initialiseer twee startplatformen
    auto staticPlatform1 = staticPlatformFactory.createEntity(350.f, startY + 300.f);
    auto staticPlatform2 = staticPlatformFactory.createEntity(150.f, startY - 150.f);

    // Grondplatformen genereren
    for (int i = 0; i < 8; ++i) {
        auto ground = staticPlatformFactory.createEntity(i * 100.f, 800.f);
        entities.push_back(ground);
    }

    // Voeg de statische platformen toe
    entities.push_back(staticPlatform1);
    entities.push_back(staticPlatform2);
}

GhanaJump::GameLogic::World::World()
    : playerFactory(), staticPlatformFactory(), grayPlatformFactory(), horizontalPlatformFactory(), verticalPlatformFactory() {

    player = playerFactory.createPlayer();
    score = std::make_shared<Score>();
    background = std::make_shared<GhanaJump::Graphics::Background>("resources/Ghana");

    generateInitialPlatforms();
}

void GhanaJump::GameLogic::World::removeEntitiesOutOfView() {
    float bottomViewBoundary = player->getY() + 1500.f;

    // Verwijder entities die buiten beeld zijn. De logica hiervoor blijft hetzelfde.
    auto entitiesEnd = std::remove_if(entities.begin(), entities.end(),
        [bottomViewBoundary](const std::shared_ptr<GhanaJump::Entities::Entity>& entity) {
            if (auto grayPlatform = std::dynamic_pointer_cast<GhanaJump::Entities::GrayPlatform>(entity)) {
                return ((grayPlatform->getY() > bottomViewBoundary) || grayPlatform->getIsUsed());
            }
            else if (auto platform = std::dynamic_pointer_cast<GhanaJump::Entities::Platform>(entity)) {
                return (platform->getY() > bottomViewBoundary);
            }
            else if (auto bonus = std::dynamic_pointer_cast<GhanaJump::Entities::Bonus>(entity)) {
                // Verwijder de bonus als hij buiten beeld is OF als hij niet meer actief is
                return (bonus->getY() > bottomViewBoundary || !bonus->getIsActive());
            }
            return false;
        });

    entities.erase(entitiesEnd, entities.end());
}

float GhanaJump::GameLogic::World::findHighestPlatformY() const {
    if (entities.empty()) {
        return this->getPlayer()->getY() + 100.f; // Als we niets vinden, nemen we de speler
    }

    float highestY = 0.f;

    for (const auto& entity : entities) {
        if (auto platform = std::dynamic_pointer_cast<GhanaJump::Entities::Platform>(entity)) {
            highestY = std::min(highestY, platform->getY());
        }
    }
    return highestY;
}

void GhanaJump::GameLogic::World::generateNewPlatforms(float highestY) {
    using namespace GhanaJump::Entities;
    Utilities::Random& rng = Utilities::Random::getInstance();

    int platformCount = 0;
    float lastGeneratedY = highestY;
    float maxJumpHeight = 200.f; // Maximale verticale afstand tussen platformen
    int maxPlatforms = 10;
    int extraPlatformChance = 80; // Kans op twee platformen op ongeveer dezelfde hoogte
    int movingPlatformChance = 0; // Kans op een dynamisch platform
    int grayPlatformChance = 0; // Kans op een grijs platform
    int bonusChance = 12; // Kans op een bonus op elk platform

    // Afhankelijk van hoe hoog we zijn wordt het spel moeilijker door variabelen aan te passen
    if (lastGeneratedY < -250000) { maxJumpHeight = 480.f; extraPlatformChance = 0; movingPlatformChance = 60; grayPlatformChance = 100; bonusChance = 0; }
    else if (lastGeneratedY < -100000) { maxJumpHeight = 475.f; extraPlatformChance = 15; movingPlatformChance = 30; grayPlatformChance = 35; bonusChance = 5; }
    else if (lastGeneratedY < -60000) { maxJumpHeight = 425.f; extraPlatformChance = 30; movingPlatformChance = 20; grayPlatformChance = 25; bonusChance = 7; }
    else if (lastGeneratedY < -30000) { maxJumpHeight = 350.f; extraPlatformChance = 45; movingPlatformChance = 10; grayPlatformChance = 15; bonusChance = 9; }
    else if (lastGeneratedY < -12500) { maxJumpHeight = 275.f; extraPlatformChance = 60; movingPlatformChance = 5; grayPlatformChance = 10; bonusChance = 12; }

    bool lastPlatformWasGray = true;

    // Loop die nieuwe platformen genereerd
    while (platformCount < maxPlatforms) {
        float x = rng.getFloat(0.f, 800.f - 100.f);
        float minY = lastGeneratedY - maxJumpHeight;
        float maxY = minY + 100.f;
        float y = rng.getFloat(minY, maxY);

        if (rng.getFloat(0.f, 100.f) < movingPlatformChance) {// Bewegend platform
            // Controleer of het vorig platform grijs was, dan is een verticaal platform niet toegestaan
            if ((rng.getInt(1, 2) == 1) || lastPlatformWasGray) {
                entities.push_back(horizontalPlatformFactory.createEntity(x, y));
                lastPlatformWasGray = false;
            }
            // Kans op verticaal of horizontaal is 50/50
            else {
                entities.push_back(verticalPlatformFactory.createEntity(x, y));
                lastPlatformWasGray = false;
            }
        }
        else if (rng.getFloat(0.f, 100.f) < grayPlatformChance) { // Grijs platform
            entities.push_back(grayPlatformFactory.createEntity(x, y));
            lastPlatformWasGray = true;
            if (rng.getFloat(0.f, 100.f) < bonusChance) {
                entities.push_back(bonusFactory.createEntity(x + 25, y - 50));
            }
        }
        else {
            entities.push_back(staticPlatformFactory.createEntity(x, y)); // Normaal platform
            lastPlatformWasGray = false;
            if (rng.getFloat(0.f, 100.f) < bonusChance) {
                entities.push_back(bonusFactory.createEntity(x + 25, y - 50));
            }
        }

        lastGeneratedY = y;
        platformCount++;

        if (rng.getFloat(0.f, 100.f) < extraPlatformChance) { // Eventueel een extra platform
            float extraX = rng.getFloat(0.f, 700.f);
            float extraY = rng.getFloat(minY, maxY);
            if (abs(extraX - x) >= 150.f) {
                entities.push_back(staticPlatformFactory.createEntity(extraX, extraY));
                lastPlatformWasGray = false;
            }
        }

        if (platformCount >= maxPlatforms) break;
    }
}

void GhanaJump::GameLogic::World::update(float deltaTime, float cameraY) {
    // 1. Maak een visitor aan voor deze update-cyclus
    Logic::CollisionVisitor collisionVisitor(player);

    // 2. Laat elke entiteit de visitor accepteren
    // Dit vervangt de hele for-lus met dynamic_casts
    for (auto& entity : entities) {
        entity->accept(collisionVisitor);
    }

    // 3. Update de speler
    player->update(deltaTime);

    // 4. Update alle andere entiteiten (voor hun eigen beweging)
    for (auto& entity : entities) {
        entity->update(deltaTime);
    }

    // 5. De rest van de logica blijft hetzelfde
    removeEntitiesOutOfView();
    float highestPlatformY = findHighestPlatformY();
    if (highestPlatformY > player->getY() - 1500.f) {
        generateNewPlatforms(highestPlatformY);
    }
}

void GhanaJump::GameLogic::World::reset() {
    entities.clear();
    // entityViews.clear() en observers.clear() zijn verwijderd

    player = playerFactory.createPlayer();

    getScore()->reset();
    getBackground()->reset();

    // addObserver calls zijn verwijderd
    generateInitialPlatforms();
}

std::shared_ptr<GhanaJump::Entities::Player> GhanaJump::GameLogic::World::getPlayer() const {
    return player;
}

const std::vector<std::shared_ptr<GhanaJump::Entities::Entity>>& GhanaJump::GameLogic::World::getEntities() const {
    return entities;
}

std::shared_ptr<GhanaJump::GameLogic::Score> GhanaJump::GameLogic::World::getScore() const {
    return score;
}

std::shared_ptr<GhanaJump::Graphics::Background> GhanaJump::GameLogic::World::getBackground() const {
    return background;
}
