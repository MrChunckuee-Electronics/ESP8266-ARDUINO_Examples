/*******************************************************************************
 *
 *                  Brightness LED test
 *
 *******************************************************************************
 * FileName:        ESP8266_001.ino
 * Processor:       NodeMCU ESP8266 Development Kit V1.0
 * Biblioteca:      esp8266 by ESP8266 Community v2.5.2
 * Complier:        Arduino v1.8.9
 * Author:          Arduining
 * Description:     Going beyond Blink sketch to see the blue LED breathing.
 *                  A PWM modulation is made in software because GPIO16 can't
 *                  be used with analogWrite().
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      22/09/2019      Testing firmware by MrChunckuee
 ******************************************************************************/

#define LED     D0        // Led in NodeMCU at pin GPIO16 (D0).
 
#define BRIGHT    350     //max led intensity (1-500)
#define INHALE    1250    //Inhalation time in milliseconds.
#define PULSE     INHALE*1000/BRIGHT
#define REST      1000    //Rest Between Inhalations.

void setup() {                
  pinMode(LED, OUTPUT);   // LED pin as output.    
}

void loop() {
  //ramp increasing intensity, Inhalation: 
  for (int i=1; i<BRIGHT; i++){
    digitalWrite(LED, LOW);          // turn the LED on.
    delayMicroseconds(i*10);         // wait
    digitalWrite(LED, HIGH);         // turn the LED off.
    delayMicroseconds(PULSE-i*10);   // wait
    delay(0);                        //to prevent watchdog firing.
  }
  //ramp decreasing intensity, Exhalation (half time):
  for (int i=BRIGHT-1; i>0; i--){
    digitalWrite(LED, LOW);          // turn the LED on.
    delayMicroseconds(i*10);          // wait
    digitalWrite(LED, HIGH);         // turn the LED off.
    delayMicroseconds(PULSE-i*10);  // wait
    i--;
    delay(0);                        //to prevent watchdog firing.
  }
  delay(REST);                       //take a rest...
}
