#include "Kulka.h"
#include<iostream>

Kulka::Kulka(float x1, float y1)
{
	ksztalt.setPosition(x1, y1); //pozycja
	ksztalt.setRadius(this->Kulkaradius);   //promien
	ksztalt.setFillColor(sf::Color::Cyan); //kolor
	ksztalt.setOrigin(this->Kulkaradius, this->Kulkaradius); //ustawienie kulki na srodek ukl wspolrzednych, przesuniecie o promien
}

void Kulka::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->ksztalt, state); // rysowanie kulki
}

void Kulka::klatka_na_klatke() {
	ksztalt.move(this->predkosc); //przesuniecie o dany wektor -> przekazanie wektora predkosci
	if (this->lewo() < 0) //sprawdzanie kolizji ze scianami
	{
		predkosc.x = KulkaVelocity;
	}

	else if (this->prawo() > 800)
		predkosc.x = -KulkaVelocity;

	else if (this->gora() < 0)
		predkosc.y = KulkaVelocity;

	else if (this->dol() > 500)
		predkosc.y = -KulkaVelocity;
}

float Kulka::prawo() //pozycja prawej krawedzi
{
	return this->ksztalt.getPosition().x + ksztalt.getRadius(); //pobiera aktualna pozioma pozycje kulki i dodaje promien
}

float Kulka::lewo() //pozycja lewej krawedzi
{
	return this->ksztalt.getPosition().x - ksztalt.getRadius(); //pobiera aktualna pozioma pozycje kulki i odejmuje promien
}

float Kulka::gora() //pozycja gornej krawedzi
{
	return this->ksztalt.getPosition().y - ksztalt.getRadius();
}

float Kulka::dol() //pozycja dolnej krawedzi
{
	return this->ksztalt.getPosition().y + ksztalt.getRadius();

}

void Kulka::moveGora()
{
	this->predkosc.y = -KulkaVelocity; //bedzie poruszac sie do gory
}
void Kulka::moveDol()
{
	this->predkosc.y = KulkaVelocity;
}

void Kulka::moveLewo()
{
	this->predkosc.x = - KulkaVelocity;
}
void Kulka::movePrawo()
{
	this->predkosc.x = KulkaVelocity;
}

sf::Vector2f Kulka::wezPozycje()
{
	return ksztalt.getPosition();
}