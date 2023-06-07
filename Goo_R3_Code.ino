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
int distance;
int mover;

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
  mover = medirDistancia();
  
  if (mover < 10) //Si la distancia con el objeto es menor a 10.
  {
    digitalWrite(motorD1, HIGH);
    digitalWrite(motorD2, LOW);
    digitalWrite(motorI1, LOW);
    digitalWrite(motorI2, LOW);
  }

  else
  {
    digitalWrite(motorD1, HIGH);
    digitalWrite(motorD2, LOW);
    digitalWrite(motorI1, HIGH);
    digitalWrite(motorI2, LOW);
  }
  
  /*if (digitalRead(interruptor) == HIGH)
  {
    while(1)
    {
      //Se para el programa.
      if (digitalRead(interruptor) == HIGH)
      {
        break;
      }
    }
  }*/
}
   

int medirDistancia()
{
  digitalWrite(triggerSensor, LOW); //Nos aseguramos de que el sensor está en el estado correcto para empezar la medición.
  delayMicroseconds(2); //Esperamos 2 microsegundos.
  digitalWrite(triggerSensor, HIGH); //Empezamos a medir distáncia.
  delayMicroseconds(10); 
  digitalWrite(triggerSensor, LOW); //Dejamos de medir distáncia.
  long duration = pulseIn(echoSensor, HIGH); //Con "pulseIn" esperamos hasta que el pin "echo" sea "HIGH" y medimos cuanto tarda en volver a ser "LOW".
  distance = duration * 0.034 / 2; /*Calculamos la distáncia medida por el sensor en cm. Multiplicamos la duración del sonido entre 0,034(velocidad
                                         del sonido en el aire) entre 2(la ida y a vuelta)*/
  Serial.println(distance);
  return distance;
}
