#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <math.h>
double  lat1;
double  lat11;
double  lat2;
double  lon1;
double  lon11;
double  lon2;
double  R;
double  b1;
double  b2;
double  pi = 3.1415926535897932384626433832795;
double  b ;
double  c ;
double  k;
double x;
double y;
double d;
double l ; 
double lon0;
double lat0;
int cont = 0;
int soma = 0;


// Choose two Arduino pins to use for software serial
int RXPin = 2;
int TXPin = 3;

int GPSBaud = 9600;

// Create a TinyGPS++ object
TinyGPSPlus gps;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (gpsSerial.available() > 0){
    if (gps.encode(gpsSerial.read())){
      displayInfo();}
  }
  

}

void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat());
    Serial.println("latitude2");
    double lat11 = (gps.location.lat()); // point 1
    Serial.println(lat11,6);
    Serial.println("------------");
    delay(1000);
    
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng());
    Serial.println("longitude2");
    double lon11 = (gps.location.lng());//point 1
    Serial.println(lon11,6);
    Serial.println("------------");
    delay(1000);

if (cont == 0){
  lon0 = lon11;
  lat0 = lat11;
  }
  
if (cont >= 1){
lat2 = lat11;
 
lon2 = lon11;

b1 = lat0 * pi/180 ;// φ, λ in radians
b2 = lat2 * pi/180;
 R = 6371; // metres
 b = (lat2-lat0) * pi/180;
 c = (lon2-lon0) * pi/180;

x = (c) * cos((b1+b2)/2);
y = (b);
d = (sqrt(x*x + y*y) * R)*1000;
l = (int) d;
soma += l;
Serial.println(d,6);
delay(2000);
Serial.println(l);
delay(2000); 
Serial.println("soma");
Serial.println(soma);
delay(2000);
  
  Serial.println("satelites");  
  Serial.println(gps.satellites.value()); 
  delay(1000);
  lat0 = lat2;
  lon0 = lon2;
  }
   cont += 1;
  }
  
 
  else
  {
    Serial.println("Location: Not Available");
  }

}
