
void PinB0()
{
  SigB[0] = digitalRead(encoderBPin[0]);
   if(SigA[0] >= SigB[0])
   {
    Step_diff_time[0] = millis() - Step_starttime[0];
    Step_starttime[0] = millis();
    Steps[0] += 1;
    
    pos[0] +=1;
    if (abs(pos[0]) >=StepSize)
    {
      pos[0] = 0;
      pos_time[0] = millis();
    
    } 
   }
  }



void PinA0()
{
  SigA[0] = digitalRead(encoderAPin[0]);
   if(SigB[0] >= SigA[0])
   {
   Step_diff_time[0] = millis() - Step_starttime[0];
  Step_starttime[0] = millis();
    Steps[0] -= 1; 
    
    pos[0] -=1;
    if (abs(pos[0]) >=StepSize)
    {
      pos[0] = 0;
      pos_time[0] = millis();
    
    }
   }
   
  
  }

  void PinB1()
{
  
  SigB[1] = digitalRead(encoderBPin[1]);
     if(SigA[1] >= SigB[1])
   {
     Step_diff_time[1] = millis() - Step_starttime[1];
  Step_starttime[1] = millis();
    Steps[1] += 1; 
   
    pos[1] +=1;
    if (abs(pos[1]) >=StepSize)
    {
      pos[1] = 0;
      pos_time[1] = millis();
    
    }
   }
   
  }



void PinA1()
{
  SigA[1] = digitalRead(encoderAPin[1]);
  if(SigB[1] >= SigA[1])
   {
     Step_diff_time[1] = millis() - Step_starttime[1];
  Step_starttime[1] = millis();
    Steps[1] -= 1; 
   }
    pos[1] -=1;
    if (abs(pos[1]) >=StepSize)
    {
      pos[1] = 0;
      pos_time[1] = millis();
    
    }
  
  }

  void PinB2()
{
  
  SigB[2] = digitalRead(encoderBPin[2]);
     if(SigA[2] >= SigB[2])
   {
  Step_diff_time[2] = millis() - Step_starttime[2];
  Step_starttime[2] = millis();
    Steps[2] -= 1; 

     pos[2] -=1;
    if (abs(pos[2]) >=StepSize)
    {
      pos[2] = 0;
      pos_time[2] = millis();
    
    }
   }
  }



void PinA2()
{
  SigA[2] = digitalRead(encoderAPin[2]);
  if(SigB[2] >= SigA[2])
   {
  Step_diff_time[2] = millis() - Step_starttime[2];
  Step_starttime[2] = millis();
    Steps[2] += 1; 
   }
    pos[2] +=1;
    if (abs(pos[2]) >=StepSize)
    {
      pos[2] = 0;
      pos_time[2] = millis();
    
    }

  }

  void PinB3()
{
  
  SigB[3] = digitalRead(encoderBPin[3]);
     if(SigA[3] >= SigB[3])
   {
  Step_diff_time[3] = millis() - Step_starttime[3];
  Step_starttime[3] = millis();
    Steps[3] += 1; 
     pos[3] +=1;
    if (abs(pos[3]) >=StepSize)
    {
      pos[3] = 0;
      pos_time[3] = millis();
    
    }
   }
  }



void PinA3()
{
  SigA[3] = digitalRead(encoderAPin[3]);
  if(SigB[3] >= SigA[3])
   {
   Step_diff_time[3] = millis() - Step_starttime[3];
  Step_starttime[3] = millis();
    Steps[3] -= 1; 
 pos[3] -=1;
    if (abs(pos[3]) >=StepSize)
    {
      pos[3] = 0;
      pos_time[3] = millis();
    
    }
   
   }

  
  }
