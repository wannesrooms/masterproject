#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "EntityVisitor.h"

namespace GhanaJump {
    namespace Entities {
        /**
         * @class Player
         * @brief Representeert de door de speler bestuurde entiteit.
         *
         * Deze klasse bevat alle logica voor de beweging van de speler,
         * inclusief springen, zwaartekracht en horizontale verplaatsing.
         */
        class Player : public Entity {
        public:
            enum class Direction { LEFT, RIGHT }; // Voor de juiste sprite te laden
        private:
            float velocityX, velocityY; // Snelheid
            float prevY; // Hoogte uit vorige frame, nodig voor collisiedetecite 
            const float gravity; // Acceleratie waarmee de speler daalt
            const float jumpStrength; // Startsneleid bij een sprong
            bool inBonusState; // Zegt ons of de speler net een bonus heeft genomen
            Direction lookingDirection;

        public:
            Player();
            ~Player() override = default; // Regel van 3
            Player(const Player&) = default;
            Player& operator=(const Player&) = default;

            void update(const float& deltaTime) override;
            void accept(Logic::EntityVisitor& visitor) override;

            // Getters & Setters
            float getVelocityX() const;
            float getVelocityY() const;
            float getPrevY() const;
            void jump();
            bool hasFallen(float cameraY) const;
            void setVelocityX(float velocity);
            void setVelocityY(float velocity);
            void setInBonusState();
            bool getInBonusState() const;
            Direction getLookingDirection() const;
        };
    }
}

#endif //PLAYER_H