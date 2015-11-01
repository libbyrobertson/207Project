/*
 Elizabeth Robertson
 This is based from my Lab 3 Exercise 2 Code
 I am changing most components to better suit my CS 207 project
 Oct 24 2015
 This is just a base
 Little knowledge about MIDI understood at this point
 */
// These numbers are constant
//All buttons set as Pull down
const int buttonPin1 = a; // location of first button (pull up button)
const int buttonPin2 = b; // location of the second push button pin
const int buttonPin3 = c;
const int buttonPin4 = d;
const int buttonPin5 = e;

const int switchPin1 = z;//pins for the switches
//not a lot of room on the arduino, this will be tough
const int switchPin2 = y;
const int switchPin3 = x;//lets try three switches for now


//const int ledPin1 =  13; // LED will potentially be added later
// int ledPin2 = 11;// LED will potentially be added later

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;//variable for second button
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

int switchState1 = 0;
int switchState2 = 0;
int switchState3 = 0;

void setup() {
  // initialize the LED pin as an output:
  //pinMode(ledPin1, OUTPUT);
  //pinMode(ledPin2, OUTPUT); //LED may be added later
  // initialize the pushbutton pins as input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);

  pinMode (switchPin1, INPUT);
  pinMode (switchPin2, INPUT);
  pinMode (switchPin3, INPUT);
}


void loop() 
{
//first check the state of the switches
  switchState1 = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);
  switchState3 = digitalRead(switchPin3);

  int musicState = 1;//declaring the variable for music state
  //initializing to 1 otherwise all buttons would play file 0
  //so different music can be played with the buttons depending which position the switch is on


  if(switchState1 == HIGH)//if the switch is turned to the one position
  //really not sure how MIDI files work but I'm guessing this is what will happen
  //assuming I can name the MIDI files?
  musicState = 1;

  if(switchState2 == HIGH)
  musicState = 2;

  if(switchState3 == HIGH)
  musicState = 3;


  
  buttonState1 = digitalRead(buttonPin1);//read the buttons
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);

  
  // check if the pushbutton is pressed.
  //pull down
  if (buttonState1 == HIGH)
  {
    for (int note = 0x1E; note < 0x5A; note == )
    {
      noteOn(0x90, note, 0x45);//45 is middle velocity
      delay(100)
      noteOn(0x90, note, 0x00);//silent velocity
      delay (100);
    }
  }

 
  //pull down button so HIGH is when the button is pressed
  if (buttonState2== HIGH)
  //so when the second button is pressed, no matter what else has happen
  {
    // MIDI file (2*musicState)

    //digitalWrite(ledPin1, LOW);//turn the first off
    //digitalWrite(ledPin2, HIGH); //turn the second on
  }

  if (buttonState3 == HIGH)
  {
    //Midi File (3*musicState)
  }

  if (buttonState4 == HIGH)
  {
   // Midi File (4*musicState)
  }

  if (buttonState5 == HIGH)
  {
    //Midi File (5*musicState)
  }

}
void noteOn(int cmd, int pitch, int velocity)
{
  serial.write (cmd);
  serial.wrtie(pitch);
  serial.write(velocity);//all this was accumulated from the arduino website
  //I take no credit
}

