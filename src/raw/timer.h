#ifndef TIMER_H
#define TIMER_H

#include "../core/object.h"


class Timer : public Object //创建时默认is_active_为false,需要使用时才设为true
{


protected:
    float timer_ = 0.0f;
    float interval_ = 3.0f;//一个循环的时间
    bool time_out_ = false;





public:


    static Timer* addTimerchild(Object* parent, float interval = 3.0f);

    virtual void update(float dt) override;


    void start() { is_active_ = true; }
    void stop() { is_active_ = false; }
    bool timeOut();
    float getProgress() { return timer_ / interval_; }


    float getTimer() const {
        return timer_;
    }

    void setTimer(float timer) {
        timer_ = timer;
    }

    float getInterval() const {
        return interval_;
    }

    void setInterval(float interval) {
        interval_ = interval;
    }



};










#endif