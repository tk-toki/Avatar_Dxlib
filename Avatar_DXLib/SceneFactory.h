#pragma once
#include "IScene.h"
#include "DrawCharacter.h"
#include "SelectAudioSource.h"

enum SceneType {
	SELECT_AUDIO_SOURCE,
	DRAW_CHARACTER
};

class SceneFactory {
public:
	static IScene* Factory(SceneType scene);
};