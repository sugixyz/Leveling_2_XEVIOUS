#include "Stage.h"
#include"Player.h"
#include"Tarukenn.h"

Stage::Stage()
	:GameObject(Tag::STAGE)
{
	new Player();
	//isCreate = true;
}

Stage::~Stage()
{}

void Stage::Update()
{
	if (!isCreate && gGameTimer.IsEvery(CREATE_ENEMY_INTERVAL))
	{
		isCreate = true;
		createTimer.Reset();
		createX = GetRand(SCREEN_WIDTH);
	}

	if (isCreate)
	{
		CreateEnemy(createX);
		createTimer.Update();
	}
}

void Stage::Draw()
{
	int x = SCREEN_OFFSET_X;
	int y = SCREEN_OFFSET_Y;
	DrawBox(x, y, x + SCREEN_WIDTH, y + SCREEN_HEIGHT, STAGE_COLOR, TRUE);
}

void Stage::CreateEnemy(float x)
{
	if (createTimer.isExpired(0))new Tarukenn(x);
	else if (createTimer.isExpired(0.2f))new Tarukenn(x - ENEMY_OFFSET_X);
	else if (createTimer.isExpired(0.4f))new Tarukenn(x + ENEMY_OFFSET_X);
	else if (createTimer.timer >= 0.6)isCreate = false;
}
