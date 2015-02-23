#include "Grabber.h"
#include "../RobotMap.h"

Grabber::Grabber() :
		Subsystem("Grabber") {
	this->motor = new CANTalon(GRABBER_MOTOR_CAN);
	this->openS = new DigitalInput(GRABBER_OPEN_SWITCH);
	this->closeS = new DigitalInput(GRABBER_CLOSE_SWITCH);
}

void Grabber::InitDefaultCommand() {
	SetDefaultCommand(0);
}

void Grabber::SetMotorPower(float power) {
	this->motor->Set(power);
}

bool Grabber::IsOpen() {
	return this->openS->Get();
}

bool Grabber::IsClosed() {
	return this->closeS->Get();
}

/*
 void Grabber::SetPistonsState(DoubleSolenoid::Value value) {
 this->pistons->Set(value);
 }

 DoubleSolenoid::Value Grabber::GetPistonsState() {
 return this->pistons->Get();
 }

 void Grabber::SwitchPistonsState() {
 if (GetPistonsState() == DoubleSolenoid::Value::kForward)
 this->pistons->Set(DoubleSolenoid::Value::kReverse);
 else if (GetPistonsState() == DoubleSolenoid::Value::kReverse)
 this->pistons->Set(DoubleSolenoid::Value::kForward);
 }
 */
