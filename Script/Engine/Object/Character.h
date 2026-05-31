#pragma once
#include "GameObject.h"
/// <summary>
/// ゲーム内のキャラクターの基底クラス
/// </summary>
class Character : public GameObject
{
public:
	Character(Tag tag)
	:GameObject(tag)
	{}
	~Character() {}
	/// <summary>
	/// 速度の設定
	/// </summary>
	/// <param name="vel">適応する速度</param>
	void SetVel(Vector2 vel) { velocity = vel; }
	/// <summary>
	/// 速度を取得する
	/// </summary>
	/// <returns>現在の速度</returns>
	Vector2 GetVel() { return velocity; }

	/// <summary>
	/// ポジションを中心とした円コライダーのセット
	/// </summary>
	/// <param name="layer">自分を識別するレイヤー</param>
	/// <param name="mask">当たりたい対象のマスク（デフォルトなし）</param>
	void SetCenterCircle(Layer layer, uint32_t mask = 0x00000000)
	{
		myCollider.SetCapsule(Vector2(0, 0), Vector2(0, 0), radius, layer, mask);
	}

	/// <summary>
	/// ポジションを中心としたボックスコライダーのセット
	/// </summary>
	/// <param name="layer">自分を識別するレイヤー</param>
	/// <param name="mask">当たりたい対象のマスク（デフォルトなし）</param>
	void SetCenterBox(Layer layer, uint32_t mask = 0x00000000)
	{
		Vector2 p1 = Vector2((float)-radius, (float)-radius);
		Vector2 p2 = Vector2((float)radius, (float)radius);
		myCollider.SetBox(p1, p2, layer, mask);
	}

	/// <summary>
	/// 移動用の共通仮想関数
	/// </summary>
	virtual void Move() {}

	/// <summary>
	/// 範囲外チェック用の共通仮想関数
	/// </summary>
	virtual void CheckOutPos() 
	{
		if (position.x <= -radius * 2)DestroyMe();
		else if (position.x >= SCREEN_WIDTH + radius * 2)DestroyMe();
		else if (position.y <= -radius * 2)DestroyMe();
		else if (position.y >= SCREEN_HEIGHT + radius * 2)DestroyMe();
	}
protected:
	//速度
	Vector2 velocity;
	//半径
	int radius;
};