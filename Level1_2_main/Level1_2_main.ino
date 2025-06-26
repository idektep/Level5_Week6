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
      break;

    case 3:  //Test LED

      break;

    case 4:  //Test Buzzer

      break;

    case 5:

      break;
    
    case 6:

      break;
      
    case 7:
    
      break;

    case 8://Stop
      Stop();
      DisplayOff();
      BuzzerOff();
      FrontLedOff();
      break;

    case 9://Reset
      ESP.restart();
      break; 
  }
}

void ForwardToWall(uint32_t Speed, uint32_t Distance)
{
    
}
