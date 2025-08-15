#ifndef BONUS_H
#define BONUS_H

#include "Entity.h"
#include "Random.h"
#include "EntityVisitor.h" // Include de visitor

namespace GhanaJump{
    namespace Entities {
        /**
         * @class Bonus
         * @brief Representeert een power-up (bonus) object in de spelwereld.
         *
         * Een bonus is een entiteit die de speler kan oppakken voor een speciaal effect,
         * zoals een extra hoge sprong. De bonus heeft een type en kan maar één keer gebruikt worden.
         */
        class Bonus : public Entity {
        public:
            enum class Type { // Twee types bonus zijn mogelijk
                Jetpack,
                Energy
            };
        private:
            Type type;
            bool isActive; // Houdt bij of de bonus al gebruikt is
        public:
            Bonus(float x, float y); // Enkel plaats is nodig om een bonus aan te maken
            ~Bonus() override = default; // Virtuele destructor, regel van drie
            Bonus(const Bonus&) = default; // Voeg copy constructor toe.
            Bonus& operator=(const Bonus&) = default; // Voeg copy assignment operator toe.

            void update(const float& deltaTime) override;
            void accept(Logic::EntityVisitor& visitor) override;

            // Getters en setters
            bool getIsActive() const;
            Type getType() const;
            void setType(Type whichType);
            void deactivate(); // Is eigenlijk een setter voor isActive, zet deze op false
        };

    }
}

#endif //BONUS_H
