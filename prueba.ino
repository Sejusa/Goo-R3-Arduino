int ledEncendido = 2;
int echoSensor = 4;
int triggerSensor = 7;
int interruptor = 8;
bool interruptorPulsado = false;

void setup() 
{
  pinMode(triggerSensor, OUTPUT);
  pinMode(echoSensor, INPUT);
  pinMode(interruptor, INPUT);
  pinMode(ledEncendido, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledEncendido, LOW);
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
  medirDistancia();
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
}