#ifndef PutToSmartDashboard_H
#define PutToSmartDashboard_H

#include "../CommandBase.h"
#include "WPILib.h"

class PutToSmartDashboard: public CommandBase
{
public:
	PutToSmartDashboard();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
