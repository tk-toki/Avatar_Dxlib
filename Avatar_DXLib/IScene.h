#pragma once

class IScene {
public:
    virtual ~IScene() {}
    virtual void Init() = 0;
    virtual void Draw() = 0; // �V�[���̕`����s���֐�
};