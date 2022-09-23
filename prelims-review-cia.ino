int LEDs[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
int lenled = sizeof(LEDs)/sizeof(int);

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  
  for (int i = 0; i <= lenled; i++)
  {
    pinMode(LEDs[i], OUTPUT);
  }
  
}

void mode1(){
  for (int r=0, l= lenled; r <= (lenled/2)-1; r++, l--){
    delay(100);
    digitalWrite(LEDs[r],HIGH);
    digitalWrite(LEDs[l-1], HIGH);
    delay(100);
  }

  if ((lenled % 2) == 1) {
    digitalWrite(LEDs[lenled/2], HIGH);
    delay(100);
    digitalWrite(LEDs[lenled/2], LOW);
  }

  for (int r= (lenled/2)-1, l= (lenled/2); l <= lenled; r--, l++){
    delay(100);
    if ((lenled % 2) == 0){
      digitalWrite(LEDs[l], LOW);
      digitalWrite(LEDs[r], LOW);
    }
    else{
      digitalWrite(LEDs[l+1], LOW);
      digitalWrite(LEDs[r], LOW);
    }
    delay(100);
  }

}

void mode2(){
  for (int n =0; n <= lenled; n++){
    delay(100);
    digitalWrite(LEDs[n], HIGH);
  }
  for (int n =0; n <= lenled; n++){
    delay(100);
    digitalWrite(LEDs[n], LOW);
  }
}

void mode3(){
  for (int n =0; n <= lenled; n++){
    delay(100);
    digitalWrite(LEDs[n], HIGH);
  }
  for (int n =0; n <= lenled-2; n++){
    delay(100);
    digitalWrite(LEDs[n], LOW);
  }
  for (int n= lenled-1; n>=0; n--){
    delay(100);
    digitalWrite(LEDs[n],HIGH);
  }
  for (int n= lenled-1; n>=1; n--){
    delay(100);
    digitalWrite(LEDs[n],LOW);
  }
}

void mode4(){
  int shrinkingArr = sizeof(LEDs)/sizeof(int);

  while (shrinkingArr != 0){
    for (int n =0; n <= shrinkingArr-1; n++){
      delay(100);
      digitalWrite(LEDs[n], HIGH);
      delay(500);
      digitalWrite(LEDs[n], LOW);
    }

    shrinkingArr--;
    digitalWrite(LEDs[shrinkingArr], HIGH);
  }
  turnoff();
}

void mode5() {
  for (int n=0; n <= lenled; n++){
    if ((LEDs[n] % 2) == 0){
      digitalWrite(LEDs[n], HIGH);
    }
  }
  delay(500);
  turnoff();
  for (int n=0; n <= lenled; n++){
    if ((LEDs[n] % 2) == 1){
      digitalWrite(LEDs[n], HIGH);
    }
  }
  delay(500);
  turnoff();
}

void mode6(){
  for (int n=0; n<=(lenled/2)-1;n++){
    digitalWrite(LEDs[n],HIGH);
  }
  delay(500);
  turnoff();
  delay(50);
  for (int n=lenled-1; n > (lenled/2)-1; n-- ){
    digitalWrite(LEDs[n],HIGH);
  }
  delay(500);
  turnoff();
  delay(50);
}

void turnoff(){
  for (int n =0; n <= lenled; n++){
    digitalWrite(LEDs[n], LOW);
  }
}

void loop() {


  int D1 = digitalRead(A0);
  int D2 = digitalRead(A1);
  int D3 = digitalRead(A2);
  int D4 = digitalRead(A3);1

  
  if ((D1 == 1) && (D2 == 0) && (D3 == 0) && (D4 == 0)) {
    mode1();
  }
  else if ((D1 == 0) && (D2 == 1) && (D3 == 0) && (D4 == 0)) {
    mode2();
  }
  else if ((D1 == 0) && (D2 == 0) && (D3 == 1) && (D4 == 0)) {
    mode3();
  }
  else if ((D1 == 0) && (D2 == 0) && (D3 == 0) && (D4 == 1)) {
    mode4();
  }
  else if ((D1 == 1) && (D2 == 1) && (D3 == 0) && (D4 == 0)) {
    mode5();
  }
  else if ((D1 == 0) && (D2 == 0) && (D3 == 1) && (D4 == 1)) {
    mode6();
  }
  else {
    turnoff();
  }
}