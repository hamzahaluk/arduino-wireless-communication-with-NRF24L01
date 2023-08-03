#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//NRF24L01 
RF24 radio(9, 8);  // CE, CSN

//haberleşme kanalı (herhangi bir "string" olabilir)
const byte address[8] = "robolink";

void setup()
{
  radio.begin();
  
  //haberleşme adresini tanımla 
  radio.openWritingPipe(address);
  
  //verici olarak ayarla
  radio.stopListening();
}

void loop()
{
  //sürekli mesaj gönder
  
  const char text[] = "Robolink Akademi"; //mesaj en fazla 32 karakter olabilir
  radio.write(&text, sizeof(text)); 
  
  delay(1000); //1 saniye bekle
}
