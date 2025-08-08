#include "Motor.h"
#include "concreteMotorStates.h"

// Motor.cpp
// ------------------------
// Defines the methods of the Motor class.
// Constructor initializes the current state to Idle.
// setState() handles state transitions, including exit() and enter() hooks.
// toggle() delegates behavior to the current state's toggle() method.
// Includes "ConcreteMotorStates.h" to access singleton state instances.


Motor::Motor()
{
	// initially at idle
	currentState = &Idle::getInstance();
}

void Motor::setState(MotorState& newState)
{
	currentState->exit(this); // do something before we change state
	currentState = &newState; // actually change states now
	currentState->enter(this); // do something after we change change
}
void Motor::toggle()
{
	// delegate the task of determining the next state to the current state
	currentState->toggle(this);
}