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
