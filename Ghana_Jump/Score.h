#ifndef SCOREH
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include <iostream>
#include "Observer.h" // Zorg ervoor dat je de Observer header opneemt

namespace GhanaJump {
    namespace GameLogic {
        /**
         * @class Score
         * @brief Beheert, berekent en rendert de score en high score van de speler.
         *
         * De score wordt berekend op basis van de hoogst bereikte y-positie.
         * Deze klasse kan ook de high score laden uit en opslaan naar een bestand.
         */
        class Score : public Graphics::Observer { // Score is een observer
        private:
            float highestY; // Hoogste y-waarde
            int highScore;  // High score
            sf::Font font;  // Lettertype voor de score
            sf::Text scoreText; // Tekstobject om de score weer te geven
            sf::Text highScoreText; // Tekstobject om de highscore weer te geven

        public:
            Score(); // Constructor

            void render(sf::RenderWindow& window, bool gameOver = false); // Render functie
            void reset(); // Reset de score bij een nieuw spel
            void loadHighScore(); // Laad de high score
            void updateHighScore(); // Update de high score
            void update(float cameraY) override; // Override van Observer

            // Getter
            int getHighScore() const; 
            int getCurrentScore() const; 
        };
    }
}

#endif //SCORE_H
