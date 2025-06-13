#include "RLcircuit.h"
#include <cmath>

RLcircuit::RLcircuit(double ts, double tt) : timeStep(ts), totalTime(tt) {}

void RLcircuit::simulate(double R, double L, double Vin) {
    currentValues.clear();
    double I = 0.0;
    double alpha = R / L;
    int steps = static_cast<int>(totalTime / timeStep);

    for (int i = 0; i < steps; ++i) {
        double t = i * timeStep;
        I = (Vin / R) * (1 - std::exp(-alpha * t));
        currentValues.push_back(I);
    }
}

const std::vector<double>& RLcircuit::getCurrentArray() const {
    return currentValues;
}
