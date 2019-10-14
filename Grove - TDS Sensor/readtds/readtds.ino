
#define SERIAL Serial
int sensorPin = A1;
int sensorValue = 0;
float tdsValue = 0;
float Voltage = 0;
void setup() {
    SERIAL.begin(9600);
}
void loop() {
    sensorValue = analogRead(sensorPin);
    Voltage = sensorValue*5/1024.0;
    tdsValue=(133.42*Voltage*Voltage*Voltage - 255.86*Voltage*Voltage + 857.39*Voltage)*0.5; //convert voltage value to tds value
    SERIAL.print("TDSvaule = " ); 
    SERIAL.print(tdsValue);
    SERIAL.println(" ppm");
    delay(1000);
}

