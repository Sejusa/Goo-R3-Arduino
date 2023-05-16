//Proyecto Arduino Goo R3
// Hecho por Sergi Funes, Marcos Cobos y Cristhian Rodríguez

int ledEncendido = 2;
int echoSensor = 4;
int triggerSensor = 7;
int interruptor = 8;
int motorI1 = 9;
int motorI2 = 10;
int motorD1 = 11;
int motorD2 = 12;
bool interruptorPulsado = false;

void setup() 
{
  pinMode(interruptor, INPUT);
  pinMode(ledEncendido, OUTPUT);
  pinMode(triggerSensor, OUTPUT);
  pinMode(echoSensor, INPUT);
  pinMode(motorD1, OUTPUT);
  pinMode(motorD2, OUTPUT);
  pinMode(motorI1, OUTPUT);
  pinMode(motorI2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledEncendido, LOW); //El LED enpieza estando apagado.
}

void loop() 
{
  if (digitalRead(interruptor) == HIGH && interruptorPulsado == false) //Solo lo ejecutamos si el LED se pulsa y si la variable bool "interruptorPuslado" es false.
  {
    interruptorPulsado = true;
    for (int i=0; i<3; i++) //Parpadeamos un led para anunciar al usuario de que se va a iniciar el dispositivo.
    {
      digitalWrite(ledEncendido, HIGH);
      delay(500);
      digitalWrite(ledEncendido, LOW);
      delay(500);
    }
  }
  digitalWrite(ledEncendido, HIGH);
  medirDistancia();
  
  if (digitalRead(interruptor) == HIGH)
  {
    while(1)
    {
      //Se para el programa.
      if (digitalRead(interruptor) == HIGH)
      {
        break;
      }
    }
  }
}
   

void medirDistancia()
{
  digitalWrite(triggerSensor, LOW); //Nos aseguramos de que el sensor está en el estado correcto para empezar la medición.
  delayMicroseconds(2); //Esperamos 2 microsegundos.
  digitalWrite(triggerSensor, HIGH); //Empezamos a medir distáncia.
  delayMicroseconds(10); 
  digitalWrite(triggerSensor, LOW); //Dejamos de medir distáncia.
  long duration = pulseIn(echoSensor, HIGH); //Con "pulseIn" esperamos hasta que el pin "echo" sea "HIGH" y medimos cuanto tarda en volver a ser "LOW".
  float distance = duration * 0.034 / 2; /*Calculamos la distáncia medida por el sensor en cm. Multiplicamos la duración del sonido entre 0,034(velocidad
                                         del sonido en el aire) entre 2(la ida y a vuelta)*/
  Serial.println(distance);

  while (distance > 100) //Si la distancia con el objeto es mayor a 100.
  {
    rotate(1);
  }

  if (distance < 100 && distance > 50) // Si la distancia con el objeto es menor a 100 pero mayor que 50.
  {
    rotate(0);
    delay(2000);
    rotate(3);
    
  }

  else if (distance < 50)
  {
    rotate(2);
    delay(2000);
    rotate(3);
  }
}

void rotate(int direction) //Parámetro para indicar hacia donde queremos que giren los motores.
{ //Empezamos con los motores quietos.
  digitalWrite(motorD1, LOW);
  digitalWrite(motorD2, LOW);
  digitalWrite(motorI1, LOW);
  digitalWrite(motorI2, LOW);
  
  if(direction == 1)
  { //Se cambia la dirección del motor. En este caso para girar hacia adelante.
    digitalWrite(motorD1, LOW);
    digitalWrite(motorD2, HIGH);
    digitalWrite(motorI1, LOW);
    digitalWrite(motorI2, HIGH);
  }

  else if (direction == 2)
  { //Se cambia la dirección del motor. En este caso para que gire marcha atrás.
    digitalWrite(motorD1, HIGH);
    digitalWrite(motorD2, LOW);
    digitalWrite(motorI1, HIGH);
    digitalWrite(motorI2, LOW);
  }

  else if (direction == 3)
  { //Se cambia la dirección del motor. En este caso para que gire a la izquierda.
    digitalWrite(motorD1, HIGH);
    digitalWrite(motorD2, LOW);
    digitalWrite(motorI1, LOW);
    digitalWrite(motorI2, HIGH);
  }

  else if (direction == 4)
  { //Se cambia la dirección del motor. En este caso para que gire a la derecha.
    digitalWrite(motorD1, LOW);
    digitalWrite(motorD2, HIGH);
    digitalWrite(motorI1, HIGH);
    digitalWrite(motorI2, LOW);
  }

  else if (direction == 0)
  { //Se cambia la dirección del motor. En este caso para que este parado.
    digitalWrite(motorD1, LOW);
    digitalWrite(motorD2, LOW);
    digitalWrite(motorI1, LOW);
    digitalWrite(motorI2, LOW);
  }
}
