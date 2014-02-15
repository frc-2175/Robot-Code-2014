// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Launcher.h"
#include "../Robotmap.h"
Launcher::Launcher() : Subsystem("Launcher") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	latchSwitch = RobotMap::launcherLatchSwitch;
	winchUpSwitch = RobotMap::launcherWinchUpSwitch;
	winchMotor = RobotMap::launcherWinchMotor;
	ballSensor = RobotMap::launcherBallSensor;
	latch = RobotMap::launcherLatch;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	
	latch->Set(false); // Just to be safe
}
    
void Launcher::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
bool Launcher::IsShooterArmDown() {
	
	return !((bool)(latchSwitch->Get()));
	
}
bool Launcher::IsWinchUp() {
	return !((bool)(winchUpSwitch->Get()));
}
bool Launcher::IsBall() {
	if (ballSensor->GetAverageValue() > 100) { /* Whatever threshold indicates a ball */
		return true;
	} else {
		return false;
	}
}
void Launcher::RunWinchAtSpeed(float speed) {
	winchMotor->Set(speed);
}
void Launcher::SetLatch(bool release) {
	latch->Set(release);
}
