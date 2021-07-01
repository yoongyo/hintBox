#include <Keypad.h>  // Keypad.h 라이브러리를 호출합니다.
#include <Wire.h>    // I2C control 라이브러리
#include <LiquidCrystal_I2C.h>  // LCD 라이브러리
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(10, 11); 
LiquidCrystal_I2C lcd(0x27,16,2);  


// *** 힌트 허용 개수 ***
int permitCount = 10;

// *** 힌트 초기화 비밀번호 ***
char initCode[5] = "3338";

// *** 업체명 ***
char Name[16] = "THE CODE";  

// 하이퍼파라미터
int count = 0;    
char len;
char Code[5] = "";  
char count1 = 0; 

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

char a001[5] = "DB38";
char a002[5] = "CA59";
char a003[5] = "DA60";
char a004[5] = "BD67";
char a005[5] = "AC35";
char a006[5] = "AD58";
char a007[5] = "BC71";
char a008[5] = "CB88";
char a009[5] = "CD37";
char a010[5] = "DC54";
char a011[5] = "CC38";
char a012[5] = "DD88";
char a013[5] = "DB34";
char a014[5] = "CA29";
char a015[5] = "AB65";
char a016[5] = "BC63";
char a017[5] = "AC25";
char a018[5] = "AD98";
char a019[5] = "BC31";
char a020[5] = "CB48";
char a021[5] = "CD27";
char a022[5] = "DC14";
char a023[5] = "CC98";
char a024[5] = "DD08";
char a025[5] = "BC51";
char a026[5] = "CB02";
char a027[5] = "CD47";
char a028[5] = "DC14";
char a029[5] = "CC58";
char a030[5] = "DD48";


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

char hintCount[14] = "Hint Count : ";
char hintCode[13] = "Hint Code : ";
char password[12] = "Password : ";

int pass = 0;
void setup() {
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
  mp3_set_volume(28);   
}

void loop() {
  char key = keypad.getKey();
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

      char Init = strcmp(Code, initCode);
      if (Init == 0){
        Code[0] = '\0';
        count1 = 0;
        pass = 1;
        delay(500);
        lcd.clear();
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
  
      char Init = strcmp(Code, initCode);
  
      char A001 = strcmp(Code, a001);
      char A002 = strcmp(Code, a002);
      char A003 = strcmp(Code, a003);
      char A004 = strcmp(Code, a004);
      char A005 = strcmp(Code, a005);
      char A006 = strcmp(Code, a006);
      char A007 = strcmp(Code, a007);
      char A008 = strcmp(Code, a008);
      char A009 = strcmp(Code, a009);
      char A010 = strcmp(Code, a010);
      char A011 = strcmp(Code, a011);
      char A012 = strcmp(Code, a012);
      char A013 = strcmp(Code, a013);
      char A014 = strcmp(Code, a014);
      char A015 = strcmp(Code, a015);
      char A016 = strcmp(Code, a016);
      char A017 = strcmp(Code, a017);
      char A018 = strcmp(Code, a018);
      char A019 = strcmp(Code, a019);
      char A020 = strcmp(Code, a020);
      char A021 = strcmp(Code, a021);
      char A022 = strcmp(Code, a022);
      char A023 = strcmp(Code, a023);
      char A024 = strcmp(Code, a024);
      char A025 = strcmp(Code, a025);
      char A026 = strcmp(Code, a026);
      char A027 = strcmp(Code, a027);
      char A028 = strcmp(Code, a028);
      char A029 = strcmp(Code, a029);
      char A030 = strcmp(Code, a030);
  
      // 초기화 번호 눌렀을 때
      if (Init == 0){
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
      if (A001 == 0){
        if (count < permitCount) {
          done1++;
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
    
      if (A002 == 0){
        if (count < permitCount) {
          done2++;
          }
        if (done2 != 0){
          mp3_play(2);
          Code[0] = '\0';
          if (D1 == 0){
            count++;
            D1++;
            }
          }
        }
    
      if (A003 == 0){
        if (count < permitCount) {
          done3++;
          }
        if (done3 != 0){
          mp3_play(3);
          Code[0] = '\0';
          if (D2 == 0){
            count++;
            D2++;
            }
          }
        }
          
      if (A004 == 0){
        if (count < permitCount) {
          done4++;
          }
        if (done4 != 0){
          mp3_play(4);
          Code[0] = '\0';
          if (D2 == 0){
            count++;
            D2++;
            }
          }
        }
        
      if (A005 == 0){
        if (count < permitCount) {
          done5++;
          }
        if (done5 != 0){
          mp3_play(5);
          Code[0] = '\0';
          if (D3 == 0){
            count++;
            D3++;
            }
          }
        }
          
      if (A006 == 0){
        if (count < permitCount) {
          done6++;
          }
        if (done6 != 0){
          mp3_play(6);
          Code[0] = '\0';
          if (D3 == 0){
            count++;
            D3++;
            }
          }
        }
        
      if (A007 == 0){
        if (count < permitCount) {
          done7++;
          }
        if (done7 != 0){
          mp3_play(7);
          Code[0] = '\0';
          if (D4 == 0){
            count++;
            D4++;
            }
          }
        }
    
      if (A008 == 0){
        if (count < permitCount) {
          done8++;
          }
        if (done8 != 0){
          mp3_play(8);
          Code[0] = '\0';
          if (D4 == 0){
            count++;
            D4++;
            }
          }
        }
    
      if (A009 == 0){
        if (count < permitCount) {
          done9++;
          }
        if (done9 != 0){
          mp3_play(9);
          Code[0] = '\0';
          if (D5 == 0){
            count++;
            D5++;
            }
          }
        }
    
      if (A010 == 0){
        if (count < permitCount) {
          done10++;
          }
        if (done10 != 0){
          mp3_play(10);
          Code[0] = '\0';
          if (D5 == 0){
            count++;
            D5++;
            }
          }
        }
          
      if (A011 == 0){
        if (count < permitCount) {
          done11++;
          }
        if (done11 != 0){
          mp3_play(11);
          Code[0] = '\0';
          if (D6 == 0){
            count++;
            D6++;
            }
          }
        }   
    
      if (A012 == 0){
        if (count < permitCount) {
          done12++;
          }
        if (done12 != 0){
          mp3_play(12);
          Code[0] = '\0';
          if (D6 == 0){
            count++;
            D6++;
            }
          }
        }
      
      if (A013 == 0){
        if (count < permitCount) {
          done13++;
          }
        if (done13 != 0){
          mp3_play(13);
          Code[0] = '\0';
          if (D7 == 0){
            count++;
            D7++;
            }
          }
        }
      
      if (A014 == 0){
        if (count < permitCount) {
          done14++;
          }
        if (done14 != 0){
          mp3_play(14);
          Code[0] = '\0';
          if (D7 == 0){
            count++;
            D7++;
            }
          }
        }
      
      if (A015 == 0){
        if (count < permitCount) {
          done15++;
          }
        if (done15 != 0){
          mp3_play(15);
          Code[0] = '\0';
          if (D8 == 0){
            count++;
            D8++;
            }
          }
        }
      
      if (A016 == 0){
        if (count < permitCount) {
          done16++;
          }
        if (done16 != 0){
          mp3_play(16);
          Code[0] = '\0';
          if (D8 == 0){
            count++;
            D8++;
            }
          }
        }
      
      if (A017 == 0){
        if (count < permitCount) {
          done17++;
          }
        if (done17 != 0){
          mp3_play(17);
          Code[0] = '\0';
          if (D9 == 0){
            count++;
            D9++;
            }
          }
        }
      
      if (A018 == 0){
        if (count < permitCount) {
          done18++;
          }
        if (done18 != 0){
          mp3_play(18);
          Code[0] = '\0';
          if (D9 == 0){
            count++;
            D9++;
            }
          }
        }
      
      if (A019 == 0){
        if (count < permitCount) {
          done19++;
          }
        if (done19 != 0){
          mp3_play(19);
          Code[0] = '\0';
          if (D10 == 0){
            count++;
            D10++;
            }
          }
        }
      
      if (A020 == 0){
        if (count < permitCount) {
          done20++;
          }
        if (done20 != 0){
          mp3_play(20);
          Code[0] = '\0';
          if (D10 == 0){
            count++;
            D10++;
            }
          }
        }
      
      if (A021 == 0){
        if (count < permitCount) {
          done21++;
          }
        if (done21 != 0){
          mp3_play(21);
          Code[0] = '\0';
          if (D11 == 0){
            count++;
            D11++;
            }
          }
        }
      
      if (A022 == 0){
        if (count < permitCount) {
          done22++;
          }
        if (done22 != 0){
          mp3_play(22);
          Code[0] = '\0';
          if (D11 == 0){
            count++;
            D11++;
            }
          }
        }
      
      if (A023 == 0){
        if (count < permitCount) {
          done23++;
          }
        if (done23 != 0){
          mp3_play(23);
          Code[0] = '\0';
          if (D12 == 0){
            count++;
            D12++;
            }
          }
        }
      
      if (A024 == 0){
        if (count < permitCount) {
          done24++;
          }
        if (done24 != 0){
          mp3_play(24);
          Code[0] = '\0';
          if (D12 == 0){
            count++;
            D12++;
            }
          }
        }
      
      if (A025 == 0){
        if (count < permitCount) {
          done25++;
          }
        if (done25 != 0){
          mp3_play(25);
          Code[0] = '\0';
          if (D13 == 0){
            count++;
            D13++;
            }
          }
        }
      
      if (A026 == 0){
        if (count < permitCount) {
          done26++;
          }
        if (done26 != 0){
          mp3_play(26);
          Code[0] = '\0';
          if (D13 == 0){
            count++;
            D13++;
            }
          }
        }
      
      if (A027 == 0){
        if (count < permitCount) {
          done27++;
          }
        if (done27 != 0){
          mp3_play(27);
          Code[0] = '\0';
          if (D14 == 0){
            count++;
            D14++;
            }
          }
        }
      
      if (A028 == 0){
        if (count < permitCount) {
          done28++;
          }
        if (done28 != 0){
          mp3_play(28);
          Code[0] = '\0';
          if (D14 == 0){
            count++;
            D14++;
            }
          }
        }
      
      if (A029 == 0){
        if (count < permitCount) {
          done29++;
          }
        if (done29 != 0){
          mp3_play(29);
          Code[0] = '\0';
          if (D15 == 0){
            count++;
            D15++;
            }
          }
        }
      
      if (A030 == 0){
        if (count < permitCount) {
          done30++;
          }
        if (done30 != 0){
          mp3_play(30);
          Code[0] = '\0';
          if (D15 == 0){
            count++;
            D15++;
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
