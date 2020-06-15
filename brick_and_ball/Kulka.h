#pragma once
#include <SFML/Graphics.hpp>

class Kulka : public sf::Drawable //dziedziczenie publiczne, interfejs drawable
{
public:
	Kulka(float x1, float y1);
	Kulka() = delete; //konstruktor
	~Kulka() = default; //destruktor

	void klatka_na_klatke(); //przemieszczenie kulki 

	float prawo(); //metody do sprawdzania kolizji z krawedziami
	float lewo();  //zwracanie poszczegolnej wspolrzednej krawedzi ksztaltu
	float gora();
	float dol();
	int punkty;
	//bool Kolizja(sf::Sprite s1, Kulka kuleczka);
	
	void moveGora();
	void moveDol();
	void moveLewo();
	void movePrawo();

	sf::Vector2f wezPozycje(); //pobieranie aktualnej pozycji paletki i kulki


private:
	sf::CircleShape ksztalt;
	const float Kulkaradius{ 10.0f }; //promien kulki
	const float KulkaVelocity{ 3.0f };  //predkosc kulki
	sf::Vector2f predkosc{ KulkaVelocity, KulkaVelocity };  //wektor dwie zmienne float, poruszanie prosto i w dol

	//metoda rysujaca:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};

