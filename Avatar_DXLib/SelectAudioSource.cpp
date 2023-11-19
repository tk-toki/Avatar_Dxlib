#include "SelectAudioSource.h"
#include <DxLib.h>

SelectAudioSource::SelectAudioSource()
{

}

SelectAudioSource::~SelectAudioSource()
{
}

void SelectAudioSource::Init()
{
}

void SelectAudioSource::Update()
{
}

bool SelectAudioSource::IsNext()
{
	return CheckHitKey(KEY_INPUT_1);
}

IScene* SelectAudioSource::NextScene()
{
	return SceneFactory::Factory(SceneType::DRAW_CHARACTER);
}
