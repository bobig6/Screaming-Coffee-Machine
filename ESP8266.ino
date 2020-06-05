#include <ESP8266WiFi.h>


const char* ssid = "Coffee-Machine";
const char* password = "parolata";

const int pin = 2;

WiFiServer server(80);

void setup()
{
  
    Serial.begin(115200);
   Serial.print("Setting soft-AP ... ");
  boolean result = WiFi.softAP(ssid, password);
  if(result == true)
  {
    Serial.println("Ready");


    server.begin();
    Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());
  }
  else
  {
    Serial.println("Failed!");
  }

      pinMode(pin,OUTPUT);
}

// prepare a web page to be send to a client (web browser)
String prepareHtmlPage()
{
  String htmlPage =
     String("HTTP/1.1 200 OK\r\n") +
            "Content-Type: text/html\r\n" +
            "Connection: close\r\n" +  // the connection will be closed after completion of the response
            "\r\n" +
            "<!DOCTYPE HTML>" +
            "<html>" +
            "<body> <h1>Coffee Machine Home Page</h1>" +
            "<form action=\"/gpio2/1\" method=\"GET\"><input type=\"submit\" value=\"ON\"></form><form action=\"/gpio2/0\" method=\"GET\"><input type=\"submit\"value=\"OFF\"></form>"+
            " </body></html>" +
            "\r\n";
  return htmlPage;
}


void loop()
{
  WiFiClient client = server.available();
  // wait for a client (web browser) to connect
  if (client)
  {
    Serial.println("\n[Client connected]");
    while (client.connected())
    {
      // read line by line what the client (web browser) is requesting
      if (client.available())
      {
        String line = client.readStringUntil('\r');
        Serial.print(line);
        // wait for end of client's request, that is marked with an empty line
        if (line.length() == 1 && line[0] == '\n')
        {
          if (line.indexOf("/gpio2/1") != -1){
            digitalWrite(pin,1);
          }else if (line.indexOf("/gpio2/0") != -1){
            digitalWrite(pin,0);  
          }
          break;
        }
      }
    }
    delay(1); // give the web browser time to receive the data

    // close the connection:
    client.stop();
    Serial.println("[Client disonnected]");
  }
}