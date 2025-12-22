#ifndef HUD_STATS_H
#define HUD_STATS_H


#include "../core/object_screen.h"

class Sprite;
class Actor;
class HUDStats : public ObjectScreen
{
protected:

    Actor* target_ = nullptr;



    Sprite* health_bar_ = nullptr;
    Sprite* health_bar_bg_ = nullptr;
    Sprite* health_icon_ = nullptr;
    float health_percentage_ = 1.0f;


    Sprite* mana_bar_ = nullptr;
    Sprite* mana_bar_bg_ = nullptr;
    Sprite* mana_icon_ = nullptr;
    float mana_percentage_ = 1.0f;



private:
    void update_health_bar();
    void update_mana_bar();


public:

    virtual void init() override;
    virtual void update(float dt) override;

    static HUDStats* addHUDStatsChild(Object* parent, Actor* target, glm::vec2 render_position);







    Sprite* getHealthBar() const {
        return health_bar_;
    }

    void setHealthBar(Sprite* health_bar) {
        health_bar_ = health_bar;
    }

    Sprite* getHealthBarBg() const {
        return health_bar_bg_;
    }

    void setHealthBarBg(Sprite* health_bar_bg) {
        health_bar_bg_ = health_bar_bg;
    }

    Sprite* getHealthIcon() const {
        return health_icon_;
    }

    void setHealthIcon(Sprite* health_icon) {
        health_icon_ = health_icon;
    }

    float getHealthPercentage() const {
        return health_percentage_;
    }

    void setHealthPercentage(float health_percentage) {
        health_percentage_ = health_percentage;
    }

    Sprite* getManaBar() const {
        return mana_bar_;
    }

    void setManaBar(Sprite* mana_bar) {
        mana_bar_ = mana_bar;
    }

    Sprite* getManaBarBg() const {
        return mana_bar_bg_;
    }

    void setManaBarBg(Sprite* mana_bar_bg) {
        mana_bar_bg_ = mana_bar_bg;
    }

    Sprite* getManaIcon() const {
        return mana_icon_;
    }

    void setManaIcon(Sprite* mana_icon) {
        mana_icon_ = mana_icon;
    }

    float getManaPercentage() const {
        return mana_percentage_;
    }

    void setManaPercentage(float mana_percentage) {
        mana_percentage_ = mana_percentage;
    }

    Actor* getTarget() const {
        return target_;
    }

    void setTarget(Actor* target) {
        target_ = target;
    }



};














#endif