#include <DS3231.h>
#include <TM1637Display.h>
// Display pins
#define CLK 9
#define DIO 28
// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

//water sensor pin
int waterPin = 33;
//esp pin
const int espPin = 32;
//relay pins
const int relayPin = 10;
//button pins
int but1Pin = 31;
int but2Pin = 30;
int CupButton = 45;

//water sensor variables
unsigned long duration = 10000;
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
  
  //sets relay pins
  pinMode(relayPin, OUTPUT);
  //sets waterSensorPins
  pinMode(waterPin, INPUT);
  //sets buttons pins
  pinMode(but1Pin, INPUT);
  pinMode(but2Pin, INPUT);
  pinMode(CupButton, INPUT);
  //sets espPin
  pinMode(espPin, INPUT);
  //sets default value to off to relays
  digitalWrite(relayPin, LOW);
  // Clear the display:
  display.clear();
  // The following lines can be uncommented to set the date and time
  rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(17, 05, 00);     // Set the time to 12:00:00 (24hr format)
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
    if(digitalRead(CupButton) == HIGH){
      delay(2000);
      if(digitalRead(CupButton) == HIGH){
        digitalWrite(relayPin, HIGH);
        duration = pulseIn(waterPin, HIGH);
        Serial.println("I am making cofee!!!");
        while(duration <= 900){
          duration = pulseIn(waterPin, HIGH);
          Serial.println(duration);
        }
        digitalWrite(relayPin, LOW);  
        int seconds_counter = 0;
        while(digitalRead(CupButton) == HIGH){
          delay(1000);
          seconds_counter++;
          if(seconds_counter == 10){
            Serial.println("Your coffee will get cold!");
          }
          if(seconds_counter == 20){
            Serial.println("Why did I make this coffee!");
          }
          if(seconds_counter >= 30){
            Serial.println("Take your coffee!");
            delay(1000);
          }
        }
      }
      
      
    }
  }
  


  
  // Wait one second before repeating :)
  //delay (1000);
}
