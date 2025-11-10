#include <windows.h>
#include <iostream>

int main()
{
	FILE* test;
	
	fopen_s(&test, "C:\\Users\\ggalas\\Documents\\GitHub\\Exo-SECCIA\\wolf .bmp", "rb");
	if (test == nullptr)
	{
		return 0;
	}

	//std::cout << fopen;
	BYTE* buf = new BYTE[5000000];
	size_t size = fread(buf, 1, 5000000, test);
	fclose(test);
	BITMAPFILEHEADER head = {};
	BITMAPINFOHEADER bih = {};
	memcpy(test, buf, size);



	return 0;
}