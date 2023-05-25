int ledEncendido = 2;
int echoSensor = 4;
int triggerSensor = 7;
int interruptor = 8;
int motorI1 = 9;
int motorI2 = 10;
int motorD1 = 11;
int motorD2 = 12;
bool interruptorPulsado = false;
byte velocidad = 160;

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
  if (interruptorPulsado == false) //Si la variable no es false esto se omite.
  {
    while (digitalRead(interruptor) == HIGH && interruptorPulsado == false)
    {
        //No se ejecuta nada en bucle hasta que pulsamos el interruptor.
    }
    for (int i=0; i<3; i++) //Parpadeamos un led para anunciar al usuario de que se va a iniciar el dispositivo.
    {
      digitalWrite(ledEncendido, HIGH);
      delay(500);
      digitalWrite(ledEncendido, LOW);
      delay(500);
    }
    interruptorPulsado = true; //Cambiamos el estado de la variable para que al volver a empezar el loop no se ejecute.
  }
  digitalWrite(ledEncendido, HIGH);
  rotate(1);
}



void rotate(int direction) //Parámetro para indicar hacia donde queremos que giren los motores.
{ //Empezamos con los motores quietos.
  
   digitalWrite(motorD1, 0);
    digitalWrite(motorD2, velocidad);
    digitalWrite(motorI1, 0);
    digitalWrite(motorI2, velocidad);
  
  if(direction == 1)
  { //Se cambia la dirección del motor. En este caso para girar hacia adelante.
    digitalWrite(motorD1, 0);
    digitalWrite(motorD2, velocidad);
    digitalWrite(motorI1, 0);
    digitalWrite(motorI2, velocidad);
  }

  else if (direction == 2)
  { //Se cambia la dirección del motor. En este caso para que gire marcha atrás.
    digitalWrite(motorD1, velocidad);
    digitalWrite(motorD2, 0);
    digitalWrite(motorI1, velocidad);
    digitalWrite(motorI2, 0);
  }

  else if (direction == 3)
  { //Se cambia la dirección del motor. En este caso para que gire a la izquierda.
    digitalWrite(motorD1, velocidad);
    digitalWrite(motorD2, 0);
    digitalWrite(motorI1, 0);
    digitalWrite(motorI2, velocidad);
  }

  else if (direction == 4)
  { //Se cambia la dirección del motor. En este caso para que gire a la derecha.
    digitalWrite(motorD1, 0);
    digitalWrite(motorD2, velocidad);
    digitalWrite(motorI1, velocidad);
    digitalWrite(motorI2, 0);
  }

  else if (direction == 0)
  { //Se cambia la dirección del motor. En este caso para que este parado.
    digitalWrite(motorD1, 0);
    digitalWrite(motorD2, 0);
    digitalWrite(motorI1, 0);
    digitalWrite(motorI2, 0);
  }
}
