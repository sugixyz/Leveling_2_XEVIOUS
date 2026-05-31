#pragma once
#include"../Engine/Object/Character.h"

class Tarukenn : public Character
{
public:
	Tarukenn(float x);
	~Tarukenn();
	void Update() override;
	void Draw() override;
	void Move() override;
	void OnCollision(GameObject* other);
private:
	void ShotBullet();
	Vector2 CalculationVelocity(float speed);
	
	void UpdateChase();
	void UpdateAttack();
	void UpdateReturn();

	bool CheckCanAttack();
private:
	enum State
	{
		CHASE,
		ATTACK,
		RETURN
	};
	State state;

	float targetY;

	Timer attackTimer;
private:
	const float SPEED = 5.0f;
	const float ATTACK_DIST = 200.0f;
	const float BULLET_SPEED = 8.0f;
};