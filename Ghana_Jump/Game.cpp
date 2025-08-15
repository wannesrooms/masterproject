#include "Game.h"
#include <memory>
// Voeg factory includes toe die nodig zijn om views te maken
#include "PlayerFactory.h"
#include "StaticPlatformFactory.h"
#include "GrayPlatformFactory.h"
#include "HorizontalPlatformFactory.h"
#include "VerticalPlatformFactory.h"
#include "BonusFactory.h"

// Implementatie van de nieuwe functie
void GhanaJump::GameLogic::Game::syncViewsWithWorld() {
    // Deze functie zorgt ervoor dat de 'entityViews' vector overeenkomt
    // met de 'entities' vector in de World.

    // Maak een set van entities in de wereld voor snelle lookups.
    const auto& worldEntities = this->world->getEntities();
    std::set<std::shared_ptr<Entities::Entity>> worldEntitySet(worldEntities.begin(), worldEntities.end());

    // 1. Verwijder views waarvan de entity niet meer in de wereld bestaat
    entityViews.erase(std::remove_if(entityViews.begin(), entityViews.end(),
        [&](const std::shared_ptr<Graphics::EntityView>& view) {
            std::shared_ptr<Entities::Entity> entity;
            if (auto pv = std::dynamic_pointer_cast<Graphics::PlatformView>(view)) entity = pv->getPlatform();
            else if (auto bv = std::dynamic_pointer_cast<Graphics::BonusView>(view)) entity = bv->getBonus();

            // Als de view geen entity heeft of de entity niet in de wereld is, verwijder de view
            return !entity || worldEntitySet.find(entity) == worldEntitySet.end();
        }), entityViews.end());

    // Maak een map van de overgebleven views voor snelle toegang
    std::map<std::shared_ptr<Entities::Entity>, std::shared_ptr<Graphics::EntityView>> existingViews;
    for (const auto& view : entityViews) {
        std::shared_ptr<Entities::Entity> entity;
        if (auto pv = std::dynamic_pointer_cast<Graphics::PlatformView>(view)) entity = pv->getPlatform();
        else if (auto bv = std::dynamic_pointer_cast<Graphics::BonusView>(view)) entity = bv->getBonus();
        if (entity) {
            existingViews[entity] = view;
        }
    }

    // 2. Maak de player view (altijd opnieuw voor de zekerheid)
    Factories::PlayerFactory playerFactory;
    playerView = std::dynamic_pointer_cast<Graphics::PlayerView>(playerFactory.createEntityView(world->getPlayer()));

    // 3. Maak views voor nieuwe entities die nog geen view hebben
    Factories::StaticPlatformFactory staticFactory;
    Factories::GrayPlatformFactory grayFactory;
    Factories::HorizontalPlatformFactory horizontalFactory;
    Factories::VerticalPlatformFactory verticalFactory;
    Factories::BonusFactory bonusFactory;

    for (const auto& entity : worldEntities) {
        if (existingViews.find(entity) == existingViews.end()) {
            // Deze entity heeft nog geen view, dus maak er een
            std::shared_ptr<Graphics::EntityView> newView = nullptr;
            if (auto p = std::dynamic_pointer_cast<Entities::StaticPlatform>(entity)) newView = staticFactory.createEntityView(p);
            else if (auto p = std::dynamic_pointer_cast<Entities::GrayPlatform>(entity)) newView = grayFactory.createEntityView(p);
            else if (auto p = std::dynamic_pointer_cast<Entities::HorizontalPlatform>(entity)) newView = horizontalFactory.createEntityView(p);
            else if (auto p = std::dynamic_pointer_cast<Entities::VerticalPlatform>(entity)) newView = verticalFactory.createEntityView(p);
            else if (auto p = std::dynamic_pointer_cast<Entities::Bonus>(entity)) newView = bonusFactory.createEntityView(p);

            if (newView) {
                entityViews.push_back(newView);
            }
        }
    }
}


void GhanaJump::GameLogic::Game::initWorld() {
    this->world = std::make_unique<World>();
}

void GhanaJump::GameLogic::Game::initCamera() {
    this->camera = std::make_unique<Camera>();
}

GhanaJump::GameLogic::Game::Game() : currentState(GameState::StartScreen) {
    this->videoMode.height = 1100;
    this->videoMode.width = 800;
    this->initWorld();
    this->initCamera();
    this->window = std::make_unique<sf::RenderWindow>(this->videoMode, "Ghana Jump", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);

    // Synchroniseer views de eerste keer
    syncViewsWithWorld();

    if (!startScreenTexture.loadFromFile("resources/Startscherm.jpg")) throw std::runtime_error("Failed to load start screen texture");
    startScreenSprite.setTexture(startScreenTexture);

    if (!endScreenTexture.loadFromFile("resources/Eindscherm.jpg")) throw std::runtime_error("Failed to load end screen texture");
    endScreenSprite.setTexture(endScreenTexture);

    if (!music.openFromFile("resources/Achtergrondmuziek.mp3")) throw std::runtime_error("Could not load music file");
    music.setLoop(true);
    music.play();
}

const bool GhanaJump::GameLogic::Game::running() const {
    return this->window->isOpen();
}

void GhanaJump::GameLogic::Game::handleStartScreenInput() {
    if (this->ev.key.code == sf::Keyboard::Enter) {
        currentState = GameState::Running;
        this->world->getPlayer()->setVelocityX(0.f);
        this->world->getPlayer()->setVelocityY(0.f);
    }
}

void GhanaJump::GameLogic::Game::handleEndScreenInput() {
    if (this->ev.key.code == sf::Keyboard::Enter) {
        currentState = GameState::StartScreen;
        this->world->reset();
        this->camera->reset();
        // Zorg ervoor dat de views ook gereset worden
        syncViewsWithWorld();
    }
}

void GhanaJump::GameLogic::Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed: // Reacties op indrukken van toetsen
            if (this->ev.key.code == sf::Keyboard::Escape) this->window->close();
            if (currentState == GameState::StartScreen) handleStartScreenInput();
            else if (currentState == GameState::Running) {
                if (this->ev.key.code == sf::Keyboard::A || this->ev.key.code == sf::Keyboard::Left) this->world->getPlayer()->setVelocityX(-425.f);
                if (this->ev.key.code == sf::Keyboard::D || this->ev.key.code == sf::Keyboard::Right) this->world->getPlayer()->setVelocityX(425.f);
            }
            else if (currentState == GameState::GameOver) handleEndScreenInput();
            break;
        case sf::Event::KeyReleased: // Reacties op loslaten van toetsen
            if (currentState == GameState::Running) {
                if (this->ev.key.code == sf::Keyboard::A || this->ev.key.code == sf::Keyboard::Left ||
                    this->ev.key.code == sf::Keyboard::D || this->ev.key.code == sf::Keyboard::Right) {
                    this->world->getPlayer()->setVelocityX(0.f);
                }
            }
            break;
        default:
            break;
        }
    }
}

void GhanaJump::GameLogic::Game::update() {
    this->pollEvents();

    GhanaJump::Utilities::Stopwatch::getInstance().update();
    float deltaTime = GhanaJump::Utilities::Stopwatch::getInstance().getDeltaTime();

    // 1. Update de wereld (de pure logica)
    this->world->update(deltaTime, this->camera->getViewY());

    // 2. Synchroniseer de views met de geüpdatete wereld
    syncViewsWithWorld();

    // 3. Update de views en andere grafische componenten
    if (playerView) playerView->update(this->camera->getViewY());
    for (const auto& view : this->entityViews) {
        view->update(this->camera->getViewY());
    }
    this->world->getBackground()->update(this->camera->getViewY());
    this->world->getScore()->update(this->camera->getViewY());

    // Controleer of de speler is gevallen
    if (this->world->getPlayer()->hasFallen(this->camera->getViewY())) {
        currentState = GameState::GameOver;
    }

    this->camera->update(this->world->getPlayer());
}

void GhanaJump::GameLogic::Game::render() {
    this->window->clear(sf::Color::White);

    if (currentState == GameState::StartScreen) {
        this->window->draw(startScreenSprite);
    }
    else if (currentState == GameState::Running) {
        sf::View currentView = this->window->getView();
        sf::View gameView(
            sf::Vector2f(this->videoMode.width / 2.f, this->camera->getViewY()),
            sf::Vector2f(this->videoMode.width, this->videoMode.height)
        );
        this->window->setView(gameView);

        // Render de grafische componenten
        this->world->getBackground()->render(*this->window);
        if (playerView) this->playerView->render(*this->window);
        for (const auto& entityView : entityViews) {
            entityView->render(*this->window);
        }

        this->window->setView(currentView);

        // Render de score (gebruik de aangepaste versie uit de vorige vraag)
        this->world->getScore()->render(*this->window, false);
    }
    else if (currentState == GameState::GameOver) {
        this->window->draw(endScreenSprite);

        // De Score klasse regelt nu de weergave
        this->world->getScore()->render(*this->window, true);
    }
    this->window->display();
}
