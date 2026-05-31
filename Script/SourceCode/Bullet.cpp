#include "Bullet.h"

Bullet::Bullet(Tag tag,Vector2 pos, Vector2 vel = {0.0f,0.0f})
	:Character(Tag::ATTACK)
{
	position = pos;
	velocity = vel;
	radius = 3;

	Vector2 start = { 0,0 };

	if (tag == Tag::PLAYER)
	{
		uint32_t mask = (uint32_t)Layer::TARUKENN | (uint32_t)Layer::TOROIDO | (uint32_t)Layer::BOSS;
		myCollider.SetCapsule(start, start, radius, Layer::PLAYER_BULLET, mask);
	}
	else if (tag == Tag::ENEMY)
	{
		uint32_t mask = (uint32_t)Layer::PLAYER;
		myCollider.SetCapsule(start, start, radius, Layer::ENEMY_BULLET, mask);
	}

}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	Move();
	CheckOutPos();
}

void Bullet::Draw()
{
	float x = position.x + SCREEN_OFFSET_X;
	float y = position.y + SCREEN_OFFSET_Y;

	DrawCircle(x, y, radius, COL_WHITE, TRUE);
}

void Bullet::OnCollision(GameObject * other)
{
	DestroyMe();
}

void Bullet::Move()
{
	position += velocity;
}
