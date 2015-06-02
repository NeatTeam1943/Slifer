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
	AddSequential(new Lift(), 3);
	AddSequential(new Drive(-0.3, 0), 3);
}
