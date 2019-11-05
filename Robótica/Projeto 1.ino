#define dirAPin 7
#define dirBPin 8
#define SEsq A1 //sensor esq
#define SDir A0 //sensor d
#define rodaEsq 6
#define rodaDir 5
int maxMotor = 100; // Pode mudar até 120
int minMotor = 0;
int LIMIAR = 750;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(5,OUTPUT); /* Motor */
    pinMode(6,OUTPUT); /* Motor */
    pinMode(rodaEsq,OUTPUT); /* Roda direita */
    pinMode(rodaDir,OUTPUT); /* Roda esquerda */
    pinMode(SDir,INPUT); /*Sensor direita*/
    pinMode(SEsq,INPUT); /*Sensor esquerda*/
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    //pinMode(dirAPin,OUTPUT);
    //pinMode(dirBPin,OUTPUT);
    //digitalWrite(dirAPin,LOW);
    //digitalWrite(dirBPin,LOW);
    analogWrite(rodaEsq, 255);
    analogWrite(rodaDir, 255);

    delay(10); // Ou (50)
}

void loop() {

  //analogWrite(rodaEsq, 100);
  //analogWrite(rodaDir, 120);
  Serial.print("Sensor dir.: ");
  Serial.print(analogRead(SEsq));
  Serial.print(" | Sensor esq.: ");
  Serial.println(analogRead(SDir));

  if(analogRead(SEsq)<LIMIAR && analogRead(SDir)<LIMIAR){ //se os 2 tiver no branco
    analogWrite(rodaEsq, maxMotor);
    analogWrite(rodaDir, maxMotor);
  } else if (analogRead(SEsq)>LIMIAR){ //carrinho vai pra direita
      analogWrite(rodaDir, maxMotor);
      analogWrite(rodaEsq, minMotor);
  } else if (analogRead(SDir)>LIMIAR){ //carrinho vai pra esquerda
      analogWrite(rodaEsq, maxMotor);
      analogWrite(rodaDir, minMotor);
  }
 
  delay(5);
}