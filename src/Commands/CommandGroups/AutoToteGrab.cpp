#include "AutoToteGrab.h"
#include "../Elevator/Lift.h"
#include "../Elevator/Lower.h"
#include "../Grabber/OpenArms.h"
#include "../Grabber/CloseArms.h"
#include "../Chassis/Drive.h"

AutoToteGrab::AutoToteGrab()
{
	AddSequential(new CloseArms());
	AddSequential(new Lower());
	AddSequential(new Drive(0.3, 0), 0.7);
	AddSequential(new Drive(0.1, 0), 0.2);
	AddSequential(new Lift(), 1.5);
	AddSequential(new Drive(-0.5, 0), 1.2);
	AddSequential(new Lower());
	AddSequential(new Drive(-0.5, -0.7), 0.5);
	AddSequential(new Drive(-0.5, 0.7), 0.5);
	AddSequential(new OpenArms());
}
