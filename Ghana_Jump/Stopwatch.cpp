#include "Stopwatch.h"

GhanaJump::Utilities::Stopwatch::Stopwatch() : deltaTime(0.f) {
    lastUpdate = std::chrono::steady_clock::now(); // Zet de laatste update op huidige tijd
}

GhanaJump::Utilities::Stopwatch& GhanaJump::Utilities::Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}

void GhanaJump::Utilities::Stopwatch::update() {
    auto now = std::chrono::steady_clock::now(); // Nieuw huidig tijdstip
    std::chrono::duration<float> delta = now - lastUpdate;
    lastUpdate = now; // Laatste update heeft een nieuwe tijd
    deltaTime = delta.count(); // Update de delta tijd
}

// Getter
float GhanaJump::Utilities::Stopwatch::getDeltaTime() const {
    return deltaTime; // Geef de laatste delta tijd terug
}