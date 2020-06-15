#pragma once
#include <iostream>  //proste menu bo nie ma czasu
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Scena.h"
#include "Kulka.h"
#include "Kloc.h"
#include "Paletka.h"
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


void menu()
{
	std::cout << "........MENU........." << std::endl;
	std::cout << " 1.Rozpocznij....gre." << std::endl;
	std::cout << " 2.Instrukcja obslugi" << std::endl;
	std::cout << " 3.Zakoncz..gre......" << std::endl;
	std::cout << " ...................." << std::endl;
	std::cout << std::endl;

}int scena()
{
	unsigned int opcja = 0;
	menu();
	while (opcja != 3)
	{
		std::cin >> opcja;
		std::cout << std::endl;
		switch (opcja) {
		case 1:
			return 0;
			break;
		case 2:
			std::cout << "Wcisnij 1 by rozpoczac gre! Aby poruszac paletka nalezy uzywac strzalki w lewo i prawo." << std::endl;
			std::cout << "Kulka bedzie odbijac sie od paletki i niszczyc bloczki" << std::endl;
			std::cout << "Powodzenia!" << std::endl;
			menu();
			break;
		case 3:
			system("PAUSE");
			return 0;
			break;
		}
	}
}