#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
 

#define SoilPin A0
int SoilValue = 0;
int percentage =0;

#define Ph_Sensor A1
float Ph_value = 0;

void setup()
{
  Serial.begin(9600);
  sensors.begin(); 
  pinMode(Ph_Sensor,INPUT);
}

void loop()
{ 
  sensors.requestTemperatures();
  Serial.print("Temperature: "); 
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.println(" C"); 

  SoilValue = analogRead(SoilPin);
  percentage = map(SoilValue,1023,0,0,100);
  Serial.print("Soil Moisture Percentage=");
  Serial.print(percentage);
  Serial.println("%");
  
  Ph_value = analogRead(Ph_Sensor);
  Ph_value = map(Ph_value ,0 ,40 ,7 ,3) ;
  //Ph_value = (Ph_value - 122)/-14 ;
  Serial.print("PH= ");
  Serial.println(Ph_value);

  delay(1000);
}
