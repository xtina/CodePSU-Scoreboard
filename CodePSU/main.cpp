//Problems.cpp - implementation of methods and variables of Problems.h
//Written by Christina Black
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Problems.h"
#include "TeamsHigh.h"
#include "TeamsLow.h"

#define LOW_PROB ONE
#define HIGH_PROB 6
#define FIRST 0
#define WIDTH 20
#define EXIT 123
#define MIN_VALUE 1
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4

using namespace std;

void main()
{

	//Loads teams into their high and low vectors
	TeamsLow low;
	TeamsHigh high;
	low.LoadLow();
	low.LoadLowMembers();
	high.LoadHigh(low.low.size());
	high.LoadHighMembers(low.low.size());

	//These vectors are used to determine first/second/third place
	vector<TeamsHigh> highFirst, highSecond, highThird;
	vector<TeamsLow> lowFirst, lowSecond, lowThird;


	bool go=true, go2 = true;
	int prob, error, score, team, answer;
	char ans;
	while(go)
	{
		cout << "What do you want to do? 1. Enter scores; 2. Display scoreboard; 3. Find 1st/2nd/3rd winners; 4. Find individual team scores; 5. Find individual problem scores: " ;
		cin >> answer;
		//Enter scores
		if(answer == ONE)
		{
			while(go2)
			{
				cout << "Team #? (Input 123 to exit) ";
				cin >> team;
				if(team == EXIT)
				{
					cout << "Are you sure you want to exit? (Y/N) ";
					cin >> ans;
					if(ans == 'Y' || ans == 'y')
					{
						break;
					}
				}

				if(team > high.high.size() + low.low.size() || team < MIN_VALUE)
				{
					cout << "You have entered an incorrect team number. Please try again." << endl;
					break;
				}

				cout << "Problem #? " ;
				cin >> prob;
				cout << "Error? 1. Incorrect output; 2. Exceeded time; 3. Wouldn't compile; 4. No error: " ;
				cin >> error;
				if(error == FOUR)
				{
					score = HIGH_PROB;
					if(prob > 5)
					{
						if(team > (int)low.low.size())
						{
							high.high[team-low.low.size()].Probs[prob-ONE].SetProblemScore(score);
							high.high[team-low.low.size()].Probs[prob-ONE].ProbOutcome(error);
						}
						else
						{
							low.low[team-ONE].Probs[prob-ONE].SetProblemScore(score);
							low.low[team-ONE].Probs[prob-ONE].ProbOutcome(error);
						}
					}
					else
					{
						score = LOW_PROB;
						if(team > (int)low.low.size())
						{
							high.high[team-low.low.size()].Probs[prob-ONE].SetProblemScore(score);
							high.high[team-low.low.size()].Probs[prob-ONE].ProbOutcome(error);
						}
						else
						{
							low.low[team-ONE].Probs[prob-ONE].SetProblemScore(score);
							low.low[team-ONE].Probs[prob-ONE].ProbOutcome(error);
						}
					}
				}

				else
				{
					if(team > (int)low.low.size())
					{
						high.high[team-ONE-low.low.size()].Probs[prob-ONE].SetProblemScore(score);
						high.high[team-ONE-low.low.size()].Probs[prob-ONE].ProbOutcome(error);
					}
					else
					{
						low.low[team-ONE].Probs[prob-ONE].SetProblemScore(score);
						low.low[team-ONE].Probs[prob-ONE].ProbOutcome(error);
					}
				}
			}
		}

		//Display scoreboard
		else if(answer == TWO)
		{
			int size;
			if(low.low.size() > high.high.size())
				size = low.low.size();
			else
				size = high.high.size();
			cout << setw(WIDTH) << "Low Teams" << setw(WIDTH) << "High Teams" << endl;
			for(int i=0; i < (int)size; i++)
			{
				if(i < (int)low.low.size() && !low.low[i].IsEmpty())
					cout << setw(WIDTH) << low.low[i].GetTeamName() << " " << low.low[i].GetTotalScore();
				if(i < (int)high.high.size() && !high.high[i].IsEmpty() && i < (int)low.low.size())
					cout << setw(WIDTH) << high.high[i].GetTeamName() << " " << high.high[i].GetTotalScore() << endl;
				else
					cout << right <<  setw(TWO*WIDTH+TWO) << high.high[i].GetTeamName() << " " << high.high[i].GetTotalScore() << endl;
			}
			cout << endl;
		}

		//Finds first/second/third place winners for high and low tiers
		else if (answer == THREE)
		{
			int first, second, third;
			first = second = third = 0;
			int temp;
			for(int i=0; i < (int)low.low.size(); i++)
			{
				temp = low.low[i].GetTotalScore();

				if(temp > first)
					lowFirst.push_back(low.low[i]);

				if(temp > second && temp < first)
					lowSecond.push_back(low.low[i]);

				if(temp > third && temp < second)
					lowThird.push_back(low.low[i]);
			}


			int greatest=0;
			cout << "First Place Intermediate: " << endl;
			for(int i=0; i < lowFirst.size(); i++)
			{
				if(lowFirst[i].GetTotalScore() > greatest)
					greatest = lowFirst[i].GetTotalScore();
			}

			for(int i=0; i < lowFirst.size(); i++)
			{
				if(lowFirst[i].GetTotalScore() == greatest)
					cout << setw(WIDTH) << lowFirst[i].GetTeamName() << " " << lowFirst[i].GetTotalScore()<< endl;
			}

			cout << endl << "Second Place Intermediate: " << endl;
			for(int i=0; i <lowSecond.size(); i++)
			{
				if(lowFirst[i].GetTotalScore() > greatest)
					greatest = lowFirst[i].GetTotalScore();
			}
			for(int i=0; i < lowSecond.size(); i++)
			{
				if(lowFirst[i].GetTotalScore() == greatest)
					cout << setw(WIDTH) << lowSecond[i].GetTeamName() << " " << lowSecond[i].GetTotalScore()<< endl;
			}

			cout << endl << "Third Place Intermediate: " << endl;
			for(int i=0; i < lowThird.size(); i++)
			{

				if(lowFirst[i].GetTotalScore() > greatest)
					greatest = lowFirst[i].GetTotalScore();
			}
			for(int i=0; i < lowThird.size(); i++)
			{
				if(lowFirst[i].GetTotalScore() == greatest)
					cout << setw(WIDTH) << lowThird[i].GetTeamName() << " " << lowThird[i].GetTotalScore()<< endl;
			}

			first = second = third = 0;
			for(int i=0; i < high.high.size(); i++)
			{
				temp = high.high[i].GetTotalScore();

				if(temp > first)
				{
					highFirst.push_back(high.high[i]);
				}

				if(temp > second && temp < first)
				{
					highSecond.push_back(high.high[i]);
				}

				if(temp > third && temp < second)
				{
					highThird.push_back(high.high[i]);
				}
			}

			cout << "First Place Advanced: " << endl;
			for(int i=0; i < highFirst.size(); i++)
			{
				if(highFirst[i].GetTotalScore() > greatest)
					greatest = highFirst[i].GetTotalScore();
			}

			for(int i=0; i < highFirst.size(); i++)
			{
				if(highFirst[i].GetTotalScore() == greatest)
					cout << setw(WIDTH) << highFirst[i].GetTeamName() << " " << highFirst[i].GetTotalScore() << endl;
			}

			cout << endl << "Second Place Advanced: " << endl;
			for(int i=0; i < highSecond.size(); i++)
			{
				if(highSecond[i].GetTotalScore() > greatest)
					greatest = highSecond[i].GetTotalScore();
			}

			for(int i=0; i < highSecond.size(); i++)
			{
				if(highSecond[i].GetTotalScore() == greatest)
					cout << setw(WIDTH) << highSecond[i].GetTeamName() << " " << highSecond[i].GetTotalScore()<< endl;
			}

			cout << endl << "Third Place Advanced: " << endl;
			for(int i=0; i < highThird.size(); i++)
			{
				if(highThird[i].GetTotalScore() > greatest)
					greatest = highThird[i].GetTotalScore();
			}

			for(int i=0; i < highThird.size(); i++)
			{
				if(highThird[i].GetTotalScore() == greatest)
					cout << setw(WIDTH) << highThird[i].GetTeamName() << " " << highThird[i].GetTotalScore()<< endl;
			}
			cout << endl;
		}

		//Finds total score of one team
		else if(answer == FOUR)
		{
			int team;
			while(true)
			{
				cout << "Team #? : " ;
				cin >> team;
				if(team > high.high.size() + low.low.size() || team < ONE)
				{
					cout << "You have entered an incorrect team number. You can choose between 1 and " << high.high.size() + low.low.size() << ". Please try again. " << endl;
				}

				else
				{
					if(team <= low.low.size())
						cout << "Team " << team << "'s score is " << low.low[team].GetTotalScore() << endl;
					else
						cout << "Team " << team << "'s score is " << high.high[team].GetTotalScore() << endl;
					break;

				}
			}
		}

		//Finds single problem score and error of a team
		else
		{
			int team, problem;
			while(true)
			{
				cout << "Team #? " ;
				cin >> team;
				cout << "Problem #? ";
				cin >> problem;

				if(team > high.high.size() + low.low.size() || team < ONE)
				{
					cout << "You have entered an incorrect team number. You must choose between 1 and " << high.high.size() + low.low.size() << ". Please try again. " << endl;
				}

				if(problem > MAX_PROB_SIZE || problem < ONE)
				{
					cout << "You have entered an incorrect problem number. You must choose between 1 and " << MAX_PROB_SIZE << ". Please try again." << endl;
				}
				else
				{
					if(team <= low.low.size())
					{
						cout << "Team " << team << "'s score of problem " << problem << " is " << low.low[team-ONE].GetSingleScore(problem-ONE) << " with error ";
						if(low.low[team-ONE].Probs[problem-ONE].Error == ONE)
							cout << "incorrect output. " << endl;
						if(low.low[team-ONE].Probs[problem-ONE].Error == TWO)
							cout << "exceeded time." << endl;
						if(low.low[team-ONE].Probs[problem-ONE].Error == THREE)
							cout << "wouldn't compile" << endl;
						if(low.low[team-ONE].Probs[problem-ONE].Error == FOUR)
							cout << "no error" << endl;
						else
							cout << "team did not answer problem." << endl;
					}
					else
					{
						cout << "Team " << team << "'s score of problem " << problem << " is " << high.high[(team-low.low.size())].GetSingleScore(problem-ONE) << " with error ";
						if(high.high[team-low.low.size()].Probs[problem-ONE].Error == ONE)
							cout << "incorrect output. " << endl;
						if(high.high[team-low.low.size()].Probs[problem-ONE].Error == TWO)
							cout << "exceeded time." << endl;
						if(high.high[team-low.low.size()].Probs[problem-ONE].Error == THREE)
							cout << "wouldn't compile" << endl;
						if(high.high[team-low.low.size()].Probs[problem-ONE].Error == FOUR)
							cout << "no error" << endl;
						else
							cout << "team did not answer problem." << endl;
					}
					cout << endl;
					break;
				}
			}
		}
	}

	system("pause");
}