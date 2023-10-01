#include "DxLib.h"
#include "Image.h"
#include "Debug.h"
#define SCREEN_SIZE_X 432
#define SCREEN_SIZE_Y 768

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h��L����
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 0); // �E�B���h�E�T�C�Y�̐ݒ�
	SetOutApplicationLogValidFlag(FALSE); // Log.txt�𐶐����Ȃ��悤�ɐݒ�
	SetBackgroundColor(0, 0, 255); // �w�i�F�͐P�F�ɂ���
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	
	auto closeMouseImage = new Image("F:\\Image\\zundamon\\n.png");
	closeMouseImage->Position(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2); // ��ʂ̐^�񒆂�
	closeMouseImage->Scale(0.2, 0.2); // �T�C�Y��5����1�ɂ���

	auto openMouseImage = new Image("F:\\Image\\zundamon\\a.png");
	openMouseImage->Position(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2); // ��ʂ̐^�񒆂�
	openMouseImage->Scale(0.2, 0.2); // �T�C�Y��5����1�ɂ���

	auto nowImage = closeMouseImage;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();//����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

		nowImage->Draw();

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}
	
	delete closeMouseImage;
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}