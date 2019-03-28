#include <IRremote.h>  
  
int RECV_PIN = 10;  
float armazenavalor; 
int motor1Pin1 = 3; // pin 2 on L293D
int motor1Pin2 = 4; // pin 7 on L293D
int enablePin = 9; // pin 1 on L293D

IRrecv irrecv(RECV_PIN);  
decode_results results;  

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  irrecv.enableIRIn(); // Inicializa o receptor IR  
  
  // set enablePin high so that motor can turn on:
  digitalWrite(enablePin, HIGH);
}
void loop() {
  if (irrecv.decode(&results))  
  {
      Serial.print("Valor lido : ");  
      Serial.println(results.value, HEX);  
      armazenavalor = (results.value);  
      if (armazenavalor == 0xFF30CF) //Verifica se a tecla 1 foi acionada  
    {
      digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
      digitalWrite(motor1Pin2, HIGH); // set pin 7 on L293D high
      digitalWrite(12, HIGH); // set pin 7 on L293D high
      digitalWrite(11, LOW); // set pin 7 on L293D high
      Serial.println("OK");
      delay(2000);
      digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D high
      digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D low   
    }
     if (armazenavalor == 0xFF18E7) //Verifica se a tecla 1 foi acionada  
    {
      digitalWrite(motor1Pin1, HIGH); // set pin 2 on L293D low
      digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D high
      digitalWrite(12, LOW); // set pin 7 on L293D high
      digitalWrite(11, HIGH); // set pin 7 on L293D high
      Serial.println("OK");
      delay(1800);
      digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D high
      digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D low  
    }
    else if (armazenavalor == 0xFFC23D)
    {
      digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D high
      digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D low
      digitalWrite(12, LOW); // set pin 7 on L293D high
      digitalWrite(11, LOW); // set pin 7 on L293D high
    }
    irrecv.resume(); //Le o próximo valor
  }
}
