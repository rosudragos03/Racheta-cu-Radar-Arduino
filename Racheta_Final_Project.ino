// DEFINIRE PINI MOTOR A
const int ENA  = 25;  // PWM pentru viteza motor A
const int IN1  = 12;
const int IN2  = 14;

// DEFINIRE PINI MOTOR B
const int ENB  = 33;  // PWM pentru viteza motor B
const int IN3  = 27;
const int IN4  = 26;

void setup() {
  // Direcție motoare
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // PWM pinii
  ledcSetup(0, 1000, 8);  // canal 0, frecvență 1kHz, rezoluție 8-bit
  ledcAttachPin(ENA, 0);  // ENA pe canal 0

  ledcSetup(1, 1000, 8);
  ledcAttachPin(ENB, 1);  // ENB pe canal 1
}

void loop() {
  // Merge ÎNAINTE
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  ledcWrite(0, 200); // Viteza motor A (0-255)
  ledcWrite(1, 200); // Viteza motor B

  delay(2000); // 2 secunde înainte

  // STOP
  ledcWrite(0, 0);
  ledcWrite(1, 0);

  delay(1000); // Pauză 1 secundă

  // Merge ÎNAPOI
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  ledcWrite(0, 180);
  ledcWrite(1, 180);

  delay(2000); // 2 secunde înapoi

  // STOP
  ledcWrite(0, 0);
  ledcWrite(1, 0);

  delay(2000); // Pauză
}

