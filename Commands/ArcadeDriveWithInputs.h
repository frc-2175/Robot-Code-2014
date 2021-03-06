// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.


#ifndef ARCADEDRIVEWITHINPUTS_H
#define ARCADEDRIVEWITHINPUTS_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ArcadeDriveWithInputs: public Command {
public:
	ArcadeDriveWithInputs(float forward, float turning, double time = 0);
	/* Inputs can be passed in to control the driving.
	 * If time is left at the default (0) then the command runs indefinitely.
	 */
	
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	float forwardSpeed;
	float turningSpeed;
	double timeoutTime;
};

#endif
