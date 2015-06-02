#include "AutoToteLift.h"
#include "../Elevator/Lift.h"
#include "../Elevator/Lower.h"
#include "../Grabber/OpenArms.h"
#include "../Grabber/CloseArms.h"
#include "../Chassis/Drive.h"

AutoToteLift::AutoToteLift()
{
	AddSequential(new OpenArms());
	AddSequential(new Lower());
	AddSequential(new CloseArms());
	AddSequential(new Lift(), 4);
	AddSequential(new Drive(0.3,0),1);
	AddSequential(new Lower(), 3);
	AddSequential(new OpenArms());
	AddSequential(new Lower());
	AddSequential(new CloseArms());
	AddSequential(new Lift(), 1);
	AddSequential(new Drive(0, 0.3), 1);
	AddSequential(new Drive(0.3, 0), 2);
}
