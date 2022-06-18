#include "DHT.h"
#include <LiquidCrystal.h>
DHT dht(9, DHT11);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT11 test!!");
  dht.begin();
  lcd.begin(16, 2);
}

void loop() 
{
  float t_c = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Temp "); 
  lcd.print(t_c);
  lcd.print(" C");
  float humi = dht.readHumidity();
  lcd.setCursor(0, 1);
  lcd.print("Hum "); 
  lcd.print(humi);
  lcd.print(" %");
}
