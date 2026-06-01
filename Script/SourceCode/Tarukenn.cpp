#include "Tarukenn.h"
#include"Bullet.h"
#include"../Engine/Tool/Event.h"

Tarukenn::Tarukenn()
	:Character(Tag::ENEMY)
{
	radius = 20;
	position = { (float)GetRand(SCREEN_WIDTH),(float)-radius};
	velocity = CalculationVelocity(SPEED);
	targetY = GetRand(200) + SCREEN_HEIGHT / 2;
	state = State::CHASE;

	Vector2 start = { 0,0 };
	uint32_t mask = (uint32_t)Layer::PLAYER | (uint32_t)Layer::PLAYER_BULLET;
	SetCenterBox(Layer::TARUKENN, mask);
}

Tarukenn::~Tarukenn()
{}

void Tarukenn::Update()
{
	switch (state)
	{
	case State::CHASE:
		UpdateChase();
		break;
	case State::ATTACK:
		UpdateAttack();
		break;
	case State::RETURN:
		UpdateReturn();
		break;
	}
	CheckOutPos();
}

void Tarukenn::Draw()
{
	float x = position.x + SCREEN_OFFSET_X;
	float y = position.y + SCREEN_OFFSET_Y;

	DrawBox(x - radius, y - radius, x + radius, y + radius, COL_RED, TRUE);
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
		Event::Instance().Get(Id::ADD_SCORE).Invoke(200);
	}
}

Vector2 Tarukenn::CalculationVelocity(float speed)
{
	GameObject* p = FindTagObjects(Tag::PLAYER)[0];
	Vector2 toPlayer = p->GetPos() - position;
	Vector2 dir = Math2D::Normalize(toPlayer);
	return dir * speed;
}

void Tarukenn::UpdateChase()
{
	Move();
	if (CheckCanAttack())
	{
		state = State::ATTACK;
	}
}

void Tarukenn::UpdateAttack()
{
	attackTimer.Update();
	if (attackTimer.isExpired(0.2f))
	{
		new Bullet(GetTag(), position, CalculationVelocity(BULLET_SPEED));
	}
	else if (attackTimer.isExpired(0.5f))
	{
		state = State::RETURN;
		velocity = { 0,-SPEED * 2 };
	}
}

void Tarukenn::UpdateReturn()
{
	Move();
}

bool Tarukenn::CheckCanAttack()
{
	return position.y >= targetY;
}
