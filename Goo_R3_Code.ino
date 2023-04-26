//Proyecto Arduino Goo R3
// Hecho por Sergi Funes, Marcos Cobos y Cristhian Rodríguez

//int interruptor = 0;
int ledEncendido = 2;
int motorRuedaI = 6;
int triggerSensor = 7;
int echoSensor = 4;
int motor1I = 10;
int motor1D = 11;
int motor2I = 12;
int motor2D = 13;

void setup() 
{
  //pinMode(interruptor, INPUT);
  pinMode(ledEncendido, OUTPUT);
  pinMode(triggerSensor, OUTPUT);
  pinMode(echoSensor, INPUT);
  pinMode(motor1I, OUTPUT);
  pinMode(motor1D, OUTPUT);
  pinMode(motor2I, OUTPUT);
  pinMode(motor2D, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  /*while (digitalRead(interruptor) == HIGH)
  {
    digitalWrite(ledEncendido, HIGH);
    //digitalWrite(motorRuedaI, HIGH);*/
    medirDistancia(); 
    /*if (digitalRead(interruptor) == LOW)
    {
      digitalWrite(ledEncendido, LOW);
      digitalWrite(motor, LOW);
    }
  }*/
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

  if (distance < 100) //Si la distancia con el objeto es menor a 100.
  {
    rotate(1);
    Serial.println(distance);
  }
  else 
  {
    Serial.println(distance);
  }
}

void rotate(int direction) //Parámetro para indicar hacia donde queremos que giren los motores.
{
  bool inPin1I = LOW; //Esta variable y las de abajo se utilizan para controlar el motor.
  bool inPin1D = HIGH;
  bool inPin2I = LOW;
  bool inPin2D = HIGH;
  
  if(direction == 1)
  { //Se cambia la dirección del motor. En este caso para girar hacia la izquierda
    inPin1I = HIGH;
    inPin1D = LOW;
    inPin2I = HIGH;
    inPin2D = LOW;

    digitalWrite(motor1I, inPin1I);
    digitalWrite(motor1D, inPin1D);
    digitalWrite(motor2I, inPin2I);
    digitalWrite(motor2D, inPin2D);
  }

  else
  { //Se cambia la dirección del motor. En este casa para girar hacia la derecha.
    digitalWrite(motor1I, inPin1I);
    digitalWrite(motor1D, inPin1D);
    digitalWrite(motor2I, inPin2I);
    digitalWrite(motor2D, inPin2D);
  }
}

void move(int speed)
{
  
}
