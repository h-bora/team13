#pragma once
#include <vector>

class RCcircuit {
private:
    std::vector<double> voltageValues; // ��°� ����
    double timeStep;
    double totalTime;

public:
    RCcircuit(double timeStep = 0.01, double totalTime = 5.0);
    void simulate(double R, double C, double Vin);
    const std::vector<double>& getVoltageArray() const;
};
