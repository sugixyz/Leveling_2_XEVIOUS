#pragma once
#include"../Engine/Object/Character.h"

class Boss : public Character
{
public:
	Boss();
	~Boss();
	void Update() override;
	void Draw() override;
	void OnCollision(GameObject* other) override;
	void Move() override;
	void CheckOutPos() override;
private:
	void UpdateMove();
	void UpdateAttack();
	void UpdateDeath();

	Vector2 CalculationBulletVel(Vector2 shotPos);
private:
	enum State
	{
		MOVE,
		ATTACK,
		DEATH
	};
	State state;
	int hp;
	enum Dir
	{
		LEFT,
		RIGHT
	};
	Dir shotDir = Dir::LEFT;
private:
	static constexpr float SPEED = 4.0f;
	static constexpr float MOVE_OFFSET_Y = 200.0f;
	static constexpr float SHOT_OFFSET_X = 30;
	static constexpr float SHOT_INTERVAL = 0.2f;
	static constexpr float BULLET_SPEED = 8.0f;
};