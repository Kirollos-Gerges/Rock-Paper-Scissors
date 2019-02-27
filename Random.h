/*
	David Brown
	9.6.16
	Random Number Generation
*/

#if !defined RANDOM_H
#define RANDOM_H

/*
	Pre: None
	Post: Randomizer will be seed with current time
*/
void seedRandomizer();

/*
	Pre: low is an integer lower than high
	Post: Returns a random number between low inclusive and high exclusive
*/
int generateRandomInt (int low, int high);

/*
	Pre: low is a float lower than high
	Post: Returns a random number between low inclusive and high exclusive
*/
float generateRandomFloat (float low, float high);

#endif
