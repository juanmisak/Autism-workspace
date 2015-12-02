
#include <SoftwareSerial.h>
SoftwareSerial BT(4,2); // RX, TX recorder que se cruzan
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);//Seleccionamos el pin 13 como salida
  pinMode(12,OUTPUT);//Seleccionamos el pin 13 como salida
  pinMode(11,OUTPUT);//Seleccionamos el pin 13 como salida
  pinMode(10,OUTPUT);//Seleccionamos el pin 13 como salida
  pinMode(9,OUTPUT);//Seleccionamos el pin 13 como salida
  pinMode(8,OUTPUT);//Seleccionamos el pin 13 como salida
  pinMode(7,OUTPUT);//Seleccionamos el pin 13 como salida
  pinMode(6,OUTPUT);//Seleccionamos el pin 13 como salida
  
  BT.begin(9600);
}

void loop()
{
  //Serial.println("Led encendido");//Se mostrará un mensaje.
  while (BT.available())//Declaramos un sentencia, Mientras el puerto Serial este disponible se empieza el ciclo 
  {
    char dato=  BT.read(); //Declaramos una variable de tipo carácter y Seo lee la variale enviada desde el Bluetooth.
    Serial.println(dato);
    switch(dato)
    {
    case 'a': //Si en el caso de ser A la varible enviada, entonces:
      {
        digitalWrite(13,LOW);//La señal será alta, encenderá el LED.
        Serial.println("Led encendido");//Se mostrará un mensaje.
        break;//El caso se detiene.
      }
    case 'A': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(13,HIGH);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'b': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(12,LOW);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'B': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(12,HIGH);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'c': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(11,LOW);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'C': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(11,HIGH);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'd': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(10,LOW);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      } 
    case 'D': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(10,HIGH);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      } 
    case 'e': //Si en el caso de ser A la varible enviada, entonces:
      {
        digitalWrite(9,LOW);//La señal será alta, encenderá el LED.
        Serial.println("Led encendido");//Se mostrará un mensaje.
        break;//El caso se detiene.
      }
    case 'E': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(9,HIGH);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'f': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(8,LOW);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'F': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(8,HIGH);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'g': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(7,LOW);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'G': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(7,HIGH);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      }
    case 'h': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(6,LOW);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      } 
    case 'H': //Si en el caso de ser A la variable enviada, entonceS:
      {
        digitalWrite(6,HIGH);//la señal será baja por lo que el LED estará apagado.
        Serial.println("Led apagado");//Se mostrará un mensaje.
        break;
      } 
    }       
  }
}
