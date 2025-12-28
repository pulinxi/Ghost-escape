#include "scene_main.h"
#include "player.h"
#include "enemy.h"
#include "world/effect.h"
#include "spawner.h"
#include "screen/ui_mouse.h"
#include "world/spell.h"
#include "screen/hud_stats.h"
#include "screen/hud_text.h"
#include "screen/hud_button.h"
#include "scene_title.h"
#include "raw/timer.h"
#include "raw/bg_star.h"
#include <fstream>


void SceneMain::init()
{
    Scene::init();
    SDL_HideCursor();
    game_.playMusic("assets/bgm/OhMyGhost.ogg");
    world_size_ = game_.getScreenSize() * 3.0f;
    camera_position_ = world_size_ / 2.0f - game_.getScreenSize() / 2.0f;
    player_ = new Player();
    player_->init();
    player_->setPosition(world_size_ / 2.0f);
    addChild(player_);

    BgStar::addBgStarChild(this, 1000, 0.2f, 0.5f, 0.7f);
    //BgStar::addBgStarChild(this, 1000, 1.0f, 1.0f, 1.0f);

    end_timer_ = Timer::addTimerchild(this);

    spawner_ = new Spawner();
    spawner_->init();
    spawner_->setTarget(player_);
    addChild(spawner_);

    button_pause_ = HUDButton::addHUDButtonChild(this, game_.getScreenSize() - glm::vec2(450.0f, 30.0f), "assets/UI/A_Pause1.png", "assets/UI/A_Pause2.png", "assets/UI/A_Pause3.png", 1.5f);
    button_restart_ = HUDButton::addHUDButtonChild(this, game_.getScreenSize() - glm::vec2(300.0f, 30.0f), "assets/UI/A_Restart1.png", "assets/UI/A_Restart2.png", "assets/UI/A_Restart3.png", 1.5f);
    button_back_ = HUDButton::addHUDButtonChild(this, game_.getScreenSize() - glm::vec2(150.0f, 30.0f), "assets/UI/A_Back1.png", "assets/UI/A_Back2.png", "assets/UI/A_Back3.png", 1.5f);

    hud_stats_ = HUDStats::addHUDStatsChild(this, player_, glm::vec2(30.0f));
    hud_text_score_ = HUDText::addHUDTextChild(this, "Score: 0", glm::vec2(game_.getScreenSize().x - 120.0f, 30.0f), glm::vec2(200.0f, 50.0f));
    ui_mouse_ = UIMouse::addUIMouseChild(this, "assets/UI/choose.png", "assets/UI/httpchoose.png", 0.5f, Anchor::TOP_LEFT);





}

bool SceneMain::handleEvents(SDL_Event& event)
{
    if (Scene::handleEvents(event)) return true;
    return false;

}

void SceneMain::update(float dt)
{
    checkSlowDown(dt);
    Scene::update(dt);
    updateScore();

    checkButtonRestart();
    checkButtonPause();
    checkButtonBack();

    if (player_ && !player_->getActive())
    {
        end_timer_->start();
        saveData("assets/score.dat");
    }
    checkEndTimer();

}

void SceneMain::render()
{
    renderBackground();
    Scene::render();
}

void SceneMain::clean()
{
    Scene::clean();
}

void SceneMain::saveData(const std::string& file_path)
{
    auto score = game_.getHighScore();
    std::ofstream file(file_path, std::ios::binary);    //binar代表以二进制的形式保存
    if (file.is_open())
    {
        file.write(reinterpret_cast<const char*>(&score), sizeof(score));
    }


}

void SceneMain::renderBackground()
{
    auto start = -camera_position_;
    auto end = world_size_ - camera_position_;
    game_.drawGrid(start, end, 80.0f, { 0.5, 0.5, 0.5, 1.0 });
    game_.drawBoundary(start, end, 5.0f, { 1.0, 1.0, 1.0, 1.0 });
}

void SceneMain::updateScore()
{
    hud_text_score_->setText("Score: " + std::to_string(game_.getScore()));
}

void SceneMain::checkButtonPause()
{
    if (!button_pause_->getIsTrigger()) return;
    if (is_pause_) resume();
    else pause();

}

void SceneMain::checkButtonRestart()
{
    if (!button_restart_->getIsTrigger())return;
    saveData("assets/score.dat");
    game_.setScore(0);
    auto scene = new SceneMain();
    game_.saveChangeScene(scene);

}

void SceneMain::checkButtonBack()
{
    if (!button_back_->getIsTrigger())return;
    saveData("assets/score.dat");
    game_.setScore(0);
    auto scene = new SceneTitle();
    game_.saveChangeScene(scene);

}

void SceneMain::checkEndTimer()
{
    if (!end_timer_->timeOut()) return;
    pause();
    button_restart_->setRenderPosition(game_.getScreenSize() / 2.0f - glm::vec2(200.0f, 0.0f));
    button_restart_->setScale(3.0f);
    button_back_->setRenderPosition(game_.getScreenSize() / 2.0f + glm::vec2(200.0f, 0.0f));
    button_back_->setScale(3.0f);
    button_pause_->setActive(false);
    end_timer_->stop();
}

void SceneMain::checkSlowDown(float& dt)
{
    if (game_.getMouseButtons() & SDL_BUTTON_RMASK)
    {
        dt *= 0.4f;
    }
}
