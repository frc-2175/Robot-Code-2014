// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/Auton0DoNothing.h"
#include "Subsystems/Arm.h"
#include "Subsystems/CompresserSubsystem.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Launcher.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/Auton1MobilityBonus.h"
#include "Commands/Auton2BlindShot.h"
#include "Commands/Auton3DoubleBlindShot.h"
#include "Commands/Auton4LowGoal.h"
#include "OI.h"
class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	SendableChooser *autoChooser;
	static OI *oi;
	LiveWindow *lw;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static Drivetrain* drivetrain;
	static Arm* arm;
	static Launcher* launcher;
	static CompresserSubsystem* compresserSubsystem;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
