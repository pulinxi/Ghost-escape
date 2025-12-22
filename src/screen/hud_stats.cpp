#include "hud_stats.h"
#include "../core/actor.h"
#include "../raw/stats.h"
#include "../affiliate/sprite.h"


void HUDStats::update_health_bar()
{
    if (!target_ || !health_bar_ || !target_->getStats()) return;

    health_bar_->setPercentage(glm::vec2(target_->getStats()->getHealth() / target_->getStats()->getMaxHealth(), 1.0f));

}

void HUDStats::update_mana_bar()
{
    if (!target_ || !mana_bar_ || !target_->getStats()) return;

    mana_bar_->setPercentage(glm::vec2(target_->getStats()->getMana() / target_->getStats()->getMaxMana(), 1.0f));

}

void HUDStats::init()
{
    ObjectScreen::init();

    health_bar_bg_ = Sprite::addSpriteChild(this, "assets/UI/bar_bg.png", 3.0f, Anchor::CENTER_LEFT);
    health_bar_bg_->setOffset(health_bar_bg_->getOffset() + glm::vec2(30.0f, 0.0f));
    health_bar_ = Sprite::addSpriteChild(this, "assets/UI/bar_red.png", 3.0f, Anchor::CENTER_LEFT);
    health_bar_->setOffset(health_bar_->getOffset() + glm::vec2(30.0f, 0.0f));
    health_icon_ = Sprite::addSpriteChild(this, "assets/UI/Red Potion.png", 0.5f, Anchor::CENTER_LEFT);


    mana_bar_bg_ = Sprite::addSpriteChild(this, "assets/UI/bar_bg.png", 3.0f, Anchor::CENTER_LEFT);
    mana_bar_bg_->setOffset(mana_bar_bg_->getOffset() + glm::vec2(300.0f, 0.0f));
    mana_bar_ = Sprite::addSpriteChild(this, "assets/UI/bar_blue.png", 3.0f, Anchor::CENTER_LEFT);
    mana_bar_->setOffset(mana_bar_->getOffset() + glm::vec2(300.0f, 0.0f));
    mana_icon_ = Sprite::addSpriteChild(this, "assets/UI/Blue Potion.png", 0.5f, Anchor::CENTER_LEFT);
    mana_icon_->setOffset(mana_icon_->getOffset() + glm::vec2(270.0f, 0.0f));


}

void HUDStats::update(float dt)
{
    ObjectScreen::update(dt);
    update_health_bar();
    update_mana_bar();

}

HUDStats* HUDStats::addHUDStatsChild(Object* parent, Actor* target, glm::vec2 render_position)
{
    HUDStats* huds = new HUDStats();
    huds->init();
    huds->setRenderPosition(render_position);
    huds->setTarget(target);
    if (parent) parent->addChild(huds);

    return huds;
}
