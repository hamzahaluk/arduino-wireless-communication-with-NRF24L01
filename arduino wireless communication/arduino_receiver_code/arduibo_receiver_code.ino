#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//NRF24L01
RF24 radio(9, 8);  // CE, CSN

//verici ile alıcının kanal isimleri aynı olmalıdır
const byte address[8] = "robolink";

void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //iletişim adresi tanımla
  radio.openReadingPipe(0, address);
  
  //modülü alıcı olarak ayarla
  radio.startListening();
}

void loop()
{
  //eğer data geldiyse okumaya başla
  if (radio.available())
  {
    char text[32] = {0}; //en fazla 32 karakter bir veri alabileceğinden dolayı, 32 karakterlik 0 lar kümesi oluşturduk. 
    //Gelen tüm karakterleri buraya sırayla geçirmiş olacağız 
    
    radio.read(&text, sizeof(text));
    
    Serial.println(text); //Seri ekrana alınan veriyi yazdır
  }
}
