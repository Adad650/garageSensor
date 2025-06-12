const int trigPin = 12;
const int echoPin = 11;
const int pin1 = 4;
const int pin2 = 5;
const int pin3 = 6;


int lastCategory = 0;     
bool timedOut = false;
unsigned long ledOnTime = 0;
const unsigned long timeout = 30000;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  int distanceInt = (int)distance;
  Serial.print("Distance: ");
  Serial.print(distanceInt);
  Serial.println(" cm");

  int status;
  if (distanceInt < 60)       status = 1;
  else if (distanceInt <= 100) status = 2;
  else                         status = 3;

  unsigned long now = millis();

  if (status != lastCategory) {
    timedOut    = false;
    ledOnTime   = now;
    lastCategory = status;
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    if (status == 1) digitalWrite(pin1, HIGH);
    if (status == 2) digitalWrite(pin2, HIGH);
    if (status == 3) digitalWrite(pin3, HIGH);
  }
  else {
    if (!timedOut && ((now - ledOnTime) >= timeout)) {
      
      timedOut = true;
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
    }

  }

  delay(250);
}
