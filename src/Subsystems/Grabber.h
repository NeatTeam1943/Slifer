#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Grabber: public Subsystem {
private:
	CANTalon *motor;
	DigitalInput *openS;
	DigitalInput *closeS;

public:
	Grabber();
	void InitDefaultCommand();
	void SetMotorPower(float power);
	bool IsOpen();
	bool IsClosed();
};

#endif
