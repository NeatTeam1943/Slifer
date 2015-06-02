#ifndef Drive_H
#define Drive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Drive: public CommandBase
{
private:
	float y;
	float x;

public:
	Drive(float move, float rotate);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
