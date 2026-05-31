#pragma once
#include"../Engine/Object/Character.h"

class Bullet : public Character
{
public:
	Bullet(Tag tag,Vector2 pos,Vector2 vel);
	~Bullet();
	void Update() override;
	void Draw() override;
	void OnCollision(GameObject* other) override;
	void Move() override;
	void CheckOutPos() override;
private:
	const int RADIUS = 3;
};