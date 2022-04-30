

// Gripper lift pins
#include <Servo.h>

int Mode_G = 0;
int Select_G = 0;
int O_C_Grip = 0;
int Grip_speed = 0;
int Grip_V_move = 0;



Servo servo[4];// create servo object to control a servo
//Servo myservo2;
//Servo myservo3;

int servo_pin[4] = {22, 24, 26, 28};
int servo_angle[4] = {90, 90, 90, 90};

int S_V = 0;
int S_Grip = 0;

int G_DIR[5] = {3, 5, 7, 9, 11};
int G_PWM[5] = {2, 4, 6, 8, 10};

int stepen[5] =  {23, 29, 35, 41, 47};
int steps[5] =   {25, 31, 37, 43, 49};
int stepdir[5] = {27, 33, 39, 45, 51};

int shootcount = 0;
int stepcount[5] = {1800, -1000, -1200, 1700, 1600};
int stepcount_2[5] = { -1800, 1000, 1200, -1700, 1600};

int Timehalt[5] = {1830, 5960, 3550, 760, 1000}; // mm per 100ms {3.6 , 3.15,5.55,5.1,5.1}

char command = 0;
int count = 0;
int bc = 0;

//const int RELAY_PIN[5] = {22, 24, 26, 28, 30};



void setup() {
  // initialize both serial ports:
  Serial.begin(115200);
  Serial.print("Code begin");
  Serial2.begin(115200);


  for (int st = 0; st <= 4; st++) {
    // pinMode(stepen[st], OUTPUT);
    //pinMode(steps[st], OUTPUT);
    //pinMode(stepdir[st], OUTPUT);
    pinMode(G_PWM[st], OUTPUT);
    pinMode(G_DIR[st], OUTPUT);
  }
  for (int st = 0; st <= 3; st++) {

    servo[st].attach(servo_pin[st]);
    //igitalWrite(stepen[st], HIGH);
    //delay(100);
    //digitalWrite(stepen[st], LOW);
  }

}

void loop() {

  recieve_and_decode();

  Run_Grip();
  scissor_lift() ;

}


void Run_Grip()
{

  for (int e = 0; e <= 1; e++) {


    if (Grip_V_move == 1)
    {
      digitalWrite(G_DIR[e], HIGH);
      analogWrite(G_PWM[e], 255);

    }
    else if (Grip_V_move == -1) {
      digitalWrite(G_DIR[e], LOW);
      analogWrite(G_PWM[e], 255);

    }
    else {
      digitalWrite(G_DIR[e], HIGH);
      analogWrite(G_PWM[e], 0);

    }
  }

  if (Mode_G == 1) {
    if (O_C_Grip == 0) {
      servo[0].write(servo_angle[0] + int((Grip_speed*0.00392) *90));
      servo[1].write(servo_angle[1] - int((Grip_speed*0.00392) *90));
      servo[2].write(servo_angle[2] - int((Grip_speed*0.00392) *90));
      servo[3].write(servo_angle[3] - int((Grip_speed*0.00392) *90));
    }
    else  {
      servo[0].write(servo_angle[0] - int((Grip_speed*0.00392) *90));
      servo[1].write(servo_angle[1] + int((Grip_speed*0.00392) *90));
      servo[2].write(servo_angle[2] + int((Grip_speed*0.00392) *90));
      servo[3].write(servo_angle[3] + int((Grip_speed*0.00392) *90));
    }


  }

  else if (Mode_G == 0) {

    if (O_C_Grip == 0) {
      servo[Select_G].write(servo_angle[Select_G] - int((Grip_speed*0.00392) *90));
      servo_angle[Select_G] = 90+ int((Grip_speed*0.00392) *90);
     // Serial.println(servo_angle[Select_G]);
      servo[0].write(servo_angle[0]);
      servo[1].write(servo_angle[1]);
      servo[2].write(servo_angle[2]);
      servo[3].write(servo_angle[3]);
      //servo[1].write((Grip_speed / 255).toInt());
      //servo[2].write((Grip_speed / 255).toInt());
      //servo[3].write((Grip_speed / 255).toInt());
    }
    else {
      servo_angle[Select_G] = 90- int((Grip_speed*0.00392) *90);
      servo[Select_G].write(servo_angle[Select_G] );
    //  Serial.println(servo_angle[Select_G]);
    }
  }
  else if (Mode_G == 2) {
    servo[0].write(servo_angle[0]);
    servo[1].write(servo_angle[1]);
    servo[2].write(servo_angle[2]);
    servo[3].write(servo_angle[3]);
  }

   for (int e = 0; e <= 1; e++) {


    if (S_V == 1)
    {
      digitalWrite(G_DIR[e], HIGH);
      analogWrite(G_PWM[e], 100);

    }
    else if (S_V == -1) {
      digitalWrite(G_DIR[e], LOW);
      analogWrite(G_PWM[e], 100);

    }
    else {
      digitalWrite(G_DIR[e], HIGH);
      analogWrite(G_PWM[e], 0);

    }
  }


}

void recieve_and_decode() {


  //   read from port 1, send to port 0:
  String inByte = "0";
  if (Serial2.available()) {
    String temp = Serial2.readStringUntil('::');
    if (temp.length() >= 17 && temp.length() <= 23 ) {

      inByte = temp;
      //Serial.println(inByte);

      int data_size = 0;
      String data[7] ;
      int last_pos = 3;

      if (inByte[3] == '#') {
        last_pos = 4 ;
      }
      else {
        last_pos = 3 ;
      }

      for (int i = 3; i <= inByte.length(); i++) {
        if (char(inByte[i]) == '@') {

          String val = "";
          for (int j = last_pos + 1 ; j < i; j++) {
            val += inByte[j];
          }
          last_pos = i;
          data[data_size] = val;
          data_size += 1;
          //Serial.println(val);

        }

      }
      String prt = "";
      for (int x = 0 ; x <= 6 ; x++) {
        prt = prt + data[x] + "  ";
        if (x< 5){
       Serial.print(servo_angle[x]);
       Serial.print("  ");
        }
        }

      Mode_G = (data[0].toInt());
      Select_G = (data[1].toInt());
      O_C_Grip = (data[2].toInt());
      Grip_speed = (data[3].toInt());
      Grip_V_move = (data[4].toInt());
      S_V = (data[5].toInt());
      S_Grip = (data[6].toInt());


      Serial.print("  ");
      Serial.println(prt);
    }
  }
  //delay(10);
}

void scissor_lift() {

  //int S_V = 0;
  //int S_Grip = 0;

  if (S_V == 1) {
    digitalWrite(G_DIR[3], LOW);
    analogWrite(G_PWM[3], 150);
    digitalWrite(G_DIR[4], LOW);
    analogWrite(G_PWM[4], 150);
   // Serial.println("clockwise");
  }
  else if (S_V == -1) {
    digitalWrite(G_DIR[3], HIGH);
    analogWrite(G_PWM[3], 150);
    digitalWrite(G_DIR[4], HIGH);
    analogWrite(G_PWM[4], 150);
 //      Serial.println("Counter_clockwise");
  }
  else {

    digitalWrite(G_DIR[3], LOW);
    analogWrite(G_PWM[3], 0);
    digitalWrite(G_DIR[4], LOW);
    analogWrite(G_PWM[4], 0);
  }

  }