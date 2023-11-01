#include <Arduino.h>
#include <SoftwareSerial.h>
#include <string>
using namespace std;

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
	uint8_t scanData[100];
	uint8_t ch;
	delay(1000);
	if (ss->available()) {
		int count = 0;
		while (ss->available()) {
			ch = (uint8_t)ss->read();
			scanData[count++] = ch;
			//Serial.print(ch < 0x10 ? PSTR(" 0x") : PSTR(" "));
			//Serial.print(ch, HEX);
      		//Serial.print(ch, HEX);
			//Serial.print((char)ch);
			//Serial.print(" ");
		}

		Serial.print(PSTR("\nScanData:")); 			//ScanData: 2     48     50     52     50     51      70      67     52     50     53     55      66     51     48   13   10  3
		for (int i = 0; i < count; ++i) {
			Serial.print(String(scanData[i], BIN)); //ScanData:10 110000 110010 110100 110010 110011 1000110 1000011 110100 110010 110101 110111 1000010 110011 110000 1101 1010 11
			Serial.print(" ");
		}
		Serial.println();
	} else {
		Serial.println(PSTR("no ScanData"));
	}
	//
}

//Øremerke: 2738737 30352
//        2       48       50       52       50       51       70       67       52       50       53       55       66       51       48       13       10        3
// 00000010 00110000 00110010 00110100 00110010 00110011 01000110 01000011 00110100 00110010 00110101 00110111 01000010 00110011 00110000 00001101 00001010 00000011