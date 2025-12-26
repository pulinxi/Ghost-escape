#ifndef BG_STAR_H
#define BG_STAR_H

#include "../core/object.h"

class BgStar : public Object
{

protected:
    std::vector<glm::vec2> star_far_;//存储星星位置
    std::vector<glm::vec2> star_mid_;
    std::vector<glm::vec2> star_near_;
    float scale_far_ = 0.2f;//存储星星背景滚动速率
    float scale_mid_ = 0.5f;
    float scale_near_ = 0.7f;
    SDL_FColor color_far_ = { 0,0,0,1 };
    SDL_FColor color_mid_ = { 0,0,0,1 };
    SDL_FColor color_near_ = { 0,0,0,1 };
    float timer_ = 0;
    int num = 2000;//每一层的星星数量



public:
    static BgStar* addBgStarChild(Object* parent, int num, float scale_far, float scale_mid, float scale_near);


    virtual void update(float dt) override;
    virtual void render() override;


};
















#endif