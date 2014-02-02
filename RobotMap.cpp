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
SpeedController* RobotMap::drivetrainLeft = NULL;
SpeedController* RobotMap::drivetrainRight = NULL;
RobotDrive* RobotMap::drivetrainRobotDrive = NULL;
Encoder* RobotMap::drivetrainLeftEncoder = NULL;
Encoder* RobotMap::drivetrainRightEncoder = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	drivetrainLeft = new Talon(1, 1);
	lw->AddActuator("Drivetrain", "Left", (Talon*) drivetrainLeft);
	
	drivetrainRight = new Talon(1, 2);
	lw->AddActuator("Drivetrain", "Right", (Talon*) drivetrainRight);
	
	drivetrainRobotDrive = new RobotDrive(drivetrainLeft, drivetrainRight);
	
	drivetrainRobotDrive->SetSafetyEnabled(true);
        drivetrainRobotDrive->SetExpiration(0.1);
        drivetrainRobotDrive->SetSensitivity(0.5);
        drivetrainRobotDrive->SetMaxOutput(1.0);
        
	drivetrainLeftEncoder = new Encoder(1, 1, 1, 2, false, Encoder::k4X);
	lw->AddSensor("Drivetrain", "Left Encoder", drivetrainLeftEncoder);
	drivetrainLeftEncoder->SetDistancePerPulse(1.0);
        drivetrainLeftEncoder->SetPIDSourceParameter(Encoder::kDistance);
        drivetrainLeftEncoder->Start();
	drivetrainRightEncoder = new Encoder(1, 3, 1, 4, false, Encoder::k4X);
	lw->AddSensor("Drivetrain", "Right Encoder", drivetrainRightEncoder);
	drivetrainRightEncoder->SetDistancePerPulse(1.0);
        drivetrainRightEncoder->SetPIDSourceParameter(Encoder::kDistance);
        drivetrainRightEncoder->Start();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
