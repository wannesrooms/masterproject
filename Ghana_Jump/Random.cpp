#include "Random.h"

GhanaJump::Utilities::Random::Random() {
    std::random_device rd; // Hardware random number generator
    rng.seed(rd()); // Seed de generator met een random waarde
}

GhanaJump::Utilities::Random& GhanaJump::Utilities::Random::getInstance() {
    static Random instance;
    return instance;
}

int GhanaJump::Utilities::Random::getInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max); // Uniforme verdeling is gelijke kansen
    return dist(rng);
}

float GhanaJump::Utilities::Random::getFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max); // Uniforme verdeling is gelijke kansen
    return dist(rng);
}
