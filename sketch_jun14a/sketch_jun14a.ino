const int trigpin = 9;
const int echopin = 10;
float duration, distance;
int LEDpin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  duration = pulseIn(echopin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 30) {
    digitalWrite(LEDpin, HIGH);
    delay(200);
    digitalWrite(LEDpin, LOW);
    delay(200);
  } else {
    digitalWrite(LEDpin, LOW);
  }

  delay(1000);
}
