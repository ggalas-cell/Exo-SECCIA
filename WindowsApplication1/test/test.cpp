#include <windows.h>
#include <iostream>

int main()			// PARAMETRE D
{
	FILE* test;
	errno_t error;
	error = fopen_s(&test, "C:\\Users\\ggalas\\Documents\\GitHub\\Exo-SECCIA\\wolf 1.bmp", "rb");
	if (error != 0)return 0;
	
	//std::cout << fopen;
	BYTE* buf = new BYTE[50000000];	// (source)	//lecture du file -> buffer 
	size_t size = fread(buf, 1, 50000000, test);		//idem
	fclose(test);
	BITMAPFILEHEADER head = {};	//destination
	BITMAPINFOHEADER bih = {};
	memcpy(&head, buf, sizeof(BITMAPFILEHEADER));
	memcpy(&bih, buf+ sizeof(BITMAPFILEHEADER), sizeof(BITMAPINFOHEADER));
	std::cout << "=== Bit File Header ===\n";
	std::cout << (char)(head.bfType & 0xFF) << (char)(head.bfType >> 8) << "\n"; 
	std::cout << "Taille fichier :" << head.bfSize << " bytes\n";
	std::cout << "offset des pixels :" << head.bfOffBits << " bytes\n";
	std::cout << "=== Bit Info Header ===\n";
	std::cout << "Taille header :" << bih.biSize << " bytes\n";
	std::cout << "Img width :" << bih.biWidth << " pixels\n";
	std::cout << "Img height :" << bih.biHeight << " pixels\n";
	std::cout << "Color planes :" << bih.biPlanes << "\n";
	std::cout << "Bits per pixel :" << bih.biBitCount << "\n";
	std::cout << "compression :" << bih.biCompression << "\n";
	std::cout << "Img size:" << bih.biSizeImage << " bytes\n";
	if (head.bfType != 0x4D42)
		std::cout << "error not a valid bmp file\n";

	delete[] buf;


	return 0;
}