#include "DietPlan.h"
#include "ExercisePlan.h"
#include "FitnessAppWrapper.h"

int countExercise = 0, countDiet = 0;

int main(int argc, char* argv[])
{
	// creating a new object of FitnessAppWrapper
	FitnessAppWrapper currentApplication;

	// run the application
	currentApplication.runApp();

	return 0;
}