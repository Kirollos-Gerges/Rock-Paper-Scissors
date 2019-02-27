//Kirollos Gerges, ME Student, T00271723

//Program Describiton:

//This program is to create a game called roshambo to be played between the user and a computer adversary.
//The user will be asked to choose between the three options of Rock, Paper or Scissors.
//Once they have selected, the computer will randomly select between the options.
//By comparing these two choices we are able to determine a winner (or if they both tied).
//The standard conditions for winning are, Rock beats Scissors, Scissors beats Paper, and Paper beats Rock.
//we will test our results over a “best of 5” or “best of 7” type of situation
//. For this reason, we will enclose the existing code into a user controlled loop that will continue
//to play the game, while keeping a running score, until the user decides to terminate the game. It is to
//be assumed that if the user has started the program, they wish to play at least one hand of roshambo. 
//Once the user terminates, you will present the statistics for current session as well as all time numbers.
//These all time statistics will be stored in a file RPS.txt.

//Loops
//storing data in rps.txt
//input validation
//output-cout at the end of the game
//comments
//quiting the game option to add
//the 3 functions


//build: g++ -c Main.cpp Random.cpp
// 		 g++ -o Main.exe Main.o Random.o


#include <iostream>

#include "Random.h"

#include <fstream>

using namespace std;

int main()
{
	//constants
	const int ROCK = 1; // if the user inputs 1 then he chose Rock.
	const int PAPER = 2; // if the user inputs 2 then he chose Paper.
	const int SCISSORS = 3; // if the user inputs 3 then he chose Scissors.
	const int Quit=4;		//The programw will quit but after giving the staseticts]
	//Variables
	int choice = 0;
	int random_choice = 0;
	 
	
	cout <<"Welcome to Roshambo, Please select your choice from the options below :"<<endl;
	cout <<"1.Rock"<<endl;
	cout <<"2.Paper"<<endl;
	cout <<"3.Scissors"<<endl;
	cout <<"4.Quit"<<endl;
	cout<<"choice :"; 
	
	cin>> choice;
	
	//Will get the Computer Choice.
	seedRandomizer ();
	random_choice = generateRandomInt (1,4);
	
	if (choice==ROCK) //case 1, user chooses rock
	{
		cout<<"you chose Rock ,";
		
		if (random_choice ==ROCK)
		{	
			cout<<"computer chose Rock, No Winner!!.\n";
		}	
		else if (random_choice ==PAPER)
		{	
			cout<<"computer chose Paper, You lose.\n";
		}
		else
		{
			cout<<"computer chose Scissors, You win.\n";
		}	

	}
	else if (choice==PAPER) //Case 2, user choses paper
	{
		
		cout<<"you chose Paper ,";
		
		if (random_choice ==ROCK)
		{	
			cout<<"computer chose Rock, you win!.\n";
		}	
		else if (random_choice ==PAPER)
		{	
			cout<<"computer chose Paper, No Winner.\n";
		}
		else
		{
			cout<<"computer chose Scissors, You lose.\n";
		}

	}
	else if (choice==SCISSORS) //case 3, user chooses scissors.
	{
		
		cout<<"you chose Scissors ,";
		
		if (random_choice ==ROCK)
		{	
			cout<<"computer chose Rock, you lose!!.\n";
		}	
		else if (random_choice ==PAPER)
		{	
			cout<<"computer chose Paper, You win.\n";
		}
		else
		{
			cout<<"computer chose Scissors, No Winner.\n";
		}
	}
	else 
	{
		cout<<"your input is invalid, game will quit."<<endl;
		
		return 1;

	}
	
	return 0;

}