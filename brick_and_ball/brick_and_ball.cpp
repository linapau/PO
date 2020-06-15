
#include "Scena.h"



//kolizja miedzy obiektami (przecinanie krawedzi)
template <class T1, class T2> bool przecina(T1& A, T2& B) //argumenty szablonowe, dowolne typy obiektow
{  
	return A.prawo() >= B.lewo() && A.lewo() <= B.prawo() && A.dol() >= B.gora() && A.gora() <= B.dol();
}

bool testKolizja(Paletka& paletka, Kulka& kulka)  //dzieki temu kulka bedzie odbijala sie od paletki
{
	if (!przecina(paletka, kulka)) return false;
	kulka.moveGora();

	if (kulka.wezPozycje().x < paletka.wezPozycje().x)
	{
		kulka.moveLewo();
	}
	else if (kulka.wezPozycje().x > paletka.wezPozycje().x)
	{
		kulka.movePrawo();
	}
}

bool testKolizja(Kloc& kloc, Kulka& kulka) {
	if (!przecina(kloc, kulka)) return false;
	kloc.zniszcz();

    //spr z ktorej str kulka uderzyla klocka
	float overlapLewo{ kulka.prawo() - kloc.lewo() };
	float overlapPrawo{ kloc.prawo() - kulka.lewo() };
	float overlapGora{ kulka.dol() - kloc.gora() };
	float overlapDol{ kloc.dol() - kulka.gora() };

	//spr z ktorej str kulka uderzyla w bloczek
	bool kulka_z_Lewej(abs(overlapLewo) < abs(overlapPrawo)); //porownujemy wartosci przesuniec, jezeli 1) < 2) tzn, ze kulka uderzyla z lewej str
	bool kulka_od_gory(abs(overlapGora) < abs(overlapDol));
	//minimalne przesuniecie w poziomie i w pionie
	float minOverlapX{ kulka_z_Lewej ? overlapLewo : overlapPrawo }; //jesli kulka uderzyla z lewej str to przypisujemy wartosc lewego przesuniecia, jesli z prawej - prawego
	float minOverlapY{ kulka_od_gory ? overlapGora : overlapDol };

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		kulka_z_Lewej ? kulka.moveLewo() : kulka.movePrawo(); //jesli uderzyla z lewej to leci z lewej, jesli z prawej to prawej
	}
	else
	{
		kulka_od_gory ? kulka.moveGora() : kulka.moveDol();
	}

}
unsigned lvl = 1;

int main()
{
	srand(time(NULL));
	scena(); //menu
	Kulka kulka(400, 300);
	Paletka paletka(400, 480);
	

	sf::RenderWindow okno{ sf::VideoMode{800,500},"Break the bricks!" }; //RenderWindow-konstruktor, tworzenie okna, sposób inicjalizacji klamrani, wlk okna, nazwa
	okno.setFramerateLimit(60);  //liczba klatek na sekunde
	sf::Event wydarzenie;
	unsigned kloceX{ 10 }; //ilosc klockow w rzedzie
	unsigned kloceY{ 6 }; //ilosc klockow w kolumnie
	unsigned kloceWYS{ 20 }; //wysokosc
	unsigned kloceSZE{ 60 }; //szerokosc

	std::vector<Kloc> kloce; //tablica dynamiczna (dynamiczna alokacja jest tylko wektorowo)

	for (int i = 0; i < kloceY; i++) //iteracja po rzedach
	{
		for (int j = 0; j < kloceX; j++) //iteracja po kolumnach
		{
			kloce.emplace_back((j + 1) * (kloceSZE + 10), (i + 2) * (kloceWYS + 5), kloceSZE, kloceWYS);
		}
	}

	sf::Texture tlo;
	tlo.loadFromFile("grafika/niebo.jpg"); //zaladowanie tla
	sf::Sprite sTlo(tlo);


	while (1)
	{

		okno.clear();
		okno.draw(sTlo);  //wypelnienie ekanu tlem galaxy 
		okno.pollEvent(wydarzenie); //teraz mo¿na ruszac oknem i je rozszerzac


		if (wydarzenie.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
		{
			okno.close(); // zamkniecie gry poprzez wcisniecie 'X' lub Esc
			break;
		}




		kulka.klatka_na_klatke(); //wywolanie kulki
		paletka.aktualizacja(); //wywolanie paletki
		testKolizja(paletka, kulka); //sprawdzenie kolizji paletki i kulki
			
		float pkt = 1;
		for (auto& kloc : kloce)
		{
			if (testKolizja(kloc, kulka)) break; //wystarczy jedna kolizja, nie trzeba iterowac po calym kontenerze
			pkt++;
		}


		//iterator na zniszczone elementy, remove_if-1sze dwa arg to zakres na ktorym dzialamy czyli wszystkie klocki 3ci arg to bloczki ktore nie spelnily wymagan i sa przeniesione na pocz wektora
		auto iterator = remove_if(begin(kloce), end(kloce), [](Kloc& kloc) {return kloc.jest_zniszczony(); });
		kloce.erase(iterator, end(kloce));
		

		int lvlup = 10;
		if (pkt == lvlup * lvl)lvl++;

		okno.draw(paletka);
		okno.draw(kulka);
	

		for (auto& kloc : kloce) //iterujemy kazdy po kazdym bloku z kontenera
			okno.draw(kloc);
	
		okno.display(); //wyswietlanie narysowanych obiektow
		
	

	}
	std::cout << "********************************" << std::endl;
	std::cout << "  !   G R A T U L A C J E   !    " << std::endl;
	std::cout << " Zakonczono gre na " << lvl <<" levelu!" <<std::endl;
	std::cout << "********************************" << std::endl;
	return 0;
}