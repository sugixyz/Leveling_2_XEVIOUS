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
	/// 移動用の共通仮想関数
	/// </summary>
	virtual void Move() {}

	/// <summary>
	/// 範囲外チェック用の共通仮想関数
	/// </summary>
	virtual void CheckOutPos() {}
protected:
	//速度
	Vector2 velocity;
};