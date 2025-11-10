#include <iostream>

int main()
{
	unsigned char a=2; //caractère défini en binaire
	a = 0b11; //binaire
	a = a << 1; //deplacement case de 1 vers la gauche devient donc 110 (passe de 3  a 6)
	a = a << 1; //déplacement de 1 case vers la gauche devient donc 1100 (passe de 6 a 12)
	std::cout << a<<"\n";
	unsigned char b= 5;
	b = (b << 1) >> 1;
	std::cout << b;

}