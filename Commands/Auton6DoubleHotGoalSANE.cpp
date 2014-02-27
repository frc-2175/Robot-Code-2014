// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Auton6DoubleHotGoalSANE.h"
#include "Commands.h"
#include "Auton6PartialStartHot.h"
#include "Auton6PartialStartCold.h"
Auton6DoubleHotGoalSANE::Auton6DoubleHotGoalSANE() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void Auton6DoubleHotGoalSANE::Initialize() {
	step = 1;
	isDone = false;
	activeCommand = new MoveArmOut();
	activeCommand->Start();
}
// Called repeatedly when this Command is scheduled to run
void Auton6DoubleHotGoalSANE::Execute() {
	switch (step) {
	case 1:		activeCommand = new Delay(0.5); // Wait for the vision system
				activeCommand->Start();
				step = 2;
				break;
	case 2:		if (!activeCommand->IsRunning()) step = 3; // Are we done delaying?
				break;
	case 3:		if (SmartDashboard::GetBoolean("IS_RECT")) { // Is there a hot goal?
					// We are in front of the hot goal
					activeCommand = new Auton6PartialStartHot();
					activeCommand->Start();
				} else {
					// We chose the wrong goal :(
					activeCommand = new Auton6PartialStartCold();
					activeCommand->Start();
				}
				step = 4;
	case 4:		if (!activeCommand->IsRunning()) step = -1;
				break;
	case -1:	isDone = true;
				break;
	}
}
// Make this return true when this Command no longer needs to run execute()
bool Auton6DoubleHotGoalSANE::IsFinished() {
	return isDone;
}
// Called once after isFinished returns true
void Auton6DoubleHotGoalSANE::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auton6DoubleHotGoalSANE::Interrupted() {
}