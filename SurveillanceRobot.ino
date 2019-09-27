#include <SoftwareSerial.h> 
#include <Servo.h>
    
long incomingByte = 0; 
int LmotorF = 8; 
int LmotorB = 9; 
int RmotorF = 10; 
int RmotorB = 11;
int Won= 12;
int Xon= 7;
int Zon = 12;
int CompareN= 1;
Servo myservo;


 

void setup() 
{ 

  Serial.begin(9600); 
  pinMode(LmotorF,OUTPUT);//Setting ports as OUTPUTS as they  
  pinMode(LmotorB,OUTPUT);//supply signal values to motor driver 
  pinMode(RmotorF,OUTPUT); 
  pinMode(RmotorB,OUTPUT);
  pinMode(Won,OUTPUT);
  pinMode(Xon,OUTPUT);
  pinMode(Zon,OUTPUT);
  myservo.attach(6);
    
  
 
}  
    
void loop() 
{ 
  
  if(Serial.available()>0)//Checking is Serial data available 
  {
  
    int incomingByte = Serial.read(); //Storing value of read data into variable 
    //Serial.println(incomingByte);
     
     
    if (incomingByte > 25)
    {
      switch(incomingByte)
      
    { 
     case 'F' : MoveF(); 
     break; 
     case 'B' : MoveB(); 
     break; 
     case 'L' : MoveL(); 
     break; 
     case 'R' : MoveR(); 
     break;
     case 'W' : MoveW(); 
     break;
     case 'X' : MoveX(); 
     break;
     case 'Z' : MoveZ(); 
     break; 
     case 'S' : Stop(); 
     break; 
     default : break; 
    } 
  }
    
 /*else
    {
      
      int r = incomingByte*5; //0,9,18,24
      myservo.write(r);
       Serial.println("ON");
    }
    */
 
 }
    
} 


void MoveF() 
{ 
  Serial.println("Forward"); 
  digitalWrite(LmotorF,HIGH);
  digitalWrite(LmotorB,LOW); 
  digitalWrite(RmotorF,HIGH); 
  digitalWrite(RmotorB,LOW); 
   
}  
void MoveB() 
{ 
  Serial.println("Backward"); 
  digitalWrite(LmotorF,LOW);
  digitalWrite(LmotorB,HIGH); 
  digitalWrite(RmotorF,LOW); 
  digitalWrite(RmotorB,HIGH);   
}  
void MoveR() 
{ 
  Serial.println("Right"); 
  digitalWrite(LmotorF,LOW); 
  digitalWrite(LmotorB,HIGH);
  digitalWrite(RmotorF,HIGH); 
  digitalWrite(RmotorB,LOW); 
}  
void MoveL() 
{ 
  Serial.println("Left");  
  digitalWrite(LmotorF,HIGH);
  digitalWrite(LmotorB,LOW);
  digitalWrite(RmotorF,LOW); 
  digitalWrite(RmotorB,HIGH); 
}

void MoveW() 
{ 
   Compare(Won);
}   

void MoveX() 
{ 
   Compare(Xon); 
}

void MoveZ() 
{ 
   Compare(Zon);
}



void Compare(int temp)  
{
  if ( CompareN == 1 )
    {
      Serial.println("ON");
      digitalWrite(temp,HIGH); //temp is a common varriable to write 3 pins
      CompareN = 0;
     }

else
    {
      Serial.println("OFF"); 
      digitalWrite(temp,LOW);
      CompareN = 1;
    }
}
  
void Stop() 
 { 
  //Serial.println("Stop"); 
  digitalWrite(LmotorF,LOW);
  digitalWrite(LmotorB,LOW); 
  digitalWrite(RmotorF,LOW); 
  digitalWrite(RmotorB,LOW); 
 } 
