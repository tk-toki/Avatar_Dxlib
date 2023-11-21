#pragma once
#include <portaudio.h>

class InputAudio {
private:
	static PaDeviceIndex deviceIndex;
public:
	static void SetInputAudioIndex(int selectAudioNumber);
	InputAudio();
	bool IsThereSound();
};