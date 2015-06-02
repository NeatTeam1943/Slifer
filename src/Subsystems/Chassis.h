#ifndef Chassis_H
#define Chassis_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem {
private:
	CANTalon *left;
	CANTalon *right;
	RobotDrive * drive;

public:
	Chassis();
	void InitDefaultCommand();
	void Drive(float move, float rotation);
	void Drive(float forward);
	void DriveJoystick(Joystick *stick);
	void DriveRightStick(Joystick *stick);
	void TurnInPlace(float power);
};

#endif
