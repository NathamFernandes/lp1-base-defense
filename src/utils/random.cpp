#include "random.h"

bool Random::seedWasGenerated = false;

void Random::seed()
{
    if (!seedWasGenerated)
    {
        srand(time(0));
        seedWasGenerated = true;
    }
}

int Random::randint(int min, int max)
{
    seed();
    return min + (rand() % (max - min));
}