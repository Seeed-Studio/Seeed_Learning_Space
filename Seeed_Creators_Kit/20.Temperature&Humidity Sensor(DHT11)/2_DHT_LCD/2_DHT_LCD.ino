//add DHT sensor library
#include <DHT.h>
//add LCD library
#include <rgb_lcd.h>

//set digital pin2 as DHTPIN
#define DHTPIN 2
//set the sensor type as DHT 11
#define DHTTYPE DHT11

/*assign dht as the name of DHT sensor
  set the sensor pin as DHTPIN(pin2),
  set the sensor type as DHTTYPE(DHT11)
*/
DHT dht(DHTPIN, DHTTYPE);

//assign lcd as the name of rgb_lcd screen
rgb_lcd lcd;

void setup() {
  //initialise the dht sensor
  dht.begin();
  //initialise the lcd screen;
  //set up the lcd's number of columns and rows:
  lcd.begin(16, 2);
  //wait for 2s
  delay(2000);
}

void loop() {
  //store the humidity value to h
  int h = dht.readHumidity();
  //store the temperature value to t(in Celsius)
  int t = dht.readTemperature();
  
  //set the LCD cursor to column 0, line 0
  lcd.setCursor(0, 0);
  //Print text temperature: to the LCD
  lcd.print("Temperature:");
  //set the LCD cursor to column 12, line 0
  lcd.setCursor(12, 0);
  //Print temperature value t to the LCD
  lcd.print(t);
  //set the LCD cursor to column 14, line 0
  lcd.setCursor(14, 0);
  //Print temperature º is character 223 on lookup table
  lcd.write(223);
  //Print C to the LCD
  lcd.print("C");
  
  //set the LCD cursor to column 0, line 1
  lcd.setCursor(0, 1);
  //Print text Humidity: to the LCD
  lcd.print("Humidity: ");
  //set the LCD cursor to column 10, line 1
  lcd.setCursor(10, 1);
  //Print humidity value h to the LCD
  lcd.print(h);
  //set the LCD cursor to column 12, line 1
  lcd.setCursor(12, 1);
  //Print sign % to the LCD
  lcd.print("%");
}
