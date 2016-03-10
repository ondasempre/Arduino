
    #include <LiquidCrystal.h>
    float kelvin;
    float celsius;
    LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
    void setup()
    {
      lcd.begin(16, 2);
    }
    void loop()
    {
      float lettura = analogRead(A0);
      kelvin = ((lettura/1023)*500);
      celsius = kelvin - 273.15;
      lcd.print("Gradi Kelvin");
      lcd.setCursor(13, 0);
      lcd.print(kelvin);
      lcd.setCursor(0,1);
      lcd.print("Gradi Celsius");
      lcd.setCursor(14, 1);
      lcd.print(celsius);
      delay(100);    
    }

