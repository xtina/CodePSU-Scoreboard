//TeamsLow.h - Declarations of methods and variables in the TeamsHigh class
//Written by Christina Black

#pragma once
#include<iostream>
#include<string>
#include "Problems.h"

#define NUM_OF_PROBS 10

using namespace std;

class TeamsLow
{
public:
	//Public static vector of low team members
	vector<TeamsLow>low;
	//Default constructor
	TeamsLow();
	//Init constructor
	TeamsLow(const string& name, int number);
	//Adds members to low vector
	void AddMembers(const string& names);
	//Public getter - gets team name
	string GetTeamName() const;
	//Public getter - gets team number
	int GetTeamNumber() const;
	//Gets team's total score
	int GetTotalScore() const;
	//Tells whether or not the given object has been initialized
	bool IsEmpty();
	//Problems and their outcomes
	Problems Probs[NUM_OF_PROBS];
	//Loads low teams into low vector
	void LoadLow();
	//Loads low members into low vector
	void LoadLowMembers();
	//Public getter - gets a score of a problem
	int GetSingleScore(int problem);

protected:
	//List of members in each team
	string Members;
	//Team name
	string TeamName;
	//Team number
	int Number;
};