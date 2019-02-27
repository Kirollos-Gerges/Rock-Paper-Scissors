/*
	Random.h / Random.cpp
	Provide functions to seed randomizer, generate random int and float
	7.13.18
	dwbrown
*/

#include <ctime>
#include <cstdlib>
#include "Random.h"

using namespace std;

void seedRandomizer ()
{
	srand (time (NULL));
}

int generateRandomInt (int low, int high)
{
	return rand() % (high-low) + low;
}

float generateRandomInt (float low, float high)
{
	return ((high - low) * ((float) rand ()/RAND_MAX)) + low;
}