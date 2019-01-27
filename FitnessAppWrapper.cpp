#include "FitnessAppWrapper.h"
#include "DietPlan.h"
#include "ExercisePlan.h"


FitnessAppWrapper::FitnessAppWrapper(DietPlan diet[7], ExercisePlan exercise[7])
{
	copyArray(this->mDiet, diet);
	copyArray(this->mExercise, exercise);
	cout << "Inside FitnessAppWrapper constructor." << endl;
}	

FitnessAppWrapper::~FitnessAppWrapper()
{
	// not necessarily doing anything, just signifying that we have entered the destructor
	cout << "Inside FitnessAppWrapper destructor. " << endl;
}

void FitnessAppWrapper::displayMenu()
{
	int option;

	do {

		do {
			// clear the screen
			system("cls");

			// print out the menu of options
			cout << "1. Load weekly diet plan from file." << endl;
			cout << "2. Load weekly exercise plan from file." << endl;
			cout << "3. Store weekly diet plan to file." << endl;
			cout << "4. Store weekly exercise plan to file." << endl;
			cout << "5. Display weekly diet plan to screen." << endl;
			cout << "6. Display weekly exercise plan to screen." << endl;
			cout << "7. Edit daily diet plan." << endl;
			cout << "8. Edit daily exercise plan." << endl;
			cout << "9. Exit." << endl;
			cout << "\nSelection: ";
			// prompt the user for the option of choice and stores it
			cin >> option;

		} while (option < 1 || option > 9); // validates entry

		if (option != 9)
		{
			// load weekly diet plan
			if (option == 1)
			{
				// open our file for read-in
				fstream input("dietPlans.txt");

				if (input.is_open())
				{
					this->loadWeeklyPlan(input, this->mDiet);
					system("cls");
					cout << "Diet plan read in successfully" << endl;
				}
				else {
					cout << "Error in reading in file" << endl;
				}
				input.close();

				system("pause");
			}
			// load weekly exercise plan
			else if (option == 2)
			{
				// open our file for read-in
				fstream input("exercisePlans.txt");
				if (input.is_open())
				{
					this->loadWeeklyPlan(input, this->mExercise);
					system("cls");
					cout << "Exercise plan read in successfully" << endl;
				}
				else {
					cout << "Error in reading in file" << endl;
				}
				input.close();

				system("pause");
			}
			// store weekly diet plan
			else if (option == 3)
			{
				fstream output("newDietPlans.txt");

				system("cls");

				if (output.is_open())
				{
					this->storeWeeklyPlan(output, this->mDiet);

					cout << "Diet plan written successfully" << endl;
				}
				else {
					cout << "Error in writing to file" << endl;
				}
				output.close();

				system("pause");
			}
			// store weekly exercise plan
			else if (option == 4)
			{
				fstream output("newExercisePlans.txt");

				system("cls");

				if (output.is_open())
				{
					this->storeWeeklyPlan(output, this->mExercise);

					cout << "Exercise plan written successfully" << endl;
				}
				else {
					cout << "Error in writing to file" << endl;
				}
				output.close();

				system("pause");
			}

			// display weekly diet plan
			else if (option == 5)
			{
				system("cls");
				
				this->displayWeeklyPlan(this->mDiet);

				system("pause");
			}

			// display weekly exercise plan
			else if (option == 6)
			{
				system("cls");
				
				this->displayWeeklyPlan(this->mExercise);

				system("pause");
			}

			// edit daily diet plan
			else if (option == 7)
			{
				this->editDailyPlan(this->mDiet);

				system("pause");
			}

			// edit daily exercise plan
			else if (option == 8)
			{
				this->editDailyPlan(this->mExercise);

				system("pause");
			}

		}
	} while (option != 9);

	fstream outputD("dietPlans.txt");
	fstream outputE("exercisePlans.txt");

	this->storeWeeklyPlan(outputD, this->mDiet);
	this->storeWeeklyPlan(outputE, this->mExercise);

	outputD.close();
	outputE.close();
}


void FitnessAppWrapper::runApp()
{
	displayMenu();
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, DietPlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		fileStream >> plan[i];
	}
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, ExercisePlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		fileStream >> plan[i];
	}
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, DietPlan &plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, DietPlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		fileStream << plan[i];
	}
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, ExercisePlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		fileStream << plan[i];
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan plan) const
{
	cout << "Diet Plan Name: " << plan.getName() << "\nGoal: " << plan.getGoalCalories() << "\nDate: " << plan.getDate() << "\n\n";
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan plan) const
{
	cout << "Exercise Plan Name: " << plan.getName() << "\nGoal: " << plan.getGoalSteps() << "\nDate: " << plan.getDate() << "\n\n";
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan plan[]) const
{
	for (int i = 0; i < 7; i++)
	{
		cout << "Diet Plan Name: " << plan[i].getName() << "\nGoal: " << plan[i].getGoalCalories() << "\nDate: " << plan[i].getDate() << "\n\n";
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan plan[]) const
{
	for (int i = 0; i < 7; i++)
	{
		cout << "Exercise Plan Name: " << plan[i].getName() << "\nGoal: " << plan[i].getGoalSteps() << "\nDate: " << plan[i].getDate() << "\n\n";
	}
}

void FitnessAppWrapper::editDailyPlan(DietPlan plan[])
{
	string date;
	int position;
	
	system("cls");
	cout << "Enter the date for the plan you would like to edit (mm/dd/yyyy): ";
	cin >> date;

	position = searchPlanForDate(plan, date);

	if (position == -1)
	{
		cout << "\n\nDate not found in plan.\n";
	}
	else
	{
		int option;

		do
		{
			system("cls");
			cout << "Choose an entry to edit:\n1) Name\n2) Goal Calories\n\nSelection: ";
			cin >> option;

		} while (option != 1 && option != 2);

		if (option == 1)
		{
			string newName;

			system("cls");
			cout << "Enter a new name for the plan: ";
			cin.ignore();
			std::getline(cin, newName);

			plan[position].setName(newName);
			
			if (plan[position].getDate() == newName) cout << "\nEdit Successful.\n";
		}

		else if (option == 2)
		{
			int newCals;

			do
			{
				system("cls");
				cout << "Enter a new calorie goal: ";
				cin >> newCals;
			} while (newCals <= 0);

			plan[position].setGoalCalories(newCals);

			if (plan[position].getGoalCalories() == newCals) cout << "\nEdit Successful.\n";
		}
	}
}

void FitnessAppWrapper::editDailyPlan(ExercisePlan plan[])
{
	string date;
	int position;

	system("cls");
	cout << "Enter the date for the plan you would like to edit (mm/dd/yyyy): ";
	cin >> date;

	position = searchPlanForDate(plan, date);

	if (position == -1)
	{
		cout << "\n\nDate not found in plan.\n";
	}
	else
	{
		int option;

		do
		{
			system("cls");
			cout << "Choose an entry to edit:\n1) Name\n2) Goal Steps\n\nSelection: ";
			cin >> option;

		} while (option != 1 && option != 2);

		if (option == 1)
		{
			string newName;

			system("cls");
			cout << "Enter a new name for the plan: ";
			cin.ignore();
			std::getline(cin, newName);

			plan[position].setName(newName);

			if (plan[position].getDate() == newName) cout << "\nEdit Successful.\n";
		}

		else if (option == 2)
		{
			int newSteps;

			do
			{
				system("cls");
				cout << "Enter a new calorie goal: ";
				cin >> newSteps;
			} while (newSteps <= 0);

			plan[position].setGoalSteps(newSteps);

			if (plan[position].getGoalSteps() == newSteps) cout << "\nEdit Successful.\n";
		}
	}

}

int FitnessAppWrapper::searchPlanForDate(DietPlan plan[], string date)
{
	int index = -1;

	for (int i = 0; i < 7; i++)
	{
		if (plan[i].getDate() == date)
		{
			index = i;
			break;
		}
	}

	return index;
}

int FitnessAppWrapper::searchPlanForDate(ExercisePlan plan[], string date)
{
	int index = -1;

	for (int i = 0; i < 7; i++)
	{
		if (plan[i].getDate() == date)
		{
			index = i;
			break;
		}
	}

	return index;
}


void copyArray(DietPlan destination[], DietPlan source[])
{
	int destSize = sizeof(destination) / sizeof(destination[0]);
	for (int i = 0; i < destSize; i++)
	{
		destination[i] = source[i];
	}
}

void copyArray(ExercisePlan destination[], ExercisePlan source[])
{
	int destSize = sizeof(destination) / sizeof(destination[0]);
	for (int i = 0; i < destSize; i++)
	{
		destination[i] = source[i];
	}
}


