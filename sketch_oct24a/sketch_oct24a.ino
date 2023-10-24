byte pins[4] = {D1,D2,D3,D4};
void setup() {
  for(int i = 0; i<4; i++){
    pinMode(pins[i], OUTPUT);
  }
  pinMode(D5, INPUT); // D5'e bağlı butonun pini giriş oldu
  pinMode(D0, OUTPUT); // D0'a bağlı ledin pinini çıkış yap
  digitalWrite(D0, LOW);
}

void loop() {
  // butona basıldı mı kontrol
  if(digitalRead(D5) == HIGH) {
    digitalWrite(D0, HIGH);
  } else {
    digitalWrite(D0, LOW);
  }
}
