#ifndef OBJECT_AFFILIATE_H
#define OBJECT_AFFILIATE_H

#include "object_screen.h"

class ObjectAffiliate : public Object 
{
protected:
    ObjectScreen *parrent_ = nullptr; // 父节点
    glm::vec2 offset_ = glm::vec2(0, 0); // 相对父节点的偏移
    glm::vec2 size_ = glm::vec2(0, 0); // 大小
    Anchor anchor_ = Anchor::CENTER; // 锚点

public:
    void setOffsetByAnchor(Anchor anchor);

    // getters and setters
    ObjectScreen *getParent() const { return parrent_; }
    void setParent(ObjectScreen *parrent) { parrent_ = parrent; }
    glm::vec2 getOffset() const { return offset_; }
    void setOffset(const glm::vec2 &offset) { offset_ = offset; }
    glm::vec2 getSize() const { return size_; }
    void setSize(const glm::vec2 &size);
    void setScale(float scale);
    Anchor getAnchor() const { return anchor_; }
    void setAnchor(Anchor anchor) { anchor_ = anchor; }
};






#endif // OBJECT_AFFILIATE_H