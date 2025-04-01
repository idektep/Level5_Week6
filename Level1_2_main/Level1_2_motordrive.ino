//-------------------------------------------------Declare variable-------------------------------------------------------//
#define MR_IN1 12 //backright motor
#define MR_IN2 13 //backright motor
#define MR_IN3 32 //frontright motor
#define MR_IN4 33 //frontright motor

#define ML_IN1 27 //frontleft motor
#define ML_IN2 14 //frontleft motor
#define ML_IN3 25 //backleft motor
#define ML_IN4 26 //backleft motor

#define BR_ENA 15  //Pin speed backright motor
#define FR_ENB 2   //Pin speed frontright motor
#define BL_ENB 4   //Pin speed backleft motor
#define FL_ENA 19  //Pin speed frontleft motor

#define FACTOR_MOTOR1 1
#define FACTOR_MOTOR2 1
#define FACTOR_MOTOR3 1
#define FACTOR_MOTOR4 1

uint8_t SpeedM1;
uint8_t SpeedM2;
uint8_t SpeedM3;
uint8_t SpeedM4;
/*-----------------------------------------------*/
void MotorDriveSetup()
{
  pinMode(MR_IN1, OUTPUT);
  pinMode(MR_IN2, OUTPUT);
  pinMode(MR_IN3, OUTPUT);
  pinMode(MR_IN4, OUTPUT);
  pinMode(ML_IN1, OUTPUT);
  pinMode(ML_IN2, OUTPUT);
  pinMode(ML_IN3, OUTPUT);
  pinMode(ML_IN4, OUTPUT);

  pinMode(BR_ENA, OUTPUT);
  pinMode(FR_ENB, OUTPUT);
  pinMode(BL_ENB, OUTPUT);
  pinMode(FL_ENA, OUTPUT);
  Stop();
}
/*-----------------------------------------------*/
void Forward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*///Motor 1
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, HIGH);  //backright motor
  digitalWrite(MR_IN2, LOW);   //backright motor
  digitalWrite(MR_IN3, HIGH);  //frontright motor
  digitalWrite(MR_IN4, LOW);   //frontright motor
  digitalWrite(ML_IN1, HIGH);  //frontleft motor
  digitalWrite(ML_IN2, LOW);   //frontleft motor
  digitalWrite(ML_IN3, HIGH);  //backleft motor
  digitalWrite(ML_IN4, LOW);   //backleft motor
  /*-----------------------------------------------*/
}

void Backward(uint8_t Speed)
{
  CalSpeedMotor(Speed); 
/*-----------------------------------------------*/
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, HIGH);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, HIGH);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, HIGH);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, HIGH);
}
/*-----------------------------------------------*/
void RotateRight(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, HIGH);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, HIGH);
  digitalWrite(ML_IN1, HIGH);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, HIGH);
  digitalWrite(ML_IN4, LOW);
}
/*-----------------------------------------------*/
void RotateLeft(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, HIGH);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, HIGH);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, HIGH);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, HIGH);
}
/*-----------------------------------------------*/
void SlideLeft(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, HIGH);
  digitalWrite(MR_IN3, HIGH);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, HIGH);
  digitalWrite(ML_IN3, HIGH);
  digitalWrite(ML_IN4, LOW);
}
/*-----------------------------------------------*/
void SlideRight(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, HIGH);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, HIGH);
  digitalWrite(ML_IN1, HIGH);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, HIGH);
}
/*-----------------------------------------------*/
void SlideLeftForward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, HIGH);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, HIGH);
  digitalWrite(ML_IN4, LOW);
}
/*-----------------------------------------------*/
void SlideRightForward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, HIGH);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, HIGH);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, LOW);
}
/*-----------------------------------------------*/
void SlideLeftBackward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, HIGH);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, HIGH);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, LOW);
}
/*-----------------------------------------------*/
void SlideRightBackward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(BR_ENA, SpeedM1);
  analogWrite(FR_ENB, SpeedM2);
  analogWrite(BL_ENB, SpeedM3);
  analogWrite(FL_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, HIGH);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, HIGH);
}
/*-----------------------------------------------*/
void Stop() 
{
/*-----------------------------------------------*/
  digitalWrite(MR_IN1, LOW);  //backright motor
  digitalWrite(MR_IN2, LOW);  //backright motor
  digitalWrite(MR_IN3, LOW);  //frontright motor
  digitalWrite(MR_IN4, LOW);  //frontright motor
  digitalWrite(ML_IN1, LOW);  //frontleft motor
  digitalWrite(ML_IN2, LOW);  //frontleft motor
  digitalWrite(ML_IN3, LOW);  //backleft motor
  digitalWrite(ML_IN4, LOW);  //backleft motor
}
/*-----------------------------------------------*/
void CalSpeedMotor(uint8_t Speed)
{
  SpeedM1 = Speed * FACTOR_MOTOR1;
  SpeedM2 = Speed * FACTOR_MOTOR2;
  SpeedM3 = Speed * FACTOR_MOTOR3;
  SpeedM4 = Speed * FACTOR_MOTOR4;
  
  if(SpeedM1 > 255)
  {
    SpeedM1 = 255;
  }

  if(SpeedM2 > 255)
  {
    SpeedM2 = 255;
  }

  if(SpeedM3 > 255)
  {
    SpeedM3 = 255;
  }

  if(SpeedM4 > 255)
  {
    SpeedM4 = 255;
  }
}
