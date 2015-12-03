
int p0=0,p1=1,p2=2,p3=3;
int l0,l1,l2,l3;    
const int motor0=3,motor1=5,motor2=6,motor3=9;
int speakerPin = 9;
int length = 15; // the number of notes
int playmusic=0,rnote;
/*do=c
re=d
mi=e
fa=f
sol=g
la=a
si=b
*/
char notes1[] = "aaaagggcacggfgfgeededecc "; 
char notes2[] = "eeedddaagaaeeddcggfgfgee ";
char notes3[] = "ffggaacacacacggfgfaacded ";
int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    analogWrite(speakerPin,255);
    delayMicroseconds(tone);
    analogWrite(speakerPin,0);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 261, 293, 329, 349, 392, 440, 494, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}


void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);   
  pinMode(motor0,OUTPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  //Scheduler.startLoop(loop2);
}
 
void loop() {
  l0 = analogRead(p0); 
  analogWrite(motor0,detectForce(l0)); 
  delay(100);
  l1 = analogRead(p1);
  analogWrite(motor1,detectForce(l1)); 
  delay(100);
  l2 = analogRead(p2);
  analogWrite(motor2,detectForce(l2)); 
  delay(100);
  /*l3 = analogRead(p3);
  if(l3>0)
    analogWrite(motor3,detectForce(l3)); 
  delay(100);*/
  music();
} 
void music(){
  if(playmusic==1){
     rnote=random(1,3);
     for (int i = 0; i < length; i++) {
        if(rnote==1){
          if (notes1[i] == ' ') {
            delay(beats[i] * tempo); // rest
          } else {
            playNote(notes1[i], beats[i] * tempo);
          }
        }
        if(rnote==2){
          if (notes2[i] == ' ') {
            delay(beats[i] * tempo); // rest
          } else {
            playNote(notes2[i], beats[i] * tempo);
          }
        }
        if(rnote==3){
          if (notes3[i] == ' ') {
            delay(beats[i] * tempo); // rest
          } else {
            playNote(notes3[i], beats[i] * tempo);
          }
        }
        // pause between notes
        delay(tempo / 2); 
      }
      playmusic=0;
  }
}

int detectForce(int fsrReading){
  if (fsrReading < 10) {
    Serial.println(" - No pressure");
    return 0;
  } else if (fsrReading < 200) {
    Serial.println(" - Light touch");
    return 90;
  } else if (fsrReading < 500) {
    Serial.println(" - Light squeeze");
    return 140;
  } else if (fsrReading < 800) {
    Serial.println(" - Medium squeeze");
    return 190;
  } else{
    Serial.println(" - Big squeeze");
    playmusic=1;
    return 230;
  }
  delay(500);
}
