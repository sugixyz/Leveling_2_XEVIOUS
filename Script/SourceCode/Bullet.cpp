#include "Bullet.h"

Bullet::Bullet(Tag tag,Vector2 pos, Vector2 vel = {0.0f,0.0f})
	:Character(Tag::ATTACK)
{
	position = pos;
	velocity = vel;

	if (tag == Tag::PLAYER)
	{

	}
	else if (tag == Tag::ENEMY)
	{

	}

}

Bullet::~Bullet()
{}

void Bullet::Update()
{
	Move();
	CheckOutPos();
}

void Bullet::Draw()
{
	float x = position.x + SCREEN_OFFSET_X;
	float y = position.y + SCREEN_OFFSET_Y;

	DrawCircle(x, y, RADIUS, COL_WHITE, TRUE);
}

void Bullet::OnCollision(GameObject * other)
{}

void Bullet::Move()
{
	position += velocity;
}

void Bullet::CheckOutPos()
{
	if (position.x <= -RADIUS)DestroyMe();
	else if (position.x >= SCREEN_WIDTH + RADIUS)DestroyMe();
	else if (position.y <= -RADIUS)DestroyMe();
	else if (position.y >= SCREEN_HEIGHT + RADIUS)DestroyMe();
}
