int red = 255;
int green = 255;
int blue = 0;
int color[3] = {1, 1, 1};

void ps4() {
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {

    if (PS4.Right())
    {
      Serial.println("Select button click");
      delay(db_delay);
      if (Select_G != PS4.Right() ) {

        Select_G += 1;
        if (Select_G >= 3)
        {

          Select_G = 0;
        }
      }
    }
    if (PS4.Down()) {
      delay(db_delay);
      Grip_V_move = -PS4.Down();
    }

  }
  if (PS4.Up())
  {
    delay(db_delay);
    Grip_V_move = PS4.Up();
  }

  if (PS4.Left()) {
    delay(db_delay);
    if (Mode_G == 0) {
      Mode_G = 1;
    }
    else {
      Mode_G = 0;
    }
  }


  if (PS4.Square()) {
    delay(db_delay);
    S_Grip = PS4.Square();
  }
  if (PS4.Cross()) {
    delay(db_delay);
    S_V = -PS4.Cross();
  }
  if (PS4.Circle()) {
    delay(db_delay);
    S_Grip = -PS4.Circle();
  }
  if (PS4.Triangle()) {
    delay(db_delay);
    S_V = PS4.Triangle();

  }


  if (PS4.UpRight()) Serial.println("Up Right");
  if (PS4.DownRight()) Serial.println("Down Right");
  if (PS4.UpLeft()) Serial.println("Up Left");
  if (PS4.DownLeft()) Serial.println("Down Left");

  if (PS4.L1())
  {
    if (O_C_Grip == 0) {
      O_C_Grip = 1;
    }
    else {
      O_C_Grip = 0;
    }
  }
  if (PS4.R1()) Serial.println("R1 Button");


  if (PS4.Share()) {
    if (blue >= 255) {
      color[2] = -1;
    }
    else if (blue <= 0 ) {
      color[2] = 1;
    }
    blue += color[2];
        Serial.println(blue);

  }
  if (PS4.Options()) {
    if (red >= 255) {
      color[0] = -1;
    }
    else if (red <= 0 ) {
      color[0] = 1;
    }
    red += color[0];
    Serial.println(red);
  }
  if (PS4.L3()) Serial.println("L3 Button");
  if (PS4.R3()) Serial.println("R3 Button");

  if (PS4.PSButton()) {
    if (green >= 255) {
      color[1] = -1;
    }
    else if (green <= 0 ) {
      color[1] = 1;
    }
    green += color[1];
    Serial.println(green);
    }
  
  if (PS4.Touchpad())     
  {
  }
 

  if (PS4.L2()) {
    Grip_speed = PS4.L2Value();
  }
  if (PS4.R2()) {
    Serial.println("R2 Button");
    Serial.printf("R2 button at %d\n", PS4.R2Value());

  }

  if (PS4.LStickX()) {
    //  Serial.printf("Left Stick x at %d\n", PS4.LStickX());
    sideways = PS4.LStickX();

  }
  if (PS4.LStickY()) {
    //  Serial.printf("Left Stick y at %d\n", PS4.LStickY());
    botspeed = PS4.LStickY();
  }
  if (PS4.RStickX()) {
    // Serial.printf("Right Stick x at %d\n", PS4.RStickX());
    bot_turn_speed = PS4.RStickX();
  }
  if (PS4.RStickY()) {
    // Serial.printf("Right Stick y at %d\n", PS4.RStickY());
}

  if (PS4.Charging()) Serial.println("The controller is charging");
  //if (PS4.Audio()) Serial.println("The controller has headphones attached");
  //if (PS4.Mic()) Serial.println("The controller has a mic attached");
  PS4.setLed(red, green, blue);
  // Serial.printf("Battery Level : %d\n", PS4.Battery());
  if (abs(PS4.LStickY()) > 20 || abs(PS4.RStickX()) > 20)
  {
    PS4.setRumble(abs(PS4.LStickY()), abs(PS4.RStickX()));
  }
  else {
    PS4.setRumble(0, 0);
  }
  // Sends data set in the above three instructions to the controller
  PS4.sendToController();
  //Serial.println();
  // This delay is to make the output more human readable
  // Remove it when you're not trying to see the output
}
