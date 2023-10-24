byte pins[8] = {D0,D1,D2,D3,D4,D5,D6,D7};
void setup() {
  for(int i = 0; i<8; i++){
    pinMode(pins[i], OUTPUT); // tüm ledler çıkış ayarlandı
    digitalWrite(pins[i], LOW); // tüm ledleri söndür
  }
  pinMode(D8, INPUT); // D8'e bağlı butonun pini giriş oldu
}

void loop() {
  // butona basıldı mı kontrol
  if(digitalRead(D8) == HIGH) {
    for(int i = 0; i<8; i++) {
      digitalWrite(pins[i], !digitalRead(pins[i])); // toggle işlemi ??
    }   
  }
  delay(250); // 250 ms bekle
}
