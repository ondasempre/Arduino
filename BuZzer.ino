int zapzap = 10;

void setup() 
{
  pinMode(zapzap, OUTPUT); // Imposta la porta di collegamento per il buzzer
}

void loop() 
{
  buzz(zapzap, 4186, 100);
  delay(10); // Attesa
}

void buzz(int targetPin, long frequency, long length) 
{
  // SUONO CONTINUO
  long delayValue = 1000000/frequency/2;
  long numCycles = frequency * length/ 1000;
 

  for (long i=0; i < numCycles; i++)
  {
    digitalWrite(targetPin,HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin,LOW);
    delayMicroseconds(delayValue);
  }
}
