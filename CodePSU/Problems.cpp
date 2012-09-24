//Problems.cpp - implementation of methods and variables of Problems.h
//Written by Christina Black
#include <iostream>
#include <string>
#include "Problems.h"

using namespace std;

//Default constructor
Problems::Problems()
{
	Score = 0;
	Error = 0;
}

//Sets problem score
void Problems::SetProblemScore(int score)
{
	Score = score;
}

//Sets the problem outcome (incorrect output, runtime error, runs over time, etc)
void Problems::ProbOutcome(int error)
{
	Error = error;
}
