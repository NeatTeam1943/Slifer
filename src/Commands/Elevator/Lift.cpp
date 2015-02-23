#include "Lift.h"

Lift::Lift()
{
	Requires(elevator);
}

// Called just before this Command runs the first time
void Lift::Initialize()
{
	elevator->Move(0);
}

// Called repeatedly when this Command is scheduled to run
void Lift::Execute()
{
	elevator->Move(1);
}

// Make this return true when this Command no longer needs to run execute()
bool Lift::IsFinished()
{
	return elevator->GetUpSwitch();
}

// Called once after isFinished returns true
void Lift::End()
{
	elevator->Move(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lift::Interrupted()
{
	End();
}
