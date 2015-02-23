#ifndef JoystickDrive_H
#define JoystickDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class JoystickDrive: public CommandBase
{
private:
	Joystick* stick;
	float power;

public:
	JoystickDrive(Joystick* stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
