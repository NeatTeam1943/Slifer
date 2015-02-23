#include "JoystickDrive.h"

JoystickDrive::JoystickDrive(Joystick* stick) {
	Requires(chassis);
	this->stick = stick;
	this->power = 0.6;
}

void JoystickDrive::Initialize() {
	chassis->Drive(0, 0);
}

void JoystickDrive::Execute() {
	if (stick->GetPOV() == -1) {
		//chassis->DriveJoystick(stick);
		chassis->Drive(-stick->GetY(), -stick->GetX());
	} else {
		switch (stick->GetPOV()) {
		case 90:
			chassis->TurnInPlace(-this->power);
			break;
		case 270:
			chassis->TurnInPlace(this->power);
			break;
		}
	}
}

bool JoystickDrive::IsFinished() {
	return false;
}

void JoystickDrive::End() {
	chassis->Drive(0, 0);
}

void JoystickDrive::Interrupted() {
}
