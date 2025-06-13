#pragma once
#include <vector>

class RLcircuit {
private:
    std::vector<double> currentValues;
    double timeStep;
    double totalTime;

public:
    RLcircuit(double timeStep = 0.01, double totalTime = 5.0);
    void simulate(double R, double L, double Vin);
    const std::vector<double>& getCurrentArray() const;
};
