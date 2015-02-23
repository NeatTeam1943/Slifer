#include "OpenArms.h"

OpenArms::OpenArms() {
	Requires(grabber);
}

// Called just before this Command runs the first time
void OpenArms::Initialize() {
	SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void OpenArms::Execute() {
	grabber->SetMotorPower(0.4);
}

// Make this return true when this Command no longer needs to run execute()
bool OpenArms::IsFinished() {
	return grabber->IsOpen() || IsTimedOut();
}

// Called once after isFinished returns true
void OpenArms::End() {
	grabber->SetMotorPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenArms::Interrupted() {
	End();
}
