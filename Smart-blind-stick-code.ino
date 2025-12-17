const int trigpin = 9;
const int echopin = 10;
float duration,distance; 
int vib = 11; // vibration sensor d0 pin connected to 11th pin of arduino 
int val; 
void setup() 
{ pinMode(trigpin,OUTPUT); 
pinMode(echopin,INPUT);
pinMode(4,OUTPUT); //buzzer connected to 4th pin
pinMode(3,OUTPUT); // led 
pinMode(11,INPUT); // vibration sensor
Serial.begin(9600); }
void loop()
{ digitalWrite(trigpin,LOW); 
delayMicroseconds(2); 
digitalWrite(trigpin,HIGH); 
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH); 
distance = duration/58; 
val= digitalRead(vib); 
Serial.print("distance:"); 
Serial.println(distance); 
Serial.print("vibration:"); 
Serial.println(val); 
delay(100); 
if(distance<42.5||val==1) { digitalWrite(4,HIGH); delay(1000); digitalWrite(4,LOW); delay(1000); digitalWrite(3,HIGH); delay(1000); digitalWrite(3,LOW); delay(1000); Serial.print("Alert"); } } 
