#pragma once
#include "MotorState.h"
#include "Motor.h"

// ConcreteMotorStates.h
// ------------------------
// Declares the concrete state classes for the motor controller:
//   - Idle
//   - Running
//   - FaultStop
// Each of these inherits from MotorState and implements toggle().
// enter() and exit() are defined inline but currently do nothing.
// Each class uses the Singleton pattern:
//   - getInstance() returns the one shared instance.
//   - Constructors and assignment operators are private to prevent copies.


class Idle : MotorState
{
public:
	void enter(Motor* motor);
	void toggle(Motor* motor);
	void exit(Motor* motor);
	static MotorState& getInstance();
	const char* getName() const override;

private:
	Idle() {}
	Idle(const Idle& other);
	Idle& operator=(const Idle& other);
};

class Running : MotorState
{
public:
	void enter(Motor* motor);
	void toggle(Motor* motor);
	void exit(Motor* motor);
	static MotorState& getInstance();
	const char* getName() const override;

private:
	Running() {}
	Running(const Running& other);
	Running& operator=(const Running& other);
};

class FaultStop : MotorState
{
public:
	void enter(Motor* motor);
	void toggle(Motor* motor);
	void exit(Motor* motor);
	static MotorState& getInstance();
	const char* getName() const override;

private:
	FaultStop() {}
	FaultStop(const FaultStop& other);
	FaultStop& operator=(const FaultStop& other);
};