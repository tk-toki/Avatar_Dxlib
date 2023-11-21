#include "WindowProperty.h"
#include "DxLib.h"
#include "SceneFactory.h"
#include "Image.h"
#include "Debug.h"
#include "InputAudio.h"
#include "DrawCharacter.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);
	SetAlwaysRunFlag(TRUE); // ��A�N�e�B�u�ł����삳����
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h��L����
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 0); // �E�B���h�E�T�C�Y�̐ݒ�
	SetOutApplicationLogValidFlag(FALSE); // Log.txt�𐶐����Ȃ��悤�ɐݒ�
	SetBackgroundColor(0, 0, 255); // �w�i�F�͐P�F�ɂ���
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	IScene* nowScene = SceneFactory::Factory(SceneType::SELECT_AUDIO_SOURCE);
	nowScene->Init();
	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

		nowScene->Update();
		if (nowScene->IsNext()) {
			IScene* nextScene = nowScene->NextScene();
			delete nowScene;
			nowScene = nextScene;
			nowScene->Init();
		}

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}
	
	delete nowScene;
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}