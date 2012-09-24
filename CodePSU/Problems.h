//Problems.h - Members and methods of the Problems class
//Written by Christina Black

#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

struct Problems
{
	//Default constructor
	Problems();
	//Sets problem score
	void SetProblemScore(int score);
	//Sets problem number
	void SetProb(int problemNum);
	//Sets the problem outcome (incorrect output, runtime error, runs over time, etc)
	void ProbOutcome(int error);

	int Score;
	int Error;
};