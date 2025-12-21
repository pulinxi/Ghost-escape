#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H

#include "core/scene.h"

class Spawner;
class Player;
class UIMouse;
class SceneMain: public Scene
{
    Player* player_ = nullptr; // 玩家
    Spawner* spawner_ = nullptr;
    UIMouse* ui_mouse_ = nullptr;
public:
    SceneMain() = default;
    virtual ~SceneMain() = default;

    virtual void init() override;
    virtual void handleEvents(SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

private:
    void renderBackground();


};




#endif // SCENE_MAIN_H