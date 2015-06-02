#include "ElevatorLiftByPOV.h"
ElevatorLiftByPOV::ElevatorLiftByPOV(Joystick* stick) {
	Requires(elevator);
	this->stick = stick;
}

// Called just before this Command runs the first time
void ElevatorLiftByPOV::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ElevatorLiftByPOV::Execute() {
	if (stick->GetPOV() == 0) { // go up
		if (!elevator->GetUpSwitch())
			elevator->Move(1);
		else
			elevator->Move(0);
	} else if (stick->GetPOV() == 180) { // go down
		if (!elevator->GetDownSwitch())
			elevator->Move(-1);
		else {
			elevator->Move(0);
		}
	} else
		elevator->Move(0);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorLiftByPOV::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElevatorLiftByPOV::End() {
	elevator->Move(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorLiftByPOV::Interrupted() {
	End();
}
