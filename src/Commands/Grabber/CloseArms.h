#ifndef CloseArms_H
#define CloseArms_H

#include "../../CommandBase.h"
#include "WPILib.h"

class CloseArms: public CommandBase
{
public:
	CloseArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
