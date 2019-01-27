#include "ExercisePlan.h"

ExercisePlan::ExercisePlan(unsigned int goalSteps, string name, string date)
{
	this->mGoalSteps = goalSteps;
	this->mName = name;
	this->mDate = date;
	cout << "Inside ExercisePlan constructor." << endl;

}

ExercisePlan::~ExercisePlan()
{
	// not necessarily doing anything
	
}

bool ExercisePlan::setGoalSteps(int goal)
{
	bool success = false;
	
	goal = (unsigned int)goal;
	this->mGoalSteps = goal;

	if (this->mGoalSteps == goal) success = true;

	return success;
}

bool ExercisePlan::setName(string name)
{
	bool success = false;

	this->mName = name;
	if (this->mName == name) success = true;

	return success;
}

bool ExercisePlan::setDate(string date)
{
	bool success = false;

	this->mDate = date;
	if (this->mDate == date) success = true;

	return success;
}


int ExercisePlan::getGoalSteps()
{
	return this->mGoalSteps;
}

string ExercisePlan::getName()
{
	return this->mName;
}

string ExercisePlan::getDate()
{
	return this->mDate;
}

fstream & operator >> (fstream &lhs, ExercisePlan &rhs)
{
	string planName = "";
	int goalSteps = 0;
	string date = "";
	string blah = "";


	std::getline(lhs, planName);

	//Goal Calories
	lhs >> goalSteps;

	//Date
	lhs >> date;

	//ignore the newline character after the date
	lhs.ignore(1024, '\n');

	//get the blank line
	std::getline(lhs, blah);

	rhs.setGoalSteps(goalSteps);
	rhs.setDate(date);
	rhs.setName(planName);

	//return the stream
	return lhs;
}

fstream & operator << (fstream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getName() << '\n' << rhs.getGoalSteps() << '\n' << rhs.getDate() << "\n\n";

	return lhs;
}
