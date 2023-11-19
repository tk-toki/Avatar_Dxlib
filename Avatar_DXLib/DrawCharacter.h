#pragma once
#include "IScene.h"
#include "InputAudio.h"
#include "Image.h"

class DrawCharacter : public IScene {
private:
    InputAudio* m_inputAudio;
    Image* m_closeMouseImage;
    Image* m_openMouseImage;
    const Image* DrawImage(bool isOpen);
public:
    DrawCharacter();
    ~DrawCharacter();
    void Init() override;
    void Update() override;
    bool IsNext() override;
    IScene* NextScene() override;
};