#pragma once
#include<functional>
#include<vector>
#include<unordered_map>
#include<array>

/// <summary>
/// イベントのID
/// </summary>
enum class Id
{
	OnFruitLanded,
	OVER,
	CLEAR,
	SIZE
};

/// <summary>
/// 登録されたイベントの処理
/// </summary>
class EventFill
{
public:
	/// <summary>
	/// イベントを登録する
	/// </summary>
	/// <param name="func">登録する関数</param>
	/// <returns>イベント番号</returns>
	unsigned int Add(std::function<void()> func)
	{
		unsigned int currentId = funcId++;
		functions.push_back({ currentId,func });
		return currentId;
	}
	/// <summary>
	/// イベントの削除
	/// </summary>
	/// <param name="id">削除したいイベント番号</param>
	void Remove(unsigned int id)
	{
		for (auto itr = functions.begin(); itr != functions.end();)
		{
			if (itr->id == id)
			{
				itr = functions.erase(itr);
				return;
			}
			else
			{
				itr++;
			}
		}
	}
	/// <summary>
	/// 登録されている関数の実行
	/// </summary>
	void Invoke()
	{
		for (const auto& func : functions)
		{
			if (func.callback)func.callback();
		}
	}
	/// <summary>
	/// 登録された関数を全部削除
	/// </summary>
	void RemoveAll()
	{
		functions.clear();
	}
private:
	//IDと実行する関数を保持する構造体
	struct FuncList
	{
		unsigned int id;
		std::function<void()> callback;
	};
	//登録するイベント
	std::vector<FuncList> functions;
	//イベント番号管理ようの整数
	unsigned int funcId = 0;
};

/// <summary>
/// イベントを管理するクラス
/// </summary>
class Event
{
public:
	/// <summary>
	/// インスタンスを静的に作成
	/// </summary>
	/// <returns>インスタンスのポインタ</returns>
	static Event& Instance()
	{
		static Event instance;
		return instance;
	}
	/// <summary>
	/// 指定したIDのイベントを取得
	/// </summary>
	/// <param name="id">イベントのID</param>
	/// <returns>イベントのポインタ</returns>
	EventFill& Get(Id id)
	{
		return channels[static_cast<size_t>(id)];
	}
	/// <summary>
	/// イベントの登録を削除
	/// </summary>
	void ClearAll()
	{
		for (auto& ch : channels)
		{
			ch.RemoveAll();
		}
	}
private:
	Event() {}
	~Event() {}
	//コピーの禁止
	Event(const Event&) = delete;
	Event& operator=(const Event&) = delete;
private:
	//IDとイベントを一意に管理
	std::array<EventFill, static_cast<size_t>(Id::SIZE)> channels;
};

