#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"

class OI
{
private:
	Joystick *stick;
	JoystickButton* buttons[10];
	DigitalInput *autoSwitch1;
	DigitalInput *autoSwitch2;

public:
	OI();
	Joystick* getJoystick();
	JoystickButton** GetButtons();
	DigitalInput* GetAutonomousSwitch1();
	DigitalInput* GetAutonomousSwitch2();
};

#endif
