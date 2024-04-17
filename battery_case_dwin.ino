#include <HardwareSerial.h>

const byte rxPin = 16; // rx2
const byte txPin = 17; // tx2
HardwareSerial dwin(2);

#define speed_add 0x61
#define rpm_add 0x62
#define icon_1_add 0x63 
#define icon_2_add 0x64 
#define icon_3_add 0x65
#define icon_4_add 0x66 
#define icon_5_add 0x67 
#define icon_6_add 0x68
#define icon_7_add 0x69 
#define icon_8_add 0x70
#define icon_9_add 0x71 
#define icon_10_add 0x72 

unsigned char Speed[8] = {0x5A, 0xA5, 0x05, 0x82, speed_add, 0x00, 0x00, 0x00};
unsigned char RPM[8] = {0x5A, 0xA5, 0x05, 0x82, rpm_add, 0x00, 0x00, 0x00};
unsigned char Icon1[8] = {0x5A, 0xA5, 0x05, 0x82, icon_1_add, 0x00, 0x00, 0x00};
unsigned char Icon2[8] = {0x5A, 0xA5, 0x05, 0x82, icon_2_add, 0x00, 0x00, 0x00};
unsigned char Icon3[8] = {0x5A, 0xA5, 0x05, 0x82, icon_3_add, 0x00, 0x00, 0x00};
unsigned char Icon4[8] = {0x5A, 0xA5, 0x05, 0x82, icon_4_add, 0x00, 0x00, 0x00};
unsigned char Icon5[8] = {0x5A, 0xA5, 0x05, 0x82, icon_5_add, 0x00, 0x00, 0x00};
unsigned char Icon6[8] = {0x5A, 0xA5, 0x05, 0x82, icon_6_add, 0x00, 0x00, 0x00};
unsigned char Icon7[8] = {0x5A, 0xA5, 0x05, 0x82, icon_7_add, 0x00, 0x00, 0x00};
unsigned char Icon8[8] = {0x5A, 0xA5, 0x05, 0x82, icon_8_add, 0x00, 0x00, 0x00};
unsigned char Icon9[8] = {0x5A, 0xA5, 0x05, 0x82, icon_9_add, 0x00, 0x00, 0x00};
unsigned char Icon10[8] = {0x5A, 0xA5, 0x05, 0x82, icon_10_add, 0x00, 0x00, 0x00};

void generateAndSendPacket(unsigned char packet[], byte varId, int value) {
  packet[6] = highByte(value);
  packet[7] = lowByte(value);
  Serial.println("Sending Value: " + String(value));
  Serial2.write(packet, 8);
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, rxPin, txPin);
}

void loop() {         
  int s = 2;
  int r = 600;

 
    generateAndSendPacket(Speed, speed_add, s);
    generateAndSendPacket(RPM, rpm_add, r);
    
   generateAndSendPacket(Icon9, icon_9_add, 1);
        Serial.println("four");
  if (Serial.available() > 0) {
    int inputValue = Serial.parseInt();
    // Call different functions based on the input value
    switch (inputValue) {
      case 0:
        generateAndSendPacket(Icon5, icon_5_add, 1);
        Serial.println("empty");
        delay(1000);
        generateAndSendPacket(Icon5, icon_5_add, 0);
        Serial.println("empty");//1
        delay(1000);
        break;
      case 1:
        generateAndSendPacket(Icon1, icon_1_add,0 );
        Serial.println("Hide four");//4
        generateAndSendPacket(Icon2, icon_2_add, 0);
        Serial.println("Hide three");//3
        generateAndSendPacket(Icon3, icon_3_add, 0);
        Serial.println("Hide two");//2
        generateAndSendPacket(Icon4, icon_4_add, 1);
        Serial.println("Display one");
        delay(1000);

        break;
      case 2:
        generateAndSendPacket(Icon1, icon_1_add,0 );
        Serial.println("Hide four");//4
        generateAndSendPacket(Icon2, icon_2_add, 0);
        Serial.println("Hide three");//3
        generateAndSendPacket(Icon4, icon_4_add, 0);
        Serial.println("Hide one");//1
        generateAndSendPacket(Icon3, icon_3_add, 1);
        Serial.println("Display two");
        delay(1000);
        break;
      case 3:
        generateAndSendPacket(Icon1, icon_1_add,0 );
        Serial.println("Hide four");//4
        generateAndSendPacket(Icon3, icon_3_add, 0);
        Serial.println("Hide two");//2
        generateAndSendPacket(Icon4, icon_4_add, 0);
        Serial.println("Hide one");//1
        generateAndSendPacket(Icon2, icon_2_add, 1);
        Serial.println("Display three");
        delay(1000);
        break;
      case 4:
        generateAndSendPacket(Icon2, icon_2_add, 0);
        Serial.println("Hide three");//3
        generateAndSendPacket(Icon3, icon_3_add, 0);
        Serial.println("Hide two");//2
        generateAndSendPacket(Icon4, icon_4_add, 0);
        Serial.println("Hide one");//1      
        generateAndSendPacket(Icon1, icon_1_add, 1);
        Serial.println("Display four");
        delay(1000);

        break;
      default:
        generateAndSendPacket(Icon1, icon_1_add,0 );
        Serial.println("Hide four");//4
        generateAndSendPacket(Icon2, icon_2_add, 0);
        Serial.println("Hide three");//3
        generateAndSendPacket(Icon3, icon_3_add, 0);
        Serial.println("Hide two");//2
        generateAndSendPacket(Icon4, icon_4_add, 0);
        Serial.println("Hide one");//1  
        generateAndSendPacket(Icon5, icon_5_add, 1);
        Serial.println("empty");
        break;
    }
  }
//BATTERY();
//BOOST();                
}
