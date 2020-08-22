/* Rajkumar Hiteshbhai Dave
 *  200413300
 *  Final project code
 *  Hand Sanitizer Machine
 *  
 *  The code is meant to take reading from the ultrasonic sensor
 *  Evaluate the value
 *  Control the motor for dispensing sanitizer
*/

/*Declaring GPIO pins for input and output*/

/* Trigger pin of the ultrasonic sensor*/
int Trigger_pin = 9; 

/*Echo pin of the ultrasonic sensor
basically output pin of the sensor*/
int Echo_pin = 10;

/*Pin 13 is connected to the relay switch which controls the motor*/
int Motor = 13; 

/*Proximity is the distance oMotorf nearest object from the sensor
 * Time duration is the time taken for the ultrasonic waves to 
 * hit an object and return back to the sensor 
 */
int proximity,time_dur;

void setup() {
  pinMode(Trigger_pin, OUTPUT); 
  pinMode(Echo_pin, INPUT); 
  pinMode(Motor, OUTPUT); 
  Serial.begin(9600); 
}
void loop() {

/*Procedure to get the reading of Ultrasonic sensor*/

  /* Toggling the Trigger pin to activate the sensor, 
   *  turning it off, then on and again off.
   */
  digitalWrite(Trigger_pin, LOW); /*Trigger pin off*/
  delay(200);
  digitalWrite(Trigger_pin, HIGH);/*Trigger pin on*/
  delay(200);
  digitalWrite(Trigger_pin, LOW);/*Trigger pin off*/

 /*Reading from the echo pin, taking the pulse in*/
  time_dur = pulseIn(Echo_pin, HIGH);

  /*Converting the time into proximity*/
  proximity = time_dur*0.034/2;

  Serial.print("\nDistance: ");
  Serial.println(proximity);

  /*If the distance is less than 3,
   * turn the motor on for 1.5 second, then turn off.
   * Also if the hand goes away then the 
   * motor is turned off.
   */
  if(proximity < 3)  
  {
    digitalWrite(Motor,HIGH); /*starting sanitizer supply*/
    delay(1500);
    digitalWrite(Motor,LOW);/*stop sanitizer supply*/
  }
  else 
  {
    digitalWrite(Motor,LOW);/*stop sanitizer supply*/
  }
}
