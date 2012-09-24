//TeamsHigh.h - Declarations of methods and variables in the TeamsHigh class
//Written by Christina Black

#include<iostream>
#include<string>
#include <fstream>
#include "TeamsLow.h"
#define MAX_PROB_SIZE 10
#define NAME "NAME"
#define DEFAULT 0
#pragma once

using namespace std;

class TeamsHigh : public TeamsLow
{
public:
	//vector of TeamsHigh that contains all high teams
	vector<TeamsHigh>high;

	//Default Constructor
	TeamsHigh();

	//Init constructor
	TeamsHigh(string& name, int number);

	//Loads high teams into vector
	void LoadHigh(int i);

	//Loads high members into vector
	void LoadHighMembers(int i);

	//Gets total score of high vector
	int GetTotalScore() const;
};