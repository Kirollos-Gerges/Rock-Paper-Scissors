// Doc Brown's Simple Roshambo
// 1.22.19
// Play one round of Rock - Paper - Scissors

#include <iostream>
#include "Random.h"

using namespace std;

int main ()
{
	int userSelect, compSelect;
	seedRandomizer ();
	
	//Get the user Input
	cout << "Welcome to Roshambo." << endl;
	cout << "Please select your choice from the options below : " << endl;
	cout << " 1. Rock" << endl;
	cout << " 2. Paper" << endl;
	cout << " 3. Scissors" << endl;
	cout << "Your choice : ";
	cin >> userSelect;

	// Basic Input Validation
	if (userSelect < 1 || userSelect > 3)
	{
		cout << "That is an invalid option.  Run again and be more careful" << endl;
		return 1;
	}
	//Get the computers guess
	compSelect = generateRandomInt (1, 4);

	//Lots of if - else statements to control who wins
	if (userSelect == 1)
	{
		if (compSelect == 1)
		{
			cout << "You and the computer both chose Rock. It is a tie" << endl;
		}
		else if (compSelect == 2)
		{
			cout << "You chose Rock, the computer chose Paper. You Lose :(" << endl;
		}
		else
		{
			cout << "You chose Rock, the computer chose Scissors. You Win!" << endl;
		}
	}
	else if (userSelect == 2)
	{
		if (compSelect == 1)
		{
			cout << "You chose Paper, the computer chose Rock. You Win!" << endl;
		}
		else if (compSelect == 2)
		{
			cout << "You and the computer both chose Paper. It is a tie" << endl;
		}
		else
		{
			cout << "You chose Paper, the computer chose Scissors. You Lose :(" << endl;
		}
	}
	else
	{
		if (compSelect == 1)
		{
			cout << "You chose Scissors, the computer chose Rock. You Lose :(" << endl;
		}
		else if (compSelect == 2)
		{
			cout << "You chose Scissors, the computer chose Paper. You Win!" << endl;
		}
		else
		{
			cout << "You and the computer both chose Scissors. It is a tie" << endl;
		}
	}

	//End the program
	return 0;
}