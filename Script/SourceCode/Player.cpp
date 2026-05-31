#include "Player.h"

namespace
{
	const int MAX_HP = 5;
	const float SPEED = 5.0f;
	const int RADIUS = 20;
}

Player::Player()
	:Character(Tag::PLAYER)
{
	position = { SCREEN_WIDTH / 2, 700.0f };
	velocity = { 0.0f,0.0f };
	hp = MAX_HP;
}

Player::~Player()
{}

void Player::Update()
{
	Move();
	CheckOutPos();
}

void Player::Draw()
{
	float x = position.x + SCREEN_OFFSET_X;
	float y = position.y + SCREEN_OFFSET_Y;

	DrawCircle((int)x, (int)y, RADIUS, COL_RED, TRUE);
}

void Player::OnCollision(GameObject * other)
{}

void Player::Move()
{
	velocity = { 0.0f,0.0f };
	if (Input::IsKeepKeyDown(KEY_INPUT_W))
	{
		velocity.y = -SPEED;
	}
	else if (Input::IsKeepKeyDown(KEY_INPUT_S))
	{
		velocity.y = SPEED;
	}

	if (Input::IsKeepKeyDown(KEY_INPUT_A))
	{
		velocity.x = -SPEED;
	}
	else if (Input::IsKeepKeyDown(KEY_INPUT_D))
	{
		velocity.x = SPEED;
	}

	position += velocity;
}

void Player::CheckOutPos()
{
	if (position.x <= RADIUS)position.x = RADIUS;
	if (position.x >= SCREEN_WIDTH - RADIUS)position.x = SCREEN_WIDTH - RADIUS;
	if (position.y <= SCREEN_HEIGHT / 2)position.y = SCREEN_HEIGHT / 2;
	if (position.y >= SCREEN_HEIGHT - RADIUS)position.y = SCREEN_HEIGHT - RADIUS;
}

void Player::ShotBullet()
{}
