#include <Servo.h>
#include "HCPCA9685.h"
#define  I2CAdd 0x40
HCPCA9685 HCPCA9685(I2CAdd);

int ud = A1;
int rl = A2;

int wri_rl = 8;
int wri_ud = 7;

int wri_rl_val;
int wri_ud_val;

int wri_rl_ang;
int wri_ud_ang;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);

  HCPCA9685.Servo(wri_rl, 90);
  HCPCA9685.Servo(wri_ud, 90);

}

void loop() {
  // put your main code here, to run repeatedly:
  wri_rl_val = analogRead(rl);
  wri_ud_val = analogRead(ud);

  wri_rl_ang = map(wri_rl_val,0,688,0,180);
  wri_ud_ang = map(wri_ud_val,0,688,0,180);

  HCPCA9685.Servo(wri_rl, wri_rl_ang);
  HCPCA9685.Servo(wri_ud, wri_ud_ang);

}
