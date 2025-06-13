#include "RCcircuit.h"
#include <cmath>

RCcircuit::RCcircuit(double ts, double tt) : timeStep(ts), totalTime(tt) {}

void RCcircuit::simulate(double R, double C, double Vin) {
    voltageValues.clear();
    double Vc = 0.0; // 초기 커패시터 전압
    double alpha = 1.0 / (R * C);
    int steps = static_cast<int>(totalTime / timeStep);

    for (int i = 0; i < steps; ++i) {
        double t = i * timeStep;
        Vc = Vin * (1 - std::exp(-alpha * t));
        voltageValues.push_back(Vc);
    }
}

const std::vector<double>& RCcircuit::getVoltageArray() const {
    return voltageValues;
}
