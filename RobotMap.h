// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static SpeedController* drivetrainLeft;
	static SpeedController* drivetrainRight;
	static RobotDrive* drivetrainRobotDrive;
	static Encoder* drivetrainLeftEncoder;
	static Encoder* drivetrainRightEncoder;
	static SpeedController* drivetrainMagicPIDOutput;
	static Gyro* drivetrainGyro;
	static DoubleSolenoid* drivetrainShifters;
	static DoubleSolenoid* armArmSolenoid;
	static SpeedController* armRollerBar;
	static DigitalInput* armArmOutSwitch1;
	static DigitalInput* armArmOutSwitch2;
	static DigitalInput* launcherLatchSwitch;
	static DigitalInput* launcherWinchUpSwitch;
	static SpeedController* launcherWinchMotor;
	static Encoder* launcherWinchEncoder;
	static AnalogChannel* launcherBallSensor;
	static Solenoid* launcherLatch;
	static DoubleSolenoid* launcherTension;
	static Solenoid* launcherCatcher;
	static Compressor* compresserSubsystemCompressor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static PIDController* drivetrainEncoderPID;
	static PIDController* drivetrainGyroPID;
	static void init();
};
#endif
