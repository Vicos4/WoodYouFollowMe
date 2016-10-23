
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <EEPROM.h>
#include <Servo.h>
#include <SPI.h>
YunServer server;

int potpin0 = 0;//brownLeftHip
int potpin1 = 1;//blueRightHip
int potpin2 = 2;//whiteRightKnee
int potpin3 = 3;//yellowLeftKneee

int val = 1;


void setup() 
{
  
  Bridge.begin();
  
  server.listenOnLocalhost();
  
  server.begin();

}

void loop() 
{
  YunClient client = server.accept();

 if (client) 
   {
    if (client.read() != 0) 
      {
//      client.println("Status: 200 OK");
//      client.println("Content-Type: text/html; charset=utf-8");
//      client.println();
//      client.print("<meta http-equiv=\"refresh\" content=\"1\">");
//      client.println("<html>");
//      client.println("<title>The title goes here</title>");
//      client.println("<body>");
//      client.println("<h1>AnalogPins</h1>");
//      client.println("<h2>");
      client.print(analogRead(potpin0));
      client.println(',');
//      client.print("</h2>");
//      client.println("<h3>");
      client.print(analogRead(potpin1));
      client.println(',');
//      client.print("</h3>");
//      client.println("<h4>");
      client.print(analogRead(potpin2));
      client.println(',');
//      client.print("</h4>");
//      client.println("<h5>");
      client.print(analogRead(potpin3));
      client.println(',');
//      client.print("</h5>");
////    client.println(analogRead(potpin1));
////    client.println(analogRead(potpin2));
////    client.println(analogRead(potpin3));
//      client.println("</body>");
//      client.println("</html>");

      client.stop();
      }
    delay(1); //Poll every 30ms
   }
}






