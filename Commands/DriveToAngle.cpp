// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.


#include "DriveToAngle.h"

DriveToAngle::DriveToAngle(float angle) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	inputAngle = angle;
}

// Called just before this Command runs the first time
void DriveToAngle::Initialize() {
	Robot::drivetrain->gyro->Reset();
	Robot::drivetrain->gyroPID->Reset();
	Robot::drivetrain->gyroPID->SetSetpoint(inputAngle);
	
	Robot::drivetrain->gyroPID->SetPID(SmartDashboard::GetNumber("P"),SmartDashboard::GetNumber("I")/1000,0);
	
	Robot::drivetrain->gyroPID->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveToAngle::Execute() {
	float PIDOut = Robot::drivetrain->gyroPID->Get();
	SmartDashboard::PutNumber("Gyro Heading", Robot::drivetrain->gyro->GetAngle());
	SmartDashboard::PutNumber("PID Output", PIDOut);
	Robot::drivetrain->ArcadeDriveWithParameters(0,PIDOut);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToAngle::IsFinished() {
	return Robot::drivetrain->gyroPID->OnTarget();
}

// Called once after isFinished returns true
void DriveToAngle::End() {
	Robot::drivetrain->gyroPID->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToAngle::Interrupted() {

}
