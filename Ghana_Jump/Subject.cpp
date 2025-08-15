#include "Subject.h"
#include <memory>

void GhanaJump::Graphics::Subject::addObserver(std::shared_ptr<Observer> observer) {
    observers.push_back(observer); // Simpel aan vector toevoegen
}

void GhanaJump::Graphics::Subject::removeObserver(std::shared_ptr<Observer> observer) {
    // Doorloop vector en verwijder
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void GhanaJump::Graphics::Subject::notifyObservers(float currentY) {
    // Doorloop vector en update elke observer
    for (const auto& observer : observers) {
        observer->update(currentY);
    }
}

// Getter
std::vector<std::shared_ptr<GhanaJump::Graphics::Observer>> GhanaJump::Graphics::Subject::getObservers() const {
    return observers;
}
