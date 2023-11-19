#pragma once
#include "IScene.h"
#include "SceneFactory.h"

class SelectAudioSource : public IScene {
private:
public:
    SelectAudioSource();
    ~SelectAudioSource();
    void Init() override;
    void Update() override;
    bool IsNext() override;
    IScene* NextScene() override;
};