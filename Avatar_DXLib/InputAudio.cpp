#include "InputAudio.h"
#include <iostream>
#include <cmath>
#include <portaudio.h>

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (512)
#define NUM_SECONDS (5)
#define NUM_SAMPLES (SAMPLE_RATE * NUM_SECONDS)
#define THRESHOLD (0.005)

int InputAudio::deviceIndex = 0;

void InputAudio::SetInputAudioIndex(int audioIndex)
{
    deviceIndex = audioIndex;
}

InputAudio::InputAudio() {

}

bool InputAudio::IsThereSound() {
    // Initialize PortAudio
    Pa_Initialize();
    // Set up input parameters
    PaStreamParameters inputParameters;
    inputParameters.device = deviceIndex;
    inputParameters.channelCount = 1;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    // Open the audio stream
    PaStream* stream;
    Pa_OpenStream(&stream, &inputParameters, NULL, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, NULL, NULL);

    // Start the audio stream
    Pa_StartStream(stream);

    // Read a buffer of audio data from the stream
    float buffer[FRAMES_PER_BUFFER];
    Pa_ReadStream(stream, buffer, FRAMES_PER_BUFFER);

    // Calculate the root mean square (RMS) of the audio data
    double rms = 0.0;
    for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
        rms += buffer[i] * buffer[i];
    }
    rms = std::sqrt(rms / FRAMES_PER_BUFFER);

    // Check if the RMS is above the threshold
    int result = (rms > THRESHOLD) ? true : false;

    // Clean up
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();

    return result;
}