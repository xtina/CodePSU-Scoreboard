//LoadTeams.h - loads teams from text files into a vector of TeamsHigh and TeamsLow objects
//Written by Christina Black

#include <iostream>
#include <fstream>
#include <vector>
#include "TeamsHigh.h"
#include "TeamsLow.h"

int i=1;

void LoadLow()
{
	string teamName;
	ifstream in("low.txt");
	while ( !in.eof() )
	{
		getline(in, teamName);
		TeamsLow::low.push_back(TeamsLow(teamName, i));
		i++;
	}

	in.close();
}

void LoadHigh()
{
	string teamName;
	ifstream in("high.txt");
	while ( !in.eof() )
	{
		getline(in, teamName);
		TeamsHigh::high.push_back(TeamsHigh(teamName, i));
		i++;
	}

	in.close();
}