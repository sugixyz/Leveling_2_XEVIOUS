#pragma once
#include"../Engine/Object/Character.h"

class Toroido : public Character
{
public:
	Toroido(float x);
	~Toroido();
	void Update() override;
	void Draw() override;
	void OnCollision(GameObject* other) override;
	void Move() override;
private:
	Vector2 CalculationVelocity(float speed);
	Vector2 CalculationVelocityInit(float speed);
	bool Return();

	void UpdateChase();
	void UpdateReturn();
private:
	enum State
	{
		CHASE,
		RETURN
	};
	State state;
private:
	static constexpr float SPEED = 6.0f;
	static constexpr float RETURN_DIST_X = 50.0f;
	static constexpr float BULLET_SPEED = 8.0f;
	static constexpr float OFFSET_Y = 300.0f;
	static constexpr float ACCELERATOR = 0.04f;
};