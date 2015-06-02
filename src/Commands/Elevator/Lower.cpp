#include "Lower.h"

Lower::Lower() {
	Requires(elevator);
}

// Called just before this Command runs the first time
void Lower::Initialize() {
	elevator->Move(0);
}

// Called repeatedly when this Command is scheduled to run
void Lower::Execute() {
	elevator->Move(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool Lower::IsFinished() {
	return elevator->GetDownSwitch()
			&& SmartDashboard::GetBoolean("DownAlternate");
}

// Called once after isFinished returns true
void Lower::End() {
	elevator->Move(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lower::Interrupted() {
	End();
}
