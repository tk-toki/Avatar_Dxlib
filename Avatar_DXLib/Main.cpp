#include "WindowProperty.h"
#include "DxLib.h"
#include "Image.h"
#include "Debug.h"
#include "InputAudio.h"
#include "DrawCharacter.h"
#include "SceneFactory.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetAlwaysRunFlag(TRUE); // 非アクティブでも動作させる
	ChangeWindowMode(TRUE); // ウィンドウモードを有効に
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 0); // ウィンドウサイズの設定
	SetOutApplicationLogValidFlag(FALSE); // Log.txtを生成しないように設定
	SetBackgroundColor(0, 0, 255); // 背景色は青単色にする
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	auto nowScene = SceneFactory::Factory(AUDIO_SOURCE_SELECT);
	nowScene->Init();
	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//裏画面消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

		nowScene->Update();
		if (nowScene->IsNext()) {
			auto nextScene = nowScene->NextScene();
			delete nowScene;

			nowScene = nextScene;
			nowScene->Init();
		}

		ScreenFlip();//裏画面を表画面にコピー
	}
	
	delete nowScene;
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}