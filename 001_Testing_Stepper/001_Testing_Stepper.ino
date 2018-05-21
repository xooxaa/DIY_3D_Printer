// Stepper Motor
#include <Stepper.h>
const short STEPS = 400; 
const short slow_speed = 96;
const short medium_speed = 112;
const short fast_speed = 128;

int PrevPosition;      // Vorherige Drehposition Wert zur Prüfung der Genauigkeit
int StepsToTake;       // Wie viel der Stepper sich bewegen muss
int StepsIntervall=16; // Anzahl der Schritte pro Raste des Potis

const short StepX_Pin1 = 30;
const short StepX_Pin2 = 32;
const short StepX_Pin3 = 34;
const short StepX_Pin4 = 36;

const short StepY_Pin1 = 40;
const short StepY_Pin2 = 42;
const short StepY_Pin3 = 44;
const short StepY_Pin4 = 46;

const short StepZ_Pin1 = 31;
const short StepZ_Pin2 = 33;
const short StepZ_Pin3 = 35;
const short StepZ_Pin4 = 37;

const short StepE_Pin1 = 41;
const short StepE_Pin2 = 43;
const short StepE_Pin3 = 45;
const short StepE_Pin4 = 47;

Stepper stepper_x(STEPS, StepX_Pin1, StepX_Pin2, StepX_Pin3, StepX_Pin4);
Stepper stepper_y(STEPS, StepY_Pin1, StepY_Pin2, StepY_Pin3, StepY_Pin4);
Stepper stepper_z(STEPS, StepZ_Pin1, StepZ_Pin2, StepZ_Pin3, StepZ_Pin4);
Stepper stepper_e(STEPS, StepE_Pin1, StepE_Pin2, StepE_Pin3, StepE_Pin4);



void setup() 
{
  stepper_x.setSpeed(fast_speed);
  stepper_x.step(128);
  delay(1000);
  
  
  stepper_x.setSpeed(slow_speed);
  stepper_x.step(-40);
  delay(1000);
  stepper_x.step(40);
  delay(1000);

  stepper_x.setSpeed(medium_speed);
  stepper_x.step(-60);
  delay(1000);
  stepper_x.step(60);
  delay(1000);

  stepper_x.setSpeed(fast_speed);
  stepper_x.step(-100);
  delay(1000);
  stepper_x.step(100);
  delay(1000);
}

void loop() 
{
  
}
