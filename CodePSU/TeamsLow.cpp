//TeamsLow.h - Declarations of methods and variables in the TeamsHigh class
//Written by Christina Black

#include <iostream>
#include <string>
#include <fstream>
#include "TeamsLow.h"

#define DEFAULT 0
#define NAME "NAME"
#define MAX_PROB_SIZE 10
using namespace std;

TeamsLow::TeamsLow()
{
	TeamName = NAME;
	Number = DEFAULT;
}

TeamsLow::TeamsLow(const string& name, int number)
{
	TeamName = name;
	Number = number;
}

string TeamsLow::GetTeamName() const
{
	return TeamName;
}

void TeamsLow::AddMembers(const string& names)
{
	Members = names;
}

int TeamsLow::GetTeamNumber() const
{
	return Number;
}

int TeamsLow::GetTotalScore()const
{
	int score=0;
	for(int j=0; j < MAX_PROB_SIZE; j++)
		score += Probs[j].Score;

	return score;
}

int TeamsLow::GetSingleScore(int problem)
{
	return (Probs[problem].Score);
}

void TeamsLow::LoadLow()
{
	int i=1;
	string teamName;
	ifstream in("low.txt");
	while ( !in.eof() )
	{
		getline(in, teamName);
		low.push_back(TeamsLow(teamName, i));
		i++;
	}

	in.close();
}

void TeamsLow::LoadLowMembers()
{
	int j=0;
	string teamName;
	ifstream in("lowmembs.txt");
	while (j < (int)TeamsLow::low.size())
	{
		getline(in, teamName);
		TeamsLow::low[j].AddMembers(teamName);
		j++;
	}

	in.close();
}

//Tells whether or not the given object has been initialized
bool TeamsLow::IsEmpty()
{
	return(TeamName == NAME);
}