#include "PlayScene.h"
#include"../../SourceCode/Ui.h"
#include"../../SourceCode/Stage.h"

/// <summary>
/// プレイ中の画面の遷移をする
/// </summary>

PlayScene::PlayScene()
{
	gGameTimer.timer = 0.0f;

	new Ui("タイマー", &gGameTimer.timer);

	new Stage();
}

PlayScene::~PlayScene()
{}

void PlayScene::Update()
{
	gGameTimer.Update();

	if (Input::IsKeyDown(KEY_INPUT_N))
	{
		SceneManager::ChangeScene(SCENE_NAME::TITLE);
	}
	if (Input::IsKeyDown(KEY_INPUT_RETURN))
	{
		gGameTimer.Switch();
	}
}

void PlayScene::Draw()
{
	DrawScreenFrame();

	DrawString(100, 0, "PlayScene", 0xffffff);
	DrawString(100, 20, "Push [N]Key To Title", 0xffffff);
}

void PlayScene::DrawScreenFrame()
{
	Vector2 p1 = { 0,0 };
	Vector2 p2 = { SCREEN_OFFSET_X,WIN_HEIGHT };
	DrawBox((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, COL_BLACK, TRUE);

	p1 = { SCREEN_OFFSET_X,0 };
	p2 = { SCREEN_WIDTH + SCREEN_OFFSET_X,SCREEN_OFFSET_Y };
	DrawBox((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, COL_BLACK, TRUE);

	p1 = { SCREEN_OFFSET_X,SCREEN_HEIGHT + SCREEN_OFFSET_Y };
	p2 = { SCREEN_WIDTH + SCREEN_OFFSET_X ,WIN_HEIGHT };
	DrawBox((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, COL_BLACK, TRUE);

	p1 = { SCREEN_WIDTH + SCREEN_OFFSET_X ,0 };
	p2 = { SCREEN_WIDTH + SCREEN_OFFSET_X * 2, WIN_HEIGHT };
	DrawBox((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, COL_BLACK, TRUE);
}

