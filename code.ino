#include <LiquidCrystal_I2C_STEM.h>

#include<SoftwareSerial.h>  // BLUETOOTH USERNAME: CLEANER ROBOT  PASSWORD:1234
#include <Wire.h> 
LiquidCrystal_I2C_STEM lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11

#define IN1 12  // ALL FROM 12 TO 9 ARE MOTOR PINS
#define IN2 11
#define IN3 10
#define IN4 9


#define IN5 4  // GRASS CUTTER 
#define IN6 5  // SEED SOWING 
#define IN7 6   //PLOUGHING
#define IN8 7   // SPRAYER
//#define EN1 6
//#define EN2 5
int rainpin = A0;
int raindata;
int perct1;

int soilpin = A1;
int soildata;
int perct;

DHT dht(DHTPIN, DHTTYPE);

String data;
int btVal;

void setup()
{
dht.begin();
//Serial.begin(115200);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
// RELAY PINS OUTPUT
pinMode(IN5, OUTPUT);
pinMode(IN6, OUTPUT);
pinMode(IN7, OUTPUT);
pinMode(IN8, OUTPUT);
pinMode(rainpin,INPUT);
 pinMode(soilpin,INPUT);
//pinMode(EN1, OUTPUT);
//pinMode(EN2, OUTPUT);
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
digitalWrite(IN5, HIGH);
digitalWrite(IN6, HIGH);
digitalWrite(IN7, HIGH);
digitalWrite(IN8, HIGH);
//analogWrite(EN1,63);
//analogWrite(EN2,63);
 
Serial.begin(9600);

lcd.init();
  // Print a message to the LCD.
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("     WELCOME");
  lcd.setCursor(0,1);
  lcd.print("       TO      ");
  delay(500);
  lcd.clear();//Solar Powered Autonomous Multipurpose Agricultural Robot Using Bluetooth
  lcd.setCursor(0,0);
  lcd.print("Solar Powered Autonomous");
  //lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Multipurpose Agricultural");
  delay(500);
  lcd.setCursor(0,2);
  lcd.print("    Multipurpose Agri");
  lcd.setCursor(0,3);
  lcd.print("Robot Using Bluetooth");
  delay(500);
  
}
void loop()
{
 raindata=analogRead(rainpin);
 Serial.print("Rain Drop value=");
 Serial.println(raindata);
 perct1 = map(raindata,1023,200,0,100);
 Serial.print("Rain Drop %=");
 Serial.println(perct1);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rain Drop %=");
  lcd.setCursor(0,1);
  lcd.print(perct1);
  lcd.print("%");
 delay(1000);

 soildata=analogRead(soilpin);
 Serial.print("soil moisture value=");
 Serial.println(soildata);
 perct = map(soildata,1023,200,0,100);
 Serial.print("soil moisture %=");
 Serial.println(perct);
  lcd.setCursor(0,2);
  lcd.print("soil moisture %=");
  lcd.setCursor(0,3);
  lcd.print(perct);
  lcd.print("%");
 delay(1000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
 float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)

  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F("°F"));
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(0,1);
  lcd.print(t);
  lcd.print(" _C ");
  lcd.setCursor(0,2);
  lcd.print("Humidity:");
  lcd.setCursor(0,3);
  lcd.print(h);
  lcd.print("_F");
  delay(1000);
  

 
while (Serial.available())
{
{
data = Serial.readStringUntil('\n');
//Serial.print(str);
}
btVal = (data.toInt());
//Serial.print("BlueTooth Value ");
Serial.println(btVal);

switch (btVal)
{
case 1:
//Serial.println("Forward");
forward();
break;
case 2:
//Serial.println("Reverse");
reverse();
break;
case 3:
//Serial.println("Left");
left();
break;
case 4:
//Serial.println("Right");
right();
break;
case 5:
//Serial.println("Stop");
stoprobot();
break;

case 6:
//CLEANER BRUSH AND VACUM CLEANER ON
GRASSCON();
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("DUST COLLECTION");
  //lcd.clear();
//lcd.setCursor(0,1);
//lcd.print("BRUSH & VACUM ON");
break;

case 7:
//CLEANER BRUSH AND VACUM CLEANER OFF
GRASSCOFF();
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("DUST COLLECTION");
  //lcd.clear();
//lcd.setCursor(0,1);
//lcd.print("BRUSH& VACUM OFF");
break;

case 8:
//MOP AND WATER SPRAYER AND DRYER FAN ON
SEEDON();
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("FLOOR CLEANING");
  //lcd.clear();
//lcd.setCursor(0,1);
//lcd.print("MOP,PUMP&FAN ON");
break;

case 9:
//MOP AND WATER SPRAYER AND DRYER FAN OFF
SEEDOFF();
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("FLOOR CLEANING");
  //lcd.clear();
//lcd.setCursor(0,1);
//lcd.print("MOP,PUMP&FAN OFF");
break;

case 10:
//MOP AND WATER SPRAYER AND DRYER FAN OFF
PLOUGHINGON();
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("FLOOR CLEANING");
  //lcd.clear();
//lcd.setCursor(0,1);
//lcd.print("MOP,PUMP&FAN OFF");
break;

case 11:
//MOP AND WATER SPRAYER AND DRYER FAN OFF
PLOUGHINGOFF();
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("FLOOR CLEANING");
  //lcd.clear();
//lcd.setCursor(0,1);
//lcd.print("MOP,PUMP&FAN OFF");
break;



case 12:
//MOP AND WATER SPRAYER AND DRYER FAN OFF
SPRAYINGON();
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("FLOOR CLEANING");
  //lcd.clear();
//lcd.setCursor(0,1);
//lcd.print("MOP,PUMP&FAN OFF");
break;

case 13:
//MOP AND WATER SPRAYER AND DRYER FAN OFF
SPRAYINGOFF();
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("FLOOR CLEANING");
  //lcd.clear();
//lcd.setCursor(0,1);
//lcd.print("MOP,PUMP&FAN OFF");
break;


}
}


if (Serial.available() < 0)
{
Serial.println("No Bluetooth Data ");
}
}


void forward()
{
 digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);

}
void reverse()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);

}
void left()
{
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
}
void right()
{
 digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4,LOW);

}
void stoprobot()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
digitalWrite(IN5, HIGH);
digitalWrite(IN6, HIGH);
digitalWrite(IN7, HIGH);
digitalWrite(IN8, HIGH);

}

void GRASSCON()
{
digitalWrite(IN5, LOW);
}

void GRASSCOFF()
{
digitalWrite(IN5, HIGH);
}

void SEEDON()
{
digitalWrite(IN6, LOW);

}

void SEEDOFF()
{
digitalWrite(IN6, HIGH);
}

void PLOUGHINGON()
{
digitalWrite(IN7, LOW);

}

void PLOUGHINGOFF()
{
digitalWrite(IN7, HIGH);
}

void SPRAYINGON()
{
digitalWrite(IN8, LOW);

}

void SPRAYINGOFF()
{
digitalWrite(IN8, HIGH);
}
