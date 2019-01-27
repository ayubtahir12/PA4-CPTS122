#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

class ExercisePlan {
public:
	// constructor
	ExercisePlan(unsigned int goalSteps = 0, string name = "", string date = "");
	// destructor
	~ExercisePlan();

	// setters
	bool setGoalSteps(int goal);
	bool setName(string name);
	bool setDate(string date);


	// getters
	int getGoalSteps();
	string getName();
	string getDate();

private:
	unsigned int mGoalSteps;
	string mName;
	string mDate;
};

fstream & operator >> (fstream &lhs, ExercisePlan &rhs);

fstream & operator << (fstream &lhs, ExercisePlan &rhs);