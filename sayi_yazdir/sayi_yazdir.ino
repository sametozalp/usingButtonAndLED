byte pins[7] = {D1, D2, D3, D4, D5, D6, D7};
byte rakamlar[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7F, 0x6F};
//byte rakamlar[10] = {0b00111111, 0b...};
void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT); // tüm ledler çıkış ayarlandı
    digitalWrite(pins[i], LOW); // tüm ledleri söndür"
  }
}

void loop() {
  //harflendirme üstten başlar simetrik G şeklinde ilerler
  /*
     D7 => a
     D6 => b
     D5 => c
     D4 => d
     D3 => e
     D2 => f
     D1 => g
  */
  //**********1*********
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, LOW);

  //**********2*********
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(D5, LOW);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);

  /**********3**********/
  for (int i = 0; i < 10; i++) {
    byte deger = rakamlar[i];
    for (int j = 1 ; j < 8; j++) {
      deger = deger >> 1;
      int kontrol = deger & 0b00000001;
      if (kontrol == 1) {
        digitalWrite(pins[j - 1], HIGH);
      } else {
        digitalWrite(pins[j - 1], LOW);
      }
    }
    delay(500);
  }
}
