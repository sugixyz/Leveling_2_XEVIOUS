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
	const unsigned int STAGE_COLOR = GetColor(30, 120, 30);
};