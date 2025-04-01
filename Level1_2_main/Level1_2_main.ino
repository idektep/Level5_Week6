//Node MCU ESP32 Week 6-7
#define LOW_SPEED 125
#define MAX_SPEED 255

uint32_t Data = 0;
long MeasureDistance = 0;
uint8_t LdrMapped = 0;
float Temp = 0;
float Humid = 0;
/*-----------------------------------------------*/
void setup() {
  Serial.begin(9600);
  SensorAndLedSetup();
  MotorDriveSetup();
  Serial.println("Level1-2");
  Welcome();

}
/*-----------------------------------------------*/
void loop() {
  if (Serial.available() > 0) {
    int newData = Serial.parseInt();
    if (newData != 0) {
      Data = newData;
    }
  }
    switch (Data) {
    case 1:  //Test Sensor
      Dht();
      delay(1000);
      Ldr();
      delay(1000);
      Ultrasonic();
      delay(1000);
      break;
    case 2:  //Test motor
      Forward(MAX_SPEED);
      LightStop();// ใช้มือกำ/ LDR เพื่อให้รถหยุด
      break;

    case 3:  //Test LED
      break;

    case 4:  //Test Buzzer
      break;

    case 5:
      ForwardToWall(MAX_SPEED,20);
      DisplayLcd(0, "Detect obstacles", 0, "");
      Backward(LOW_SPEED);
      delay(500);
      RotateRight(LOW_SPEED);
      delay(500);
      break;
    
    case 6:
      break;
      
    case 7:
      break;

    case 8://Stop
      DisplayOff();
      BuzzerOff();
      Stop();
      FrontLedOff();
      break;

    case 9://Reset
      ESP.restart();
          break; 
  }
}
void LightStop()
{
  Ldr();
  if(LdrMapped < 15)
  {
    Data = 8;
  }
}
void ForwardToWall(uint32_t Speed, uint32_t Distance)
{
  int i = 1;
  do
  {
    Ultrasonic();
    if((MeasureDistance < Distance) && (MeasureDistance > 0))
    {
      Stop();
      delay(10);
      i--;
    }
    else
    {
      DisplayLcd(4, "Auto Car", 0, "");
      Forward(Speed);
      LightStop();
    }
  }while(i);
}