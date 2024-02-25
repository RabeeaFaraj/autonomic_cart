#include<IRremote.h>
#include <AFMotor.h>
#define HC06 Serial2
#define Speed 100

int IRpinforward=33;
int IRpinright=35;
int IRpinleft=31;
IRrecv IRforwad(IRpinforward);
IRrecv IRright(IRpinright);
IRrecv IRleft(IRpinleft);
decode_results results;

int trigpinlift=47;
int echopinlift=46;
int pingTravelTimelift;
int pingTravelDestancelift;

int trigpinmidright=51;
int echopinmidright=50;
int pingTravelTimemidright;
int pingTravelDestancemidright;

int trigpinmidleft=45;
int echopinmidleft=44;
int pingTravelTimemidleft;
int pingTravelDestancemidleft;

int trigpinright=49;
int echopinright=48;
int pingTravelTimeright;
int pingTravelDestanceright;


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char commad;

int irforward();
int irright();
int irleft();
void forward();
void left();
void right();
void Stop();
int sonicmidleft();
int soniclift();
int sonicright();
int sonicmidright();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC06.begin(9600);
  IRforwad.enableIRIn();
  IRright.enableIRIn();
  IRleft.enableIRIn();
  
  pinMode(trigpinlift,OUTPUT);
  pinMode(echopinlift,INPUT);
  pinMode(echopinmidleft,INPUT);
  pinMode(trigpinmidleft,OUTPUT);
  pinMode(trigpinright,OUTPUT);
  pinMode(echopinright,INPUT);
  pinMode(echopinmidright,INPUT);
  pinMode(trigpinmidright,OUTPUT);
  
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
}

void loop() {
if(HC06.available()){
    commad=HC06.read();
    int x=1;
    int y=2;
    int flag=0;
    int flagir=0;
    Serial.write(commad);
    Serial.println(commad);
    switch(commad){
      case '0':
        while (x==1){
             commad=HC06.read();
             if(commad == '4'){
              Stop();
              break;
             }
            if (150<irforward()){
              forward();
              delay(10);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              while ((sonicmidleft()>35 || sonicmidright()>35)&&(150<irforward())){
                 forward();
                 //delay(10);
                 commad=HC06.read();
                 if(commad == '4'){
                  Stop();
                  break;
                 }
//                 if (150>irforward()){
//                  Stop();
//                  delay(50);
//                  break;
//                 }
               }
              Stop();
              delay(5);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              if ((sonicmidleft()<30 || sonicmidright()<30)&&(150<irleft()|| 150<irright()||150<irforward())){
                 Stop();
                 delay(500);
                 break;
                }
            } 
            if (150<irright()){
              right();
              delay(350);
              Stop();
              delay(100);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              if (150>irforward()){
                right();
                delay(200);
                Stop();
                delay(100);
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
              }
            }
            if (150<irleft()){
              left();
              delay(300);
              Stop();
              delay(100);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              if (150>irforward()){
                left();
                delay(200);
                Stop();
                delay(100);
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
              }
             }
            else{
              if(150>irleft() && 150>irright() && 150>irforward()){
                Stop();
                delay(250);
                left();
                delay(250);
                Stop();
                delay(100);
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
              }
             }
        }
       break;

             case '1':
        while (x==1){
             commad=HC06.read();
             if(commad == '4'){
              Stop();
              break;
             }
            if (150<irforward()){
              forward();
              delay(10);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              while ((sonicmidleft()>35 || sonicmidright()>35)&&(150<irforward())){
                 forward();
                 //delay(10);
                 commad=HC06.read();
                 if(commad == '4'){
                  Stop();
                  break;
                 }
//                 if (150>irforward()){
//                  Stop();
//                  delay(50);
//                  break;
//                 }
               }
              Stop();
              delay(5);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              if ((sonicmidleft()<30 || sonicmidright()<30)&&(150<irleft()|| 150<irright()||150<irforward())){
                 Stop();
                 delay(500);
                 break;
                }
            } 
            if (150<irright()){
              right();
              delay(350);
              Stop();
              delay(100);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              if (150>irforward()){
                right();
                delay(200);
                Stop();
                delay(100);
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
              }
            }
            if (150<irleft()){
              left();
              delay(300);
              Stop();
              delay(100);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              if (150>irforward()){
                left();
                delay(200);
                Stop();
                delay(100);
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
              }
             }
            else{
              if(150>irleft() && 150>irright() && 150>irforward()){
                Stop();
                delay(250);
                right();
                delay(250);
                Stop();
                delay(100);
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
              }
             }
        }
       break;

       case '3':
        while (y==2){
             commad=HC06.read();
             if(commad == '4'){
              Stop();
              break;
             }
            if (150<irforward()){
              flagir=1;
              forward();
              delay(10);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              while ((sonicmidleft()>35 || sonicmidright()>35)&&(150<irforward())){
                 forward();
                 //delay(10);
                 commad=HC06.read();
                 if(commad == '4'){
                  Stop();
                  break;
                 }
//                 if (150>irforward()){
//                  Stop();
//                  delay(50);
//                  break;
//                 }
               }
              Stop();
              delay(5);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              if ((sonicmidleft()<30 || sonicmidright()<30)&&(150<irleft()|| 150<irright()||150<irforward())){
                 Stop();
                 delay(500);
                 break;
                }
            } 
            if (150<irright()){
              flagir=1;
              right();
              delay(350);
              Stop();
              delay(100);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              if (150>irforward()){
                right();
                delay(200);
                Stop();
                delay(100);
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
              }
            }
            if (150<irleft()){
              flagir=1;
              left();
              delay(300);
              Stop();
              delay(100);
              commad=HC06.read();
              if(commad == '4'){
                Stop();
                break;
              }
              if (150>irforward()){
                left();
                delay(200);
                Stop();
                delay(100);
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
              }
             }
            else{
              if(150>irleft() && 150>irright() && 150>irforward()&&(flag>1)){
                Stop();
                delay(250);
                right();
                delay(250);
                Stop();
                delay(100);
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
              }
             }
//              if (150<irforward()){
//              forward();
//              delay(10);
//              while (sonicmidleft()>35 || sonicmidright()>35){
//                 forward();
//                 delay(10);
//              }
//              Stop();
//              delay(5);
//              if ((sonicmidleft()<30 || sonicmidright()<30)&&(150<irleft()|| 150<irright()||150<irforward())){
//                 Stop();
//                 delay(500);
//                 break;
//                }
//              } 
//            if (150<irright()){
//              right();
//              delay(350);
//              Stop();
//              delay(100);
//              if(150>irforward()){
//                right();
//                delay(200);
//                Stop();
//                delay(100);
//              }
//            }
//            if (150<irleft()){
//              left();
//              delay(300);
//              Stop();
//              delay(100);
//              if(150>irforward()){
//                left();
//                delay(200);
//                Stop();
//                delay(100);
//              }
//             }
//            else{
//              if(150>irleft() && 150>irright() && 150>irforward()&&flag>1){
//                Stop();
//                delay(250);
//                left();
//                delay(250);
//                Stop();
//                delay(100);
//              }
//             }
            if (flagir==0){
            while ((sonicmidleft() > 45 || sonicmidright()>45)&&(flag<2)){
            forward();
            delay(10);
            commad=HC06.read();
            if(commad == '4'){
              Stop();
              break;
            }
            }
            if (sonicmidleft() < 45 || sonicmidright()<45) {
               Stop();
               delay(500);
               commad=HC06.read();
               if(commad == '4'){
                  Stop();
                  break;
               }
               if (flag==0){
                while (soniclift()>45){
                  right();
                  commad=HC06.read();
                  if(commad == '4'){
                    Stop();
                    break;
                  }
                }
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
                right();
                delay(30);
                Stop();
                delay(500);
                while(soniclift()<50){
                  forward();
                  commad=HC06.read();
                  if(commad == '4'){
                    Stop();
                    break;
                  }
                }
               Stop();
               delay(500);
               left();
               delay(600);
               Stop();
               delay(500);
               commad=HC06.read();
               if(commad == '4'){
                  Stop();
                  break;
               }
               forward();
               delay(200);
               commad=HC06.read();
               if(commad == '4'){
                  Stop();
                  break;
               }
               }
               if(flag==1) {
                while (sonicright()>45){
                  left();
                }
                commad=HC06.read();
                if(commad == '4'){
                  Stop();
                  break;
                }
                 left();
                 delay(30);
                 Stop();
                 delay(500);
                 while(sonicright()<50){
                    forward();
                    commad=HC06.read();
                    if(commad == '4'){
                      Stop();
                      break;
                    }
                }
               Stop();
               delay(500);
               right();
               delay(620);
               Stop();
               delay(500);
               commad=HC06.read();
               if(commad == '4'){
                  Stop();
                  break;
               }
               forward();
               delay(100);
               }
               commad=HC06.read();
               if(commad == '4'){
                  Stop();
                  break;
               }
               flag++;
               delay(50);
            }
            }
        }
        break;
       }
    }
 }
  



int irforward(){
  int t1=pulseIn(IRpinforward,HIGH,38000);
  int t2=pulseIn(IRpinforward,LOW,38000);
  int t=1000000/(t1+t2);
  //Serial.println(t);
  delay(100);
  return t;
  IRforwad.resume();
}

int irright(){
  int t1=pulseIn(IRpinright,HIGH,38000);
  int t2=pulseIn(IRpinright,LOW,38000);
  int t=1000000/(t1+t2);
  //Serial.println(t);
  delay(100);
  return t;
  IRright.resume();
}

int irleft(){
  int t1=pulseIn(IRpinleft,HIGH,38000);
  int t2=pulseIn(IRpinleft,LOW,38000);
  int t=1000000/(t1+t2);
  //Serial.println(t);
  delay(100);
  return t;
  IRleft.resume();
}

void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void left() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void right() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


int sonicmidleft() {
//  digitalWrite(trigpinmidleft,LOW);
//  delayMicroseconds(10);
  digitalWrite(trigpinmidleft,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpinmidleft,LOW);
  delayMicroseconds(10);
  pingTravelTimemidleft=pulseIn(echopinmidleft,HIGH);
  delay(15);
  pingTravelDestancemidleft=(pingTravelTimemidleft*0.034)/2;
  //Serial.println(pingTravelDestancemid);
  return pingTravelDestancemidleft;
}

int sonicmidright() {
//  digitalWrite(trigpinmidright,LOW);
//  delayMicroseconds(10);
  digitalWrite(trigpinmidright,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpinmidright,LOW);
  delayMicroseconds(10);
  pingTravelTimemidright=pulseIn(echopinmidright,HIGH);
  delay(15);
  pingTravelDestancemidright=(pingTravelTimemidright*0.034)/2;
  //Serial.println(pingTravelDestancemid);
  return pingTravelDestancemidright;
}

int soniclift() {
//  digitalWrite(trigpinlift,LOW);
//  delayMicroseconds(10);
  digitalWrite(trigpinlift,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpinlift,LOW);
  delayMicroseconds(10);
  pingTravelTimelift=pulseIn(echopinlift,HIGH);
  delay(20);
  pingTravelDestancelift=(pingTravelTimelift*0.034)/2;
  //Serial.println(pingTravelDestancemid);
  return pingTravelDestancelift;
}

int sonicright() {
//  digitalWrite(trigpinright,LOW);
//  delayMicroseconds(10);
  digitalWrite(trigpinright,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpinright,LOW);
  delayMicroseconds(10);
  pingTravelTimeright=pulseIn(echopinright,HIGH);
  delay(25);
  pingTravelDestanceright=(pingTravelTimeright*0.034)/2;
  //Serial.println(pingTravelDestancemid);
  return pingTravelDestanceright;
}
