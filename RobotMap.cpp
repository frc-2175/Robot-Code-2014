// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::drivetrainLeft = NULL;
SpeedController* RobotMap::drivetrainRight = NULL;
RobotDrive* RobotMap::drivetrainRobotDrive = NULL;
Encoder* RobotMap::drivetrainLeftEncoder = NULL;
Encoder* RobotMap::drivetrainRightEncoder = NULL;
SpeedController* RobotMap::drivetrainMagicPIDOutput = NULL;
Gyro* RobotMap::drivetrainGyro = NULL;
DoubleSolenoid* RobotMap::drivetrainShifters = NULL;
DoubleSolenoid* RobotMap::armArmSolenoid = NULL;
SpeedController* RobotMap::armRollerBar = NULL;
DigitalInput* RobotMap::armArmOutSwitch1 = NULL;
DigitalInput* RobotMap::armArmOutSwitch2 = NULL;
DigitalInput* RobotMap::launcherLatchSwitch = NULL;
DigitalInput* RobotMap::launcherWinchUpSwitch = NULL;
SpeedController* RobotMap::launcherWinchMotor = NULL;
Encoder* RobotMap::launcherWinchEncoder = NULL;
AnalogChannel* RobotMap::launcherBallSensor = NULL;
Solenoid* RobotMap::launcherLatch = NULL;
DoubleSolenoid* RobotMap::launcherTension = NULL;
Solenoid* RobotMap::launcherCatcher = NULL;
Compressor* RobotMap::compresserSubsystemCompressor = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
PIDController* RobotMap::drivetrainEncoderPID = NULL;
PIDController* RobotMap::drivetrainGyroPID = NULL;
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	drivetrainLeft = new Talon(1, 1);
	lw->AddActuator("Drivetrain", "Left", (Talon*) drivetrainLeft);
	
	drivetrainRight = new Talon(1, 2);
	lw->AddActuator("Drivetrain", "Right", (Talon*) drivetrainRight);
	
	drivetrainRobotDrive = new RobotDrive(drivetrainLeft, drivetrainRight);
	
	drivetrainRobotDrive->SetSafetyEnabled(true);
        drivetrainRobotDrive->SetExpiration(0.1);
        drivetrainRobotDrive->SetSensitivity(0.5);
        drivetrainRobotDrive->SetMaxOutput(1.0);
        
	drivetrainLeftEncoder = new Encoder(1, 1, 1, 2, false, Encoder::k4X);
	lw->AddSensor("Drivetrain", "Left Encoder", drivetrainLeftEncoder);
	drivetrainLeftEncoder->SetDistancePerPulse(0.001);
        drivetrainLeftEncoder->SetPIDSourceParameter(Encoder::kDistance);
        drivetrainLeftEncoder->Start();
	drivetrainRightEncoder = new Encoder(1, 3, 1, 4, false, Encoder::k4X);
	lw->AddSensor("Drivetrain", "Right Encoder", drivetrainRightEncoder);
	drivetrainRightEncoder->SetDistancePerPulse(0.001);
        drivetrainRightEncoder->SetPIDSourceParameter(Encoder::kDistance);
        drivetrainRightEncoder->Start();
	drivetrainMagicPIDOutput = new Talon(1, 10);
	lw->AddActuator("Drivetrain", "Magic PID Output", (Talon*) drivetrainMagicPIDOutput);
	
	drivetrainGyro = new Gyro(1, 1);
	lw->AddSensor("Drivetrain", "Gyro", drivetrainGyro);
	drivetrainGyro->SetSensitivity(0.007);
	drivetrainShifters = new DoubleSolenoid(1, 1, 2);      
	
	
	armArmSolenoid = new DoubleSolenoid(1, 3, 4);      
	
	
	armRollerBar = new Talon(1, 4);
	lw->AddActuator("Arm", "Roller Bar", (Talon*) armRollerBar);
	
	armArmOutSwitch1 = new DigitalInput(1, 10);
	lw->AddSensor("Arm", "Arm Out Switch 1", armArmOutSwitch1);
	
	armArmOutSwitch2 = new DigitalInput(1, 11);
	lw->AddSensor("Arm", "Arm Out Switch 2", armArmOutSwitch2);
	
	launcherLatchSwitch = new DigitalInput(1, 5);
	lw->AddSensor("Launcher", "Latch Switch", launcherLatchSwitch);
	
	launcherWinchUpSwitch = new DigitalInput(1, 8);
	lw->AddSensor("Launcher", "Winch Up Switch", launcherWinchUpSwitch);
	
	launcherWinchMotor = new Talon(1, 3);
	lw->AddActuator("Launcher", "Winch Motor", (Talon*) launcherWinchMotor);
	
	launcherWinchEncoder = new Encoder(1, 13, 1, 14, false, Encoder::k4X);
	lw->AddSensor("Launcher", "Winch Encoder", launcherWinchEncoder);
	launcherWinchEncoder->SetDistancePerPulse(1.0);
        launcherWinchEncoder->SetPIDSourceParameter(Encoder::kDistance);
        launcherWinchEncoder->Start();
	launcherBallSensor = new AnalogChannel(1, 2);
	lw->AddSensor("Launcher", "Ball Sensor", launcherBallSensor);
	
	launcherLatch = new Solenoid(1, 5);
	lw->AddActuator("Launcher", "Latch", launcherLatch);
	
	launcherTension = new DoubleSolenoid(1, 6, 7);      
	
	
	launcherCatcher = new Solenoid(1, 8);
	lw->AddActuator("Launcher", "Catcher", launcherCatcher);
	
	compresserSubsystemCompressor = new Compressor(1, 7, 1, 3);
	
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	
	drivetrainEncoderPID = new PIDController(1.0, 0.1, 0.0,/* F: 0.0, */ drivetrainLeftEncoder, drivetrainMagicPIDOutput, 0.02);
	// The output of this controller is irrelevant, since we will get the value manually and use it ourselves.
	lw->AddActuator("Drivetrain", "Encoder PID", drivetrainEncoderPID);
	drivetrainEncoderPID->SetContinuous(false); drivetrainEncoderPID->SetAbsoluteTolerance(0.2); 
	drivetrainEncoderPID->SetOutputRange(-0.8, 0.8);
	
	drivetrainGyroPID = new PIDController(0.05, 0.0001, 0.0,/* F: 0.0, */ drivetrainGyro, drivetrainMagicPIDOutput, 0.02);
	// The output of this controller is irrelevant, since we will get the value manually and use it ourselves.
	lw->AddActuator("Drivetrain", "Gyro PID", drivetrainGyroPID);
	drivetrainGyroPID->SetContinuous(false); drivetrainGyroPID->SetAbsoluteTolerance(0.2); 
	drivetrainGyroPID->SetOutputRange(-0.8, 0.8);
}
