// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef OI_H
#define OI_H
#include "WPILib.h"
class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Joystick* gamepad;
	JoystickButton* releaseLatchOverride;
	JoystickButton* shootAndReload;
	JoystickButton* intakeWheelsBackwards;
	JoystickButton* intakeWheelsForward;
	JoystickButton* armOut;
	JoystickButton* armIn;
	Joystick* joystickRight;
	JoystickButton* commandShiftButton;
	Joystick* joystickLeft;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	JoystickButton* windLauncherButton;
	JoystickButton* unwindWinchButton;
	
	const double deadbandAmount;
public:
	OI();
	double deadband(double input);
	bool shouldOverrideLatch();
 
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	Joystick* getJoystickLeft();
	Joystick* getJoystickRight();
	Joystick* getGamepad();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	
	double getForwardSpeed();
	double getTurningSpeed();
};
#endif
