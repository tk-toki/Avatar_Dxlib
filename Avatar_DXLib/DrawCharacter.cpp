#include "DrawCharacter.h"
#include "WindowProperty.h"

DrawCharacter::DrawCharacter()
{
}

DrawCharacter::~DrawCharacter()
{
	delete m_inputAudio;
	delete m_openMouseImage;
	delete m_closeMouseImage;
}

void DrawCharacter::Init() {
	m_inputAudio = new InputAudio();

	m_closeMouseImage = new Image("D:\\ProgrammingSource\\Avatar\\Image\\n.png");
	m_closeMouseImage->Position(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2); // ��ʂ̐^�񒆂�
	m_closeMouseImage->Scale(0.2, 0.2); // �T�C�Y��5����1�ɂ���

	m_openMouseImage = new Image("D:\\ProgrammingSource\\Avatar\\Image\\a.png");
	m_openMouseImage->Position(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2); // ��ʂ̐^�񒆂�
	m_openMouseImage->Scale(0.2, 0.2); // �T�C�Y��5����1�ɂ���
}

void DrawCharacter::Update() {
	bool isOpen = m_inputAudio->IsThereSound();
	const Image* nowImage = DrawImage(isOpen);
	nowImage->Update();
}

bool DrawCharacter::IsNext()
{
	return false;
}

IScene* DrawCharacter::NextScene()
{
	return nullptr;
}

const Image* DrawCharacter::DrawImage(bool isOpen) {
	if (isOpen) {
		return m_openMouseImage;
	}
	return m_closeMouseImage;
}