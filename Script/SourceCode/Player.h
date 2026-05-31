#pragma once
#include"../Engine/Object/Character.h"

class Player : public Character
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void OnCollision(GameObject* other) override;
	void Move() override;
	void CheckOutPos() override;
private:
	void ShotBullet();
private:
	int hp;
private:
	const int MAX_HP = 5;
	const float SPEED = 5.0f;
	const int RADIUS = 20;

	const Vector2 SHOT_OFFSET = Vector2(-8.0f, 10.0f);
	const Vector2 SHOT_VEL = Vector2(0.0f, -20.0f);
};