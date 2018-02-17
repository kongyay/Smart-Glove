// Pins
// Fill in the pins you used on your own setup.
// WARNING: Make sure you have resistors connected between the rows and the arduino.

#include "LedControlMS.h"
#include "pitches.h"

#define F_THUMB A0
#define F_INDEX A1
#define F_MIDDLE A2
#define F_RING A3
#define F_PINKY A4
#define SOUND 8
#define arr_len( x )  ( sizeof( x ) / sizeof( *x ) )

//int dataPin, int clkPin, int csPin, int numDevices
LedControl lc=LedControl(12,11,10,1);

// เหลือง ส้ม เขียว ม่วง น้ำเงิน

// The display buffer
// It's prefilled with a smiling face (1 = ON, 0 = OFF)
byte smile[] = {B01111110,B10000001,B10100101,B00000000,B00011000,B01000010,B00111100,B00000000};
byte nutral[] = {B11111111,B10000001,B10100101,B10000001,B10000001,B10111101,B10000001,B11111111};
byte angry[] = {B11111111,B10000001,B10100101,B10000001,B00000000,B00111100,B01000010,B00000000};
byte spriteBae[] = {B00000000,B00000000,B00000000,B10101001,B10101001,B10101001,B10101001,B10101111};
byte spriteGum[] = {B01100000,B01100000,B00000000,B11110111,B10010001,B10010001,B10010001,B10010001};
byte spriteHand[] = {B01010000,B11110000,B00000000,B11010111,B11010001,B01010101,B11110101,B11010111};
byte spriteNum[10][8] = {
  {B00000000,B00111100,B00100100,B00100100,B00100100,B00100100,B00100100,B00111100},
  {B00000000,B00001000,B00011000,B00001000,B00001000,B00001000,B00001000,B00011100},
  {B00000000,B00011000,B00100100,B00000100,B00001000,B00010000,B00100000,B00111100},
  {B00000000,B00011000,B00100100,B00000100,B00011100,B00000100,B00100100,B00011000},
  {B00000000,B00000100,B00001100,B00010100,B00100100,B00111110,B00000100,B00000100},
  {B00000000,B00111100,B00100000,B00100000,B00111100,B00000100,B00000100,B00111100},
  {B00000000,B00111100,B00100000,B00100000,B00111100,B00100100,B00100100,B00111100},
  {B00000000,B00111100,B00000100,B00000100,B00000100,B00000100,B00000100,B00000100},
  {B00000000,B00111100,B00100100,B00100100,B00111100,B00100100,B00100100,B00111100},
  {B00000000,B00111100,B00100100,B00100100,B00111100,B00000100,B00000100,B00111100}
};
// edit
byte spriteOk[] = { B00000000,B00000000,B11101001,B10101010,B10101100,B10101010,B11101001,B00000000};
byte spriteLove2[] = {B00000000,B01100110,B11111111,B11111111,B11111111,B01111110,B00111100,B00011000};
byte spriteLove1[] = {B00000000,B00000000,B01101100,B11111110,B11111110,B01111100,B00111000,B00000000};
byte spriteRock[] = {B00011000,B00011000,B00011000,B00011000,B00011000,B00000000,B00011000,B00011000};
byte spriteCall[] = {B00000110,B00001111,B00001100,B10001100,B01001100,B00101111,B00010110,B00000000};
byte spriteGo1[] = {B11111111,B00000000,B01100111,B10000101,B10000101,B10110101,B10010101,B01100111};
byte spriteGo2[] = {B10100101,B00000000,B01100111,B10000101,B10000101,B10110101,B10010101,B01100111};
byte spriteGood2[] = {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
byte spriteGood1[] = {B00111100,B01000010,B10100101,B10000001,B10000001,B10011001,B01000010,B00111100};
byte spriteFuck2[] = {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};
byte spriteFuck1[] = {B00111100,B01000010,B10100101,B10000001,B10011001,B10000001,B01000010,B00111100};
byte spritePromise[] = {B00000000,B00011110,B00010010,B01111010,B01011110,B01001000,B01111000,B00000000};
// circle
byte spriteCircle[21][8] = {
  {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111}
, {B11011111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111}
,{ B11001111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111}
,{ B11000111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111}
,{ B11000011,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111}
,{ B11000011,B11111101,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111}
,{ B11000011,B11111101,B11111110,B11111111,B11111111,B11111111,B11111111,B11111111}
,{ B11000011,B11111101,B11111110,B11111110,B11111111,B11111111,B11111111,B11111111}
,{ B11000011,B11111101,B11111110,B11111110,B11111110,B11111111,B11111111,B11111111}
,{ B11000011,B11111101,B11111110,B11111110,B11111110,B11111110,B11111111,B11111111}
,{ B11000011,B11111101,B11111110,B11111110,B11111110,B11111110,B11111101,B11111111}
,{ B11000011,B11111101,B11111110,B11111110,B11111110,B11111110,B11111101,B11111011}
,{ B11000011,B11111101,B11111110,B11111110,B11111110,B11111110,B11111101,B11110011}
,{ B11000011,B11111101,B11111110,B11111110,B11111110,B11111110,B11111101,B11100011}
,{ B11000011,B11111101,B11111110,B11111110,B11111110,B11111110,B11111101,B11000011}
,{ B11000011,B11111101,B11111110,B11111110,B11111110,B11111110,B10111101,B11000011}
,{ B11000011,B11111101,B11111110,B11111110,B11111110,B01111110,B10111101,B11000011}
,{ B11000011,B11111101,B11111110,B11111110,B01111110,B01111110,B10111101,B11000011}
,{ B11000011,B11111101,B11111110,B01111110,B01111110,B01111110,B10111101,B11000011}
,{ B11000011,B11111101,B01111110,B01111110,B01111110,B01111110,B10111101,B11000011}
,{ B11000011,B10111101,B01111110,B01111110,B01111110,B01111110,B10111101,B11000011}
};



int melody1[] = {
  NC4, NG3,NG3, NA3, NG3,0, NB3, NC4};
int correct[] = {
  NC5, NG4, NC5, NG4, NC5, NG4, NC5, NG4};
int tel[] = {
  NE5, ND5, NFS4, NGS4,   NCS5, NB4, ND4, NE4,  NB4,NA4,NCS4,NE4,NA4};
int rock[] = {
  NB4, NCS4, ND4, NE4, NFS4,    NB4, NCS4, ND4, NE4, NFS4,    NE4, ND4, NE4, NFS4, NE4,ND4, NE4,NFS4,NG4,NFS4,0,NFS4};
int fuck1[] = {
  NF2,NG2,NA2,NB2,NC3,ND3,NE3,NF3};
int fuck2[] = {
  NG5 ,NDS5 ,ND5 ,NC5 ,ND5 ,NC5 ,ND5,NC5,ND5   ,NAS4 ,NC5,NAS4,NC5, ND5 ,NG4 , NC5, NAS4,NG4};
int love1[] = {
  ND5,NDS5,NE5,NF5,NFS5,NG5,NGS5,NA5};
int love2[] = {
  NFS5,NG5,NGS5,NA5,NAS5,NB5,NC6,NCS6};
int hi[] = {
  NA6,NG6};
int go[] = {
  NB4,NB4,NB4,NB4};
int promise[] = {
  NB4,NC5,NB4,NC5};
int ok[] = {
  NAS5,NF5,NAS5,NF5};
int count[] = {
  NB4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int d_melody[] = {
  4, 8, 8, 4,4,4,4,4 };
int d_correct[] = {
  8, 8, 8, 1, 8,8,8,1 };
int d_tel[] = {
  8, 8, 4, 4, 8,8,4,4,  8,8,4,4,1};
int d_rock[] = {
  8,8,8,8,2 ,8,8,8,8,2 ,8,8,8,8,8,8,8,8,8,8,8,1};
int d_fuck1[] = {
  16,16,16,16,16,16,16,16};
int d_fuck2[] = {
  8,8,8,8,8,8,12,12,4 ,8,12,12,8,8,8,8,8,12};
int d_love1[] = {
  8,8,8,8,8,8,8,8};
int d_love2[] = {
  8,8,8,8,8,8,8,8};
int d_hi[] = {
  16,8};
int d_go[] = {
  16,16,16,1};
int d_promise[] = {
  16,16,16,1};
int d_ok[] = {
  16,16,16,1};
int d_count[] = {
  13};

int dataInput[5][51];
int dataOutput[5];

int lastOutput[5];
int lastPlay[5];
int counterState[5];

bool stateChange = false;

int indexInput=0;
int indexOutput=0;
int avgData[5] = {0,0,0,0,0};

int FINGERS[] = {F_THUMB, F_INDEX , F_MIDDLE , F_RING, F_PINKY };


bool isReady = false;

void writeBytes(byte arr[]) {
  for(int i=0;i<8;i++) {
    lc.setRow(0,i,arr[7-i]);
  }
}

void PlaySound(int melody[],int noteDurations[],int index) {
  for (int thisNote = 0; thisNote < index; thisNote++) {
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(SOUND, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(SOUND);
  }
}

void writeSetUpHand() {
  /* here is the data for the characters */\
  for(int i=0;i<4;i++) {
    writeBytes(spriteBae);
    delay(500);
    writeBytes(spriteHand);
    delay(500);
  }
  lc.clearDisplay(0);
  
}
void writeSetUpGum(){
  for(int i=0;i<4;i++) {
    writeBytes(spriteGum);
    delay(500);
    writeBytes(spriteHand);
    delay(500);
  }
  lc.clearDisplay(0);
}

void setup() {
    // Open serial port
    Serial.begin(9600);
    
    pinMode(F_THUMB,INPUT);
    pinMode(F_INDEX,INPUT);
    pinMode(F_MIDDLE,INPUT);
    pinMode(F_RING,INPUT);
    pinMode(F_PINKY,INPUT);

    /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
  
  Calibrate();
}

void loop() {
    if(isReady) {
      
      
      setOn();
      stateCheck();
      
      if(stateChange && !compare(lastPlay,dataOutput)) {
          for(int i=0;i<5;i++) {
            lastPlay[i] = dataOutput[i];
          }
          allCase();
          
      }
        
      
    }
}

void stateCheck() {
      stateChange = false;
      for(int i=0;i<5;i++) {
        if(lastOutput[i] != dataOutput[i]) {
          counterState[i] = 0;
          stateChange = false;
        } else {
          counterState[i]++;
        }
        
        if(counterState[i]>=5) {
            if(i==0 || stateChange!=false) stateChange = true;
        } 
        else {
           stateChange = false;
        }
        
        
      }
}

bool compare(int a[],int b[]) {
  for(int i=0;i<5;i++) {
    if(a[i]!=b[i])
      return false;
  }
  return true;
}

void Calibrate() {
    int avg1[5];
    int avg2[5];
    float time=0.0;
  
    bool gum=false;
    isReady = false;
    for(int i=0;i<2;i++){
      
      indexInput=0;
      time=0.0;
      if(!gum)
        writeSetUpHand();
      else
        writeSetUpGum();
      do{
        
        writeBytes(spriteNum[5-(int)time]);    
        
        setLog();
        delay(100);
        time+=0.1;
      }while(time<=5);

      if(!gum) writeBytes(spriteGum); 

      for(int i=0;i<5;i++){
        if(!gum) {
          avg1[i] = averageLog(dataInput[i]); 
        }
         else {
          avg2[i] = averageLog(dataInput[i]); 
          avgData[i]=((avg1[i]+avg2[i])/2);
          Serial.print(i);
          Serial.print(".) Average =");  
          Serial.println(avgData[i]);
         }
      }
      
      PlaySound(melody1,d_melody,sizeof(melody1)/sizeof(int));
      gum=true;
      
      
    }
    isReady = true;
}

void setLog(){
  Serial.print(indexInput);
  Serial.print(".)");
  for(int i=0;i<5;i++) {
    dataInput[i][indexInput]=analogRead(FINGERS[i]);
    if(indexInput!=0 && dataInput[i][indexInput-1] != 0 && (dataInput[i][indexInput] > dataInput[i][indexInput-1]*2 || dataInput[i][indexInput] <0)) 
      dataInput[i][indexInput] = dataInput[i][indexInput-1];
    Serial.print(dataInput[i][indexInput]);
    Serial.print("* ");
  }
  Serial.println("");
  indexInput++;
}

int averageLog(int dataInput[]){
  long long int avg = 0;
    for(int i=0;i<indexInput;i++){
      avg+=dataInput[i];  
    }
    avg/=indexInput;

    return avg;
   
}

void setOn(){
  for(int i=0;i<5;i++) {
    lastOutput[i] = dataOutput[i];
    
    if(analogRead(FINGERS[i])<avgData[i]){
      dataOutput[i]=1;
    }else{
      dataOutput[i]=0;  
    }
    
  }
  
  Serial.print("Data = ");
    for(int i=0;i<5;i++) {
      Serial.print("(");
      Serial.print(dataOutput[i]);
      Serial.print(")->");
      Serial.print(analogRead(FINGERS[i]));
      Serial.print(" ");
    }
  Serial.println("");
  
}
void allCase(){
  Serial.println("Case Change");
  if(dataOutput[0]==1&&dataOutput[1]==1&&dataOutput[2]==1&&dataOutput[3]==1&&dataOutput[4]==1){
    startCounter();
  }
  else if(dataOutput[0]==1&&dataOutput[1]==1&&dataOutput[2]==0&&dataOutput[3]==0&&dataOutput[4]==0){
    writeBytes(spriteOk);  // OK
    PlaySound(ok,d_ok,sizeof(ok)/sizeof(int));
  }
  
  else if(dataOutput[0]==0&&dataOutput[1]==0&&dataOutput[2]==1&&dataOutput[3]==1&&dataOutput[4]==0){ 
    writeBytes(spriteLove1);  // <3
    PlaySound(love1,d_love1,sizeof(love1)/sizeof(int));
    writeBytes(spriteLove2);
    PlaySound(love2,d_love2,sizeof(love2)/sizeof(int));
  }
  
  else if(dataOutput[0]==1&&dataOutput[1]==0&&dataOutput[2]==1&&dataOutput[3]==1&&dataOutput[4]==0){
    writeBytes(spriteRock);  // Rock  
    PlaySound(rock,d_rock,sizeof(rock)/sizeof(int));
  }
  
  else if(dataOutput[0]==0&&dataOutput[1]==1&&dataOutput[2]==1&&dataOutput[3]==1&&dataOutput[4]==0){
    writeBytes(spriteCall);  // Call me   
    PlaySound(tel,d_tel,sizeof(tel)/sizeof(int));
  }
  
  else if(dataOutput[0]==0&&dataOutput[1]==0&&dataOutput[2]==1&&dataOutput[3]==1&&dataOutput[4]==1){   
    writeBytes(spriteGo1);  // Go
    delay(200);
    writeBytes(spriteGo2);  
    PlaySound(go,d_go,sizeof(go)/sizeof(int));
  }
  
  else if(dataOutput[0]==0&&dataOutput[1]==1&&dataOutput[2]==1&&dataOutput[3]==1&&dataOutput[4]==1){
    writeBytes(spriteGood1);  // Good
    delay(200);
    writeBytes(spriteGood2);  
    PlaySound(correct,d_correct,sizeof(correct)/sizeof(int));
  }
  
  else if(dataOutput[0]==1&&dataOutput[1]==1&&dataOutput[2]==0&&dataOutput[3]==1&&dataOutput[4]==1){
    writeBytes(spriteFuck1);  // Fuck
    PlaySound(fuck1,d_fuck1,sizeof(fuck1)/sizeof(int));
    writeBytes(spriteFuck2);  
    PlaySound(fuck2,d_fuck2,sizeof(fuck2)/sizeof(int));
  }
  
  else if(dataOutput[0]==1&&dataOutput[1]==1&&dataOutput[2]==1&&dataOutput[3]==1&&dataOutput[4]==0){
    writeBytes(spritePromise);  // Promise
    PlaySound(promise,d_promise,sizeof(promise)/sizeof(int));
  }
  
  else{
      if(dataOutput[0]+dataOutput[1]+dataOutput[2]+dataOutput[3]+dataOutput[4]==0){
        writeBytes(spriteNum[5]);  
      }else if(dataOutput[0]+dataOutput[1]+dataOutput[2]+dataOutput[3]+dataOutput[4]==1){
        writeBytes(spriteNum[4]);  
      }else if(dataOutput[0]+dataOutput[1]+dataOutput[2]+dataOutput[3]+dataOutput[4]==2){
        writeBytes(spriteNum[3]);  
      }else if(dataOutput[0]+dataOutput[1]+dataOutput[2]+dataOutput[3]+dataOutput[4]==3){
        writeBytes(spriteNum[2]);  
      }else if(dataOutput[0]+dataOutput[1]+dataOutput[2]+dataOutput[3]+dataOutput[4]==4){
        writeBytes(spriteNum[1]);  
      }else if(dataOutput[0]+dataOutput[1]+dataOutput[2]+dataOutput[3]+dataOutput[4]==5){
        writeBytes(spriteNum[0]);  
      }
      PlaySound(hi,d_hi,sizeof(hi)/sizeof(int));
  }
  
}


void startCounter() {
  int counted = 0;
  bool isCount = true;
  while(isCount) {
    for(int i=0;i<21;i++) {
      writeBytes(spriteCircle[i]);
      delay(900/21); 
    }
    writeBytes(spriteNum[(++counted)%10]);
    Serial.println(counted);
    PlaySound(count,d_count,sizeof(count)/sizeof(int));
    setOn();
    for(int i=0;i<5;i++) {
      if(lastOutput[i] != dataOutput[i]) {
        isCount = false;
      }
    }
    
  }
  writeBytes(spriteNum[(counted)%10]);
  PlaySound(melody1,d_melody,sizeof(melody1)/sizeof(int));  
}



