/* 
 * Project MP3 Player Test
 * Author: Brian Rashap
 * Date: 10-APR-2024
 */

 #include "Particle.h"
 #include "DFRobotDFPlayerMini.h"
 #include "Button.h"
 
 DFRobotDFPlayerMini myDFPlayerVoice;
 DFRobotDFPlayerMini myDFPlayerInstru;
 Button nextButton(D0);
 unsigned int lastSong;
 
 SYSTEM_MODE(SEMI_AUTOMATIC);
 
 void setup() {
 
   Serial.begin(9600);
   waitFor(Serial.isConnected,10000);
   Serial1.begin(9600);
   Serial3.begin(9600);
   delay(1000);
 
   Serial.printf("DFRobot DFPlayer Mini Demo\n");
   Serial.printf("Initializing DFPlayer ... (May take 3~5 seconds)\n");
   
   if (!myDFPlayerVoice.begin(Serial1)) {  //Use softwareSerial to communicate with mp3.
     Serial.printf("Unable to start Voice:\n");
     Serial.printf("1.Please recheck the connection!\n");
     Serial.printf("2.Please insert the SD card!\n");
   }
   else {
    Serial.printf("Voice Ready to Go\n");
   }

   if (!myDFPlayerInstru.begin(Serial3)) {  //Use softwareSerial to communicate with mp3.
    Serial.printf("Unable to start Instrumental:\n");
    Serial.printf("1.Please recheck the connection!\n");
    Serial.printf("2.Please insert the SD card!\n");
  }
  else {
    Serial.printf("Instrumental Ready to Go\n");
   }
   
   myDFPlayerVoice.volume(30);  //Set volume value. From 0 to 30
   myDFPlayerVoice.loop(1);  //Play the first mp3
   myDFPlayerVoice.enableLoopAll();

   myDFPlayerInstru.volume(30);  //Set volume value. From 0 to 30
   myDFPlayerInstru.loop(1);  //Play the first mp3
   myDFPlayerInstru.enableLoopAll();

 }
 
 void loop() {
   if(nextButton.isClicked()) {
     Serial.printf("Next Song\n");
     myDFPlayerVoice.next();
     myDFPlayerInstru.next(); 
   }
 }
 