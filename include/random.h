#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <ctime>

using namespace std;

class Random
{
public:
    static int randint(int min, int max);
private:
    static bool seedWasGenerated;
    static void seed();
};

#endif // RANDOM_H