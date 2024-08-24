#ifndef BONUS_POINTS_H
#define BONUS_POINTS_H

enum BonusType
{
    LIFE = 0,
    AMMUNITION,
    LAST_BONUS_TYPE,
};

class BonusPoints
{
public:
    void render();
    void update();
private:
    int x, y;
    int points;
};

#endif // BONUS_POINTS_H