#include "Player.h"
#include"Bullet.h"

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

	ShotBullet();
}

void Player::Draw()
{
	float x = position.x + SCREEN_OFFSET_X;
	float y = position.y + SCREEN_OFFSET_Y;

	DrawCircle((int)x, (int)y, RADIUS, COL_GREEN, TRUE);
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
{
	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		new Bullet(Tag::PLAYER, position + SHOT_OFFSET, SHOT_VEL);
		new Bullet(Tag::PLAYER, position + Vector2(-SHOT_OFFSET.x, SHOT_OFFSET.y), SHOT_VEL);
	}
}
