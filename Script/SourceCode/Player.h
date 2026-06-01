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
	void IEGameOver();
	void AddScore(int point) { score += point; }
private:
	int hp;
	int score;
	Coroutine gameOver;
	unsigned int eventId;
private:
	static constexpr int MAX_HP = 5;
	static constexpr float SPEED = 5.0f;
	static constexpr int RADIUS = 20;

	const Vector2 SHOT_OFFSET = Vector2(-8.0f, 10.0f);
	const Vector2 SHOT_VEL = Vector2(0.0f, -20.0f);
};