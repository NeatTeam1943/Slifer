#include "Drive.h"

Drive::Drive(float move, float rotate) {
	Requires(chassis);
	this->y = move;
	this->x = rotate;
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	chassis->Drive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	chassis->Drive(this->y, this->x);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	chassis->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {
	End();
}
