#define MR_IN1 12 //motor1
#define MR_IN2 13 //motor1
#define MR_IN3 32 //motor2
#define MR_IN4 33 //motor2

#define ML_IN1 27 //motor4
#define ML_IN2 14 //motor4
#define ML_IN3 25 //motor3
#define ML_IN4 26 //motor3

#define R_ENA 15  //Adjust speed  //motor1
#define R_ENB 2   //Adjust speed //motor2
#define L_ENA 19  //Adjust speed //motor4
#define L_ENB 4   //Adjust speed //motor3

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
  pinMode(L_ENA, OUTPUT);
  pinMode(L_ENB, OUTPUT);
  pinMode(R_ENA, OUTPUT);
  pinMode(R_ENB, OUTPUT);
  Stop();
}
/*-----------------------------------------------*/
void Forward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*///Motor 1
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, HIGH); //motor1
  digitalWrite(MR_IN2, LOW);  //motor1
  digitalWrite(MR_IN3, HIGH); //motor2
  digitalWrite(MR_IN4, LOW);  //motor2
  digitalWrite(ML_IN1, HIGH); //motor4
  digitalWrite(ML_IN2, LOW);  //motor4
  digitalWrite(ML_IN3, HIGH); //motor3
  digitalWrite(ML_IN4, LOW);  //motor3
  /*-----------------------------------------------*/
}

void Backward(uint8_t Speed)
{
  CalSpeedMotor(Speed); 
/*-----------------------------------------------*/
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);  //motor1
  digitalWrite(MR_IN2, HIGH); //motor1
  digitalWrite(MR_IN3, LOW);  //motor2
  digitalWrite(MR_IN4, HIGH); //motor2
  digitalWrite(ML_IN1, LOW);  //motor4
  digitalWrite(ML_IN2, HIGH); //motor4
  digitalWrite(ML_IN3, LOW);  //motor3
  digitalWrite(ML_IN4, HIGH); //motor3
}
/*-----------------------------------------------*/
void RotateRight(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);  //motor1
  digitalWrite(MR_IN2, HIGH); //motor1
  digitalWrite(MR_IN3, LOW);  //motor2
  digitalWrite(MR_IN4, HIGH); //motor2
  digitalWrite(ML_IN1, HIGH); //motor4
  digitalWrite(ML_IN2, LOW);  //motor4
  digitalWrite(ML_IN3, HIGH); //motor3
  digitalWrite(ML_IN4, LOW);  //motor3
}
/*-----------------------------------------------*/
void RotateLeft(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, HIGH); //motor1
  digitalWrite(MR_IN2, LOW);  //motor1
  digitalWrite(MR_IN3, HIGH); //motor2
  digitalWrite(MR_IN4, LOW);  //motor2
  digitalWrite(ML_IN1, LOW);  //motor4
  digitalWrite(ML_IN2, HIGH); //motor4
  digitalWrite(ML_IN3, LOW);  //motor3
  digitalWrite(ML_IN4, HIGH); //motor3
}
/*-----------------------------------------------*/
void SlideLeft(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);  //motor1
  digitalWrite(MR_IN2, HIGH); //motor1
  digitalWrite(MR_IN3, HIGH); //motor2
  digitalWrite(MR_IN4, LOW);  //motor2
  digitalWrite(ML_IN1, LOW);  //motor4
  digitalWrite(ML_IN2, HIGH); //motor4
  digitalWrite(ML_IN3, HIGH); //motor3
  digitalWrite(ML_IN4, LOW);  //motor3
}
/*-----------------------------------------------*/
void SlideRight(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, HIGH); //motor1
  digitalWrite(MR_IN2, LOW);  //motor1
  digitalWrite(MR_IN3, LOW);  //motor2
  digitalWrite(MR_IN4, HIGH); //motor2
  digitalWrite(ML_IN1, HIGH); //motor4
  digitalWrite(ML_IN2, LOW);  //motor4
  digitalWrite(ML_IN3, LOW);  //motor3
  digitalWrite(ML_IN4, HIGH); //motor3
}
/*-----------------------------------------------*/
void SlideLeftForward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);  //motor1
  digitalWrite(MR_IN2, LOW);  //motor1
  digitalWrite(MR_IN3, HIGH); //motor2
  digitalWrite(MR_IN4, LOW);  //motor2
  digitalWrite(ML_IN1, LOW);  //motor4
  digitalWrite(ML_IN2, LOW);  //motor4
  digitalWrite(ML_IN3, HIGH); //motor3
  digitalWrite(ML_IN4, LOW);  //motor3
}
/*-----------------------------------------------*/
void SlideRightForward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, HIGH);  //motor1
  digitalWrite(MR_IN2, LOW);   //motor1
  digitalWrite(MR_IN3, LOW);   //motor2
  digitalWrite(MR_IN4, LOW);   //motor2
  digitalWrite(ML_IN1, HIGH);  //motor4
  digitalWrite(ML_IN2, LOW);   //motor4
  digitalWrite(ML_IN3, LOW);   //motor3
  digitalWrite(ML_IN4, LOW);   //motor3
}
/*-----------------------------------------------*/
void SlideLeftBackward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);  //motor1
  digitalWrite(MR_IN2, HIGH); //motor1
  digitalWrite(MR_IN3, LOW);  //motor2
  digitalWrite(MR_IN4, LOW);  //motor2
  digitalWrite(ML_IN1, LOW);  //motor4
  digitalWrite(ML_IN2, HIGH); //motor4
  digitalWrite(ML_IN3, LOW);  //motor3
  digitalWrite(ML_IN4, LOW);  //motor3
}
/*-----------------------------------------------*/
void SlideRightBackward(uint8_t Speed)
{
  CalSpeedMotor(Speed);
/*-----------------------------------------------*/
  analogWrite(R_ENA, SpeedM1);
  analogWrite(R_ENB, SpeedM2);
  analogWrite(L_ENB, SpeedM3);
  analogWrite(L_ENA, SpeedM4);

  digitalWrite(MR_IN1, LOW);  //motor1
  digitalWrite(MR_IN2, LOW);  //motor1
  digitalWrite(MR_IN3, LOW);  //motor2
  digitalWrite(MR_IN4, HIGH); //motor2
  digitalWrite(ML_IN1, LOW);  //motor4
  digitalWrite(ML_IN2, LOW);  //motor4
  digitalWrite(ML_IN3, LOW);  //motor3
  digitalWrite(ML_IN4, HIGH); //motor3
}
/*-----------------------------------------------*/
void Stop() 
{
/*-----------------------------------------------*/
  digitalWrite(MR_IN1, LOW); //motor1
  digitalWrite(MR_IN2, LOW); //motor1
  digitalWrite(MR_IN3, LOW); //motor2
  digitalWrite(MR_IN4, LOW); //motor2
  digitalWrite(ML_IN1, LOW); //motor4
  digitalWrite(ML_IN2, LOW); //motor4
  digitalWrite(ML_IN3, LOW); //motor3
  digitalWrite(ML_IN4, LOW); //motor3
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
