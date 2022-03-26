int red = 255;
int green = 0;
int blue = 255;

void ps4() {
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {
    if (PS4.Right()) Serial.println("Right Button");
    if (PS4.Down()) Serial.println("Down Button");
    if (PS4.Up()) Serial.println("Up Button");
    if (PS4.Left()) Serial.println("Left Button");

    if (PS4.Square()) Serial.println("Square Button");
    if (PS4.Cross()) Serial.println("Cross Button");
    if (PS4.Circle()) Serial.println("Circle Button");
    if (PS4.Triangle()) Serial.println("Triangle Button");

    if (PS4.UpRight()) Serial.println("Up Right");
    if (PS4.DownRight()) Serial.println("Down Right");
    if (PS4.UpLeft()) Serial.println("Up Left");
    if (PS4.DownLeft()) Serial.println("Down Left");

    if (PS4.L1()) Serial.println("L1 Button");
    if (PS4.R1()) Serial.println("R1 Button");

    if (PS4.Share()) Serial.println("Share Button");
    if (PS4.Options()) Serial.println("Options Button");
    if (PS4.L3()) Serial.println("L3 Button");
    if (PS4.R3()) Serial.println("R3 Button");

    if (PS4.PSButton()) Serial.println("PS Button");
    if (PS4.Touchpad()) Serial.println("Touch Pad Button");

    if (PS4.L2()) {
      Serial.println("L2 Button");
      Serial.printf("L2 button at %d\n", PS4.L2Value());

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

    //if (PS4.Charging()) Serial.println("The controller is charging");
    //if (PS4.Audio()) Serial.println("The controller has headphones attached");
    //if (PS4.Mic()) Serial.println("The controller has a mic attached");
    PS4.setLed(255, 0, 255);
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
    Serial.println();
    // This delay is to make the output more human readable
    // Remove it when you're not trying to see the output
  }
}
