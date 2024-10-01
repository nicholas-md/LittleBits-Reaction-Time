const int ledPin = 1;
const int win1Pin = 5; 
const int win2Pin = 9;
 
const int button1Pin = A0;
const int button2Pin = A1;

const int slidePin = 0;

unsigned long RandomDelay;

bool RoundActive = false;

int sliderValue = 0;

void setup() {
  
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(slidePin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(win1Pin, OUTPUT);
  pinMode(win2Pin, OUTPUT);

  Serial.begin(9600);


}

void loop() {


sliderValue = digitalRead(slidePin);

if (sliderValue == HIGH) {

  if (RoundActive) {

  if (digitalRead(button1Pin) == HIGH) {
    displayWinner(1);
    }

    else if (digitalRead(button2Pin) == HIGH) {
      displayWinner(2);
    }

  }

else  {
  startNewRound();
}
}
}


void startNewRound() {
  RoundActive = false;

    digitalWrite(win1Pin, LOW);
    digitalWrite(win2Pin, LOW);
    digitalWrite(ledPin, LOW);

    RandomDelay = random(500, 4000);

    delay(RandomDelay);
    digitalWrite(ledPin, HIGH);

    RoundActive = true;


}

  void displayWinner(int player) {
    RoundActive = false;
    digitalWrite(win1Pin, LOW);
    digitalWrite(win2Pin, LOW);
    digitalWrite(ledPin, LOW);


    if (player == 1) {
    for(int i=0; i<10; i++) {
      player1win();

    }

  }  else if (player == 2) {
    for(int i=0; i<10; i++) {

      player2win();

    }
  }
    delay(1000);

  }

  void player1win(){
  digitalWrite(win1Pin, HIGH);
  delay(100);
  digitalWrite(win1Pin, LOW);
  delay(100);

  }

    void player2win(){
  digitalWrite(win2Pin, HIGH);
  delay(100);
  digitalWrite(win2Pin, LOW);
  delay(100);

  }


  







