//TeamsHigh.h - Declarations of methods and variables in the TeamsHigh class
//Written by Christina Black


#include "TeamsHigh.h"
#include <iostream>
using namespace std;


	//Default Constructor
	TeamsHigh::TeamsHigh()
	{
		TeamName = NAME;
		Number = DEFAULT;
	}

	//Init constructor
	TeamsHigh::TeamsHigh(string& name, int number)
	{
		TeamName = name;
		Number = number;
	}

	//Loads high teams into vector
	void TeamsHigh::LoadHigh(int i)
	{
		string teamName;
		ifstream in("high.txt");
		while ( !in.eof() )
		{
			getline(in, teamName);
			high.push_back(TeamsHigh(teamName, i));
			i++;
		}

		in.close();
	}

	//Loads high members into vector
	void TeamsHigh::LoadHighMembers(int i)
	{
		int j=0;
		string teamName;
		ifstream in("highmembs.txt");
		while (j < (int)TeamsHigh::high.size())
		{
			getline(in, teamName);
			high[j].AddMembers(teamName);
			j++;
		}

		in.close();
	}

	//Gets total score of high vector
	int TeamsHigh::GetTotalScore() const
	{
		int score=0;
		for(int j=0; j < MAX_PROB_SIZE; j++)
			score += Probs[j].Score;

		return score;
	}