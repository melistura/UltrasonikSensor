int trigPin = 9; //Trigger (tetikleyici) pinini tanımlıyoruz.
int echoPin = 10; //Echo pini tanımlıyoruz.

long zaman; //zaman uzun bir tam sayı olacağında long değişkeni olarak tanımlıyoruz.
long mesafe; //mesafe uzun bir tam sayı olacağında long değişkeni olarak tanımlıyoruz.

void setup() {
  pinMode(trigPin, OUTPUT); //Tetikleyici çıkış birimidir. Ultrasonik ses gönderir. 
  pinMode(echoPin, INPUT); //Yansıyan sinyalin geri dönüp giriş yaptığı birimdir. Echo giriş birimidir. 
  Serial.begin(9600); //Seri port haberleşme hızı (varsayılan)
}

void loop(){
  digitalWrite(trigPin, LOW); //Sensör sıfırlandı (önceden açık kalma ihtimaline karşı)
  delayMicroseconds(5); //milisaniyeden daha küçük değer vermek için kullanıyoruz. 
  digitalWrite(trigPin, HIGH); //Ses dalgasının üretilmesi için tetikleyiciyi açıyoruz.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //Ses dalgasını gönderdikten sonra tetikleyiciyi kapatıyoruz.
  zaman = pulseIn(echoPin, HIGH); //ses dalgasının geri dönüş süresini ölçmek için 
  mesafe = (zaman / 29.1)/2 ; //zaman değişkeni ile ölçülen süreyi mesafeye çevirmek için gereken matematiksel işlem yapılıyor.
  Serial.print("Uzaklik "); //seri port ekranına mesafe değişkeni yazdırılıyor
  Serial.print(mesafe);
  Serial.println(" cm");
  delay(500);
}
