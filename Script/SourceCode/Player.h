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
};