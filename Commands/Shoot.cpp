// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.



#include "Shoot.h"

#include "WinchLauncherDown.h"
#include "UnwindWinch.h"
#include "ReleaseLatch.h"
#include "MoveArmOut.h"
#include "Delay.h"

Shoot::Shoot() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	
	if (Robot::arm->IsArmOut()){
		if (!Robot::launcher->IsShooterArmDown()) {
			AddSequential(new WinchLauncherDown());
		}
		if (!Robot::launcher->IsWinchUp()) {
			AddSequential(new UnwindWinch());
		}
		//Actually shoot
		if (Robot::arm->IsArmOut()) AddSequential(new ReleaseLatch());
		AddSequential(new Delay(2));
		//Prepare for next shot
		if (Robot::arm->IsArmOut()) {
			AddSequential(new WinchLauncherDown());
			AddSequential(new UnwindWinch());
		} else {
			AddSequential(new MoveArmOut());
		}
		AddSequential(new WinchLauncherDown());
		AddSequential(new UnwindWinch());
	}
}
