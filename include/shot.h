#ifndef SHOT_H
#define SHOT_H

class Shot
{
public:
    Shot();
    ~Shot();

    // bool init();
    // void deinit();

private:
    float dx, dy, x, y;
    bool isBulletFromSelf;
};

#endif