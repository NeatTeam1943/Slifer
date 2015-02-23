#ifndef Elevator_H
#define Elevator_H

//#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public Subsystem {
private:
	DigitalInput *upSwitch;
	DigitalInput *downSwitch;
	CANTalon *motor;

public:
	Elevator();
	void InitDefaultCommand();
	void Move(float power);
	bool GetUpSwitch();
	bool GetDownSwitch();

};

#endif
