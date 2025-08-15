#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Observer.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <stdexcept>

namespace GhanaJump {
    namespace Graphics {
        /**
         * @class Background
         * @brief Beheert en rendert de oneindig scrollende achtergrond van het spel.
         *
         * Deze klasse laadt meerdere achtergrond-texturen en plaatst ze boven elkaar.
         * De update-functie zorgt ervoor dat sprites die uit beeld verdwijnen,
         * weer bovenaan worden geplaatst om een naadloze parallax-scrolling illusie te creëren.
         */
        class Background : public Observer {
        private:
            std::vector<sf::Sprite> sprites; // Sprites voor de achtergronden
            std::vector<sf::Texture> textures; // Texturen voor de verschillende achtergronden
            int numSprites; // Aantal sprites (hier 5)
        public:
            Background(const std::string& baseTextureName, int numTextures = 5);

            void update(float cameraY) override; // Override de update functie van Observer
            void render(sf::RenderWindow& window); // Render de achtergrond op het scherm
            void reset(); // Bij een nieuw spel wordt de achtergrond opnieuw ingesteld 
        };
    }
}

#endif //BACKGROUND_H

