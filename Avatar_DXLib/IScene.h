#pragma once

class IScene {
public:
    virtual ~IScene() {}
    virtual void Init() = 0;
    virtual void Update() = 0; // ƒV[ƒ“‚Ì•`‰æ‚ğs‚¤ŠÖ”
    virtual bool IsNext() = 0;
    virtual IScene* NextScene() = 0;
};