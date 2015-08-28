
//Light Pins
const int teamOneLight = 00;
const int teamTwoLight = 00;
const int teamThreeLight = 00;
const int teamFourLight = 00;
const int teamFiveLight = 00;
const int teamSixLight = 00;
const int teamSevenLight = 00;
const int teamEightLight = 00;
const int teamNineLight = 00;
const int teamTenLight = 00;
const int masterLight = 00;

//Button Pins
const int teamOneButton = 00;
const int teamTwoButton = 00;
const int teamThreeButton = 00;
const int teamFourButton = 00;
const int teamFiveButton = 00;
const int teamSixButton = 00;
const int teamSevenButton = 00;
const int teamEightButton = 00;
const int teamNineButton = 00;
const int teamTenButton = 00;
const int masterButton = 00;

//Globals
int breakLoop = false;

void setup() {
  //Setup the lights
  pinMode(teamOneLight, OUTPUT);
  pinMode(teamTwoLight, OUTPUT);
  pinMode(teamThreeLight, OUTPUT);
  pinMode(teamFourLight, OUTPUT);
  pinMode(teamFiveLight, OUTPUT);
  pinMode(teamSixLight, OUTPUT);
  pinMode(teamSevenLight, OUTPUT);
  pinMode(teamEightLight, OUTPUT);
  pinMode(teamNineLight, OUTPUT);
  pinMode(teamTenLight, OUTPUT);
  pinMode(masterLight, OUTPUT);

  //Setup the buttons
  pinMode(teamOneButton, INPUT_PULLUP);
  pinMode(teamTwoButton, INPUT_PULLUP);
  pinMode(teamThreeButton, INPUT_PULLUP);
  pinMode(teamFourButton, INPUT_PULLUP);
  pinMode(teamFiveButton, INPUT_PULLUP);
  pinMode(teamSixButton, INPUT_PULLUP);
  pinMode(teamSevenButton, INPUT_PULLUP);
  pinMode(teamEightButton, INPUT_PULLUP);
  pinMode(teamNineButton, INPUT_PULLUP);
  pinMode(teamTenButton, INPUT_PULLUP);
  pinMode(masterButton, INPUT_PULLUP);
}

/*
 * TODO
 * What happens on the inital run? What is the state???
 * 
 */
void loop() {

  if ( breakLoop == false) {
    if (digitalRead(teamOneButton) == LOW) {
      playerSelected(teamOneLight);

    } else if (digitalRead(teamTwoButton) == LOW) {
      playerSelected(teamTwoLight);

    } else if (digitalRead(teamThreeButton) == LOW) {
      playerSelected(teamThreeLight);
    }
  }

  //master button was hit
  //read the master button to see if it should be reset
  if (digitalRead(masterButton) == HIGH) {
    //flash the main light
    //reset the master loop
    breakLoop = true;
    resetLights();
    digitalWrite(masterLight, HIGH);
    waitingForPlayer();
  }
}

void playerSelected(int pin) {
  breakLoop = true;
  resetLights();
  digitalWrite(masterLight, LOW);
  digitalWrite(pin, HIGH);
}

void waitingForPlayer() {
  int delayTime = 200;
  
  while(breakLoop == false ) {
    digitalWrite(teamOneLight, LOW);
    delay(delayTime);
    digitalWrite(teamOneLight, HIGH);

    digitalWrite(teamTwoLight, LOW);
    delay(delayTime);
    digitalWrite(teamTwoLight, HIGH);

    digitalWrite(teamThreeLight, LOW);
    delay(delayTime);
    digitalWrite(teamThreeLight, HIGH);

    digitalWrite(teamFourLight, LOW);
    delay(delayTime);
    digitalWrite(teamFourLight, HIGH);

    digitalWrite(teamFiveLight, LOW);
    delay(delayTime);
    digitalWrite(teamFiveLight, HIGH);

    digitalWrite(teamSixLight, LOW);
    delay(delayTime);
    digitalWrite(teamSixLight, HIGH);

    digitalWrite(teamSevenLight, LOW);
    delay(delayTime);
    digitalWrite(teamSevenLight, HIGH);

    digitalWrite(teamEightLight, LOW);
    delay(delayTime);
    digitalWrite(teamEightLight, HIGH);

    digitalWrite(teamNineLight, LOW);
    delay(delayTime);
    digitalWrite(teamNineLight, HIGH);

    digitalWrite(teamTenLight, LOW);
    delay(delayTime);
    digitalWrite(teamTenLight, HIGH);
  }
}

void resetLights() {
  digitalWrite(teamOneLight, LOW);
  digitalWrite(teamTwoLight, LOW);
  digitalWrite(teamThreeLight, LOW);
  digitalWrite(teamFourLight, LOW);
  digitalWrite(teamFiveLight, LOW);
  digitalWrite(teamSixLight, LOW);
  digitalWrite(teamSevenLight, LOW);
  digitalWrite(teamEightLight, LOW);
  digitalWrite(teamNineLight, LOW);
  digitalWrite(teamTenLight, LOW);
}
