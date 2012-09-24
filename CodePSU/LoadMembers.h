//LoadTeams.h - loads team members from text files into a vector of TeamsHigh and TeamsLow objects
//Written by Christina Black

#include <iostream>
#include <fstream>
#include <vector>
#include "TeamsHigh.h"
#include "TeamsLow.h"

void LoadHighMembers()
{
	int j=0;
	string teamName;
	ifstream in("highmembs.txt");
	while (j < (int)TeamsHigh::high.size())
	{
		getline(in, teamName);
		TeamsHigh::high[j].AddMembers(teamName);
		j++;
	}

	in.close();
}

void LoadLowMembers()
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