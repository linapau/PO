#include "Kloc.h"

Kloc::Kloc(float x, float y, float dlugosc, float wysokosc)
{
	kloc.setPosition(x, y);
	kloc.setSize({ dlugosc, wysokosc });
	kloc.setFillColor(sf::Color::Blue); //kolor
	kloc.setOrigin(dlugosc / 2.f, wysokosc / 2.f);
}

void Kloc::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->kloc, state); // rysowanie paletki
}


float Kloc::prawo() //pozycja prawej krawedzi
{
	return this->kloc.getPosition().x + kloc.getSize().x / 2.f; //pobiera aktualna pozioma pozycje paletki i dodaje polowe rozmiaru
}

float Kloc::lewo() //pozycja lewej krawedzi
{
	return this->kloc.getPosition().x - kloc.getSize().x / 2.f; //pobiera aktualna pozioma pozycje paletki i odejmuje polowe rozmiaru
}

float Kloc::gora() //pozycja gornej krawedzi
{
	return this->kloc.getPosition().y - kloc.getSize().y / 2.f;
}

float Kloc::dol() //pozycja dolnej krawedzi
{
	return this->kloc.getPosition().y + kloc.getSize().y / 2.f;
}

sf::Vector2f Kloc::wezPozycje()
{
	return kloc.getPosition();
}


bool Kloc::jest_zniszczony()//metoda do sprawdzenia zniszczenia klocka
{
	return this->zniszczony;
}

void Kloc::zniszcz()
{
	this->zniszczony = true;
}
sf::Vector2f Kloc::wezRozmiar() 
{
	return kloc.getSize(); //zwracamy rozmiar przechowywany przez ksztalt
}

void Kloc::aktualizacja() 
{

}

