#include <Arduino.h>

#define LED1   PB15
#define LED2   PB2
#define LED3   PA5
#define LED4   PA4
#define LED5   PB9
#define LED6   PB8
#define LED7   PB3
#define LED8   PA15

int dataIn;
uint32_t counter;
uint32_t myindex;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  
  Serial.begin(9600); // baudrate is not actually used
  Serial1.begin(9600, SERIAL_HALF_DUPLEX, SERIAL_CTRL_BLOCKING);
  Serial3.begin(1200); // bottom sensor
  Serial4.begin(1200); // top sensor
}

void loop() {
  if (counter++ == 1000000) {
    counter = 0;
    myindex++;
    digitalWrite(LED1, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(100);              // wait for a second
    digitalWrite(LED1, LOW);  // turn the LED off by making the voltage LOW
    delay(100);              // wait for a second
    Serial1.print("S1:Hello Receiver!\n");
    Serial1.println(myindex, DEC);
    Serial4.write("S4:Hello Receiver!\n");
    Serial4.println(myindex, DEC);
  }

  dataIn = Serial4.read();
  if (dataIn >= 0)
  Serial.write(dataIn);
}
