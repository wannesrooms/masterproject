#include "CollisionVisitor.h"
#include <memory>
#include <algorithm> // Nodig voor std::min en std::max

// Include de volledige definities van ALLE bezochte klassen
#include "StaticPlatform.h"
#include "GrayPlatform.h"
#include "HorizontalPlatform.h"
#include "VerticalPlatform.h"
#include "Bonus.h"

namespace GhanaJump {
    namespace Logic {

        CollisionVisitor::CollisionVisitor(std::shared_ptr<Entities::Player> p)
            : player(p), collisionHandled(false) {
        }

        // Controleert op botsingen met een statisch platform (beweegt niet op en neer)
        void CollisionVisitor::handleStaticCollision(const Entities::Platform& platform) {
            if (collisionHandled || player->getVelocityY() <= 0) return;

            const float platformLeft = platform.getX();
            const float platformRight = platform.getX() + platform.getWidth();
            const float platformTop = platform.getY();

            const float playerFeetY_now = player->getY() + player->getHeight();
            const float playerFeetY_prev = player->getPrevY() + player->getHeight();
            const float playerX_left = player->getX() + 15;
            const float playerX_right = player->getX() + player->getWidth() - 15;

            if ((playerX_right > platformLeft && playerX_left < platformRight) &&
                (playerFeetY_prev <= platformTop) &&
                (playerFeetY_now >= platformTop))
            {
                player->setPosition(player->getX(), platform.getY() - player->getHeight());
                player->setVelocityY(0.f);
                player->jump();
                collisionHandled = true;
            }
        }

        // Controleert op botsingen met op en neer bewegende platformen (vertical)
        void CollisionVisitor::handleDynamicVerticalCollision(const Entities::VerticalPlatform& platform) {
            if (collisionHandled || player->getVelocityY() <= 0) return;

            const float playerX_left = player->getX() + 15;
            const float playerX_right = player->getX() + player->getWidth() - 15;
            const float platformLeft = platform.getX();
            const float platformRight = platform.getX() + platform.getWidth();

            // Controleer eerst op horizontale overlap
            if (playerX_right <= platformLeft || playerX_left >= platformRight) return;

            // Bepaal het bewegingspad (swept volume) van de speler en het platform
            const float player_top = player->getPrevY() + player->getHeight();
            const float player_bottom = player->getY() + player->getHeight();

            const float platform_top_prev = platform.getPrevY();
            const float platform_top_now = platform.getY();

            // Het totale gebied waar het platform was in de laatste frame
            const float platform_swept_top = std::min(platform_top_prev, platform_top_now);
            const float platform_swept_bottom = std::max(platform_top_prev, platform_top_now) + platform.getHeight();

            // Controleer of de bewegingspaden elkaar kruisen (interval intersectie)
            if (player_top <= platform_swept_bottom && player_bottom >= platform_swept_top) {
                player->setPosition(player->getX(), platform.getY() - player->getHeight());
                player->setVelocityY(0.f);
                player->jump();
                collisionHandled = true;
            }
        }

        void CollisionVisitor::visit(Entities::Player& player) {}

        void CollisionVisitor::visit(Entities::StaticPlatform& platform) {
            handleStaticCollision(platform);
        }

        void CollisionVisitor::visit(Entities::HorizontalPlatform& platform) {
            // Horizontale platformen bewegen niet verticaal, dus we doen de simpele check
            handleStaticCollision(platform);
        }

        void CollisionVisitor::visit(Entities::VerticalPlatform& platform) {
            // Verticaal bewegende platformen hebben de andere check nodig
            handleDynamicVerticalCollision(platform);
        }

        void CollisionVisitor::visit(Entities::GrayPlatform& platform) {
            bool alreadyCollided = collisionHandled;
            handleStaticCollision(platform); // Grijze platformen zijn statisch
            if (!alreadyCollided && collisionHandled) {
                platform.use();
            }
        }

        void CollisionVisitor::visit(Entities::Bonus& bonus) {
            if (bonus.getIsActive() && !player->getInBonusState() &&
                bonus.getX() >= player->getX() - 40.f && bonus.getX() <= player->getX() + 90.f &&
                bonus.getY() >= player->getY() - 40.f && bonus.getY() <= player->getY() + 134.f) {

                if (bonus.getType() == Entities::Bonus::Type::Jetpack) player->setVelocityY(-3292.f);
                else if (bonus.getType() == Entities::Bonus::Type::Energy) player->setVelocityY(-1900.67f);

                bonus.deactivate();
                player->setInBonusState();
            }
        }
    }
}
