#pragma once
#include "IScene.h"
#include "DrawCharacter.h"
#include "AudioSourceSelect.h"
#include "SceneFactory.h"

enum Scene {
	AUDIO_SOURCE_SELECT,
	DRAW_CHARACTER
};

class SceneFactory {
public:
	static IScene* Factory(Scene scene);
};