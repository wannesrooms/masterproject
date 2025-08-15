#ifndef ENTITYVISITOR_H
#define ENTITYVISITOR_H

// Forward declarations om circulaire includes te voorkomen
namespace GhanaJump {
    namespace Entities {
        class Player;
        class StaticPlatform;
        class GrayPlatform;
        class HorizontalPlatform;
        class VerticalPlatform;
        class Bonus;
    }
}

namespace GhanaJump {
    namespace Logic {
        /**
         * @class EntityVisitor
         * @brief De abstracte interface voor het Visitor-ontwerppatroon.
         *
         * Deze klasse definieert een `visit`-operatie voor elke concrete subklasse van
         * `Entity`. Dit maakt het mogelijk om nieuwe operaties aan entiteiten toe te voegen
         * zonder de klassen van die entiteiten zelf aan te passen.
         */
        class EntityVisitor {
        public:
            virtual ~EntityVisitor() = default;

            // Een 'visit' methode voor elke concrete entity-klasse
            virtual void visit(Entities::Player& player) = 0;
            virtual void visit(Entities::StaticPlatform& platform) = 0;
            virtual void visit(Entities::GrayPlatform& platform) = 0;
            virtual void visit(Entities::HorizontalPlatform& platform) = 0;
            virtual void visit(Entities::VerticalPlatform& platform) = 0;
            virtual void visit(Entities::Bonus& bonus) = 0;
        };
    }
}

#endif // ENTITYVISITOR_H