#ifndef SCENE_TITLE_H
#define SCENE_TITLE_H


#include "core/scene.h"



class SceneTitle : public Scene
{


protected:
    SDL_FColor boundary_color_ = { 0.5f,0.5f,0.5f,1.0f };
    float color_timer_ = 0.0f;



public:
    void init() override;
    void handleEvents(SDL_Event& event) override;
    void update(float dt) override;
    void render() override;
    void clean() override;



private:
    void renderBackground();
    void updateColor();

};










#endif