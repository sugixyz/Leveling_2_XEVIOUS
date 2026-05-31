#pragma once
#include"Math2D.h"

/// <summary>
/// キーボードとコントローラーの入力を管理する
/// </summary>

namespace Input {
	//キーボード取得関連

	/// <summary>
	/// キーボードの入力を更新
	/// </summary>
	void KeyStateUpdate();
	/// <summary>
	/// 指定したキーの押し込み検出
	/// </summary>
	/// <param name="keyCode">キーの名前(KEY_INPUT_)</param>
	/// <returns>押されたらtrue</returns>
	bool IsKeyUP(int keyCode);
	/// <summary>
	/// 指定したキーの引き上げ検出
	/// </summary>
	/// <param name="keyCode">キーの名前</param>
	/// <returns>上げられたらtrue</returns>
	bool IsKeyDown(int keyCode);
	/// <summary>
	/// 指定したキーの継続入力検出
	/// </summary>
	/// <param name="keyCode">キーの名前</param>
	/// <returns>長押しされてたらtrue</returns>
	int IsKeepKeyDown(int keyCode);

	//コントローラー

	/// <summary>
	/// パッドの入力を更新
	/// </summary>
	void PadStateUpdate();
	/// <summary>
	/// 指定したボタンの押し込み検出
	/// </summary>
	/// <param name="padCode">ボタンの名前(enum Pad::)</param>
	/// <returns>押されたらtrue</returns>
	bool IsPadUp(int padCode);
	/// <summary>
	/// 指定したボタンの引き上げ検出
	/// </summary>
	/// <param name="padCode">ボタンの名前(enum Pad::)</param>
	/// <returns>上げられたらtrue</returns>
	bool IsPadDown(int padCode);
	/// <summary>
	/// 指定したボタンの継続入力検出
	/// </summary>
	/// <param name="padCode">ボタンの名前(enum Pad::)</param>
	/// <returns>長押しされてたらtrue</returns>
	int IsKeepPadDown(int padCode);
	/// <summary>
	/// アナログスティックの入力数値取得
	/// </summary>
	/// <returns>左右:x 上下:y</returns>
	Vector2 GetStick();
}

enum Pad
{
	DOWN,
	LEFT,
	RIGHT,
	UP,
	A,
	B,
	X,
	Y,
	RB,
	LB,
	VIEW,
	OPTION
};