//Proyecto Arduino Goo R3
// Hecho por Sergi Funes, Marcos Cobos y Cristhian Rodríguez
 
int interruptor = 0;
int ledEncendido = 1;
int motor = 2;

void setup() 
{
  pinMode(interruptor, INPUT);
  pinMode(ledEncendido, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() 
{
  while (digitalRead(interruptor) == HIGH)
  {
    digitalWrite(ledEncendido, HIGH);
    digitalWrite(motor, HIGH);
    if (digitalRead(interruptor) == LOW)
    {
      digitalWrite(ledEncendido, LOW);
      digitalWrite(motor, LOW);
    }
  }
}
