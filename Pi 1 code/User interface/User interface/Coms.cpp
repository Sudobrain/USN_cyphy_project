#include "Coms.h"

void Coms::intro()
{
	std::cout << "Velkommen til h�ydem�ler system." << std::endl;
}

void Coms::menu_main()
{
	std::cout << "Velg den tjenesten du har lyst � burke:" << std::endl
		<< "1 : Ny M�ling" << std::endl
		<< "2 : Eksiterende M�ling" << std::endl
		<< "0 : Avslutt systemet" << std::endl;
}

void Coms::menu_new()
{
	std::cout << "Ny m�ling:" << std::endl
		<< "1 : Skap ny m�ling" << std::endl
		<< "0 : Tilbake" << std::endl;
}

void Coms::menu_existing()
{
	std::cout << "Eksterende m�ling:" << std::endl
		<< "1 : S�k etter m�ling" << std::endl
		<< "0 : Tilbake" << std::endl;
}

void Coms::end()
{
	std::cout << "Takk for bruken av h�ydem�ler system ." << std::endl;
}

void Coms::error_message(std::string error)
{
	std::cout << "Det har ser ut til at en feil har dukket opp." << std::endl
			  <<"ERROR KODE: "<<error<<std::endl;
}

void Coms::wrong_input()
{
	std::cout << "Det har ser ut skrever inn ugyldig input, pr�v igjenn." << std::endl << std::endl;
}

int Coms::get_menu_int(int options)//Ask for int within range 0 <= input <= options
{
	std::string input; //what user writes in console.
	std::cout << "Skriv inn verdi for �nsket handling: ";
	std::cin >> input; //get uset input
	std::cout << std::endl;
	for (int i = 0; i <= options; i++) { //go through and check if input matches and int in options
		if (std::to_string(i) == input) {
			return i;
		}
	}
	wrong_input();
	return -1;


}
