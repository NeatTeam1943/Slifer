#include "AutoBinGrab.h"
#include "../Elevator/Lift.h"
#include "../Elevator/Lower.h"
#include "../Grabber/OpenArms.h"
#include "../Grabber/CloseArms.h"
#include "../Chassis/Drive.h"

AutoBinGrab::AutoBinGrab()
{
	AddSequential(new OpenArms());
	AddSequential(new Drive(0.3, 0), 0.7);
	AddSequential(new CloseArms());
	AddSequential(new Lift(), 1);
	AddSequential(new Drive(-0.5, 0), 1.2);
}
