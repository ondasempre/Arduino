const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 120000;

void setup()
{
  for (int x = 2; x < 8; x++)
  {
    pinMode(x, OUTPUT);
  }
  
  pinMode(switchPin, INPUT);
}

void loop()
{
  unsigned long currentTime = millis();
  
  if (currentTime - previousTime > interval)
  {
    previousTime = currentTime;
    
    if (led > 7)
    {
      warning();
    }
    else
    {
      digitalWrite(led, HIGH);
      led++;
    }
  }
  
  switchState = digitalRead(switchPin);
  
  if (switchState != prevSwitchState)
  {
    for(int x = 2; x < 8; x++)
    {
      digitalWrite(x, LOW);
    }
    
    led = 2;
    previousTime = currentTime;
  }
  
  prevSwitchState = switchState;
}

void warning()
{
   for(int x = 2; x < 8; x++)
   {
     digitalWrite(x, LOW);
   }
   delay(250);
   
   for(int x = 2; x < 8; x++)
   {
     digitalWrite(x, HIGH);
   }
}
