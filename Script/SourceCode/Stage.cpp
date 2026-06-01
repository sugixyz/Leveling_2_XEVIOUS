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
	create.Update();
	if (!create.IsActive() && gGameTimer.IsEvery(CREATE_ENEMY_INTERVAL))
	{
		createX = GetRand(SCREEN_WIDTH);
		create.Request([this] {IECreateEnemy();}, 0.6f);
	}

}

void Stage::Draw()
{
	int x = SCREEN_OFFSET_X;
	int y = SCREEN_OFFSET_Y;
	DrawBox(x, y, x + SCREEN_WIDTH, y + SCREEN_HEIGHT, STAGE_COLOR, TRUE);
}

void Stage::IECreateEnemy()
{
	float x = createX;
	if (create.timer.IsEvery(0.2f))new Tarukenn(createX);
	//if (create.IsEnd())new Tarukenn(createX);
}
