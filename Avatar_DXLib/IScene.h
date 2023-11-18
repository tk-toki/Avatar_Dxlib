#pragma once
#include "SceneFactory.h"

class IScene {
public:
    virtual ~IScene() {}
    virtual void Init() = 0;
    virtual void Update() = 0; // �V�[���̕`����s���֐�
    virtual bool IsNext() = 0; // ���̃V�[���Ɉڍs���邩
    virtual IScene* NextScene() = 0; // ���̃V�[����Ԃ�
};