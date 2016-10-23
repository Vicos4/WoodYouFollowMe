
#include <Bridge.h>
#include <HttpClient.h>

#include <Servo.h>

Servo LeftKnee;
Servo LeftHip;
Servo RightKnee;
Servo RightHip;
Servo HeadHorizontal;
Servo HeadVertical;

void setup() {
  
  LeftHip.attach(2);//red
  RightHip.attach(3);//blue
  LeftKnee.attach(4);//brown
  RightKnee.attach(5);//white
  HeadHorizontal.attach(6);//purple
  HeadVertical.attach(7);//yellow

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  Serial.begin(9600);

  while (!Serial); // wait for a serial connection
}

void loop() {
  // Initialize the client library
  HttpClient client;

  // Make a HTTP request:
client.get("http://192.168.240.1/arduino/11");

String lh = client.readStringUntil(',');
String rh = client.readStringUntil(',');
String lk = client.readStringUntil(',');
String rk = client.readStringUntil(',');

int ilh = lh.toInt();
int irh = rh.toInt();
int ilk = lk.toInt();
int irk = rk.toInt();

int lhOUT = mapHighLow(ilh, 708, 594, 90, 0);
int rhOUT = mapLowHigh(irh, 367, 505, 90, 180);
int lkOUT = mapLowHigh(ilk, 105, 220, 90, 0);
int rkOUT = mapHighLow(irk, 579, 380, 90, 180);

Serial.println(lhOUT);
Serial.println(rhOUT);
Serial.println(lkOUT);
Serial.println(rkOUT);

LeftHip.write(lhOUT);
RightHip.write(rhOUT);
LeftKnee.write(lkOUT);
RightKnee.write(rkOUT);


    
  Serial.flush();

  delay(5 );
}


int mapHighLow(int x, int in_max, int in_min, int out_max, int out_min)
{
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

int mapLowHigh(int x, int in_min, int in_max, int out_min, int out_max)
{
  return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}




