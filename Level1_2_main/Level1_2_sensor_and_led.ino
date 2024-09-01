#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <NewPing.h>

#define FRONT_RIGHT_LED_PIN 16 
#define FRONT_LEFT_LED_PIN 17 
#define ULTRASONIC_ECHO_PIN 35
#define ULTRASONIC_TRIG_PIN 5
#define MAX_DISTANCE 50 
#define BUZZER_PIN 18
#define DHT_PIN 23
#define DHT_TYPE DHT22
#define LDR_PIN 34
#define DELAY_BLINK 500

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHT_PIN, DHT_TYPE);
NewPing sonar(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN, MAX_DISTANCE);
/*-----------------------------------------------*/
void Welcome()
{
  DisplayLcd(4, "Level1_2", 0, "");
}
void SensorAndLedSetup()
{
  dht.begin();

  pinMode(FRONT_RIGHT_LED_PIN, OUTPUT);
  pinMode(FRONT_LEFT_LED_PIN, OUTPUT);

  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(LDR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  lcd.init();
  lcd.display();        
  lcd.backlight();      
  lcd.clear();          
}
/*-----------------------------------------------*/
void Ultrasonic()
{ 
  MeasureDistance = sonar.ping_cm();
  String DistanceText = String(MeasureDistance) + " Cm";
  DisplayLcd(5, "Distance", 5, DistanceText); // Display
  //Serial.println(DistanceText);
}
/*-----------------------------------------------*/
void Dht()
{
  Humid = dht.readHumidity();
  Temp = dht.readTemperature();
  String TempText = "Temp: " + String(Temp, 1) + " C";
  String HumidityText = "Humidity: " + String(Humid, 1) + " %";
  DisplayLcd(0, TempText, 0, HumidityText); // Display
  //Serial.println(TempText);
  //Serial.println(HumidityText);
}
/*-----------------------------------------------*/
void Ldr()
{
  uint16_t LdrInput = 0;
  LdrMapped = 0;
  LdrInput = analogRead(LDR_PIN);
  LdrMapped = map(LdrInput, 0, 4095, 100, 0);
  String LdrText = "Light : " + String(LdrMapped) + " %";
  DisplayLcd(0, LdrText, 0,""); // Display
  //Serial.println(LdrText);
}
/*-----------------------------------------------*/
void BuzzerOn()
{
  digitalWrite(BUZZER_PIN, 1);
  //tone(BUZZER_PIN, 300);
}
/*-----------------------------------------------*/
void BuzzerOff()
{
  digitalWrite(BUZZER_PIN, 0);
}
/*-----------------------------------------------*/
void BuzzerBlink()
{
  BuzzerOn();
  delay(DELAY_BLINK);
  BuzzerOff();
  delay(DELAY_BLINK);
}
/*-----------------------------------------------*/
void FrontRightLedOn()
{
  digitalWrite(FRONT_RIGHT_LED_PIN, HIGH);
}
/*-----------------------------------------------*/
void FrontRightLedOff()
{
  digitalWrite(FRONT_RIGHT_LED_PIN, LOW);
}
/*-----------------------------------------------*/
void FrontLeftLedOn()
{
  digitalWrite(FRONT_LEFT_LED_PIN, HIGH);
}
/*-----------------------------------------------*/
void FrontLeftLedOff()
{
  digitalWrite(FRONT_LEFT_LED_PIN, LOW);
}
/*-----------------------------------------------*/
void FrontLedblink()
{
  FrontRightLedOn();
  FrontLeftLedOn();
  delay(DELAY_BLINK);
  FrontRightLedOff();
  FrontLeftLedOff();
  delay(DELAY_BLINK);
}
/*-----------------------------------------------*/
void FrontLedOn()
{
  FrontRightLedOn();
  FrontLeftLedOn();
}
/*-----------------------------------------------*/
void FrontLedOff()
{
  FrontRightLedOff();
  FrontLeftLedOff();
}
/*-----------------------------------------------*/
void FrontRightLedBlink()
{
  FrontRightLedOn();
  delay(DELAY_BLINK);
  FrontRightLedOff();
  delay(DELAY_BLINK);
}
/*-----------------------------------------------*/
void FrontLeftLedBlink()
{
  FrontLeftLedOn();
  delay(DELAY_BLINK);
  FrontLeftLedOff();
  delay(DELAY_BLINK);
}
/*-----------------------------------------------*/
void DisplayOff() 
{
  lcd.clear();
}
/*-----------------------------------------------*/
void DisplayLcd(uint8_t Row1,String Text1,uint8_t Row2,String Text2)
{
  lcd.clear();
  lcd.setCursor(Row1,0); 
  lcd.print(Text1); 
  lcd.setCursor(Row2,1); 
  lcd.print(Text2); 
}