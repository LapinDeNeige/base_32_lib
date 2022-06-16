#include "base.h"

std::string strng="ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";







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
		itt[0] = *tm.c_str();

	}

	if(itt[0]!=i)
		cot=0;

	return cot;
}




void revi (unsigned char inpt_str[6],char outpt_str[9],bool is_full) 
{

	uint8_t rev_arr[9]={0}; //array to save reverted numbers
	


	//===========get 3 last bites from the first var and unit to it two first of second==================
	rev_arr[0]=rev_arr[0]|(inpt_str[0]>>3 & B5); //get first 5 bits from first var


	rev_arr[1]=rev_arr[1]| (inpt_str[0]&B3); //get first 3 bits
	rev_arr[1]=rev_arr[1]<<2| (inpt_str[1]>>6&B2); //shift 2 bits to the left and add first two bits from the next


	rev_arr[2]=rev_arr[2]| (inpt_str[1]>>1&B5);//get mid 5 bits


	rev_arr[3]=rev_arr[3]| (inpt_str[1]&B1); //get last bit
	rev_arr[3]=rev_arr[3]<<4|(inpt_str[2]>>4&B4); //shift to the 4 and get 4 first bit from next


	rev_arr[4]=rev_arr[4]| (inpt_str[2]&B4); //get last 4 bits
	rev_arr[4] = rev_arr[4] << 1 | (inpt_str[3] >> 7 & B1);

	
	rev_arr[5] = rev_arr[5] | (inpt_str[3] >> 2 & B5);

	rev_arr[6] = rev_arr[6] | (inpt_str[3]) & B2;
	rev_arr[6] = rev_arr[6] << 3 | (inpt_str[4] >> 5 & B3);

	rev_arr[7] = rev_arr[7] | (inpt_str[4] & B5);

	for (int i = 0; i < 8; i++)
	{
		if (rev_arr[i] == 0)
		{
			if (is_full)
				outpt_str[i] = 'A';
			else
				outpt_str[i] = '=';
		}
			
		else
			outpt_str[i] = (char)strng[rev_arr[i]];
	}
	outpt_str[8] = '\0';
}







void ret (unsigned char inpt_str[8],uint8_t outpt_str[6]) //get 5 8  bites varables from 3 8  bites chars
{

	unsigned int val_to_invert[8]={0};


	for(int i=0;i<8;i++) //getting a number after an index in the string range
	{

		if (inpt_str[i] == 61) //=
			break;//val_to_invert[i]=0;

	else
		val_to_invert[i]=finInd(inpt_str[i]);


	}
//reverting 5 bit char array into 3 8 bit int array



	outpt_str[0]=outpt_str[0]|(val_to_invert[0]&B5); //first five

	outpt_str[0]=outpt_str[0]<<3|(val_to_invert[1])>>2&B3; //shift first array to 3 bit and get three first bits from second array uniting it to the first array


	outpt_str[1]=outpt_str[1]|(val_to_invert[1]&B2); //get two last first bit from second and free space six bits
	outpt_str[1]=outpt_str[1]<<5|(val_to_invert[2]&B5); //get 5 bit from third
	outpt_str[1]=outpt_str[1]<<1| (val_to_invert[3]>>4&B1); //and get one first from 4th


	outpt_str[2]=outpt_str[2]|val_to_invert[3]&B4;  //get last four bits
	outpt_str[2]=outpt_str[2]<<4|(val_to_invert[4] >> 1 )&B4; //shift to four bits and concate first 4 bits of the nxt number

	outpt_str[3] = outpt_str[3] | (val_to_invert[4] & B1);
	outpt_str[3] = outpt_str[3] << 5 | (val_to_invert[5] & B5);
	outpt_str[3] = outpt_str[3] << 2 | (val_to_invert[6] >> 3 & B2);

	outpt_str[4] = outpt_str[4] | val_to_invert[6] & B3;
	outpt_str[4] = outpt_str[4]<<5 | val_to_invert[7] & B5;

	outpt_str[5] = '\0';
//all right
}











std::string encode(std::string in) //encode char
{

	unsigned char var[6]={0};
    char end[9]={0};
	string ret;

	ret.clear();
	int j = 0;
	for (int i = 0; i < in.size(); i++, j++)
	{
		var[j] = in[i];

		if ((j + 1) % 5 == 0)
		{

			//var[strlen(var)] = '\0';
			revi(var, end,1); //encode

			ret.append(end, strlen(end));
			j = -1;
			memset(var, 0, 5);
			memset(end, 0, 8);

		}
	}



	if(j % 5>0)
	{
		revi(var,end,0);
		ret.append(end, strlen(end));


	}

	return ret;
}





std::string decode(string in) //decode string
{

	uint8_t vr[6]={0}; //decoded
	unsigned char dc[8]={0}; //encoded

	std::string rt="";


	int j=0;

	for (int i = 0; i < in.size(); i++, j++)
	{
		dc[j] = in[i]; //to buffer for encoding

		if ((i + 1) % 8 == 0) //reached 8
		{
			ret(dc, vr); //encode
			rt.append((char*)vr, 0, 5); //concate 5 bytes

			memset(vr, 0, 3);
			memset(dc, 0, 5);
			j = -1;
		}

	}

	


return rt;
}






