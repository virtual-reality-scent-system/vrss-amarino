#include <MeetAndroid.h>

MeetAndroid meetAndroid;//(error);

int pumpRelay = 2;

void error(uint8_t flag, uint8_t values) {
  meetAndroid.send("ERROR: ");
  meetAndroid.send(flag);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(57600);    //串口初始化
  meetAndroid.registerFunction(valve, 'A');
}

void loop() {
  // put your main code here, to run repeatedly:
  meetAndroid.receive();
}
void valve(byte flag, byte numOfValues) {
  int heading = meetAndroid.getInt();
  digitalWrite(heading, HIGH);
  delay(500);
  digitalWrite(heading, LOW);
}

