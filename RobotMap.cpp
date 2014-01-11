// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::drivetrainLeftController = NULL;
SpeedController* RobotMap::drivetrainRightController = NULL;
RobotDrive* RobotMap::drivetrainRobotDrive2 = NULL;
Solenoid* RobotMap::launcherRelease = NULL;
Solenoid* RobotMap::shiftersShifters = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	drivetrainLeftController = new Talon(1, 1);
	lw->AddActuator("Drivetrain", "Left Controller", (Talon*) drivetrainLeftController);
	
	drivetrainRightController = new Talon(1, 2);
	lw->AddActuator("Drivetrain", "Right Controller", (Talon*) drivetrainRightController);
	
	drivetrainRobotDrive2 = new RobotDrive(drivetrainLeftController, drivetrainRightController);
	
	drivetrainRobotDrive2->SetSafetyEnabled(true);
        drivetrainRobotDrive2->SetExpiration(0.1);
        drivetrainRobotDrive2->SetSensitivity(0.5);
        drivetrainRobotDrive2->SetMaxOutput(1.0);
        drivetrainRobotDrive2->SetInvertedMotor(RobotDrive::kRearRightMotor, true);        
	launcherRelease = new Solenoid(1, 1);
	lw->AddActuator("Launcher", "Release", launcherRelease);
	
	shiftersShifters = new Solenoid(1, 2);
	lw->AddActuator("Shifters", "Shifters", shiftersShifters);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
