#include "Player.h"
#include"Bullet.h"
#include"Ui.h"
#include"../Engine/Tool/Event.h"

Player::Player()
	:Character(Tag::PLAYER)
{
	radius = 20;
	position = { SCREEN_WIDTH / 2, 700.0f };
	velocity = { 0.0f,0.0f };
	hp = MAX_HP;
	score = 0;

	new Ui("残機", &hp);
	new Ui("スコア", &score);

	eventId = Event::Instance().Get(Id::ADD_SCORE).Add([this](int point) {AddScore(point); });

	uint32_t mask = (uint32_t)Layer::TARUKENN | (uint32_t)Layer::TOROIDO | (uint32_t)Layer::BOSS | (uint32_t)Layer::ENEMY_BULLET;
	SetCenterCircle(Layer::PLAYER, mask);
	//SetCenterBox(Layer::PLAYER, mask);
}

Player::~Player()
{
	Event::Instance().Get(Id::ADD_SCORE).Remove(eventId);
}

void Player::Update()
{
	gameOver.Update();
	Move();
	CheckOutPos();

	ShotBullet();
}

void Player::Draw()
{
	if (hp <= 0)return;
	float x = position.x + SCREEN_OFFSET_X;
	float y = position.y + SCREEN_OFFSET_Y;

	DrawCircle((int)x, (int)y, radius, COL_GREEN, TRUE);
}

void Player::OnCollision(GameObject * other)
{
	hp--;
	if (hp <= 0)
	{
		gameOver.Start([this] {IEGameOver(); }, 1.0f);
	}
}

void Player::Move()
{
	velocity = { 0.0f,0.0f };
	if (Input::IsKeepKeyDown(KEY_INPUT_W))
	{
		velocity.y = -SPEED;
	}
	else if (Input::IsKeepKeyDown(KEY_INPUT_S))
	{
		velocity.y = SPEED;
	}

	if (Input::IsKeepKeyDown(KEY_INPUT_A))
	{
		velocity.x = -SPEED;
	}
	else if (Input::IsKeepKeyDown(KEY_INPUT_D))
	{
		velocity.x = SPEED;
	}

	position += velocity;
}

void Player::CheckOutPos()
{
	if (position.x <= radius)position.x = radius;
	if (position.x >= SCREEN_WIDTH - radius)position.x = SCREEN_WIDTH - radius;
	if (position.y <= SCREEN_HEIGHT / 2)position.y = SCREEN_HEIGHT / 2;
	if (position.y >= SCREEN_HEIGHT - radius)position.y = SCREEN_HEIGHT - radius;
}

void Player::ShotBullet()
{
	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		new Bullet(Tag::PLAYER, position + SHOT_OFFSET, SHOT_VEL);
		new Bullet(Tag::PLAYER, position + Vector2(-SHOT_OFFSET.x, SHOT_OFFSET.y), SHOT_VEL);
	}
}

void Player::IEGameOver()
{
	if (gameOver.IsEnd())
	{
		SceneManager::ChangeScene(SCENE_NAME::GAMEOVER);
	}
}
