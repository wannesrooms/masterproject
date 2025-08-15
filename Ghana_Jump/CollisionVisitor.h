#ifndef COLLISIONVISITOR_H
#define COLLISIONVISITOR_H

#include "EntityVisitor.h"
#include "Player.h"
#include "Platform.h" // Include Platform voor de helper functie
#include <memory>

namespace GhanaJump {
    namespace Logic {
        /**
         * @class CollisionVisitor
         * @brief Een concrete implementatie van EntityVisitor die botsingsdetectie afhandelt.
         *
         * Deze klasse centraliseert de logica voor het detecteren en afhandelen van
         * interacties tussen de speler en andere entiteiten, zoals platformen en bonussen.
         * Dit voorkomt het gebruik van `dynamic_cast` in de gameloop.
         */
        class CollisionVisitor : public EntityVisitor {
        private:
            std::shared_ptr<Entities::Player> player;
            bool collisionHandled;

            // Helper voor platformen die niet verticaal bewegen
            void handleStaticCollision(const Entities::Platform& platform);

            // Helper voor platformen die wel verticaal bewegen
            void handleDynamicVerticalCollision(const Entities::VerticalPlatform& platform);

        public:
            CollisionVisitor(std::shared_ptr<Entities::Player> p);

            // Override alle visit methodes
            void visit(Entities::Player& player) override;
            void visit(Entities::StaticPlatform& platform) override;
            void visit(Entities::GrayPlatform& platform) override;
            void visit(Entities::HorizontalPlatform& platform) override;
            void visit(Entities::VerticalPlatform& platform) override;
            void visit(Entities::Bonus& bonus) override;
        };
    }
}

#endif // COLLISIONVISITOR_H