// esp32 mac ac:67:b2:36:24:de

int encoderAPin[4] = {14,12,32,27}; // ISSUE WITH 34 35 PIN EXT PULLUP 
int encoderBPin[4] = {25,13,33,26}; // ISSE 12 PIN BOOT FAIL USE 27 OR MAY TRY 14
int Step_starttime[4] = {0,0,0,0};
int Step_diff_time[4] = {0,0,0,0};


volatile int SigA[4] = {0,0,0,0};
volatile int SigB[4] = {0,0,0,0};
volatile int botspeed = 0;
volatile int bot_turn_speed = 0;

int motor_speed[4] = [0,0,0,0];

int Steps[4] = {0,0,0,0};
int rev[4] = {0,0,0,0};
int rpm[4] = {0,0,0,0};
int pos[4] = {0,0,0,0};
double pos_time[4] = {0,0,0,0};
int StepSize = 600;
int error[4] = {0,0,0,0};
// ------------------------

int DirPin[4] = {4,19,22,5};
int PwmPin[4]= {2,21,23,18};

#include <PS4Controller.h>
#include <analogWrite.h>


  TaskHandle_t Task1;

 void Task(void * parameter)
  {
    
for(int i =0 ; i<=3; i++){
  pinMode(encoderAPin[i], INPUT_PULLUP);
  pinMode(encoderBPin[i], INPUT_PULLUP);


} 
  Serial.begin(115200);
  PS4.begin();
  Serial.println("Ready.");
  
 attachInterrupt(encoderAPin[0], PinA0, CHANGE);
  attachInterrupt(encoderBPin[0], PinB0, CHANGE);
   attachInterrupt(encoderAPin[1], PinA1, CHANGE);
  attachInterrupt(encoderBPin[1], PinB1, CHANGE);
   attachInterrupt(encoderAPin[2], PinA2, CHANGE);
  attachInterrupt(encoderBPin[2], PinB2, CHANGE);
   attachInterrupt(encoderAPin[3], PinA3, CHANGE);
  attachInterrupt(encoderBPin[3], PinB3,CHANGE);
    
  for(;;)
  {
    ps4();
    delay(10);
    }


  }
  
void setup() {
 //Serial.begin (250000); // UART0 TX GPIO1 RX GPIO3
 Serial.begin(115200); // UART2 TX GPIO17 RX GPIO16

   
for(int i =0 ; i <= 3; i++){
  pinMode(encoderAPin[i], INPUT_PULLUP);
  pinMode(encoderBPin[i], INPUT_PULLUP);

  
  pinMode(DirPin[i],OUTPUT);
  analogWriteResolution(PwmPin[i], 12);

} 

/*
  attachInterrupt(encoderAPin[0], PinA0, CHANGE);
  attachInterrupt(encoderBPin[0], PinB0, CHANGE);
   attachInterrupt(encoderAPin[1], PinA1, CHANGE);
  attachInterrupt(encoderBPin[1], PinB1, CHANGE);
   attachInterrupt(encoderAPin[2], PinA2, CHANGE);
  attachInterrupt(encoderBPin[2], PinB2, CHANGE);
   attachInterrupt(encoderAPin[3], PinA3, CHANGE);
  attachInterrupt(encoderBPin[3], PinB3, CHANGE);

*/ 

  xTaskCreatePinnedToCore(
      Task,
      "T1",
      10000,  //STACK
      NULL,
      1,    // PRIORITY
      &Task1,
      0 ); //core


}
int inputtemp=70;

void loop(){




for(int i =0; i<=3; i++){
rpm[i] = 0.5*(142*abs(pos[i])/((millis()+1)-pos_time[i]))+ 0.5*rpm[i];
error[i] = -(rpm[i] - inputtemp);
//Serial.print(abs(inputtemp)+error[i]);
//Serial.print("  ");
//Serial.print(error[i]);
//Serial.print("  ");

//Serial.print(rpm[i]);
//Serial.print("  ");
//
//Serial.print(abs(inputtemp)+1*error[i]);
//Serial.print("  ");
}
//
Serial.println(botspeed);


 


for(int i =0; i<=3; i++){

analogWrite(PwmPin[i], abs(inputtemp+1*error[i]));
digitalWrite(DirPin[i],HIGH);

}
  //just here to slow down the output, and show it will workeven during a delay
}
