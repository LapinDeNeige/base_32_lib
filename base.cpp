

#include "base.h"
#define B1 0b1
#define B2 0b11
#define B3 0b111
#define B4 0b1111
#define B5 0b11111
#define B8 0b11111111

std::string strng="=ABCDEFGHIJKLMNOPQRSTUVWXYZ23456";







inline uint8_t  finInd(char i) //find index of char
{
uint8_t cot=0;
char itt[1]={0};

std::string tm=" ";

while(itt[0]!=i) //until the string under current index is not equal
{
if(cot==strng.size()-1)
	break;               //the char to be searched
cot++;
tm=strng.at(cot);
strcpy(&itt[0],tm.c_str());

}
if(itt[0]!=i)
	cot=0;

return cot;
}




void revi (uint8_t inpt_str[3],unsigned char outpt_str[5]) //here get 5 8 bit numbers and revers them into 8 5 bit
{

uint8_t rev_arr[5]={0}; //array to save reverted numbers



//===========get 3 last bites from the first var and unit to it two first of second==================
rev_arr[0]=rev_arr[0]|(inpt_str[0]>>3 & B5); //get first 5 bits from first var


rev_arr[1]=rev_arr[1]| (inpt_str[0]&B3); //get first 3 bits
rev_arr[1]=rev_arr[1]<<2| (inpt_str[1]>>6&B2); //shift 2 bits to the left and add first two bits from the next


rev_arr[2]=rev_arr[2]| (inpt_str[1]>>1&B5);//get mid 5 bits


rev_arr[3]=rev_arr[3]| (inpt_str[1]&B1); //get last bit
rev_arr[3]=rev_arr[3]<<4|(inpt_str[2]>>4&B4); //shift to the 4 and get 4 first bit from next


rev_arr[4]=rev_arr[4]| (inpt_str[2]&B4); //get last 4 bits


for(int i=0;i<5;i++)
{

if(rev_arr[i]==0)
    outpt_str[i]=61; //=


else
{
    uint8_t temp_var=rev_arr[i];
    outpt_str[i]=strng.c_str()[temp_var];
}

}




}




void ret (unsigned char inpt_str[5],uint8_t outpt_str[3]) //get 5 8  bites varables from 3 8  bites chars
{

uint8_t val_to_invert[5]={0};


for(int i=0;i<5;i++) //getting a number after an index in the string range
{

 if(inpt_str[i]==61) //=
 	 val_to_invert[i]=0;

else
	val_to_invert[i]=finInd(inpt_str[i]);


}



//reverting 5 bit char array into 3 8 bit int array



outpt_str[0]=outpt_str[0]|(val_to_invert[0]&B5); //first five

outpt_str[0]=outpt_str[0]<<3;
outpt_str[0]=outpt_str[0]|(val_to_invert[1])>>2&B3; //shift first array to 3 bit and get three first bits from second array uniting it to the first array


outpt_str[1]=outpt_str[1]|(val_to_invert[1]&B2); //get two last first bit from second and free space six bits
outpt_str[1]=outpt_str[1]<<5|(val_to_invert[2]&B5); //get 5 bit from third
outpt_str[1]=outpt_str[1]<<1| (val_to_invert[3]>>4&B1); //and get one first from 4th


outpt_str[2]=outpt_str[2]|val_to_invert[3]&B4;  //get last four bits
outpt_str[2]=outpt_str[2]<<4|(val_to_invert[4])&B4; //shift to four bits and concate first 4 bits of the nxt number


//all right
}











std::string encode(std::string in) //encode char
{


char ch[1];
uint8_t var[3]={0};
unsigned char end[5]={0};

string ret;
ret.clear();
int j=0;

for(int i=0;i<in.size();i++,j++)
{
ch[0]=in[i];
var[j]=static_cast<uint8_t>(ch[0]);

if((j+1)%3==0)
{
revi(var,end); //encode
j=-1;


ret.append((const char*)end,sizeof(end)/sizeof(unsigned char));


const char *y=ret.c_str();

memset(var,0,3);
memset(end,0,5);

}

}


if(j%3>0)
{
revi(var,end);
ret.append((char*)end,sizeof(end)/sizeof(unsigned char));

//memset(var,0,3);
//memset(end,0,5);
}

return ret;
}





std::string decode(string in) //decode string
{

uint8_t vr[3]={0}; //decoded
unsigned char dc[5]={0}; //encoded

std::string rt="";

char tm[3]={0};
int j=0;

for(int i=0;i<in.size();i++,j++)
{
dc[j]=in[i]; //to buffer for encoding

if((i+1)%5==0) //reached 8
{
ret(dc,vr); //encode

j=-1;



for(int o=0;o<3;o++) //from uint8 to char
	tm[o]=static_cast<char>(vr[o]);

rt.append(tm,0,3); //concate 3 bytes

memset(vr,0,3);
memset(dc,0,5);
}

}

return rt;
}






