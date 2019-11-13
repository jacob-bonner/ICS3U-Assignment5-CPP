// Copyright (c) 2019 Jacob Bonner All rights reserved.
//
// Created by: Jacob Bonner
// Created on: October 2019
// This program rolls two dice (d6) until doubles are rolled

#include <stdlib.h>
#include <ctime>
#include <iostream>

int main() {
    // This function rolls two dice (d6) until doubles are rolled

    // Variables
    int overall = 0;
    int repeats = 0;
    float iterationPercentage = 0;
    float overallPercentage;
    int iteration;
    int rollCounter;
    int firstNumber;
    int secondNumber;

    // Random number seed
    unsigned int seed = time(NULL);

    // Input
    std::cout << "Enter the amount of times you want to roll the dice: " \
              <<std::endl;
    std::cin >> repeats;

    // Process
    for (iteration = 0; iteration < repeats; iteration++) {
        // Variable reset
        rollCounter = 0;
        firstNumber = 0;
        secondNumber = 1;
        iterationPercentage = 0;
        overallPercentage = 0;

        while (firstNumber != secondNumber) {
            firstNumber = (rand_r(&seed) % 6) + 1;
            secondNumber = (rand_r(&seed) % 6) + 1;
            rollCounter = rollCounter + 1;
            overall = overall + 1.0;
            iterationPercentage = (1.0/rollCounter)*100;
            std::cout << "Your rolls: " << firstNumber << " and " \
                      << secondNumber << std::endl;
        }

        // While loop output
        std::cout << "You successfully rolled doubles after " \
                  << rollCounter << " attempts!"<< std::endl;
        std::cout << "Percentage of rolling doubles per " << rollCounter \
                  << " rolls: " << iterationPercentage << "%" << std::endl;
        std::cout << "" << std::endl;
    }
    // For loop output
    overallPercentage = (static_cast<float>(iteration) \
                         /static_cast<float>(overall))*100;
    std::cout << "After " << repeats \
              << " iterations, the percentage of doubles rolled is "
              <<overallPercentage << "%" <<std::endl;
}
