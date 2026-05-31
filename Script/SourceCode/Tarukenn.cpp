#include "Tarukenn.h"

Tarukenn::Tarukenn()
	:Character(Tag::ENEMY)
{
	position = { (float)GetRand(SCREEN_WIDTH),0.0f };
	velocity = CalculationVelocity();
	radius = 20;

	Vector2 start = { 0,0 };
	uint32_t mask = (uint32_t)Layer::PLAYER | (uint32_t)Layer::PLAYER_BULLET;
	myCollider.SetCapsule(start, start, radius, Layer::TARUKENN, mask);
}

Tarukenn::~Tarukenn()
{}

void Tarukenn::Update()
{
	Move();
	CheckOutPos();
}

void Tarukenn::Draw()
{
	float x = position.x + SCREEN_OFFSET_X;
	float y = position.y + SCREEN_OFFSET_Y;

	DrawCircle(x, y, radius, COL_RED, TRUE);
}

void Tarukenn::Move()
{
	position += velocity;
}

void Tarukenn::OnCollision(GameObject * other)
{
	if (other->GetTag() == Tag::ATTACK)
	{
		DestroyMe();
	}
}

void Tarukenn::ShotBullet()
{}

Vector2 Tarukenn::CalculationVelocity()
{
	auto pl = FindTagObjects(Tag::PLAYER);
	for (GameObject* p : pl)
	{
		Vector2 toPlayer = p->GetPos() - position;
		Vector2 dir = Math2D::Normalize(toPlayer);
		return dir * SPEED;
	}
	return { 0,0 };
}
