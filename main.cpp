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


//build: g++ -c Main2.cpp Random.cpp
// 		 g++ -o Main2.exe Main2.o Random.o
//refrences, Dr brown's random computer choice 


#include <iostream>

#include "Random.h"

#include <fstream>

using namespace std;

//constants

const int ROCK = 1; 	 // if the user inputs 1 then he chose Rock.
const int PAPER = 2; 	 // if the user inputs 2 then he chose Paper.
const int SCISSORS = 3;  // if the user inputs 3 then he chose Scissors.
const int Quit=4;		 //if the user inputs 4 then he chose to quit.

//variables for prevoius data
int total_prev_wins=0; 	//for the prevoius wins
int total_prev_games=0;	//for the prevoius number of games
int total_prev_tied=0;	//for the prevoius ties

void toread (void){                  //A function to read the date from the txt file.
	ifstream file;
	file.open("rps.txt");
	file >> total_prev_games >> total_prev_tied >> total_prev_wins;
	file.close();
	}
	
void towrite (void){				//A function to write and increment the new data to the prevoius ones on a txt  file.
	ofstream file;
	file.open ("rps.txt");
	file << total_prev_games<< " ";
	file << total_prev_tied<< " ";
	file << total_prev_wins<< " ";
	file.close();
	}
int userRock (int compChoice){		//A function for the case of selecting Rock by the user.
	
	cout<<"you chose Rock ,";
	
	if (compChoice == ROCK)
	{	
		cout<<"computer chose Rock, No Winner!!.\n";
		return 0;    //returning 0 corresponds to tieing which we will use later on to increment the number of tieing.
	}	
	else if (compChoice == PAPER)
	{	
		cout<<"computer chose Paper, You lose.\n";
		return -1;	//returning -1 corresponds to losing which we will use later on to increment the number of losses.
	}
	else
	{
		cout<<"computer chose Scissors, You win.\n";
		return 1; //returning 1 corresponds to losing which we will use later on to increment the number of wins.
	}	

	
}
int userPaper (int compChoice)     			//A function for the case of selecting paper by the user.
{
	cout<<"you chose Paper ,";
	
	if (compChoice ==ROCK)
	{	
		cout<<"computer chose Rock, you win!.\n";
		return 1;
	}	
	else if (compChoice ==PAPER)
	{	
		cout<<"computer chose Paper, No Winner.\n";
		return 0;
	}
	else
	{
		cout<<"computer chose Scissors, You lose.\n";
		return -1;
	}
}
int userScissors (int compChoice)			//A function for the case of selecting scissors by the user.
{
cout<<"you chose Scissors ,";
	
	if (compChoice ==ROCK)
	{	
		cout<<"computer chose Rock, you lose!!.\n";
		return -1;
	}	
	else if (compChoice ==PAPER)
	{	
		cout<<"computer chose Paper, You win.\n";
		return 1;
	}
	else
	{
		cout<<"computer chose Scissors, No Winner.\n";
		return 0;
	}

}

int main()
{
	
	//Variables for current game
	int choice = 0;
	int random_choice = 0;
	int total_wins=0;
	int total_games=0;
	int total_tied=0;
	int result=0;
	 
	cout <<"Welcome to Roshambo."<<endl;
	do
	{
		choice=0; //intitialzing choice to 0
		while (choice < 1 || choice > 4)  //while loop in case the user selects an invalid option
		{
			cout << "Please select your choice from the options below : "<<endl;
			cout <<"1.Rock"<<endl;
			cout <<"2.Paper"<<endl;
			cout <<"3.Scissors"<<endl;
			cout <<"4.Quit"<<endl;
			cout <<"choice :"; 
			
			cin >> choice;  //to get the user choice
			
			//Input validation
			
			if (choice < 1 || choice > 4)
			{
				cout << "That is an invalid option.  Run again and be more careful" << endl;
			
			}
		}
		if (choice ==4)  //for what happens if the user chooses to quit the game
		{
			toread();							//will read the data from the txt file
			total_prev_games+=total_games;
			total_prev_wins+=total_wins;
			total_prev_tied+=total_tied;
			cout << "Thank you for playing. This time you played " <<total_games; //will print the current game result, of number of games , wins , and ties. 
			cout << " hands and won "<<total_wins<<" and tied "<<total_tied;
			cout <<". Overall, you have played " <<total_prev_games<<" hands and won "<<total_prev_wins<<" and tied "<<total_prev_tied<<endl; //will print the prevoius game result, of # of games , wins , and ties. 
			towrite(); //will write and add the new game results to the txt file. 
			break; //will get out of the loop
			
		}
		
		

		//Will get the Computer Choice.
		
		seedRandomizer ();
		random_choice = generateRandomInt (1,4);
		
		
		total_games++; //will increment the number of games he plays this time 
		if (choice==ROCK) //case 1, user chooses rock
		{
			
			result = userRock (random_choice);   //will see the result from the function for that the user chooses rock.
			if (result==1)
			{
				total_wins++; //will increment the number of wins of this game 
			}
			else if (result==0)
			{
				total_tied++;	//will increment the number of ties of this game 
			}
	
		}
		else if (choice==PAPER) //Case 2, user choses paper
		{
			
			result = userPaper (random_choice); //will see the result from the function for that the user chooses paper
			if (result==1)
			{
				total_wins++; //will increment the number of wins of this game
			}
			else if (result==0)
			{
				total_tied++;	//will increment the number of ties of this game
			}
		}
		else if (choice==SCISSORS) //case 3, user chooses scissors.
		{
			
			result = userScissors (random_choice);	//will see the result from the function for that the user chooses scissors
			if (result==1)
			{
				total_wins++; //will increment the number of wins of this game
			}
			else if (result==0)
			{
				total_tied++;	//will increment the number of ties of this game
			}			
		}
		else 
		{
			cout<<"your input is invalid, game will quit."<<endl;
			
			return 1;
		}
		
		
		
		
	} while (choice >= 1 && choice <4); // will keep the loop going as long as the user chosses 1,2,or3
	return 0;
	

}