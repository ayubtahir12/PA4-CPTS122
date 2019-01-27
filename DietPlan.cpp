#include "DietPlan.h"

DietPlan::DietPlan(unsigned int newGoalCalories, string newName, string newDate)
{
	// set values of member variables to inputted values
	this->mGoalCalories = newGoalCalories;
	this->mName = newName;
	this->mDate = newDate;
	cout << "Inside DietPlan constructor." << endl;
}

DietPlan::~DietPlan()
{
	// not necessarily doing anything
}

bool DietPlan::setGoalCalories(int goal)
{
	bool success = false;

	goal = (unsigned int)goal;
	// sets the calorie goal
	this->mGoalCalories = goal;
	if (this->mGoalCalories == goal) success = true;

	return success;
}

bool DietPlan::setName(string name)
{
	bool success = false;

	this->mName = name;
	if (this->mName == name) success = true;

	return success;
}

bool DietPlan::setDate(string date)
{
	bool success = false;

	this->mDate = date;
	if (this->mDate == date) success = true;

	return success;
}


int DietPlan::getGoalCalories()
{
	return this->mGoalCalories;
}

string DietPlan::getName()
{
	return this->mName;
}

string DietPlan::getDate()
{
	return this->mDate;
}

//bool DietPlan::findDate(string date)
//{
//
//}
//
//
//void DietPlan::editGoal()
//{
//	string str;
//
//	system("cls");
//	cout << "Enter a date to edit (mm/dd/yyyy): ";
//	cin >> str;
//
//
//}

fstream & operator >> (fstream &lhs, DietPlan &rhs)
{
	string planName = "";
	int goalCalories = 0;
	string date = "";
	string blah = "";

	// name
	std::getline(lhs, planName);

	// calories
	lhs >> goalCalories;
	
	// date
	lhs >> date;

	//ignore the newline character after the date
	lhs.ignore(1024, '\n');

	//get the blank line
	std::getline(lhs, blah);

	rhs.setGoalCalories(goalCalories);
	rhs.setDate(date);
	rhs.setName(planName);

	//return the stream
	return lhs;
}

fstream & operator << (fstream &lhs, DietPlan &rhs)
{
	lhs << rhs.getName() << '\n' << rhs.getGoalCalories() << '\n' << rhs.getDate() << "\n\n";

	return lhs;
}