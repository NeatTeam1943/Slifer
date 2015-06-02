#ifndef OpenArms_H
#define OpenArms_H

#include "../../CommandBase.h"
#include "WPILib.h"

class OpenArms: public CommandBase
{
public:
	OpenArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
