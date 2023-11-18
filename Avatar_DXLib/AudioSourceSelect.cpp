#include "AudioSourceSelect.h"
#include <DxLib.h>

void AudioSourceSelect::Init()
{
}

void AudioSourceSelect::Update()
{

}

bool AudioSourceSelect::IsNext()
{
    return CheckHitKey(KEY_INPUT_1);
}

IScene* AudioSourceSelect::NextScene() {
    return SceneFactory::Factory(DRAW_CHARACTER);
}