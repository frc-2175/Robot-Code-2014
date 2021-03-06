// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "DriveForDistance.h"
DriveForDistance::DriveForDistance(float feet, bool backwards) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	inputFeet = feet;
	inputBackwards = backwards;
}
// Called just before this Command runs the first time
void DriveForDistance::Initialize() {
	printf("Driving for distance...\n");
	
	float setpoint = inputFeet;
	if (inputBackwards) setpoint *= -1;
	Robot::drivetrain->leftEncoder->Reset();
	Robot::drivetrain->encoderPID->Reset();
	Robot::drivetrain->encoderPID->SetSetpoint(setpoint);
	Robot::drivetrain->encoderPID->Enable();
}
// Called repeatedly when this Command is scheduled to run
void DriveForDistance::Execute() {
	float PIDOut = Robot::drivetrain->encoderPID->Get();
	Robot::drivetrain->ArcadeDriveWithParameters(PIDOut,0);
}
// Make this return true when this Command no longer needs to run execute()
bool DriveForDistance::IsFinished() {
	return Robot::drivetrain->encoderPID->OnTarget();
}
// Called once after isFinished returns true
void DriveForDistance::End() {
	Robot::drivetrain->encoderPID->Disable();
	printf("Done driving for distance.\n\n");
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForDistance::Interrupted() {
	End();
}
