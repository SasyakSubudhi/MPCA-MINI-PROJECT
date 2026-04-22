int trigPin = 6;
int echoPin = 7;

int gasPin = A0;
int flamePin = 4;

int buzzer = 8;
int led = 9;

int gasThreshold = 300;
int distanceThreshold = 10; // cm

long duration;
int distance;

// 🔊 Buzzer patterns
void buzzIntrusion() {
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
}

void buzzGas() {
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
  delay(300);
}

void buzzFlame() {
  digitalWrite(buzzer, HIGH); // continuous alarm
}

// 📏 Distance function
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(flamePin, INPUT);   // make sure DO pin is used
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
  Serial.println("System Ready");
}

void loop() {

  int dist = getDistance();
  int gasValue = analogRead(gasPin);

  // 🔥 Flame detection (LOW = detected)
  bool flameDetected = false;
  if (digitalRead(flamePin) == LOW) {
    delay(50);
    if (digitalRead(flamePin) == LOW) {
      flameDetected = true;
    }
  }

  bool intrusionDetected = (dist > 0 && dist < distanceThreshold);
  bool gasDetected = (gasValue > gasThreshold);

  // 📟 Serial output
  Serial.print("Distance=");
  Serial.print(dist);
  Serial.print(" Gas=");
  Serial.print(gasValue);
  Serial.print(" Flame=");
  Serial.println(flameDetected);

  // 🚨 Alert logic (priority: Flame > Gas > Intrusion)
  if (flameDetected) {
    digitalWrite(led, HIGH);
    buzzFlame();
  }
  else if (gasDetected) {
    digitalWrite(led, HIGH);
    buzzGas();
  }
  else if (intrusionDetected) {
    digitalWrite(led, HIGH);
    buzzIntrusion();
  }
  else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(50); // small delay for stability
}