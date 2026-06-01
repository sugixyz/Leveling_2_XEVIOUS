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
	void IECreateEnemy();
	void CreatePattern1();
	void CreatePattern2();
	void CreatePattern3();
	void CreateBoss();
private:
	enum Pattern
	{
		PATTERN1,
		PATTERN2,
		PATTERN3,
		BOSS
	};
	Pattern pattern;
	Coroutine create;
	float createX = 0.0f;
private:
	const unsigned int STAGE_COLOR = GetColor(30, 120, 30);
	static constexpr float CREATE_TOROIDO_INTERVAL = 2.0f;
	static constexpr float CREATE_TARUKENN_INTERVAL = 1.0f;
	static constexpr float ENEMY_OFFSET_X = 20;
	static constexpr float PATTERN_CHANGE_TIME = 9.0f;
};