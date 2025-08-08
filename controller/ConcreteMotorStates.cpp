#include "ConcreteMotorStates.h"
#include <iostream>

// ConcreteMotorStates.cpp
// ------------------------
// Defines the behavior of each motor state.
// Implements:
//   - toggle(): transitions to the next state by calling motor->setState()
//   - getInstance(): returns a reference to the singleton instance
// Uses static variables inside getInstance() for safe and lazy instantiation.
// Includes "ConcreteMotorStates.h" to access class declarations.



void Idle::toggle(Motor* motor)
{
	// idle -> running
	if (motor->cmdRun == true && motor->eStop == false && motor->sensorBlock == false && motor->runtime < motor->maxRuntime) {
		motor->setState(Running::getInstance());
		std::cout << "Transition: Idle -> Running \n";
	} 
	else {
		std::cout << "No state change: Still in Idle \n";
	}
}

void Idle::enter(Motor* motor)
{
	std::cout << "Entered Idle state. \n";
}

void Idle::exit(Motor* motor)
{
	std::cout << "Exiting Idle state. \n";
}

MotorState& Idle::getInstance()
{
	static Idle singleton;
	return singleton;
}

const char* Idle::getName() const {
	return "Idle";
}

void Running::toggle(Motor* motor)
{
	// running -> fault_stop or back to idle
	if (motor->eStop == true || motor->sensorBlock == true || motor->runtime >= motor->maxRuntime) {
		motor->setState(FaultStop::getInstance());
		std::cout << "Transition: Running -> Fault stop \n";
	}
	else if(motor->cmdRun == false && motor->eStop == false && motor->sensorBlock == false && motor->runtime < motor->maxRuntime) {
		motor->setState(Idle::getInstance());
		std::cout << "Transition: Running -> Idle \n";
	}
	else {
		std::cout << "No state change: Still in Running \n";
	}
}

void Running::enter(Motor* motor)
{
	motor->runtime = 0;
	motor->isRunning = true;
	std::cout << "Entered Running: timer reset and started. \n";
}

void Running::exit(Motor* motor)
{
	motor->isRunning = false;
	std::cout << "Exiting Running: timer stopped. \n";
}

MotorState& Running::getInstance()
{
	static Running singleton;
	return singleton;
}

const char* Running::getName() const {
	return "Running";
}

void FaultStop::toggle(Motor* motor)
{
	// Fault_stop -> idle
	if (motor->manualReset==true) {
		motor->setState(Idle::getInstance());
		std::cout << "Transition: FaultStop -> Idle (Manual Reset) \n";
	}
	else {
		std::cout << "No state change: Still in Fault Stop \n";
	}
}

void FaultStop::exit(Motor* motor)
{
	motor->eStop = false;
	motor->sensorBlock = false;
	motor->runtime = 0;
	motor->manualReset = false;
	std::cout << "Exiting FaultStop: All faults cleared. \n";

}

void FaultStop::enter(Motor* motor)
{
	std::cout << "Entered FaultStop: motor halted due to fault. \n";
}

MotorState& FaultStop::getInstance()
{
	static FaultStop singleton;
	return singleton;
}

const char* FaultStop::getName() const {
	return "FaultStop";
}


