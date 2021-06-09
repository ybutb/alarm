// Define connection pins:
#define datchik 2
#define siniu 13
#define krasniu 12
#define jeltiu 11
#define zeleniu 10


// Create variables:
int val = 0;
bool motionState = false; // We start with no motion detected.

void setup() {
  // Configure the pins as input or output:
  pinMode(siniu, OUTPUT);
  pinMode(krasniu, OUTPUT);
  pinMode(jeltiu, OUTPUT);
  pinMode(zeleniu, OUTPUT);

  pinMode(datchik, INPUT);

  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Read out the pirPin and store as val:
  val = digitalRead(datchik);
  // If motion is detected (pirPin = HIGH), do the following:
  if (val == HIGH) {
    digitalWrite(siniu, HIGH); // Turn on the on-board LED.
    delay(1000);
    digitalWrite(krasniu, HIGH); // Turn on the on-board LED.
    delay(1000);
    digitalWrite(jeltiu, HIGH); // Turn on the on-board LED.
    delay(1000);
    digitalWrite(zeleniu, HIGH); // Turn on the on-board LED.
    delay(1000);
    digitalWrite(zeleniu, LOW); // Turn on the on-board LED.
    delay(1000);
    digitalWrite(jeltiu, LOW); // Turn on the on-board LED.
    delay(1000);
    digitalWrite(krasniu, LOW); // Turn on the on-board LED.
    delay(1000);
    digitalWrite(siniu, LOW); // Turn on the on-board LED.
    delay(1000);


    // Change the motion state to true (motion detected):
    if (motionState == false) {
      Serial.println("Motion detected!");
      motionState = true;
    }
  }
  // If no motion is detected (pirPin = LOW), do the following:
  else {
digitalWrite(zeleniu, LOW); // Turn on the on-board LED.
    delay(1000);
    digitalWrite(jeltiu, LOW); // Turn on the on-board LED.
    digitalWrite(krasniu, LOW); // Turn on the on-board LED.
    digitalWrite(siniu, LOW); // Turn on the on-board LED.
    delay(1000);

    // Change the motion state to false (no motion):
    if (motionState == true) {
      Serial.println("Motion ended!");
      motionState = false;
    }
  }

}
