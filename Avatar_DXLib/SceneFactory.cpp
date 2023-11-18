#include "SceneFactory.h"

SceneFactory::SceneFactory()
{
}

IScene* SceneFactory::Factory(Scene scene)
{
	switch (scene) {
	case AUDIO_SOURCE_SELECT:
		return new AudioSourceSelect();
	case DRAW_CHARACTER:
		return new DrawCharacter();
	}
}