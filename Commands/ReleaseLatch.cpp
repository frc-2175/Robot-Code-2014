// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "ReleaseLatch.h"
ReleaseLatch::ReleaseLatch() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::launcher);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SetTimeout(1.0);
}
// Called just before this Command runs the first time
void ReleaseLatch::Initialize() {
	printf("Releasing the latch...\n");
}
// Called repeatedly when this Command is scheduled to run
void ReleaseLatch::Execute() {
	if ((Robot::arm->IsArmOut() && Robot::launcher->IsShooterArmDown() && Robot::launcher->IsWinchUp() && true /* isBall */) || Robot::oi->shouldOverrideLatch()) {
		Robot::launcher->SetLatch(true);
	}
}
// Make this return true when this Command no longer needs to run execute()
bool ReleaseLatch::IsFinished() {
	return IsTimedOut();
}
// Called once after isFinished returns true
void ReleaseLatch::End() {
	Robot::launcher->SetLatch(false);
	printf("Done releasing the latch.\n\n");
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseLatch::Interrupted() {
	End();
}
