#pragma once
#include "IScene.h"

class AudioSourceSelect : public IScene {
private:
public:
    void Init() override;
    void Update() override;
    bool IsNext() override;
    IScene* NextScene() override;
};