char serial_read; // Data received from the serial port
int ledPin = 12; // Set the pin to digital I/O 13
boolean ledState = LOW; //to toggle our LED


void setup() 
{
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  digitalWrite(ledPin, HIGH);

  
  Serial.begin(9600); //initialize serial communications at a 9600 baud rate

  establishContact();  // send a byte to establish contact until receiver responds
}


void loop() 
{
  if (Serial.available() > 0) // If data is available to read,
  { 
    serial_read = Serial.read(); // read it and store it in val
      
    if (serial_read == '1') // If 1 was received
    { 
      digitalWrite(ledPin, HIGH); // turn the LED on
    } 
    if (serial_read == '0') // If 0 was received
    {
      digitalWrite(ledPin, LOW); // otherwise turn it off
    }
   
    delay(100);
  }
  else
  {
    Serial.println(random(2,255)); //send back a hello world
    delay(100);
  }
}


void establishContact() 
{
  while (Serial.available() <= 0) 
  {
    Serial.println("A");   // send a capital A
    delay(300);
  }
}
