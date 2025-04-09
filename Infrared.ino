#include <Servo.h>

Servo myservo;

// --- Pin Definitions ---
const int sensorPin = 2;    // Sensor infrared terhubung ke pin digital 2
const int servoPin = 3;     // Servo terhubung ke pin digital 3 (PWM)

// --- Status Variables ---
bool isDispensing = false;

void setup() {
  // Inisialisasi servo
  myservo.attach(servoPin);          // Hubungkan servo ke pin PWM
  myservo.write(0);                  // Posisi awal servo

  // Inisialisasi pin sensor infrared
  pinMode(sensorPin, INPUT_PULLUP);  // Sensor IR aktif LOW, gunakan internal pull-up resistor
}

void loop() {
  // Baca status dari sensor infrared
  int sensorValue = digitalRead(sensorPin);

  if (sensorValue == LOW && !isDispensing) {  // Objek terdeteksi
    isDispensing = true;

    // Aktifkan dispenser (putar servo)
    myservo.write(90);     // Putar servo ke 90 derajat (posisi buka)
    delay(1000);           // Tunggu 1 detik
    myservo.write(0);      // Kembali ke posisi awal
    delay(1000);           // Delay untuk mencegah pembacaan berulang
  }

  if (sensorValue == HIGH) {
    isDispensing = false;  // Reset status jika tidak ada objek
  }
}
