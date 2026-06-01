#include "Stage.h"
#include"Player.h"
#include"Tarukenn.h"
#include"Toroido.h"

Stage::Stage()
	:GameObject(Tag::STAGE)
{
	new Player();
	pattern = Pattern::PATTERN1;
}

Stage::~Stage()
{}

void Stage::Update()
{
	create.Update();
	switch (pattern)
	{
	case Pattern::PATTERN1:
		CreatePattern1();
		break;
	case Pattern::PATTERN2:
		CreatePattern2();
		break;
	case Pattern::PATTERN3:
		CreatePattern3();
		break;
	case Pattern::BOSS:
		CreateBoss();
		break;
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
	if (create.timer.IsEvery(0.2f))new Toroido(createX);
}

void Stage::CreatePattern1()
{
	if (!create.IsActive() && gGameTimer.IsEvery(CREATE_TOROIDO_INTERVAL))
	{
		create.Request([this] {IECreateEnemy(); }, 0.6f);
		createX = GetRand(SCREEN_WIDTH);
	}
	if (gGameTimer.isExpired(PATTERN_CHANGE_TIME * 1.0f))
	{
		create.Reset();
		pattern = Pattern::PATTERN2;
	}
}

void Stage::CreatePattern2()
{
	if (gGameTimer.IsEvery(CREATE_TARUKENN_INTERVAL))
	{
		new Tarukenn();
	}
	if (gGameTimer.isExpired(PATTERN_CHANGE_TIME * 2.0f))
	{
		create.Reset();
		pattern = Pattern::PATTERN3;
	}
}

void Stage::CreatePattern3()
{
	if (!create.IsActive() && gGameTimer.IsEvery(CREATE_TOROIDO_INTERVAL))
	{
		create.Request([this] {IECreateEnemy(); }, 0.6f);
		createX = GetRand(SCREEN_WIDTH);
	}
	if (gGameTimer.IsEvery(CREATE_TARUKENN_INTERVAL))
	{
		new Tarukenn();
	}
	if (gGameTimer.isExpired(PATTERN_CHANGE_TIME * 3.0f))
	{
		create.Reset();
		pattern = Pattern::BOSS;
	}
}

void Stage::CreateBoss()
{
	//ToDo: ボスの生成
	//ToDo: タイマーの停止
	//ToDo: ボスが死んだらイベントでタイマーを再開（必要ないかも）
	//ToDo: 35秒になったらタイマーのリセット、パターン１に行き、ステージを進める
}
