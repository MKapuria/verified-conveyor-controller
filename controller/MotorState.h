#pragma once
#include "motor.h"

// MotorState.h
// ------------------------
// Abstract base class for all motor states (Idle, Running, FaultStop).
// Declares the interface that each state must implement:
//   - enter(): logic when entering this state
//   - toggle(): logic to determine and trigger the next state
//   - exit(): logic when exiting this state
// All methods take a pointer to the Motor object so states can modify it.
// This class uses pure virtual methods (= 0), making it abstract.


// Defining the MotorState interface. This will let us take advantage of polymorphism so we can
// refer to a generic state without having to specific the true type of state

// Forward declaration to resolve circular dependancy/include
class Motor;

class MotorState // abstract class
{
public: //functions are accessible to code outside of class also
	virtual void enter(Motor* motor) = 0; //virtual function enter that takes a pointer motor of type Motor
	virtual void toggle(Motor* motor) = 0;
	virtual void exit(Motor* motor) = 0;
	virtual ~MotorState() {} // virtual destructor that deletes this instance on 'delete _'
	virtual const char* getName() const = 0; // every state must tell me its name
};
#pragma once
