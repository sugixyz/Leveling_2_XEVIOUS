#include "Stage.h"
#include"Player.h"
#include"Tarukenn.h"

Stage::Stage()
	:GameObject(Tag::STAGE)
{
	new Player();
}

Stage::~Stage()
{}

void Stage::Update()
{
	if (gGameTimer.IsEvery(CREATE_ENEMY_INTERVAL))
	{
		new Tarukenn();
	}
}

void Stage::Draw()
{
	int x = SCREEN_OFFSET_X;
	int y = SCREEN_OFFSET_Y;
	DrawBox(x, y, x + SCREEN_WIDTH, y + SCREEN_HEIGHT, STAGE_COLOR, TRUE);
}
