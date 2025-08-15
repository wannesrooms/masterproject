#ifndef ENTITY_H
#define ENTITY_H

// Forward declare de visitor klasse
namespace GhanaJump { namespace Logic { class EntityVisitor; } }

namespace GhanaJump {
    namespace Entities {
        /**
         * @class Entity
         * @brief De abstracte basisklasse voor alle objecten in de spelwereld.
         *
         * Deze klasse definieert de basis-eigenschappen van een spelobject,
         * zoals positie en afmetingen, en de interface voor updates en interacties
         * via het Visitor-patroon.
         */
        class Entity {
        protected:
            float x, y;
            const float width, height;

        public:
            virtual void update(const float& deltaTime) = 0;
            Entity(float x, float y, float width, float height);

            // Regel van 3
            virtual ~Entity() = default; 
            Entity(const Entity&) = default;
            Entity& operator=(const Entity&) = default;
            
            // De nieuwe pure virtual accept methode
            virtual void accept(Logic::EntityVisitor& visitor) = 0;

            // Getters
            float getX() const;
            float getY() const;
            float getWidth() const;
            float getHeight() const;

            // Setters
            void setPosition(float xPos, float yPos);
        };
    }
}

#endif //ENTITY_H