#include "Enemy.h"

#include <iostream>


void Enemy::load()
{
	if (m_texture.loadFromFile(m_textureSheet))
	{
		std::cout << "Enemy texture was loaded!" << std::endl;

		m_sprite.setTexture(m_texture);
		m_sprite.setTextureRect(sf::IntRect(m_rectLeft, m_rectTop, m_width, m_height));
	}
	else
	{
		std::cout << "Enemy texture was not loaded!" << std::endl;
	}
}

//-
void Enemy::setupHitbox()
{
	m_hitboxRect.setFillColor(sf::Color::Transparent);
	m_hitboxRect.setOutlineColor(sf::Color::Red);
	m_hitboxRect.setOutlineThickness(1);
	m_hitboxRect.setSize(sf::Vector2f(m_width, m_height));
}

//-
void Enemy::update()
{
	m_hitboxRect.setPosition(m_sprite.getPosition());
}

void Enemy::draw(sf::RenderWindow& window, bool drawHitbox)
{
	if (drawHitbox)
	{
		window.draw(m_hitboxRect);
	}

	window.draw(m_sprite);
}

//-
sf::Sprite& Enemy::getSprite()
{
	return m_sprite;
}