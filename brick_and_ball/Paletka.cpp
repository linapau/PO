#include"Paletka.h"

Paletka::Paletka(float x, float y) {
	prostokat.setPosition(x, y);
	prostokat.setSize({this->Dl_Paletka, this->Wys_Paletka});
	prostokat.setFillColor(sf::Color::Magenta); //kolor
	prostokat.setOrigin(Dl_Paletka / 2.f, Wys_Paletka / 2.f);
}


void Paletka::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->prostokat, state); // rysowanie paletki
}

void Paletka::aktualizacja(){
	this->prostokat.move(this->predkosc); //przesuwamy ksztalt o aktualny wektor predkosci. Przekazujemy predkosc

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->lewo() > 0) {
		predkosc.x = -PaletkaVelocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->prawo() < 800) {
		predkosc.x = PaletkaVelocity;
	}
	else {
		predkosc.x = 0;
	}
}



float Paletka::prawo() //pozycja prawej krawedzi
{
	return this->prostokat.getPosition().x + prostokat.getSize().x / 2.f ; //pobiera aktualna pozioma pozycje paletki i dodaje polowe rozmiaru
}

float Paletka::lewo() //pozycja lewej krawedzi
{
	return this->prostokat.getPosition().x - prostokat.getSize().x / 2.f; //pobiera aktualna pozioma pozycje paletki i odejmuje polowe rozmiaru
}

float Paletka::gora() //pozycja gornej krawedzi
{
	return this->prostokat.getPosition().y - prostokat.getSize().y / 2.f;
}

float Paletka::dol() //pozycja dolnej krawedzi
{
	return this->prostokat.getPosition().y + prostokat.getSize().y / 2.f;
}

sf::Vector2f Paletka::wezPozycje()
{
	return prostokat.getPosition();
}