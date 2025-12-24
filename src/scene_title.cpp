#include "scene_title.h"
#include "screen/hud_text.h"
#include "screen/hud_button.h"
#include "cmath"




void SceneTitle::init()
{
    Scene::init();
    auto size = glm::vec2(game_.getScreenSize().x / 2.0f, game_.getScreenSize().y / 3.0f);
    HUDText::addHUDTextChild(this, "幽 灵 逃 生", game_.getScreenSize() / 2.0f - glm::vec2(0.0f, 100.0f), size, "assets/font/VonwaonBitmap-16px.ttf", 64);
    auto score_text = "最高分" + std::to_string(game_.getHighScore());
    HUDText::addHUDTextChild(this, score_text, game_.getScreenSize() / 2.0f + glm::vec2(0.0f, 100.0f), glm::vec2(200.0f, 50.0f), "assets/font/VonwaonBitmap-16px.ttf", 32);

    button_quit_ = HUDButton::addHUDButtonChild(this, game_.getScreenSize() / 2.0f + glm::vec2(200.0f, 200.0f), "assets/UI/A_Quit1.png", "assets/UI/A_Quit2.png", "assets/UI/A_Quit3.png", 2.0f);


}

void SceneTitle::handleEvents(SDL_Event& event)
{
    Scene::handleEvents(event);
}

void SceneTitle::update(float dt)
{

    Scene::update(dt);
    color_timer_ += dt;
    updateColor();
    checkButtonQuit();

}

void SceneTitle::render()
{
    renderBackground();
    Scene::render();
}

void SceneTitle::clean()
{
    Scene::clean();
}

void SceneTitle::renderBackground()
{
    game_.drawBoundary(glm::vec2(30.0f), game_.getScreenSize() - glm::vec2(30.0f), 10.0f, boundary_color_);
}

void SceneTitle::updateColor()
{
    boundary_color_.r = 0.5f + 0.5f * sinf(2.0f * color_timer_ * 0.9f);
    boundary_color_.g = 0.5f + 0.5f * sinf(2.0f * color_timer_ * 0.6f);
    boundary_color_.b = 0.5f + 0.5f * sinf(2.0f * color_timer_ * 0.4f);


}

void SceneTitle::checkButtonQuit()
{
    if (button_quit_->getIsTrigger())
    {
        game_.quit();
    }
}
