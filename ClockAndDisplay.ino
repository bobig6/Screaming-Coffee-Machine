#include <DS3231.h>
#include <TM1637Display.h>
// Display pins
#define CLK 9
#define DIO 28
// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
//esp pin
const int espPin = 32;
// ultrasonic pins
const int trigPin = 3;
const int echoPin = 2;
//relay pins
const int relayPin = 10;
// defines variables for sensors
long duration;
int distance;
//button pins
int but1Pin = 30;
int but2Pin = 31;
//button variables
int buttonPushCounter1 = 0;   // counter for the number of button presses
int buttonState1 = 0;         // current state of the button
int lastButtonState1 = 0;     // previous state of the button

int buttonPushCounter2 = 0;   // counter for the number of button presses
int buttonState2 = 0;         // current state of the button
int lastButtonState2 = 0;     // previous state of the button
//clock time
int timerHours = 17;
int timerMinutes = 0;
void setup()
{
  // Setup Serial connection
  Serial.begin(115200);
  
  // IStarts the clock module
  rtc.begin();
  
  //sets sensor pins
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  //sets relay pins
  pinMode(relayPin, OUTPUT);
  //sets buttons pins
  pinMode(but1Pin, INPUT);
  pinMode(but2Pin, INPUT);
  //sets espPin
  pinMode(espPin, INPUT);
  //sets default value to off to relays
  digitalWrite(relayPin, HIGH);
  // Clear the display:
  display.clear();
  // The following lines can be uncommented to set the date and time
  rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(17, 00, 00);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(29, 12, 2019);   // Set the date to January 1st, 2014
}

void loop()
{
  // Set the brightness:
  display.setBrightness(7);


  
  //divide by ":" to get the time in int
  char *buf = rtc.getTimeStr();
  int i = 0;
  char *p = strtok (buf, ":");
  char *arr[3];
  while (p != NULL)
  {
      arr[i++] = p;
      p = strtok (NULL, ":");
  }
  //set hours and minutes
  int hours = atoi(arr[0]);
  int minutes = atoi(arr[1]);   


  // Print time on serial monitor just in case
  Serial.println(rtc.getTimeStr());
  //hours = hours*100 + minutes;


  //calculate distance on sensor 1
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

/*
 * TEST 1
  // Print 1234 with the center colon:
  display.showNumberDecEx(hours, 0b11100000, false, 4, 0);


  if(distance <= 5 && hours >= 1505){
      digitalWrite(relayPin, LOW);
  }else if(distance > 5 && hours >= 1505){
      digitalWrite(relayPin, HIGH);
  }
*/ 

  //Button1 timer++
  buttonState1 = digitalRead(but1Pin);
  if (buttonState1 != lastButtonState1) {
    if (buttonState1 == HIGH) {
      timerMinutes++;
      if(timerMinutes >= 60){
        timerMinutes = 0;
        timerHours++;
        if(timerHours >= 24){
          timerHours = 0;
        }
      }
    } 
    delay(50);
  }
  lastButtonState1 = buttonState1;

  //Button2 timer--
  buttonState2 = digitalRead(but2Pin);
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      timerMinutes--;
      if(timerMinutes < 0){
        timerMinutes = 59;
        timerHours--;
        if(timerHours < 0){
          timerHours = 23;
        }
      }
    } 
    delay(50);
  }
  lastButtonState2 = buttonState2;
  
  int timerOnDisplay = timerHours*100 + timerMinutes;
  display.showNumberDecEx(timerOnDisplay, 0b11100000, false, 4, 0);
  
  //logic
  if((hours == timerHours && minutes == timerMinutes) || (digitalRead(espPin) == HIGH)){
    if(distance <= 5){
      digitalWrite(relayPin, LOW);
      Serial.println("I am making cofee!!!");
      delay(5000);
      digitalWrite(relayPin, HIGH);  
    }
  }
  


  
  // Wait one second before repeating :)
  //delay (1000);
}
/*
//Not implemented function for fast count if held
int Pushbutton(){
  if (millis() - buttontimeout >20){   //only read the analog line every 20ms. I had problems reading it more frequently.
   buttontimeout = millis();
   leftbuttons = analogRead(A5);
   
    button = 0;
    if (leftbuttons <785 && leftbuttons>745) button = 1; //LH Button 1 is pushed
    if (leftbuttons <630 && leftbuttons>590) button = 2; //LH Button 2 is pushed
     
    if (button != oldbutton){
      oldbutton = button;
      if ( button !=0){
      repeatbutton = millis();
      return button; 
      }
    }
   
   

  if (millis()- repeatbutton > 500){
     repeatbutton = millis();
     return button;
     
   }
  }
}
*/
