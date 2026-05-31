#pragma once
#include"../Engine/Object/Character.h"

class Tarukenn : public Character
{
public:
	Tarukenn();
	~Tarukenn();
	void Update() override;
	void Draw() override;
	void Move() override;
	void OnCollision(GameObject* other);
private:
	void ShotBullet();
	Vector2 CalculationVelocity();
private:
	const float SPEED = 5.0f;
};