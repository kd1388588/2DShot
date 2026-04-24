#pragma once
// SceneManager.h

// 前方宣言
class BaseScene;

class SceneManager
{
public:

	enum SceneType
	{
		// int型の列挙
		Title,	// タイトル
		Game,	// ゲーム
		Result,
	};

	void PreUpdate();
	void Update();
	void Draw();


	void SetNextScene(SceneType _NextScene)
	{
		m_NextSceneType = _NextScene;
	}

	SceneType GetCurrentScene()const
	{
		return m_CurrentSceneType;
	}

private:

	void Init();
	void Release();
	void ChangeScene(SceneType _SceneType);

	// 変数
	std::shared_ptr<BaseScene> m_CurrentScene;	// 現在のシーン

	SceneType m_CurrentSceneType = SceneType::Title;	// 現在のシーンの種類
	SceneType m_NextSceneType = m_CurrentSceneType;		// 次のシーンの種類


	// シングルトンパターン
private:
	SceneManager() { Init(); }
	~SceneManager() { Release(); }
public:
	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}
};
