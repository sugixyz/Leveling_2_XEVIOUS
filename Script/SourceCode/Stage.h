#pragma once
#include"../Engine/Object/GameObject.h"

class Stage : public GameObject
{
public:
	Stage();
	~Stage();
	void Update() override;
	void Draw() override;
private:
	void CreateEnemy(float x);
private:
	Timer createTimer;
	bool isCreate = false;
	float createX = 0.0f;
private:
	const unsigned int STAGE_COLOR = GetColor(30, 120, 30);
	const float CREATE_ENEMY_INTERVAL = 2.0f;
	const float ENEMY_OFFSET_X = 20;
};