#pragma once
#include "MotorState.h"

// Motor.h
// ------------------------
// Declares the Motor class — the object being controlled.
// The Motor holds a pointer to its current state (MotorState*).
// Public methods:
//   - getCurrentState(): returns current state pointer
//   - toggle(): delegates logic to currentState->toggle()
//   - setState(): handles transitions (calls exit(), updates pointer, calls enter())
// The Motor class starts in the Idle state by default.


//Forward declaration to resolve circular include
class MotorState;

class Motor
{
public:
	bool cmdRun; //true if operator commands start
	bool eStop; // true if emergency stop is triggered
	bool sensorBlock; // true if sensor detects obstruction
	bool manualReset; // true when operator resets fault stop 
	bool isRunning; // true is motor is running in Running
	int runtime; // how long the motor has been running
	int maxRuntime; // limit

	


	Motor();
	inline MotorState* getCurrentState() const { return currentState;  }
	void toggle();

	void setState(MotorState& newState);

private:
	MotorState* currentState;
};