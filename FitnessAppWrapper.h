#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "DietPlan.h"
#include "ExercisePlan.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

class FitnessAppWrapper {

public:
	// constructor
	FitnessAppWrapper(DietPlan diet[7] = { NULL }, ExercisePlan exercise[7] = { NULL });
	
	// destructor
	~FitnessAppWrapper();

	void displayMenu();
	
	void runApp();

	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);

	void loadWeeklyPlan(fstream &fileStream, DietPlan plan[]);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan plan[]);

	void storeDailyPlan(fstream &fileStream, DietPlan &plan);
	void storeDailyPlan(fstream &fileStream, ExercisePlan &plan);

	void storeWeeklyPlan(fstream &fileStream, DietPlan plan[]);
	void storeWeeklyPlan(fstream &fileStream, ExercisePlan plan[]);

	void displayDailyPlan(DietPlan plan) const;
	void displayDailyPlan(ExercisePlan plan) const;

	void displayWeeklyPlan(DietPlan plan[]) const;
	void displayWeeklyPlan(ExercisePlan plan[]) const;

	void editDailyPlan(DietPlan plan[]);
	void editDailyPlan(ExercisePlan plan[]);

	int searchPlanForDate(DietPlan plan[], string date); // both to be used in edit function
	int searchPlanForDate(ExercisePlan plan[], string date);

private:
	DietPlan mDiet[7];
	ExercisePlan mExercise[7];
};

void copyArray(DietPlan destination[], DietPlan source[]);
void copyArray(ExercisePlan destination[], ExercisePlan source[]);