#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "Commands/Elevator/Lift.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Grabber/OpenArms.h"
#include "Commands/Grabber/CloseArms.h"
#include "Commands/Chassis/Drive.h"
#include "Commands/PutToSmartDashboard.h"

OI::OI() {
	this->stick = new Joystick(JOYSTICK_CHANNEL);
	for (int i = 0; i < 10; i++) {
		this->buttons[i] = new JoystickButton(this->stick, i + 1);
	}
	this->autoSwitch1 = new DigitalInput(AUTONOMOUS_SWITCH1);
	this->autoSwitch2 = new DigitalInput(AUTONOMOUS_SWITCH2);

	this->buttons[0]->WhenPressed(new OpenArms()); // 'A' Button
	this->buttons[1]->WhenPressed(new CloseArms()); // 'B' Button

	this->buttons[3]->WhileHeld(new Drive(0.3, 0)); // 'Y' Button

	this->buttons[4]->WhileHeld(new Lower()); // 'LB' Button
	this->buttons[5]->WhileHeld(new Lift()); // 'RB' Button

	Scheduler::GetInstance()->AddCommand(new PutToSmartDashboard());
}

Joystick* OI::getJoystick() {
	return this->stick;
}

JoystickButton** OI::GetButtons() {
	return this->buttons;
}

DigitalInput* OI::GetAutonomousSwitch1() {
	return this->autoSwitch1;
}

DigitalInput* OI::GetAutonomousSwitch2() {
	return this->autoSwitch2;
}
