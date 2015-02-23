#include "Elevator.h"
#include "../RobotMap.h"
#include "Commands/Elevator/ElevatorLiftByPOV.h"

Elevator::Elevator() :
		Subsystem("Elevator") {
	this->motor = new CANTalon(ELEVATOR_MOTOR_CAN);
	this->upSwitch = new DigitalInput(ELEVATOR_UP_SWITCH);
	this->downSwitch = new DigitalInput(ELEVATOR_DOWN_SWITCH);
}

void Elevator::InitDefaultCommand() {
	SetDefaultCommand(new ElevatorLiftByPOV(CommandBase::oi->getJoystick()));
}
void Elevator::Move(float power) {
	this->motor->Set(power);
}

bool Elevator::GetUpSwitch() {
	return this->upSwitch->Get();
}

bool Elevator::GetDownSwitch() {
	return this->downSwitch->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
