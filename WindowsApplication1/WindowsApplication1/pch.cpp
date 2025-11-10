#include <windows.h>
#include <filesystem>
#include <iostream>
#include "pch.h"


int main()
{
	FILE* test;		
	test = fopen("\Documents\GitHub\Exo - SECCIA\wolf.bmp", "rb");
	if (test == nullptr)
	{
		return 0;
	}
	
	std::cout << fopen;
		fread;
	return 0;
}