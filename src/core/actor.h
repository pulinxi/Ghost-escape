#ifndef ACTOR_H
#define ACTOR_H

#include "object_world.h"

class Stats;
class AffiliateBar;
class Actor : public ObjectWorld
{
protected:
    Stats* stats_ = nullptr; // 角色属性
    AffiliateBar* health_bar_ = nullptr;//生命条
    glm::vec2 velocity_ = glm::vec2(0, 0); // 速度
    float max_speed_ = 100.0f; // 最大速度大小

public:


    virtual void update(float dt) override;
    virtual void takeDamage(float damage) override;


    void move(float dt);    // 移动
    // getters and setters
    glm::vec2 getVelocity() const { return velocity_; }
    void setVelocity(const glm::vec2& velocity) { velocity_ = velocity; }
    float getMaxSpeed() const { return max_speed_; }
    void setMaxSpeed(float max_speed) { max_speed_ = max_speed; }
    Stats* getStats() const { return stats_; }
    void setStats(Stats* stats) { stats_ = stats; }
    bool getIsAlive() const;
    void setHealthBar(AffiliateBar* healthbar) { health_bar_ = healthbar; }
    AffiliateBar* gerHealthBar() const { return health_bar_; }


private:
    void updateHealthBar();



};






#endif // ACTOR_H