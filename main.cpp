#include "mbed.h"
//Create a digitalOut connected to the 7 segments
DigitalOut Disp1(PTC6,PTC5,PTC16,PTA16,PTA17,PTC10,PTC11,PTC13); 


//Create DigitalIns to probe rows
DigitalIn row1(PTE5) // row1 Input
DigitalIn row2(PTE4) // row2 Input
DigitalIn row3(PTE3) // row3 Input
DigitalIn row4(PTE2) // row4 Input
//Create DigitalOuts to scan columns
DigitalOut col1(PTB11)// col1 output
DigitalOut col2(PTB10)// col2 output
DigitalOut col3(PTB9)// col3 output
DigitalOut col4(PTB8)// col4 output
void setvdd(); 
{
vdd=1;
}
//Pul a single column Lo
void setCol1Lo() {
col1=0;
col2=1;
col3=1;
col4=1;
}
void setCol2Lo() {
col1=1;
col2=0;
col3=1;
col4=1;
}
void setCol3Lo() {
col1=1;
col2=1;
col3=0;
col4=1;
}
void setCol4Lo() {
col1=1;
col2=1;
col3=1;
col4=0;
}
//Pull all columns Hi
void setColsHi() {
col1=1;
col2=1;
col3=1;
col4=1;
}
//Display the digit on 7-seg
void key_0() {
Disp1=0x7E;
}
void key_1() {
Disp1=0x30;
}
void key_2() {
Disp1=0x6D;
}
void key_3() {
Disp1=0x79;
}
void key_4() {
Disp1=0x33;
}
void key_5() {
Disp1=0x5B;
}
void key_6() {
Disp1=0x5F;
}
void key_7() {
Disp1=0x70;
}
void key_8() {
Disp1=0x7F;
}
void key_9() {
Disp1=0x7B;
}
//Display nothing on 7-seg
void key_nope() {
Disp1=0xC0;
}
// Key scan function
void keyscan() {
setColsHi();
wait(0.2);
setCol1Lo();
wait(0.2);
if (row1==0)
key_1();
if (row2==0)
key_4();
if (row3==0)
key_7();
if (row4==0)
key_F();
wait(0.2)
setCol2Lo();
wait(0.2)
if (row1==0)
key_2();
if (row2==0)
key_5();
if (row3==0)
key_8();
if (row4==0)
key_0();
wait(0.2)
setCol3Lo();
wait(0.2)
if (row1==0)
key_3();
if (row2==0)
key_6();
if (row3==0)
key_9();
if (row4==0)
key_E();
wait(0.2)
setCol4Lo();
wait(0.2)
if (row1==0)
key_A();
if (row2==0)
key_B();
if (row3==0)
key_C();
if (row4==0)
key_D();
wait(0.2)
}
// main program routine
int main() {
int input1;
int input2:
char operation;
int result;
setvdd(); 
while (1) { 
  input1=keyscan();
  operation=keyscan();
  input2=keyscan();

wait(0.2);
}

if(key_A()){
 result=input1+input2;
}
  else if(key_B()){
  result=input1-input2;
}
if(key_D()){
  keyscan(result);
}
if (result > 9) {
  Disp1=0x47;
}
if(result<0){
  Disp1=0x77;
}



}