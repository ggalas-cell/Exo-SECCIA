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
	BYTE* buf = new BYTE[5000000];	// (source)	//lecture du file -> buffer 
	size_t size = fread(buf, 1, 5000000, test);		//idem
	fclose(test);
	BITMAPFILEHEADER head = {};	//destination
	BITMAPINFOHEADER bih = {};
	memcpy(&head, buf, sizeof(BITMAPFILEHEADER));
	memcpy(&bih, buf+ sizeof(BITMAPFILEHEADER), sizeof(BITMAPINFOHEADER));
	std::cout << (char)(head.bfType & 0xFF) << (char)(head.bfType >> 8) << "\n";
	std::cout << "Taille :" << head.bfSize << "bytes\n";
	std::cout << "offset des pixels :" << head.bfOffBits << "bytes\n";


	return 0;
}