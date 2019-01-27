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

class DietPlan {

public:
	// constructor
	DietPlan(unsigned int goalCalories = 0, string name = "", string date = "");
	// destructor
	~DietPlan();

	// setters
	bool setGoalCalories(int goal);
	bool setName(string name);
	bool setDate(string date);

	// getters
	int getGoalCalories();
	string getName();
	string getDate();

	// search functions
	//bool findDate(string date);

	// edit goal
	//void editGoal();

private:
	unsigned int mGoalCalories;
	string mName;
	string mDate;
};

fstream & operator >> (fstream &lhs, DietPlan &rhs);

fstream & operator << (fstream &lhs, DietPlan &rhs);