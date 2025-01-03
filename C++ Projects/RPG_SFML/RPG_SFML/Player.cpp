#include "Player.h"
#include "MathUtils.h"

#include <iostream>


void Player::load()
{
	if (m_texture.loadFromFile("Assets/Player/player_textureSheet.png"))
	{
		std::cout << "Player texture was loaded!" << std::endl;

		m_sprite.setTexture(m_texture);
		m_sprite.setTextureRect(sf::IntRect(m_rectLeft, m_rectTop, m_width, m_height));
	}
	else
	{
		std::cout << "Player texture was not loaded!" << std::endl;
	}
}

//-
void Player::setupHitbox()
{
	m_hitboxRect.setFillColor(sf::Color::Transparent);
	m_hitboxRect.setOutlineColor(sf::Color::Red);
	m_hitboxRect.setOutlineThickness(1);
	m_hitboxRect.setSize(sf::Vector2f(m_width, m_height));
}

void Player::checkForCollision(Enemy& enemy, const float dt)
{
	m_collisionTimeAccumulator += dt;

	if (MathUtils::collisionDetection(m_sprite.getGlobalBounds(),
		enemy.getSprite().getGlobalBounds()))
	{
		if (m_collisionTimeAccumulator >= 1.0f)
		{
			std::cout << "Collison!" << std::endl;
			m_collisionTimeAccumulator = 0;
		}
	}
}

//-
void Player::movement(const float dt)
{
	dtMoveSpeed = m_moveSpeed;
	dtMoveSpeed *= (dt * 1000);

	oldX = m_position.x;
	oldY = m_position.y;

	isMovingX = false;
	isMovingY = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_position.y -= dtMoveSpeed;
		isMovingY = true;
		movementAnimation(1, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_position.y += dtMoveSpeed;
		isMovingY = true;
		movementAnimation(0, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_position.x -= dtMoveSpeed;
		isMovingX = true;
		movementAnimation(2, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_position.x += dtMoveSpeed;
		isMovingX = true;
		movementAnimation(3, dt);
	}

	if (isMovingX && isMovingY)
	{
		m_position.x = oldX + ((m_position.x - oldX) / m_SQRT2);
		m_position.y = oldY + ((m_position.y - oldY) / m_SQRT2);
	}

	m_sprite.setPosition(m_position);
}

void Player::movementAnimation(int rectTop, const float dt)
{
	m_animationTimeAccumulator += dt;

	if (m_animationTimeAccumulator >= 0.1f)
	{
		m_rectTop = 64;

		if (m_rectLeft == 320)
		{
			m_rectLeft = 0;
		}

		m_rectTop *= rectTop;
		m_rectLeft += 64;

		m_sprite.setTextureRect(sf::IntRect(m_rectLeft, m_rectTop, m_width, m_height));
		m_animationTimeAccumulator = 0;
		m_resetAnimationTimeAccumulator = 0;
	}
}

void Player::resetMovementAnimation(const float dt)
{
	m_resetAnimationTimeAccumulator += dt;
	if (m_resetAnimationTimeAccumulator >= 0.2f)
	{
		m_sprite.setTextureRect(sf::IntRect(320, m_rectTop, m_width, m_height));
		m_resetAnimationTimeAccumulator = 0;
	}
}

//-
void Player::update(Enemy& enemy, const float dt)
{
	movement(dt);
	resetMovementAnimation(dt);

	m_hitboxRect.setPosition(m_position);
	checkForCollision(enemy, dt);
}

void Player::draw(sf::RenderWindow& window, bool drawHitbox)
{
	if (drawHitbox)
	{
		window.draw(m_hitboxRect);
	}

	window.draw(m_sprite);
}