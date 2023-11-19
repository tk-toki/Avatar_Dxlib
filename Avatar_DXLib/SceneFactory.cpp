#include "SceneFactory.h"

IScene* SceneFactory::Factory(SceneType scene)
{
	switch (scene)
	{
	case SELECT_AUDIO_SOURCE:
		return new SelectAudioSource();
	case DRAW_CHARACTER:
		return new DrawCharacter();
	default:
		return nullptr;
	}
}