#include <string>
#include <iostream>
#include "base.h"

int main()
{
std::string txt="quakequaka";
std::string rst; //result

rst=encode(txt);

std::cout<<rst<<"\n";

txt.clear();

txt=decode(rst);
std::cout<<txt;

return 0;
}
