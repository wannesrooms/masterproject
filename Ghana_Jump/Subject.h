#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
#include <memory>

namespace GhanaJump {
    namespace Graphics {
        /**
         * @class Subject
         * @brief De `Subject` klasse voor het Observer-ontwerppatroon.
         *
         * Beheert een lijst van `Observer` objecten en kan hen op de hoogte stellen
         * van veranderingen door hun `update`-methode aan te roepen.
         */
        class Subject {
        protected:
            std::vector<std::shared_ptr<Observer>> observers; // Lijst van observers

        public:
            void addObserver(std::shared_ptr<Observer> observer);
            void removeObserver(std::shared_ptr<Observer> observer);
            void notifyObservers(float cameraY);
            std::vector<std::shared_ptr<Observer>> getObservers() const; // Getter
        };
    }
}

#endif // SUBJECT_H