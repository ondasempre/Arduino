/* 
 MouseContinousDrawing

 Controls the mouse from two potentiometer on an Arduino Leonardo.
 Uses a pushbutton to turn on and off mouse control, and
 a second pushbutton to click the left mouse button

 Hardware:
 * 2 potentiometers connected to pins A0 and A1
 * pushbuttons connected to pin D2 and D3

 The mouse movement is always relative. This sketch reads 
 two analog inputs that range from 0 to 1023 (or less on either end)
 and translates them into an offset compared to the previous position. 

 WARNING:  When you use the Mouse.move() command, the Arduino takes
 over your mouse!  Make sure you have control before you use the command.
 This sketch includes a pushbutton to toggle the mouse control state, so
 you can turn on and off mouse control.

 based on the original Leonardo mouse examples made by Tom Igoe

 this code is in the public domain

*/

// set pin numbers for switch, joystick axes, and LED:
const int switchPin = 2;      // switch to turn on and off mouse control
const int mouseButton = 3;    // input pin for the mouse pushButton
const int xAxis = A0;         // joystick X axis  
const int yAxis = A1;         // joystick Y axis
const int ledPin = 13;         // Mouse control LED 

// parameters for reading the joystick:
int range = 12;               // output range of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range/4;      // resting threshold
int center = range/2;         // resting position value
int prevxVal = 0;
int prevyVal = 0;

int prevXreading = 0;
int prevYreading = 0;
int toggle = 0;

boolean mouseIsActive = false;    // whether or not to control the mouse
int prevSwitchState = LOW;        // previous switch state
int prevButtonState = LOW;

void setup() {
  pinMode(switchPin, INPUT);       // the switch pin
  pinMode(ledPin, OUTPUT);         // the LED pin  
  // take control of the mouse:
  Mouse.begin();
}

void loop() {
  // read the switch:
  int switchState = digitalRead(switchPin);
  // if it's changed and it's high, toggle the mouse state:
  if (switchState != prevSwitchState) {
    if (switchState == HIGH) {
      mouseIsActive = !mouseIsActive;
      // turn on LED to indicate mouse state:
      digitalWrite(ledPin, mouseIsActive);
    } 
  }

  // save switch state for next comparison:
  prevSwitchState = switchState;

  // read and scale the two axes:
  // int xReading = readAxis(A0,  xVal);
  // int yReading = readAxis(A1, lastyVal);
  int currXreading = analogRead(xAxis);
  int currYreading = analogRead(yAxis);

  int xReading = prevXreading - currXreading;
  int yReading = prevYreading - currYreading;

  prevXreading = currXreading;
  prevYreading = currYreading;

  // if the mouse control state is active, move the mouse:
  if (mouseIsActive) {
    Mouse.move(xReading, yReading, 0);
  }  

  // read the mouse button and click or not click:
  // if the mouse button is pressed:
  int buttonState = digitalRead(mouseButton);
  if (buttonState == HIGH && prevButtonState == LOW) {
    // if the mouse is not pressed, press it:
    toggle++;
    if(toggle == 1)
      if (!Mouse.isPressed(MOUSE_LEFT)) {
        Mouse.press(MOUSE_LEFT); 
      }  
  }
  else if(toggle == 2)
  {
    // else the mouse button is not pressed:
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT); 
    }
    toggle = 0;
  }

  prevButtonState = buttonState;

  delay(responseDelay);
}




/**
 * Continuous Lines.
 *
 * Click and drag the mouse to draw a line.
 */

void setup() 
{
  size(640, 480);
  background(102);
}

void draw() 
{
  stroke(255);
  strokeWeight(10);
  if(mousePressed) {
    line(mouseX, mouseY, pmouseX, pmouseY);
  }
}
