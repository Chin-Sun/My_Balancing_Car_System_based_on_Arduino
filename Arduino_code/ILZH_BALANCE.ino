#include "PID_v1.h"
#include "MsTimer2.h"
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "EEPROM.h"
#include "Define.h"
#include "Interrupt.h"
#include "E2PRom.h"
#include "SerialControl.h"
#include "MotorDriver.h"

void setup()
{
  delay(50);  
  pinMode(AN1, OUTPUT);
  pinMode(AN2, OUTPUT);
  pinMode(BN1, OUTPUT);
  pinMode(BN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(STBY, HIGH);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  GetParamers();
  speedcount = sc;
  Offset_Setpoint = osp;
  Serial.begin(115200);
  Wire.begin();
  delay(100);
  mpu.initialize();
  delay(2); 
  devStatus = mpu.dmpInitialize();
  if (devStatus == 0)
  {     
    mpu.setDMPEnabled(true);   
    attachInterrupt(0, dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus(); 
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  }
  Setpoint = Offset_Setpoint;
  myPID.SetTunings(kp, ki, kd);
  myPID.SetOutputLimits(-255 + dl, 255 - dl);
  myPID.SetSampleTime(5);
  myPID.SetMode(AUTOMATIC);
  sPID.SetTunings(sp, si, sd);
  sPID.SetOutputLimits(-10, 70);
  sPID.SetSampleTime(200);
  sPID.SetMode(AUTOMATIC);
  attachInterrupt(1, speed, RISING);
  MsTimer2::set(500, flash);       
  MsTimer2::start();    
}

void loop()
{
  if (!dmpReady)
    return; 
  if (!mpuInterrupt && fifoCount < packetSize)
    return;
  mpuInterrupt = false;
  mpuIntStatus = mpu.getIntStatus(); 
  fifoCount = mpu.getFIFOCount(); 
  if ((mpuIntStatus & 0x10) || fifoCount == 1024)
    mpu.resetFIFO();  
  else if (mpuIntStatus & 0x02)
  {    
    while (fifoCount < packetSize)
      fifoCount = mpu.getFIFOCount();   
    mpu.getFIFOBytes(fifoBuffer, packetSize);    
    fifoCount -= packetSize;
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    angle = -ypr[2] * 180 / M_PI;
  }
  Inputs = speedcount;
  sPID.Compute();
  Setpoint = Offset_Setpoint + Outputs;
  Input = angle;
   Serial.println(Input);
  myPID.Compute();
  if (angle > 60 || angle < -60)
    Output = 0;
  motor(Output);
  SerialControl();
  sPID.SetTunings(sp, si, sd);
  myPID.SetTunings(kp, ki, kd);
  SendData();
}

