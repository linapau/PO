#pragma once
#include <SFML/Graphics.hpp>


class Kloc : public sf::Drawable
{
public:
	Kloc(float x, float y, float dlugosc, float wysokosc);
	Kloc() = delete; //konstruktor
	~Kloc() = default;
	void aktualizacja();
	sf::Vector2f wezPozycje();

	float prawo(); 
	float lewo();  
	float gora();
	float dol();

	bool jest_zniszczony(); //metoda do sprawdzenia zniszczenia klocka
	void zniszcz();
	sf::Vector2f wezRozmiar();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	sf::RectangleShape kloc;
	bool zniszczony{ false };

};



