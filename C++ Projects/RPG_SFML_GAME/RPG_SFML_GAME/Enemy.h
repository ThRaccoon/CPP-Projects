#pragma once

#include <SFML/Graphics.hpp>


class Enemy
{
public:
	Enemy(std::string textureSheet) :
		m_textureSheet(textureSheet)
	{}

	void load();

	//-
	void setupHitbox();

	//-
	void update();
	void draw(sf::RenderWindow& window, bool drawHitbox);

	//-
	sf::Sprite& getSprite();


private:
	int m_width = 64;
	int m_height = 64;

	int m_rectLeft = 0;
	int m_rectTop = 0;

	float m_moveSpeed = 0.01f;
	float m_SQRT2 = 1.41421356f;

	std::string m_textureSheet;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;

	//Hitbox
	sf::RectangleShape m_hitboxRect;
};

