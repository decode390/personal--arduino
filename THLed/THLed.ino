#include <LiquidCrystal.h>
#include <TroykaDHT.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
DHT dht(8, DHT11);

void setup() {
  lcd.begin(16,2);
  dht.begin();
}

void loop()
{
  dht.read();
  lcd.setCursor(0, 0);
  switch(dht.getState()) {

    case DHT_OK:
      lcd.print((String)"Temp " + dht.getTemperatureC() + "C");
      lcd.setCursor(0,1);
      lcd.println((String)"Humedad " + dht.getHumidity() + "%");
      break;

    case DHT_ERROR_CHECKSUM:
      lcd.println("Checksum error");
      break;
      
    case DHT_ERROR_TIMEOUT:
      lcd.println("Time out error");
      break;

    case DHT_ERROR_NO_REPLY:
      lcd.println("Sensor not connected");
      break;
  }
  
  delay(2000);
}
