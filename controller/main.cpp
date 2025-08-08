#include "Motor.h"
#include "ConcreteMotorStates.h"
#include <iostream>

// main.cpp
// ------------------------
// Entry point of the program.
// Creates a Motor object and performs basic simulation:
//   - Print initial state pointer
//   - Call toggle() once
//   - Print new state pointer
// This is for testing and observing that the FSM transitions work correctly.


int main() {
	Motor motor; //create a motor object

	// Operator sends a start command and there are no faults
	motor.cmdRun = true;
	motor.eStop = false;
	motor.sensorBlock = false;
	motor.runtime = 0;
	motor.maxRuntime = 5;
	motor.manualReset = false; 

	// Print initial state
	std::cout << "Initial state:" << motor.getCurrentState()->getName() << "\n";

	// Call toggle() to simulate system steps
	std::cout << "Operator sends CmdRun = true command and there are no faults. \n";
	motor.toggle(); //Step 1: expect to go from idle to running

	// Simulate a few cycles of running
	for (int i = 0; i < 6; i++) {
		if (motor.getCurrentState() == &Running::getInstance()) {
			motor.runtime++;
		}
		std::cout << "Runtime: " << motor.runtime << "\n";
		motor.toggle(); // This will eventually trigger FaultStop if runtime > max runtime
	}

	// motor is now in fault stop

	// Now simulate manual reset
	motor.manualReset = true;
	std::cout << "Operator does Manual reset. \n";
	motor.toggle(); // should go from faultstop to idle


	return 0;
}