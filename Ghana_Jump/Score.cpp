#include "Score.h"

GhanaJump::GameLogic::Score::Score() : highestY(400.f), highScore(0) {
    // Laad het lettertype
    if (!font.loadFromFile("resources/BebasNeue-Regular.ttf")) {
        std::cerr << "Error: Could not load font file." << std::endl;
    }

    // Laad de stijl van de tekst
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10.f, 10.f); // Positie van de score

    // Initialiseer highScoreText (voor Game Over scherm)
    highScoreText.setFont(font);
    highScoreText.setCharacterSize(75);
    highScoreText.setFillColor(sf::Color::Black);
    highScoreText.setPosition(135.f, 400.f);

    loadHighScore(); // Laad de high score bij het starten van het spel
}

void GhanaJump::GameLogic::Score::render(sf::RenderWindow& window, bool gameOver) {
    if (!gameOver) {
        // Toon de normale score tijdens het spel
        window.draw(scoreText);
    }
    else {
        // Toon score en high score op het game over scherm
        // We moeten hier de tekst van scoreText en highScoreText bijwerken

        // Update scoreText voor de game over layout
        scoreText.setString("Score: " + std::to_string(getCurrentScore()));
        scoreText.setCharacterSize(75); // Grotere font size voor game over
        scoreText.setFillColor(sf::Color::Red); // Andere kleur voor game over
        scoreText.setPosition(135.f, 300.f); // Positie voor game over

        // Update highScoreText
        highScoreText.setString("High Score: " + std::to_string(highScore)); // Gebruik de member highScore
        highScoreText.setPosition(135.f, 400.f); // Positionering van de high score

        window.draw(scoreText);
        window.draw(highScoreText);
    }
}

void GhanaJump::GameLogic::Score::reset() {
    highestY = 400.f; // Reset de hoogste y-waarde (startpositie van de speler)
    // ScoreText wordt gereset in update, maar we kunnen hier ook zorgen voor juiste initiële weergave.
    scoreText.setString("Score: 0");
    scoreText.setCharacterSize(50); // Terug naar normale grootte
    scoreText.setFillColor(sf::Color::Black); // Terug naar normale kleur
    scoreText.setPosition(10.f, 10.f); // Terug naar normale positie
}

void GhanaJump::GameLogic::Score::loadHighScore() { // Laad de highscore uit een .txt bestand
    std::ifstream inFile("highscore.txt");
    if (inFile.is_open()) {
        inFile >> highScore;
        inFile.close();
    }
    else {
        // Als het bestand er niet is, begin met een high score van 0
        highScore = 0;
    }
}

void GhanaJump::GameLogic::Score::updateHighScore() {
    int currentScore = getCurrentScore();
    if (currentScore > highScore) {
        highScore = currentScore;
        std::ofstream outFile("highscore.txt");
        if (outFile.is_open()) { // Controleer of het bestand succesvol geopend is
            outFile << highScore;
            outFile.close();
        }
        else {
            // Log een error als het bestand niet geschreven kan worden
            std::cerr << "Error: Could not open highscore.txt for writing." << std::endl;
        }
    }
}

void GhanaJump::GameLogic::Score::update(float cameraY) {
    // Update de hoogste y-waarde als de cameraY hoger is (lager Y-getal)
    if (cameraY < highestY || highestY == 0) {
        highestY = cameraY;
    }

    // Zet de tekst van de score voor het normale spel
    if (highestY != 0) { // Alleen updaten als er een geldige hoogste Y is
        scoreText.setString("Score: " + std::to_string(getCurrentScore()));
        scoreText.setCharacterSize(50);
        scoreText.setFillColor(sf::Color::Black);
        scoreText.setPosition(10.f, 10.f);
    }

    // Update de high score
    updateHighScore();
}

//Getters
int GhanaJump::GameLogic::Score::getHighScore() const {
    return highScore;
}

int GhanaJump::GameLogic::Score::getCurrentScore() const {
    // Score is een lineaire functie van de hoogste y-waarde, zo is deze altijd nul bij startpositie
    return static_cast<int>(std::max(0.f, 357.f - highestY));
}