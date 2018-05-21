import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;

boolean firstContact = false; //Check for Handshake


void setup()
{
  size(200,200); //make our canvas 200 x 200 pixels big
  background (200,200,209); 
  
  printArray(Serial.list());
  
  String portName = Serial.list()[0]; //Open whatever port is the one you're using.
  
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}


void draw()
{
  //if ((mousePressed == true)  &&  ( mouseButton  ==  LEFT ))  
  //{                            //if we clicked in the window
  //  myPort.write('1');         //send a 1
  //  println("1");   
  //} 
  
  //if ((mousePressed == true)  &&  ( mouseButton  ==  RIGHT ))  
  //{                             //otherwise
  //  myPort.write('0');          //send a 0
  //  println("0");
  //}
}


void serialEvent( Serial myPort) {
//put the incoming data into a String - 
//the '\n' is our end delimiter indicating the end of a complete packet
val = myPort.readStringUntil('\n');
//make sure our data isn't empty before continuing
if (val != null) {
  //trim whitespace and formatting characters (like carriage return)
  val = trim(val);
  println(val);

  //look for our 'A' string to start the handshake
  //if it's there, clear the buffer, and send a request for data
  if (firstContact == false) {
    if (val.equals("A")) {
      myPort.clear();
      firstContact = true;
      myPort.write("A");
      println("contact");
    }
  }
  else { //if we've already established contact, keep getting and parsing data
    println(val);

    if ((mousePressed == true)  &&  ( mouseButton  ==  LEFT ))  
    {                            //if we clicked in the window
      myPort.write('1');         //send a 1
      println("1");   
    } 
  
    if ((mousePressed == true)  &&  ( mouseButton  ==  RIGHT ))  
    {                             //otherwise
      myPort.write('0');          //send a 0
      println("0");
    }

    // when you've parsed the data you have, ask for more:
    myPort.write("A");
    }
  }
}
