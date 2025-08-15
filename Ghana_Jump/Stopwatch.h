#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

namespace GhanaJump {
    namespace Utilities {
        /**
         * @class Stopwatch
         * @brief Een Singleton-klasse voor het bijhouden van de verstreken tijd tussen frames.
         *
         * Wordt gebruikt om een stabiele `deltaTime` te berekenen, wat essentieel is
         * voor frame-rate onafhankelijke beweging en fysica.
         */
        class Stopwatch {
        private:
            std::chrono::steady_clock::time_point lastUpdate;
            float deltaTime; // Houdt de delta tijd bij (verschil in tijd tussen updates)
            Stopwatch();
        public:
            Stopwatch(const Stopwatch&) = delete;
            Stopwatch& operator=(const Stopwatch&) = delete;
            static Stopwatch& getInstance();
            void update(); // Update functie om delta tijd bij te werken
            float getDeltaTime() const; // Getter
        };
    }
}

#endif // STOPWATCH_H