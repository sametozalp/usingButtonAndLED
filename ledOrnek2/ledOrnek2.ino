byte pins[8] = {D0,D1,D2,D3,D4,D5,D6,D7};
int sayac = 0;
void setup() {
  delay(2000);
  Serial.begin(9600); // seri portu başlat
  Serial.println("Merhaba");
  for(int i = 0; i<7; i++){
    pinMode(pins[i], OUTPUT); // tüm ledler çıkış ayarlandı
    digitalWrite(pins[i], LOW); // tüm ledleri söndür
  }
  pinMode(D8, INPUT); // D8'e bağlı butonun pini giriş oldu
}

void loop() {
  // butona basıldı mı kontrol
  if(digitalRead(D8) == HIGH) {
    for(int i = 0; i<8; i++) {
      sayac++;
      digitalWrite(pins[i], HIGH);  
    }  
  } else {
     for(int i = 0; i<8; i++) {
      digitalWrite(pins[i], LOW);  
    }  
  }
  Serial.println(sayac);
  delay(250); // 250 ms bekle
}
