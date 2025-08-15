#include "Game.h"

int main() {
    GhanaJump::GameLogic::Game game; // Maak een Game object aan

    // Game loop
    while (game.running()) {
        game.update(); // Update de game
        game.render(); // Render de game
    }

    return 0; // Sluit het programma
}