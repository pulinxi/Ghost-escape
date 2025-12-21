#ifndef SPRITE_H
#define SPRITE_H

#include "../core/object_affiliate.h"
#include <string>

struct Texture
{
    SDL_Texture *texture = nullptr;
    SDL_FRect src_rect = {0, 0, 0, 0};
    float angle = 0;
    bool is_flip = false;
    Texture() = default;
    Texture(const std::string& file_path); 
};

class Sprite : public ObjectAffiliate
{
protected:
    Texture texture_;
    bool is_finish_ = false;

public:
    static Sprite* addSpriteChild(ObjectScreen* parrent, const std::string& file_path, float scale = 1.0f, Anchor anchor = Anchor::CENTER);

    virtual void render() override;

    // getters and setters
    Texture getTexture() const { return texture_; }
    virtual void setTexture(const Texture &texture);
    void setFlip(bool is_flip) { texture_.is_flip = is_flip; }
    void setAngle(float angle) { texture_.angle = angle; }
    bool getFlip() const { return texture_.is_flip; }
    float getAngle() const { return texture_.angle; }
    bool getFinish() const { return is_finish_; }
    void setFinish(bool is_finish) { is_finish_ = is_finish; }

};







#endif // SPRITE_H