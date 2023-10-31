#include <Arduino.h>
#include <SoftwareSerial.h>

EspSoftwareSerial::UART swSer1;

void checkSwSerial(EspSoftwareSerial::UART* ss);

void setup() {
  Serial.begin(9600);
  swSer1.begin(9600, EspSoftwareSerial::SWSERIAL_8N1, GPIO_NUM_19, GPIO_NUM_19, false, 256);
  swSer1.enableIntTx(false);
  swSer1.enableTx(false);
  swSer1.enableRx(true);

}

void loop() {
	checkSwSerial(&swSer1);
}


void checkSwSerial(EspSoftwareSerial::UART* ss) {
	byte ch;
	// wait 1 second for the reply from EspSoftwareSerial if any
	delay(1000);
	if (ss->available()) {
		Serial.print(PSTR("\nResult:"));
		while (ss->available()) {
			ch = (byte)ss->read();
			//Serial.print(ch < 0x10 ? PSTR(" 0x") : PSTR(" "));
			//Serial.print(ch, HEX);
      //Serial.print(ch, HEX);
      Serial.print(ch);
      Serial.print(" ");
		}
		Serial.println();
	} else {
    		Serial.println(PSTR("not avaliable"));

  }
}
