#include "Boss.h"
#include"../Engine/Tool/Event.h"
#include"Bullet.h"

Boss::Boss()
	:Character(Tag::ENEMY)
{
	radius = 80;
	position = { float(SCREEN_WIDTH / 2),(float)-radius };
	velocity = { 0 , SPEED };
	hp = MAX_HP;
	state = State::MOVE;

	uint32_t mask = (uint32_t)Layer::PLAYER_BULLET;
	SetCenterCircle(Layer::BOSS, mask);
}

Boss::~Boss()
{}

void Boss::Update()
{
	switch (state)
	{
	case State::MOVE:
		UpdateMove();
		break;
	case State::ATTACK:
		UpdateAttack();
		break;
	case State::DEATH:
		UpdateDeath();
		break;
	}
	CheckOutPos();
}

void Boss::Draw()
{
	float x = position.x + SCREEN_OFFSET_X;
	float y = position.y + SCREEN_OFFSET_Y;

	if (state != State::DEATH)
	{
		DrawCircle(x, y, radius + 5, COL_RED, TRUE);
	}
	DrawCircle(x, y, radius, COL_WHITE, TRUE);
}

void Boss::OnCollision(GameObject * other)
{
	hp--;
	if (hp <= 0)
	{
		state = State::DEATH;
		Event::Instance().Get(Id::ADD_SCORE).Invoke(1000);
	}
}

void Boss::Move()
{
	position += velocity;
}

void Boss::CheckOutPos()
{
	if (position.y >= SCREEN_HEIGHT + radius * 2)
	{
		Event::Instance().Get(Id::NEXT_STAGE).Invoke();
		DestroyMe();
	}
}

void Boss::UpdateMove()
{
	Move();
	if (position.y >= MOVE_OFFSET_Y)
	{
		state = State::ATTACK;
	}
}

void Boss::UpdateAttack()
{
	if (gGameTimer.IsEvery(SHOT_INTERVAL))
	{
		Vector2 shotPos;
		if (shotDir == Dir::LEFT)
		{
			shotPos = Vector2(position.x - SHOT_OFFSET_X, position.y + radius);
			new Bullet(Tag::ENEMY,shotPos , CalculationBulletVel(shotPos));
			shotDir = Dir::RIGHT;
		}
		else
		{
			shotPos = Vector2(position.x + SHOT_OFFSET_X, position.y + radius);
			new Bullet(Tag::ENEMY, shotPos, CalculationBulletVel(shotPos));
			shotDir = Dir::LEFT;
		}
	}
}

void Boss::UpdateDeath()
{
	Move();
}

Vector2 Boss::CalculationBulletVel(Vector2 shotPos)
{
	GameObject* p = FindTagObjects(Tag::PLAYER)[0];
	Vector2 toPlayer = p->GetPos() - shotPos;
	Vector2 dir = Math2D::Normalize(toPlayer);
	return dir * SPEED;
}
