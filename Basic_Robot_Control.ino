#include <Servo.h>
Servo Motor_Left;
Servo Motor_Right;
const int MF = 20;//motor forward
const int MB = 138;//motor backward
const int MS = 91;//motor stop


#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_SHIELD

#include <OneSheeld.h>

void setup() 
{
  OneSheeld.begin();

  //motor pin config
  Motor_Left.attach(11);
  Motor_Right.attach(12);

}

void loop()
{
  if(GamePad.isUpPressed())//foward
  {
    Motor_Left.write(MF);
    Motor_Right.write(MF);
  } 
  else if(GamePad.isDownPressed())//backward
  {
    Motor_Left.write(MB);
    Motor_Right.write(MB);
  }

  else if(GamePad.isRightPressed())//CW
  {
    Motor_Left.write(MF);
    Motor_Right.write(MB);
  }

  else if(GamePad.isLeftPressed())//CCW
  {
    Motor_Left.write(MB);
    Motor_Right.write(MF);
  }

  else
  {
    Motor_Left.write(MS);
    Motor_Right.write(MS);
  }
}
