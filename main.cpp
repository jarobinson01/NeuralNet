#include <vector>
#include <iostream>

#include "Net.h"

int main() {
    std::vector<unsigned> topology;
    topology.push_back(2);
    topology.push_back(4);
    topology.push_back(1);
    Net myNet(topology);

    std::vector<double> inputVals;
    std::vector<double> targetVals;
    std::vector<double> resultVals;

    for(unsigned i = 1; i <= 2000; i++) {
        inputVals.clear();
        targetVals.clear();
        unsigned input1 = rand() % 2;
        unsigned input2 = rand() % 2;
        inputVals.push_back(input1);
        inputVals.push_back(input2);

        unsigned target = input1 != input2 ? 1 : 0;
        targetVals.push_back(target);

        myNet.feedForward(inputVals);
        myNet.backProp(targetVals);
        myNet.getResults(resultVals);

        std::cout << std::endl;
        std::cout << "Pass " << i << std::endl;
        std::cout << "Inputs: " << input1 << " " << input2 << std::endl;
        std::cout << "Outputs: " << resultVals[0] << std::endl;
        std::cout << "Targets: " << target << std::endl;
    }
    
    return 0;
}