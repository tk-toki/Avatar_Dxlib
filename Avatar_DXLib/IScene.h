#pragma once

class IScene {
public:
    virtual ~IScene() {}
    virtual void Init() = 0;
    virtual void Update() = 0; // シーンの描画を行う関数
    virtual bool IsNext() = 0;
    virtual IScene* NextScene() = 0;
};