#include <Keypad.h>  // Keypad.h 라이브러리를 호출합니다.
#include <Wire.h>    // I2C control 라이브러리
#include <LiquidCrystal_I2C.h>  // LCD 라이브러리
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
#include <EEPROM.h>

SoftwareSerial mySerial(10, 11); 
LiquidCrystal_I2C lcd(0x27,16,2);  

// 힌트 허용 개수 주소
byte addr = 24;
// 첫번째 비밀번호 주소
byte addr1 = 25;
// 두번째 비밀번호 주소
byte addr2 = 26;
// 세번째 비밀번호 주소
byte addr3 = 27;
// 네번째 비밀번호 주소
byte addr4 = 28;
// 볼륨 조절 주소
byte addr5 = 29;

// *** 힌트 허용 개수 ***
byte hCount = EEPROM.read(addr);

// *** 힌트 초기화 비밀번호 ***
int pw01 = EEPROM.read(addr1);
int pw02 = EEPROM.read(addr2);
int pw03 = EEPROM.read(addr3);
int pw04 = EEPROM.read(addr4);
String initCode = String(pw01) + String(pw02) + String(pw03) + String(pw04);

// *** 업체명 ***
char Name[16] = "HINT BOX";

// 하이퍼파라미터
int count = 0;    
char len;
char Code[5] = "";
char count1 = 0; 

// 볼륨
byte sound = EEPROM.read(addr5);

// 문제 개수와 동일 (사용한 힌트는 반복해서 들을 수 있게)
char D1 = 0;
char D2 = 0;
char D3 = 0;
char D4 = 0;
char D5 = 0;
char D6 = 0;
char D7 = 0;
char D8 = 0;
char D9 = 0;
char D10 = 0;
char D11 = 0;
char D12 = 0;
char D13 = 0;
char D14 = 0;
char D15 = 0;
char D16 = 0;
char D17 = 0;
char D18 = 0;
char D19 = 0;
char D20 = 0;
char D21 = 0;
char D22 = 0;
char D23 = 0;
char D24 = 0;
char D25 = 0;
char D26 = 0;
char D27 = 0;
char D28 = 0;
char D29 = 0;
char D30 = 0;

// 문제 개수와 동일 (힌트 사용이 끝이나도 반복해서 들을 수 있게)
char done1 = 0;
char done2 = 0;
char done3 = 0;
char done4 = 0;
char done5 = 0;
char done6 = 0;
char done7 = 0;
char done8 = 0;
char done9 = 0;
char done10 = 0;
char done11 = 0;
char done12 = 0;
char done13 = 0;
char done14 = 0;
char done15 = 0;
char done16 = 0;
char done17 = 0;
char done18 = 0;
char done19 = 0;
char done20 = 0;
char done21 = 0;
char done22 = 0;
char done23 = 0;
char done24 = 0;
char done25 = 0;
char done26 = 0;
char done27 = 0;
char done28 = 0;
char done29 = 0;
char done30 = 0;

String A001 = "DB38";
String A002 = "CA59";
String A003 = "DA60";
String A004 = "BD67";
String A005 = "AC35";
String A006 = "AD58";
String A007 = "BC71";
String A008 = "CB88";
String A009 = "CD37";
String A010 = "DC54";
String A011 = "CC38";
String A012 = "DD88";
String A013 = "DB34";
String A014 = "CA29";
String A015 = "AB65";
String A016 = "BC63";
String A017 = "AC25";
String A018 = "AD98";
String A019 = "BC31";
String A020 = "CB48";
String A021 = "CD27";
String A022 = "DC14";
String A023 = "CC98";
String A024 = "DD08";
String A025 = "BC51";
String A026 = "CB02";
String A027 = "CD47";
String A028 = "DC14";
String A029 = "CC58";
String A030 = "DD48";


 // 키패드의 행, 열의 갯수
const byte rows = 4;
const byte cols = 4;


// 키패드 버튼 위치 설정
char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


// 키패드에 연결된 핀번호 설정
byte rowPins[rows] = {6, 7, 8, 9};
byte colPins[cols] = {2, 3, 4, 5};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

// LCD
char hintCount[14] = "Hint Count : ";
char hintCode[13] = "Hint Code : ";
char password[12] = "Password : ";
char changepass[16] = "Change Password";
char volumecontrol[16] = "Volume Control";
char volumesize[16] = "Volume Size : ";
char Changepass[5] = "DCBA";
char ChangeKey[5] = "ABCD";
String volume = "AAAA";
char countSetting[16] = "Count Setting";
char presentsize[16] = "Present Size: "; 
char presentcount[16] = "PresentCount: ";
char changecount[16] = "Change Count: ";
int pass = 0;

void setup() {
  // Serial
  Serial.begin(9600);
  
  // LCD
  lcd.init();
  lcd.backlight();
  lcd.print(Name);
  lcd.setCursor(0,1);
  lcd.print(password);
  
  // mp3 모듈 설정
  mySerial.begin(9600);
  mp3_set_serial(mySerial);    
  delay(1);                    
  mp3_set_volume(sound);
}

// 연결자
char p = 0;
char p2 = 0;
char next = 0;

// 초반 선언
int permitCount = "";
int pw1 = "";
int pw2 = "";
int pw3 = "";
int pw4 = "";
int pw11 = "";
int pw22 = "";
int pw33 = "";
int pw44 = "";
int vol = "";

void loop() {
  char key = keypad.getKey();
  if (pass == 7){
    lcd.setCursor(0,0);
    lcd.print(presentsize);
    lcd.setCursor(14,0);
    lcd.print(sound);
    lcd.setCursor(0,1);
    lcd.print(volumesize);
    if (((key >= '0' && key <= '9') || (key == 'C')) && (count1 <3)){
      count1++;
      len = strlen(Code);
      Code[len] = key;
      Code[len+1] = '\0';
      lcd.setCursor(14,1);
      lcd.print(Code);
      if (key == 'C'){
        vol = atoi(Code);
        if (vol <= 30){
          EEPROM.write(addr5, vol);
          lcd.clear();
          Code[0] = '\0';
          count1 = 0;
          pass = 1;
          delay(300);
        }else {
          EEPROM.write(addr5, 30);
          lcd.clear();
          Code[0] = '\0';
          count1 = 0;
          pass = 1;
          delay(300);
        }
      }
    }
  }
  if (pass == 6){
    lcd.setCursor(0,0);
    lcd.print(volumecontrol);
    lcd.setCursor(0,1);
    lcd.print(password);
    if ((key >= '0' && key <= '9') && (count1 < 4)) {
      count1++;
      len = strlen(Code);
      Code[len] = key;
      Code[len+1] = '\0';
      lcd.setCursor(11,1);
      lcd.print(Code);
      if (initCode == Code){
        delay(500);
        Code[0] = '\0';
        count1 = 0;  
        pass = 7;
        lcd.clear();
      }
    }
    if (key == '*' || key == '#'){
        lcd.clear();
        Code[0] = '\0';
        count1 = 0;
    }
  }
  if (pass == 5){
    lcd.setCursor(0,0);
    lcd.print(password);
    lcd.setCursor(0,1);
    lcd.print(password);
    if (((key >= '0' && key <= '9')||(key == 'C')) && (count1 < 2)) {
      count1++;
      len = strlen(Code);
      Code[len] = key;
      Code[len+1] = '\0';
      if (p2 == 0){
        lcd.setCursor(11,0);
        lcd.print(Code);
        if(count1 == 1){
          pw1 = atoi(Code);
          Code[0] = '\0';
          count1 = 0;
          p2 = 1;
        }
      }
      if (p2 == 1){
        lcd.setCursor(12,0);
        lcd.print(Code);
        if (count1 == 1){
          pw2 = atoi(Code);
          Code[0] = '\0';
          count1 = 0;
          p2 = 2;
        }
      }
      if (p2 == 2){
        lcd.setCursor(13,0);
        lcd.print(Code);
        if (count1 == 1){
          pw3 = atoi(Code);
          Code[0] = '\0';
          count1 = 0;
          p2 = 3;
        }
      }
      if (p2 == 3){
        lcd.setCursor(14,0);
        lcd.print(Code);
        if (count1 == 1){
          pw4 = atoi(Code);
          Code[0] = '\0';
          count1 = 0;
          p2 = 4;
        }
      }
      if (p2 == 4){
        lcd.setCursor(11,1);
        lcd.print(Code);
        if (count1 == 1){
          pw11 = atoi(Code);
          Code[0] = '\0';
          count1 = 0;
          p2 = 5;
        }
      }
      if (p2 == 5){
        lcd.setCursor(12,1);
        lcd.print(Code);
        if (count1 == 1){
          pw22 = atoi(Code);
          Code[0] = '\0';
          count1 = 0;
          p2 = 6;
        }
      }
      if (p2 == 6){
        lcd.setCursor(13,1);
        lcd.print(Code);
        if (count1 == 1){
          pw33 = atoi(Code);
          Code[0] = '\0';
          count1 = 0;
          p2 = 7;
        }
      }
      if (p2 == 7){
        lcd.setCursor(14,1);
        lcd.print(Code);
        if (count1 == 1){
          pw44 = atoi(Code);
          Code[0] = '\0';
          count1 = 0;
          if ((pw1 == pw11) && (pw2 == pw22) && (pw3 == pw33) && (pw4 == pw44)){
            EEPROM.write(addr1, pw1);
            EEPROM.write(addr2, pw2);
            EEPROM.write(addr3, pw3);
            EEPROM.write(addr4, pw4);
            delay(500);
            lcd.clear();
            pass = 1;
          }
        }
      }
    }
    if (key == '*' || key == '#'){
        lcd.clear();
        Code[0] = '\0';
        count1 = 0;
    }
  }
  if (pass == 4){
    lcd.setCursor(0,0);
    lcd.print(changepass);
    lcd.setCursor(0,1);
    lcd.print(password);
    if (((key >= '0' && key <= '9')||(key == 'C')) && (count1 < 4)) {
      count1++;
      len = strlen(Code);
      Code[len] = key;
      Code[len+1] = '\0';
      lcd.setCursor(11,1);
      lcd.print(Code);
            
      if (initCode == Code){
        delay(500);
        Code[0] = '\0';
        count1 = 0;  
        pass = 5;
        lcd.clear();
      }
    }
    if (key == '*' || key == '#'){
        lcd.clear();
        Code[0] = '\0';
        count1 = 0;
     }
  }
  if (pass == 3){
    lcd.setCursor(0,0);
    lcd.print(presentcount);
    lcd.setCursor(14,0);
    lcd.print(hCount);
    lcd.setCursor(0,1);
    lcd.print(changecount);
    if (((key >= '0' && key <= '9')||(key == 'C')) && (count1 < 3)) {
      if (key == 'C'){
        lcd.clear();
        Code[0] = '\0';
        count1 = 0;  
        pass = 1;
        p = 1;
        delay(300);
      }
      if (p == 0){
        count1++;
        len = strlen(Code);
        Code[len] = key;
        Code[len+1] = '\0';
        lcd.setCursor(14,1);
        lcd.print(Code);
        permitCount = atoi(Code);        
        EEPROM.write(addr, permitCount);
      }
    }
  }
  if (pass == 2){
    lcd.setCursor(0,0);
    lcd.print(countSetting);
    lcd.setCursor(0,1);
    lcd.print(password);
    if (((key >= '0' && key <= '9') || (key >= 'A' && key <= 'D')) && (count1 < 4)) {
      count1++;
      len = strlen(Code);
      Code[len] = key;
      Code[len+1] = '\0';
      
      if (next == 0){  
        lcd.setCursor(11,1);
        lcd.print(Code);
      }
      
      if (initCode == Code){
        next = 1;
        Code[0] = '\0';
        count1 = 0;
        delay(400);  
        pass = 3;
        lcd.clear();
      }
    }
    if (key == '*' || key == '#'){
      lcd.clear();
      Code[0] = '\0';
      count1 = 0;
    }
  }
  if (pass == 0){
    lcd.setCursor(0,0);
    lcd.print(Name);
    lcd.setCursor(0,1);
    lcd.print(password);
    if (((key >= '0' && key <= '9') || (key >= 'A' && key <= 'D')) && (count1 < 4)) {
      count1++;
      len = strlen(Code);
      Code[len] = key;
      Code[len+1] = '\0';
      lcd.setCursor(11,1);
      lcd.print(Code);

      char Change = strcmp(Code, ChangeKey);
      char ChangePass = strcmp(Code, Changepass);
      
      if (initCode == Code){
        Code[0] = '\0';
        count1 = 0;
        pass = 1;
        delay(500);
        lcd.clear();
      }
      if (volume == Code){
        delay(500);
        Code[0] = '\0';
        count1 = 0;
        pass = 6;
        lcd.clear();
      }
      if (Change == 0){
        delay(500);
        Code[0] = '\0';
        count1 = 0;
        lcd.clear();
        pass = 2;
      }

      if (ChangePass == 0){
        delay(500);
        Code[0] = '\0';
        count1 = 0;
        lcd.clear();
        pass = 4;
      }
    }
    if (key == '*' || key == '#'){
      lcd.clear();
      Code[0] = '\0';
      count1 = 0;
    }
  }
  if (pass == 1){
    lcd.setCursor(0,0);
    lcd.print(hintCount);
    lcd.setCursor(13,0);
    lcd.print(count);
    lcd.setCursor(0,1);
    lcd.print(hintCode);
    
    char key = keypad.getKey();
    if (((key >= '0' && key <= '9') || (key >= 'A' && key <='D')) && (count1 < 4)) {
      count1 ++;
      len = strlen(Code);
      Code[len] = key;
      Code[len+1] = '\0';
      lcd.setCursor(12,1);
      lcd.print(Code);
  
      // 초기화 번호 눌렀을 때
      if (initCode == Code){
        delay(300);
        lcd.clear();
        count1 = 0;
        count = 0;
        Code[0] = '\0';
        D1 = 0;
        D2 = 0;
        D3 = 0;
        D4 = 0;
        D5 = 0;
        D6 = 0;
        D7 = 0;
        D8 = 0;
        D9 = 0;
        D10 = 0;
        D11 = 0;
        D12 = 0;
        D13 = 0;
        D14 = 0;
        D15 = 0;
        D16 = 0;
        D17 = 0;
        D18 = 0;
        D19 = 0;
        D20 = 0;
        D21 = 0;
        D22 = 0;
        D23 = 0;
        D24 = 0;
        D25 = 0;
        D26 = 0;
        D27 = 0;
        D28 = 0;
        D29 = 0;
        D30 = 0;
        done1 = 0;
        done2 = 0;
        done3 = 0;
        done4 = 0;
        done5 = 0;
        done6 = 0;
        done7 = 0;
        done8 = 0;
        done9 = 0;
        done10 = 0;
        done11 = 0;
        done12 = 0;
        done13 = 0;
        done14 = 0;
        done15 = 0;
        done16 = 0;
        done17 = 0;
        done18 = 0;
        done19 = 0;
        done20 = 0;
        done21 = 0;
        done22 = 0;
        done23 = 0;
        done24 = 0;
        done25 = 0;
        done26 = 0;
        done27 = 0;
        done28 = 0;
        done29 = 0;
        done30 = 0;
      }
      if (A001 == Code){
        if (count < hCount) {
          done1++;
          } else {
          mp3_play(100);
          Code[0]='\0';
        }
          
        if (done1 != 0){
          mp3_play(1);
          Code[0] = '\0';
          if (D1 == 0){
            count++;
            D1++;
            }
          }
        }
    
      if (A002 == Code){
        if (count < hCount) {
          done2++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done2 != 0){
          mp3_play(2);
          Code[0] = '\0';
          if (D2 == 0){
            count++;
            D2++;
            }
          }
        }
    
      if (A003 == Code){
        if (count < hCount) {
          done3++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done3 != 0){
          mp3_play(3);
          Code[0] = '\0';
          if (D3 == 0){
            count++;
            D3++;
            }
          }
        }
          
      if (A004 == Code){
        if (count < hCount) {
          done4++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done4 != 0){
          mp3_play(4);
          Code[0] = '\0';
          if (D4 == 0){
            count++;
            D4++;
            }
          }
        }
        
      if (A005 == Code){
        if (count < hCount) {
          done5++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done5 != 0){
          mp3_play(5);
          Code[0] = '\0';
          if (D5 == 0){
            count++;
            D5++;
            }
          }
        }
          
      if (A006 == Code){
        if (count < hCount) {
          done6++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done6 != 0){
          mp3_play(6);
          Code[0] = '\0';
          if (D6 == 0){
            count++;
            D6++;
            }
          }
        }
        
      if (A007 == Code){
        if (count < hCount) {
          done7++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done7 != 0){
          mp3_play(7);
          Code[0] = '\0';
          if (D7 == 0){
            count++;
            D7++;
            }
          }
        }
    
      if (A008 == Code){
        if (count < hCount) {
          done8++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done8 != 0){
          mp3_play(8);
          Code[0] = '\0';
          if (D8 == 0){
            count++;
            D8++;
            }
          }
        }
    
      if (A009 == Code){
        if (count < hCount) {
          done9++;
          } else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done9 != 0){
          mp3_play(9);
          Code[0] = '\0';
          if (D9 == 0){
            count++;
            D9++;
            }
          }
        }
    
      if (A010 == Code){
        if (count < hCount) {
          done10++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done10 != 0){
          mp3_play(10);
          Code[0] = '\0';
          if (D10 == 0){
            count++;
            D10++;
            }
          }
        }
          
      if (A011 == Code){
        if (count < hCount) {
          done11++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done11 != 0){
          mp3_play(11);
          Code[0] = '\0';
          if (D11 == 0){
            count++;
            D11++;
            }
          }
        }   
    
      if (A012 == Code){
        if (count < hCount) {
          done12++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done12 != 0){
          mp3_play(12);
          Code[0] = '\0';
          if (D12 == 0){
            count++;
            D12++;
            }
          }
        }
      
      if (A013 == Code){
        if (count < hCount) {
          done13++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done13 != 0){
          mp3_play(13);
          Code[0] = '\0';
          if (D13 == 0){
            count++;
            D13++;
            }
          }
        }
      
      if (A014 == Code){
        if (count < hCount) {
          done14++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done14 != 0){
          mp3_play(14);
          Code[0] = '\0';
          if (D14 == 0){
            count++;
            D14++;
            }
          }
        }
      
      if (A015 == Code){
        if (count < hCount) {
          done15++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done15 != 0){
          mp3_play(15);
          Code[0] = '\0';
          if (D15 == 0){
            count++;
            D15++;
            }
          }
        }
      
      if (A016 == Code){
        if (count < hCount) {
          done16++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done16 != 0){
          mp3_play(16);
          Code[0] = '\0';
          if (D16 == 0){
            count++;
            D16++;
            }
          }
        }
      
      if (A017 == Code){
        if (count < hCount) {
          done17++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done17 != 0){
          mp3_play(17);
          Code[0] = '\0';
          if (D17 == 0){
            count++;
            D17++;
            }
          }
        }
      
      if (A018 == Code){
        if (count < hCount) {
          done18++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done18 != 0){
          mp3_play(18);
          Code[0] = '\0';
          if (D18 == 0){
            count++;
            D18++;
            }
          }
        }
      
      if (A019 == Code){
        if (count < hCount) {
          done19++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done19 != 0){
          mp3_play(19);
          Code[0] = '\0';
          if (D19 == 0){
            count++;
            D19++;
            }
          }
        }
      
      if (A020 == Code){
        if (count < hCount) {
          done20++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done20 != 0){
          mp3_play(20);
          Code[0] = '\0';
          if (D20 == 0){
            count++;
            D20++;
            }
          }
        }
      
      if (A021 == Code){
        if (count < hCount) {
          done21++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done21 != 0){
          mp3_play(21);
          Code[0] = '\0';
          if (D21 == 0){
            count++;
            D21++;
            }
          }
        }
      
      if (A022 == Code){
        if (count < hCount) {
          done22++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done22 != 0){
          mp3_play(22);
          Code[0] = '\0';
          if (D22 == 0){
            count++;
            D22++;
            }
          }
        }
      
      if (A023 == Code){
        if (count < hCount) {
          done23++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done23 != 0){
          mp3_play(23);
          Code[0] = '\0';
          if (D23 == 0){
            count++;
            D23++;
            }
          }
        }
      
      if (A024 == Code){
        if (count < hCount) {
          done24++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done24 != 0){
          mp3_play(24);
          Code[0] = '\0';
          if (D24 == 0){
            count++;
            D24++;
            }
          }
        }
      
      if (A025 == Code){
        if (count < hCount) {
          done25++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done25 != 0){
          mp3_play(25);
          Code[0] = '\0';
          if (D25 == 0){
            count++;
            D25++;
            }
          }
        }
      
      if (A026 == Code){
        if (count < hCount) {
          done26++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done26 != 0){
          mp3_play(26);
          Code[0] = '\0';
          if (D26 == 0){
            count++;
            D26++;
            }
          }
        }
      
      if (A027 == Code){
        if (count < hCount) {
          done27++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done27 != 0){
          mp3_play(27);
          Code[0] = '\0';
          if (D27 == 0){
            count++;
            D27++;
            }
          }
        }
      
      if (A028 == Code){
        if (count < hCount) {
          done28++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done28 != 0){
          mp3_play(28);
          Code[0] = '\0';
          if (D28 == 0){
            count++;
            D28++;
            }
          }
        }
      
      if (A029 == Code){
        if (count < hCount) {
          done29++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done29 != 0){
          mp3_play(29);
          Code[0] = '\0';
          if (D29 == 0){
            count++;
            D29++;
            }
          }
        }
      
      if (A030 == Code){
        if (count < hCount) {
          done30++;
          }else {
          mp3_play(100);
          Code[0]='\0';
        }
        if (done30 != 0){
          mp3_play(30);
          Code[0] = '\0';
          if (D30 == 0){
            count++;
            D30++;
            }
          }
        }
      }
      
      if (key == '*' || key == '#'){
        lcd.clear();
        Code[0] = '\0';
        count1 = 0;
      }
    }
  }
