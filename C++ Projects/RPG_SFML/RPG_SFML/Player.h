#pragma once

#include <SFML/Graphics.hpp>

#include "Enemy.h"


class Player
{
public:
	void load();

	//-
	void setupHitbox();
	void checkForCollision(Enemy& enemy, const float dt);

	//-
	void movement(const float dt);
	void movementAnimation(int rectTop, const float dt);
	void resetMovementAnimation(const float dt);

	//-
	void update(Enemy& enemy, const float dt);
	void draw(sf::RenderWindow& window, bool drawHitbox);


private:
	int m_rectLeft = 0;
	int m_rectTop = 0;

	int m_width = 64;
	int m_height = 64;

	float m_moveSpeed = 0.1f;
	float m_SQRT2 = 1.41421356f;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;

	//Hitbox
	sf::RectangleShape m_hitboxRect;

	//Player movement
	float dtMoveSpeed = 0.0f;

	float oldX = 0.0f;
	float oldY = 0.0f;

	bool isMovingX = 0.0f;
	bool isMovingY = 0.0f;

	//Collision
	float m_collisionTimeAccumulator = 0.0f;

	//Animation
	float m_animationTimeAccumulator = 0.0f;
	float m_resetAnimationTimeAccumulator = 0.0f;
};