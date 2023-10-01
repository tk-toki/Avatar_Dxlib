#include "DxLib.h"
#include "Image.h"
#include "Debug.h"
#define SCREEN_SIZE_X 432
#define SCREEN_SIZE_Y 768

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // ウィンドウモードを有効に
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 0); // ウィンドウサイズの設定
	SetOutApplicationLogValidFlag(FALSE); // Log.txtを生成しないように設定
	SetBackgroundColor(0, 0, 255); // 背景色は青単色にする
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	
	auto closeMouseImage = new Image("F:\\Image\\zundamon\\n.png");
	closeMouseImage->Position(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2); // 画面の真ん中に
	closeMouseImage->Scale(0.2, 0.2); // サイズは5分の1にする

	auto openMouseImage = new Image("F:\\Image\\zundamon\\a.png");
	openMouseImage->Position(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2); // 画面の真ん中に
	openMouseImage->Scale(0.2, 0.2); // サイズは5分の1にする

	auto nowImage = closeMouseImage;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//裏画面消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

		nowImage->Draw();

		ScreenFlip();//裏画面を表画面にコピー
	}
	
	delete closeMouseImage;
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}