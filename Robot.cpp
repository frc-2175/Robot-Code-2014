// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Drivetrain* Robot::drivetrain = 0;
Arm* Robot::arm = 0;
Launcher* Robot::launcher = 0;
CompresserSubsystem* Robot::compresserSubsystem = 0;
OI* Robot::oi = 0;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
void Robot::RobotInit() {
	printf("Initializing robot\n");
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	drivetrain = new Drivetrain();
	arm = new Arm();
	launcher = new Launcher();
	compresserSubsystem = new CompresserSubsystem();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new Auton0DoNothing();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	
	autoChooser = new SendableChooser();
	autoChooser->AddDefault("0 - No Action", new Auton0DoNothing());
	autoChooser->AddObject("1 - Mobility Bonus", new Auton1MobilityBonus());
	autoChooser->AddObject("2 - Blind Shot", new Auton2BlindShot());
	autoChooser->AddObject("3 - Double Blind Shot", new Auton3DoubleBlindShot());
	autoChooser->AddObject("4 - Low Goal", new Auton4LowGoal());
	autoChooser->AddObject("5 - Hot Goal", new Auton5HotGoal());
	autoChooser->AddObject("6 - Double Hot Goal", new Auton6DoubleHotGoal());
//	autoChooser->AddObject("4 - Hot Goal, Mobility Bonus", /* tbd */);
//	autoChooser->AddObject("5 - High Goal, Hot Goal, Mobility Bonus", /* tbd */);
	SmartDashboard::PutData("Autonomous Routine",autoChooser);
}
	
void Robot::AutonomousInit() {
	printf("Initializing autonomous\n");
	autonomousCommand = (Command *)autoChooser->GetSelected();
	autonomousCommand->Start();
}
	
void Robot::AutonomousPeriodic() {
	printf("Running autonomous\n");
	Scheduler::GetInstance()->Run();
	if (oi->getGamepad()->GetRawButton(6))
		printf("-----------------------------------\n");
}
	
void Robot::TeleopInit() {
	printf("Initializing teleop\n");
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
}
	
void Robot::TeleopPeriodic() {
	printf("Running teleop\n");
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
	if (oi->getGamepad()->GetRawButton(6))
		printf("-----------------------------------\n");
//	SmartDashboard::PutBoolean("Shooter Down", Robot::launcher->IsShooterArmDown());
//	SmartDashboard::PutBoolean("Shooter Up", Robot::launcher->IsWinchUp());
//	SmartDashboard::PutBoolean("Arm Out Switch 1", Robot::arm->armOutSwitch1->Get());
//	SmartDashboard::PutBoolean("Arm Out Switch 2", Robot::arm->armOutSwitch2->Get());
	
//	SmartDashboard::PutNumber("Shooter Down", (double)Robot::launcher->IsShooterArmDown());
//	SmartDashboard::PutNumber("Shooter Up", (double)Robot::launcher->IsWinchUp());
//	SmartDashboard::PutNumber("Arm Out Switch 1", (double)Robot::arm->armOutSwitch1->Get());
//	SmartDashboard::PutNumber("Arm Out Switch 2", (double)Robot::arm->armOutSwitch2->Get());
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
