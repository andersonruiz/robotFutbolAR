#include<Servo.h>
#include<SoftwareSerial.h>
Servo servoderecho;
Servo servoizquierdo;
int pinservode = 11;
int pinservoiz = 12;
int pinmax = 2450;
int pinmin = 600;
char orden;
void setup()
{
  Serial.begin(9600);
  servoderecho.attach(pinservode,pinmin,pinmax);
  servoizquierdo.attach(pinservoiz,pinmin,pinmax);
}
void loop()
{
  Serial.available();
  orden = Serial.read();
  switch(orden)
  {
    case 's':
    servoderecho.write(180);
    servoizquierdo.write(0);
    delay(1000);
    break;
     case 'w':
    servoderecho.write(0);
    servoizquierdo.write(180);
    delay(1000);
    break;
     case 'd':
    servoderecho.write(90);
    servoizquierdo.write(180);
    delay(1000);
    break;
     case 'a':
    servoderecho.write(0);
    servoizquierdo.write(90);
    delay(1000);
    break;
     case 'q':
    servoderecho.write(90);
    servoizquierdo.write(90);
    delay(1000);
    break;
  }
}
