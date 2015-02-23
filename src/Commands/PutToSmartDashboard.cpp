#include "PutToSmartDashboard.h"
#include "CommandBase.h"

PutToSmartDashboard::PutToSmartDashboard() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void PutToSmartDashboard::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PutToSmartDashboard::Execute() {
	SmartDashboard::PutBoolean("Is Elevator up",
			CommandBase::elevator->GetUpSwitch());
	SmartDashboard::PutBoolean("Is Elevator down",
			CommandBase::elevator->GetDownSwitch());
	SmartDashboard::PutBoolean("Is Grabber open",
			CommandBase::grabber->IsOpen());
	SmartDashboard::PutBoolean("Is Grabber closed",
			CommandBase::grabber->IsClosed());
}

// Make this return true when this Command no longer needs to run execute()
bool PutToSmartDashboard::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PutToSmartDashboard::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PutToSmartDashboard::Interrupted() {

}
