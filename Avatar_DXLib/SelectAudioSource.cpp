#include "SelectAudioSource.h"
#include <DxLib.h>
#include <portaudio.h>
#include "Debug.h"

void SelectAudioSource::DrawDeviceNameList()
{
    int numDevices = Pa_GetDeviceCount();
    if (numDevices < 0) {
        DrawString(0, 0, Pa_GetErrorText(numDevices), GetColor(255, 255, 255));
    }

    for (int i = 0; i < numDevices; i++) {
        const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(i);
        DrawString(0, 0, "<SelectDevice>", GetColor(255, 255, 255));

        // 現在選択状態のものとそうでないもので色を分ける
        int color = (i == m_deviceIndex) ? GetColor(255, 255, 255) : GetColor(125, 125, 125);

        // デバイス名をTCHAR*に変換
        TCHAR deviceNameT[128];
        _stprintf_s(deviceNameT, sizeof(deviceNameT), _T("%s"), deviceInfo->name);

        TCHAR deviceInfoT[150];
        _stprintf_s(deviceInfoT, sizeof(deviceInfoT), _T("#%d: %s"), i, deviceNameT);
        DrawString(0, 15 + 15 * i, deviceInfoT, color);
    }

    Pa_Terminate();
}

int SelectAudioSource::ChangeSelectDevice()
{
    int max = Pa_GetDeviceCount();
    //デバイスの選択
    if (CheckHitKey(KEY_INPUT_DOWN)) {
        m_deviceIndex++;
        if (m_deviceIndex > max) {
            m_deviceIndex = 0;
        }
    }
    else if (CheckHitKey(KEY_INPUT_UP)) {
        m_deviceIndex--;
        if (m_deviceIndex < 0) {
            m_deviceIndex = max;
        }
    }
    return m_deviceIndex;
}

SelectAudioSource::SelectAudioSource()
{
    m_deviceIndex = 0;
}

SelectAudioSource::~SelectAudioSource()
{
}

void SelectAudioSource::Init()
{
}

void SelectAudioSource::Update()
{
    PaError err = Pa_Initialize();
    // 入力反映
    ChangeSelectDevice();
    // デバイス名の表示
    DrawDeviceNameList();
}

bool SelectAudioSource::IsNext()
{
    if (CheckHitKey(KEY_INPUT_RETURN)) {
        InputAudio::SetInputAudioIndex(m_deviceIndex);
        return true;
    }
	return false;
}

IScene* SelectAudioSource::NextScene()
{
	return SceneFactory::Factory(SceneType::DRAW_CHARACTER);
}
