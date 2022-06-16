#include <iostream>

#include <string.h>
#include <bitset>

#ifndef _BASE_H
#define _BASE_H

#define B1 0b1
#define B2 0b11
#define B3 0b111
#define B4 0b1111
#define B5 0b11111
#define B8 0b11111111


using namespace std;

/*
Encodes message string
@param string to encode
@ret value encoded string
*/
string encode(string in); 

/*
Decodes message string
@param string to decode
@ret value decoded string
*/
string decode(string in);

#endif // _BASE_H
