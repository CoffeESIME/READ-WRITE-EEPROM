#include <EEPROM.h>

void setup(){

Serial.begin(9600);
Serial.println("Entrada necesaria de EEPROM entre 0 - 1024");
}

int direc;
int datos;
void loop(){
String entrada="";




entrada=Serial.readString();
if (entrada.startsWith("read"))



{
  direc=entrada.substring(entrada.indexOf(' ')+1).toInt();
  //Serial.println(direc);
  Serial.print("Dato en EEPROM: ");
  Serial.println(EEPROM.read(direc));
//Serial.println("BIEN");

}






else if (entrada.startsWith("write"))
{
  
  String direc=entrada.substring(entrada.indexOf(' ')+1);
  String Direct2= direc.substring(direc.indexOf(' ')+1);
  String Direct1= direc.substring(0,direc.indexOf(' '));
  int ARG1=Direct1.toInt();
  int ARG2=Direct2.toInt();
  Serial.print("Direccion EEPROM: ");
  Serial.println(Direct1);
  Serial.print("Entrada a escribir EEPROM: ");
  Serial.println(Direct2);
  //Serial.println(ARG1);
  //Serial.println(ARG2);
  //Serial.println(direc);
  byte byte1Arg2 = ARG2 & 0XFF;
  byte byte2Arg2 = (ARG2 >> 8) & 0XFF;        
  EEPROM.write(ARG1, byte1Arg2);
  EEPROM.write(ARG1 + 1, byte2Arg2);
 // Serial.println(EEPROM.read(direc));
//Serial.println("BIEN");

}
//Serial.print(entrada);
delay(100);

}
