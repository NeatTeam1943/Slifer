#include <Commands/Chassis/JoystickDrive.h>
#include "Chassis.h"
#include "../CommandBase.h"
#include "../RobotMap.h"

Chassis::Chassis() :
		Subsystem("Chassis") {
	this->left = new CANTalon(CHASSIS_LEFT_MOTOR_CAN);
	this->right = new CANTalon(CHASSIS_RIGHT_MOTOR_CAN);
	this->drive = new RobotDrive(this->left, this->right);
	this->drive->SetSafetyEnabled(false);
}

void Chassis::InitDefaultCommand() {
	SetDefaultCommand(new JoystickDrive(CommandBase::oi->getJoystick()));
}

void Chassis::Drive(float move, float rotation) {
	this->drive->ArcadeDrive(move, rotation, false);
}

void Chassis::Drive(float forward) {
	//this->drive->
}

void Chassis::DriveJoystick(Joystick *stick) {
	float x = 0, y = 0;
	if (stick->GetY() > 0.2 || stick->GetY() < -0.2)
		y = -stick->GetY();
	if (stick->GetX() > 0.2 || stick->GetX() < -0.2)
		x = -stick->GetX();
	this->drive->ArcadeDrive(y, x, false);
}

void Chassis::DriveRightStick(Joystick *stick) {
	float x = 0, y = 0;
	if (stick->GetRawAxis(5) > 0.2 || -stick->GetRawAxis(5) < -0.2)
		y = stick->GetRawAxis(5);
	if (stick->GetRawAxis(4) > 0.2 || -stick->GetRawAxis(4) < -0.2)
		x = stick->GetRawAxis(4);
	this->drive->ArcadeDrive(y, x, false);
}

void Chassis::TurnInPlace(float power) {
	this->drive->ArcadeDrive(0, power, false);
}
