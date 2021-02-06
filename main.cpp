
#include "base.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#define CH 1 //char 
#define IN 2 //int

#define TIM 340000


/*
test for base32 library

*/


std::string chr_gn(short sz) //random generate of char
{

std::string srt="";

for(int i=0;i<sz;i++)
{

char pp=rand()%23+'a';

std::string th=""; //tmp str
th.append(&pp,1); //append to tmp string
srt.append(th);//append to string
}

return srt;
}


inline void prn_hlp()
{
std::cout<<"Usage\n";
std::cout<<"tst -s size of digits\n";
}



int tst_char(int sz) //test in char
{



for(int i=1;i<=sz;i++)
{

std::cout<<"\n\n";
srand(time(0));
std::string  gn=chr_gn(i); //generate random 

std::cout<<"\n\nmessage is "<<gn.c_str()<<"\n\n";
usleep(TIM);

std::string encd=encode(gn);

std::cout<<"\nencoded message is "<<encd<<"\n";
usleep(TIM);

std::string dcd=decode(encd);

std::cout<<"\ndecoded message is "<<dcd<<"\n";
usleep(TIM);

if(gn.compare(dcd)!=0) //not 
{
std::cout<<"\nsome error:\n";
std::cout<<dcd<<"not equal to "<<gn;
break;
}

//gn.clear();

}

return 0;
}



int main(int argc,char **argv)
{
//uint8_t vr[5]={87,65,45,56,43};

int zs=5;
bool rt=CH; //in char letters

/////////////
//Arguments
//tst -s size -h help 
/////////////

if(argc>=2 && argc <=5) //arg must be between 2 and 5 WORDS
{
for(int o=1;o<argc;o++)
{


if(strcmp(&argv[o][0],"-s")==0) //size argument
{
//printf("size:\n ");
char *ty=&argv[o][3];
int tr=atoi(ty);

if(tr<=40&&tr>0)
	zs=tr;
else
{
printf("\nnot appropriate size\n");
printf("\nmust be between 1 and 40 letters\n ");
return -1;
}
o++; continue;
}




else if(strcmp(&argv[o][0],"-h")==0)
{
prn_hlp();
return -2;
}

else
{
prn_hlp();
return -4;
}

}
}
 
if(argc>5)
{
prn_hlp();
return -6;
}


tst_char(zs);




return 0;
}


