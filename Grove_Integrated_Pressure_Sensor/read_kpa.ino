// MPX5700 pressure sensor (700kPa)

#if defined(ARDUINO_ARCH_AVR)
#pragma message("Defined architecture for ARDUINO_ARCH_AVR.")
#define SERIAL Serial

#elif defined(ARDUINO_ARCH_SAM)
#pragma message("Defined architecture for ARDUINO_ARCH_SAM.")
#define SERIAL SerialUSB

#elif defined(ARDUINO_ARCH_SAMD)
#pragma message("Defined architecture for ARDUINO_ARCH_SAMD.")	
#define SERIAL SerialUSB

#elif defined(ARDUINO_ARCH_STM32F4)
#pragma message("Defined architecture for ARDUINO_ARCH_STM32F4.")
#define SERIAL SerialUSB
#else
#pragma message("Not found any architecture.")
#endif



int rawValue; // A/D readings
int offset = 410; // zero pressure adjust
int fullScale = 9630; // max pressure (span) adjust
float pressure; // final pressure

void setup() {
  SERIAL.begin(9600);
}

void loop() {
  rawValue = 0;
  for (int x = 0; x < 10; x++) rawValue = rawValue + analogRead(A0);
  pressure = (rawValue - offset) * 700.0 / (fullScale - offset); // pressure conversion

  SERIAL.print("Raw A/D is  ");
  SERIAL.print(rawValue);
  SERIAL.print("   Pressure is  ");
  SERIAL.print(pressure, 1); // one decimal places
  SERIAL.println("  kPa");
  delay(1000);
}
