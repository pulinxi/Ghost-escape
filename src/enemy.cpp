#include "enemy.h"
#include "core/scene.h"
#include "affiliate/collider.h"
#include "raw/stats.h"

Enemy *Enemy::addEnemyChild(Object *parent, glm::vec2 pos, Player *target)
{
    auto enemy = new Enemy();
    enemy->init();
    enemy->setPosition(pos);
    enemy->setTarget(target);
    if (parent) parent->addChild(enemy);
    return enemy;
}

void Enemy::init()
{
    Actor::init();
    anim_normal_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-Sheet.png", 2.0f);
    anim_hurt_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghostHurt-Sheet.png", 2.0f);
    anim_die_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghostDead-Sheet.png", 2.0f);
    anim_hurt_->setActive(false);
    anim_die_->setActive(false);
    anim_die_->setLoop(false);

    current_anim_ = anim_normal_;
    collider_ = Collider::addColliderChild(this, current_anim_->getSize());
    stats_ = Stats::addStatsChild(this);
}

void Enemy::update(float dt){
    Actor::update(dt);
    if (target_->getActive()){
        aim_target(target_);
        move(dt);
        attack();
    }
}


void Enemy::aim_target(Player *target)
{
    if (target == nullptr) return;
    auto direction = target->getPosition() - this->getPosition();
    direction = glm::normalize(direction);
    velocity_ = direction * max_speed_;
}

void Enemy::checkState()
{
}

void Enemy::changeState(State new_state)
{
    if (new_state == current_state_) return;
    current_anim_->setActive(false);
    switch (new_state) {
    case State::NORMAL:
        current_anim_ = anim_normal_;
        current_anim_->setActive(true);
        break;
    case State::HURT:
        current_anim_ = anim_hurt_;
        current_anim_->setActive(true);
        break;
    case State::DIE:
        current_anim_ = anim_die_;
        current_anim_->setActive(true);
        break;
    }
    current_state_ = new_state;
}

void Enemy::remove()
{
    if (anim_die_->getFinish()) {
        need_remove_ = true;
    }
}

void Enemy::attack()
{
    if (!collider_ || !target_ || target_->getCollider() == nullptr) return;
    if (collider_->isColliding(target_->getCollider())) {
        // TODO: attack
        if (stats_ && target_->getStats()) {
            target_->takeDamage(stats_->getDamage());
        }
    }
}