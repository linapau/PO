#pragma once
#include <SFML/Graphics.hpp>


class Paletka : public sf::Drawable
{
public:
	Paletka(float x, float y);
	Paletka() = delete;
	~Paletka() = default;
	void aktualizacja();
	float prawo(); //metody do sprawdzania kolizji z krawedziami
	float lewo();  //zwracanie poszczegolnej wspolrzednej krawedzi ksztaltu
	float gora();
	float dol();
	sf::Vector2f wezPozycje();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	sf::RectangleShape prostokat;
	const float Dl_Paletka{ 90.0f }; //promien paletki
	const float Wys_Paletka{ 20.0f }; 
    const float PaletkaVelocity{ 6.0f };  //predkosc paletki

	sf::Vector2f predkosc{ PaletkaVelocity, 0.f };
};