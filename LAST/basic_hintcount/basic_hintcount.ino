#include <EEPROM.h>
int addr = 24;
int addr1 = 25;
int addr2 = 26;
int addr3 = 27;
int addr4 = 28;
int addr5 = 29;

void setup() {
  EEPROM.write(addr, 3);
  EEPROM.write(addr1, 0);
  EEPROM.write(addr2, 0);
  EEPROM.write(addr3, 0);
  EEPROM.write(addr4, 0);
  EEPROM.write(addr5, 28);
}

void loop() {
  
}
