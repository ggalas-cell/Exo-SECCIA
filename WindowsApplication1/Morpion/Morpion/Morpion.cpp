#include <iostream>
#include <array>
#include <conio.h>

using Board = std::array<char, 9>;
int parties = 0;
unsigned int GameInfo;
void afficherPlateau(const Board& b)
{
	system("cls");

    std::cout << "Morpion (Tic-Tac-Toe) en C++\n";
    std::cout << "Disposition des cases :\n";
    std::cout << " 7 | 8 | 9\n";
    std::cout << "---+---+---\n";
    std::cout << " 4 | 5 | 6\n";
    std::cout << "---+---+---\n";
    std::cout << " 1 | 2 | 3\n\n";

    std::cout << "\n";
    std::cout << "Partie : " << (parties+1) << "\n";
    std::cout << "\n";
    std::cout << " " << b[6] << " | " << b[7] << " | " << b[8] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << b[3] << " | " << b[4] << " | " << b[5] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << b[0] << " | " << b[1] << " | " << b[2] << "\n";
    std::cout << "\n";
}

bool caseLibre(const Board& b, int index)
{
    return b[index] == ' ';
}

bool coupGagnant(const Board& b, char joueur)
{
    const int lignesGagnantes[8][3] = {
        {0, 1, 2}, // lignes
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6}, // colonnes
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8}, // diagonales
        {2, 4, 6}
    };

    for (const auto& ligne : lignesGagnantes)
	{
        if (b[ligne[0]] == joueur && b[ligne[1]] == joueur && b[ligne[2]] == joueur)
            return true;
    }
    return false;
}

bool plateauPlein(const Board& b)
{
    for (char c : b)
	{
        if (c == ' ')
			return false;
    }
    return true;
}

int demanderCoup(const Board& b, char joueur)
{
    int choix = -1;
    while (true)
	{
        std::cout << "Joueur " << joueur << ", choisissez une case (1-9) : ";
        if (!(std::cin >> choix))
		{
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Saisie invalide, recommencez.\n";
            continue;
        }

        if (choix < 1 || choix > 9)
		{
            std::cout << "Veuillez entrer un nombre entre 1 et 9.\n";
            continue;
        }

        int index = choix - 1;
        if (caseLibre(b, index)==false)
		{
            std::cout << "Case déjà prise, choisissez-en une autre.\n";
            continue;
        }

        return index;
    }
}
int GetCurrentPlayer() { return GameInfo & 0x1; }

int GetPlayer1Win() { return GameInfo >> 3 & 0x7 ; }
int GetPlayer2Win() { return GameInfo >> 6 & 0x7 ; }
int GetPlayerDraw() { return GameInfo >> 9 & 0x1F; }

int GetGameState() { return GameInfo >>1 & 0x3 ; }      
int GetGridState(int x, int y) { return GameInfo >> (14 + (2 - x) * 2 + (2 - y) * 6) & 0x3; }
                                                                             
int main()
{
    GameInfo = 0b10101001001000011000111001011011;
    std::cout <<"current player :" << GetCurrentPlayer() << "\n";
    std::cout <<"Player 1 Win :" << GetPlayer1Win() << "\n";
    std::cout <<"Player 2 Win :" << GetPlayer2Win() << "\n";
    std::cout <<"Player Draw :" << GetPlayerDraw() << "\n";
    std::cout <<"Game State :" << GetGameState() << "\n";
    std::cout <<"Grid State :" << GetGridState(0,2) << "\n";
    exit(1);
    Board plateau;
    plateau.fill(' ');

    char joueurCourant = 'X';
    bool fini = false;
    
	while(true)
	{
		while (fini==false)
		{
			afficherPlateau(plateau);

			int index = demanderCoup(plateau, joueurCourant);
			plateau[index] = joueurCourant;

			if (coupGagnant(plateau, joueurCourant))
			{
				afficherPlateau(plateau);
				std::cout << "Le joueur " << joueurCourant << " a gagné !\n";
				fini = true;
			}
			else if (plateauPlein(plateau))
			{
				afficherPlateau(plateau);
				std::cout << "Match nul !\n";
				fini = true;
			}
			else
			{
				joueurCourant = (joueurCourant == 'X') ? 'O' : 'X';
			}
		}
		parties++;
		fini = false;
		_getch();
	}
 
    return 0;
}
