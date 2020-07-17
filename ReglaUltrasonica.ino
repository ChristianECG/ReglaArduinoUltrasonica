int echo_regla=4;
int trigger_regla=7;
int temp=0;

void setup(){
  Serial.begin(9600);
  pinMode(trigger_regla,OUTPUT);
  pinMode(echo_regla,INPUT);
  digitalWrite(trigger_regla, LOW);
}

void loop(){
  long t,d;
  digitalWrite(trigger_regla, HIGH);
  delayMicroseconds(10);      //Enviamos un pulso de 10us
  digitalWrite(trigger_regla, LOW);
  t = pulseIn(echo_regla, HIGH); //obtenemos el ancho del pulso
  d = t/59;

  //Serial.println(Serial.available());
  
  //if (Serial.available())
  //{
    //char dato=Serial.read();
    if(temp!=d){
      ejecucion(d);
      temp=d;
    }
  //}
  delay(100);
}

void ejecucion(long c){
  Serial.print(c);
  Serial.print(" cm.");
  Serial.println();
}
