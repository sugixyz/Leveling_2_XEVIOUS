#include "Stage.h"
#include"Player.h"
#include"Tarukenn.h"
#include"Toroido.h"
#include"Boss.h"
#include"Ui.h"
#include"../Engine/Tool/Event.h"

Stage::Stage()
	:GameObject(Tag::STAGE)
{
	new Player();
	pattern = Pattern::PATTERN1;

	stage = 1;
	new Ui("ステージ", &stage);

	eventId = Event::Instance().Get(Id::NEXT_STAGE).Add([this] {NextStage(); });

}

Stage::~Stage()
{
	Event::Instance().Get(Id::NEXT_STAGE).Remove(eventId);
}

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
	if (gGameTimer.isExpired(30.0f))
	{
		new Boss();
	}
}

void Stage::NextStage()
{
	stage++;

	gGameTimer.Reset();
	pattern = Pattern::PATTERN1;
}
