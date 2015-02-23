#include <Commands/CommandGroups/Autonomous.h>
#include <Commands/CommandGroups/AutoToteGrab.h>
#include <Commands/CommandGroups/AutoToteLift.h>
#include "Commands/Elevator/Lift.h"
#include "Commands/Elevator/Lower.h"
#include "Commands/Grabber/OpenArms.h"
#include "Commands/Grabber/CloseArms.h"
#include "Commands/Chassis/JoystickDrive.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Robot: public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *autoChooser;

	void RobotInit() {
		CommandBase::init();
		lw = LiveWindow::GetInstance();

		SmartDashboard::PutData(Scheduler::GetInstance());
		autoChooser = new SendableChooser();
		autoChooser->AddDefault("Grab TOTE and go back", new AutoToteGrab());
		autoChooser->AddObject("Lift TOTE and go back", new AutoToteLift());
		autoChooser->AddObject("Lift BIN and go back", new AutoToteLift());

		SmartDashboard::PutData("Autonomous Chooser", autoChooser);
		SmartDashboard::PutData("Lift", new Lift());
		SmartDashboard::PutData("Lower", new Lower());
		SmartDashboard::PutData("OpenArms", new OpenArms());
		SmartDashboard::PutData("Close", new CloseArms());
	}

	void DisabledPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit() {
		autonomousCommand = (Command*) autoChooser->GetSelected();
		if (autonomousCommand != NULL) {
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit() {
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
