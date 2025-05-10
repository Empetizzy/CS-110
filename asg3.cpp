/*****************************
* Student Name: Dairo Emmanuel
* 
* Student Number: 200503652
* 
* Assignmet number: 3
* 
* Program name: asg3.cpp
* 
* 
* 
* Problem Statement: Code uses logic of craps to determine win or loss of player
* 
* Major Variables: first roll: first roll of dice  gotten from void function
* Secondroll: Second roll of dice gotten from void function
* rollsum: Sum of roll
* newsumroll: new sum of roll gotten from loop in case a point is established
* loopstate :loop statement declared in other to use flag loop
* 
* Major Function:
* Getroll which uses rand() to generate random number for dice roll
* Calcsum to generate sum of first and second dice roll
* Printroll ro print first and second dice roll and their sum to the user
* 
* Main Algorithim:  Decalare functions
* Declare variables
* use Srand() to generate new value with time(everytime it is called)
* Call functions in other to get data and use in main function and also to print values
* If statement to check if initial sum is a win , lose or an establised point
* flag loop to get new sum till either 7(loss) is gotten or when point(initial sum) is equal to new sum which means a win while 
* also printing out result using print roll 
* Used flag loop instead of sentinel loop due to presence of two sentinel value 7 and intial sum
* 
**************/
#include <iostream> // For Input and output stream
#include <time.h> // Decalred time library in other to use srand and generate different roll with time

using namespace std; // To look for compiler in the std space

void GetRoll(int&); // Decalred void statement while passing by refernce to get number of dice
int CalcSum(int, int); // Declared a value return statement to return value of sum
void Printroll(int, int, int); // Decalred void statement to print ths numbers and their sum

int main() {
	srand(time(NULL)); // Used seed to modify output to prevent roll of dice from being the same value or repeated
	
	int firstroll; // Decalred data type for first roll of dice
	int secondroll; // Decalred data type for second roll of dice
	int rollsum; // Decalred sum to store summation of first and second roll
	bool loopstate = true; // Decalred and set to true the boolean statment for flag loop
	int newrollsum; // Decalred data type for newsum to be used in the loop
	

	GetRoll(firstroll); // Initial void function call to get first roll
	GetRoll(secondroll);// Second void function call to get second roll
	rollsum = CalcSum(firstroll, secondroll); // Value returning function to return sum
	Printroll(firstroll, secondroll, rollsum); // To print numbers and their sum

	if (rollsum == 2 || rollsum == 3 || rollsum == 12) // To print out loss if initial sum value is 2 or 3 or 13
	{
		cout << "You lose";
	}
	else if (rollsum == 7 || rollsum == 11) // To print out win if initial sum value is 7 or 11
	{
		cout << "You win";
	}
	else {

		cout << "Point is " << rollsum << endl; // To print out established point which becomes initial sum for loop

        while (loopstate)  // used flag loop instead of sentinel loop due to prsence of two sentinel value which are 7 and initial sum 
		{
			// Called function again to generate new roll and sum them till either if statement are true
			GetRoll(firstroll); 
			GetRoll(secondroll);
			newrollsum = CalcSum(firstroll, secondroll);
			Printroll(firstroll, secondroll, newrollsum);

			if (newrollsum == 7) // First sentinel value which prints lose when sum of 7 is acquired
			{
				cout << "You lose";
				loopstate = false; // To exit the loop by declaring boolean statement false
			}
			else if (newrollsum == rollsum) // Second sentinel value which prints win when initial sum from begining is equal to the newest sum generated in the loop
			{
				cout << "You win";
				loopstate = false; // To exit the loop by declaring boolean statement false

			}

		}
	}

	
	

	return 0;
}
void GetRoll(int& a) // Void and pass by refrence to generate the random value for roll
{
	
	a = rand() % 6 + 1; // Added + 1 to generate values only ranging from 1 to 6 without including zero

}

int CalcSum(int c, int d) // Value returning function to return value for  sum of numbers from rolls when called
{
	int sum; // Decalred data type for sum
	sum = c + d; // Declared formula to get sum
	return sum; // Return statement to return sum
}
void Printroll(int e, int f, int g) // Used void function to print rolls and their sum
{
	cout << "Your rolled " << e << " + " << f << " = " << g << endl; 
}