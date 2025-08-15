#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Stopwatch.h"
#include "World.h"
#include "Camera.h"
#include "EntityView.h"
#include "PlayerView.h"
#include "PlatformView.h"
#include "BonusView.h"


namespace GhanaJump {
    namespace GameLogic {
        /**
         * @class Game
         * @brief De centrale controller-klasse die de gameloop en spelstaten beheert.
         *
         * Deze klasse is verantwoordelijk voor het initialiseren van het spel, het verwerken
         * van gebruikersinvoer, het beheren van de gameloop (update/render), en het fungeren
         * als bemiddelaar tussen het Model (World) en de View (EntityView's).
         */
        class Game {
        public:
            enum class GameState {
                StartScreen,
                Running,
                GameOver
            };
        private:
            // Variabelen
            std::unique_ptr<World> world;
            std::unique_ptr<sf::RenderWindow> window;
            sf::VideoMode videoMode;
            sf::Event ev;
            GameState currentState;
            std::unique_ptr<Camera> camera;
            sf::Music music;

            sf::Texture endScreenTexture;
            sf::Sprite endScreenSprite;
            sf::Texture startScreenTexture;
            sf::Sprite startScreenSprite;

            // Containers voor views toegevoegd
            std::shared_ptr<Graphics::PlayerView> playerView;
            std::vector<std::shared_ptr<Graphics::EntityView>> entityViews;

            // Helper functie toegevoegd
            void syncViewsWithWorld();

        public:
            // Initialisaties
            void initWorld();
            void initCamera();

            // Constructor
            Game();

            // Functies
            const bool running() const;
            void handleStartScreenInput();
            void handleEndScreenInput();
            void pollEvents();
            void update();
            void render();
        };
    }
}

#endif //GAME_H