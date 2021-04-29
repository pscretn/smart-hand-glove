
<img src="images/smart talk.gif" width="600"  />  <br><br>
# smart-hand-glove
Smart Talk for Sign language Translation is a work that aims to present an easy way of communication for speech impaired and hearing impaired people. Work consists
of a glove equipped with sensors which senses different sign language gestures. This data is fed to ESP32 which is then transferred to an smartphone/laptop via
Bluetooth/Wifi,and the data is further processed.<br><br><br>
# Block Diagram 
![](/images/img2.png) <br><br>
# Circuit Diagram
![](/images/imga.png) <br><br>
# Explanation
![](/images/img3.png) ![](/images/img4.png)  <br><br>
The gestures made by the user is converted to analog voltage signal using the flex sensor and the accelerometer.Using Analog to Digital Converter (ADC) from
the microcontroller board, the analog signal received is converted to digital signals which may then be processed by the microcontroller.The microcontroller
processes the digital signal, detects respective characters and transmits the data to a smartphone or a laptop via Bluetooth/Wifi. The data received via
Bluetooth/Wifi on the smartphone or the laptop is displayed on the screen.If setup, the data may be converted to voice using Text-to-Speech API.<br><br>
![](/images/img6.png)  <br><br>
# Program
### Intialization
We need to include following  libraries given below  
```C++
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
```
### Full Program
below is the complete program
```C++
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>




const char *ssid = "SmartTalk";
const char *password = "smarttalk";

WiFiServer server(80);

int sensorValue1 ;
int sensorValue2 ;
int sensorValue3 ;
void setup() {
 
  

  
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  server.begin();

  
}

void loop() {
  sensorValue1 = analogRead(34);
  sensorValue2 = analogRead(33);
  sensorValue3 = analogRead(32);
  WiFiClient client = server.available();   

  if (client) {                             
               
    String currentLine = "";                
    while (client.connected()) {            
     if (client.available()) {             
       char c = client.read();            
       Serial.write(c);                    
       if (c == '\n') {                    
          
        if (currentLine.length() == 0) {
         client.print("<HEAD>");
         client.print("<meta http-equiv=\"refresh\" content=\"0.5\">"); 
            
            
            
        

       
         if ((sensorValue1 >=100) and (sensorValue1 <=500)and(sensorValue3 >=600) and (sensorValue3 <=900)) {
           client.println("<title>VICTORY</title>");
          client.print("VICTORY");
          client.println();
          break;
         }
         else if ((sensorValue1 >= 100 ) and (sensorValue1 <=500 ) and (sensorValue3 >= 100) and (sensorValue3 <=500 )) {
           client.println("<title>HELLO</title>");
          client.print("HELLO");
          
          client.println();
          break;
         }
         
         else if ((sensorValue3 >= 100) and (sensorValue3 <=500)) {
           client.println("<title>BYE</title>");
          client.print("BYE");
          client.println();
          break;
         }
         
         else if ((sensorValue2 >= 100) and (sensorValue2 <=300)) {
           client.println("<title>HELP</title>");
          client.print("HELP");
          client.println();
          break;
         }
         
        
         else     {
           client.println("<title></title>");
          client.println();
          
          break;
          
        
           
          } 
        } else if (c != '\r') {  
          currentLine += c;     
           
        }
        }
     }
    }
     client.stop();
  
  }
}
```
<br><br>
# Output
Here the shown below images are the screenshots from smarttalk app and it's corresponding sign
<br><br>
![](/images/imgc.png)<br>
![](/images/imgd.png) <br>
![](/images/imge.png) <br>
![](/images/imgf.png) <br>

