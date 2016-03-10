    // Esempio 01: far lampeggiare un led  
      
      #define LED 13            // LED collegato al pin digitale 13  
      
    void setup() 
    {  
      pinMode(LED, OUTPUT);     // imposta il pin digitale come output  
    }  
      
    void loop()
    {  
      
      for(int i=0; i<=50;i++)
      {
        digitalWrite(LED, HIGH);  // accende il LED  
        delay(100);              // aspetta un secondo  
        digitalWrite(LED, LOW);   // spegne il LED  
        delay(100);              // aspetta un secondo
     
      } 
      
        digitalWrite(LED, LOW);   // spegne il LED  
        delay(5000);              // aspetta un secondo 
      
    }  

