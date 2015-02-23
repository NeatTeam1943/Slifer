#ifndef ElevatorLiftByPOV_H
#define ElevatorLiftByPOV_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ElevatorLiftByPOV: public CommandBase {
private:
	Joystick* stick;

public:
	ElevatorLiftByPOV(Joystick* stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
