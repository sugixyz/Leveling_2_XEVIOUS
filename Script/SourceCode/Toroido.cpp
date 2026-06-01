#include "Toroido.h"
#include"Bullet.h"
#include"../Engine/Tool/Event.h"

Toroido::Toroido(float x)
    :Character(Tag::ENEMY)
{
	radius = 20;
	position = { x,(float)-radius };
	velocity = CalculationVelocityInit(SPEED);
	state = State::CHASE;
	Vector2 start = { 0,0 };
	uint32_t mask = (uint32_t)Layer::PLAYER | (uint32_t)Layer::PLAYER_BULLET;
	SetCenterCircle(Layer::TOROIDO, mask);
}

Toroido::~Toroido()
{}

void Toroido::Update()
{
	switch (state)
	{
	case State::CHASE:
		UpdateChase();
		break;
	case State::RETURN:
		UpdateReturn();
		break;
	}
	CheckOutPos();
}

void Toroido::Draw()
{
	float x = position.x + SCREEN_OFFSET_X;
	float y = position.y + SCREEN_OFFSET_Y;

	DrawCircle(x, y, radius, COL_RED, TRUE);
}

void Toroido::OnCollision(GameObject * other)
{
	if (other->GetTag() == Tag::ATTACK)
	{
		DestroyMe();
		Event::Instance().Get(Id::ADD_SCORE).Invoke(100);
	}
}

void Toroido::Move()
{
	position += velocity;
}

Vector2 Toroido::CalculationVelocity(float speed)
{
	GameObject* p = FindTagObjects(Tag::PLAYER)[0];
	Vector2 toPlayer = p->GetPos() - position;
	Vector2 dir = Math2D::Normalize(toPlayer);
	return dir * speed;
}

Vector2 Toroido::CalculationVelocityInit(float speed)
{
	GameObject* p = FindTagObjects(Tag::PLAYER)[0];
	Vector2 toPlayer = p->GetPos() + Vector2(0, OFFSET_Y) - position;
	Vector2 dir = Math2D::Normalize(toPlayer);
	return dir * speed;
}

bool Toroido::Return()
{
	GameObject* p = FindTagObjects(Tag::PLAYER)[0];
	return abs(p->GetPos().x - position.x) < RETURN_DIST_X;
}

void Toroido::UpdateChase()
{
	Move();
	if (Return())
	{
		state = State::RETURN;
		if (GetRand(10) == 0)new Bullet(Tag::ENEMY, position, CalculationVelocity(BULLET_SPEED));
		velocity.x *= -1;
	}
}

void Toroido::UpdateReturn()
{
	Move();
	velocity.x *= ( 1.0f + ACCELERATOR);
}
