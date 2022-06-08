MPU6050 mpu(0x68);
double Offset_Setpoint, osp;
signed int speedcount, sc;
unsigned char dl, ds, dt;
double kp, ki, kd;
double sp, si, sd;
double Setpoint, Input, Output;
double Setpoints, Inputs, Outputs;
PID myPID(&Input, &Output, &Setpoint, kp, ki, kd, DIRECT);
PID sPID(&Inputs, &Outputs, &Setpoints, sp, si, sd, DIRECT);
int AN1 = 7;   
int AN2 = 8;  
int BN1 = 4;   
int BN2 = 5;  
int PWMA = 9; 
int PWMB = 10; 
int STBY = 6;  
int MPB =  8;   
bool dmpReady = false;  
uint8_t mpuIntStatus;   
uint8_t devStatus;     
uint16_t packetSize;    
uint16_t fifoCount;     
uint8_t fifoBuffer[64];
Quaternion q;         
VectorFloat gravity;   
float ypr[3];           
float angle;  
char flag = 0;
char num = 0;
byte inByte;
boolean LED;
float fVol;
String oString = "", nString = "";
String strSS[2];
int iPos;
boolean readCompleted = false;
int iSendType = 0;