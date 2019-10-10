/*
	Daniel Dooley
	C++ 1st Semester 2019
	Due: Due Date 10/10/19
	Lab number 4
	Description: Design and write a C++ program that inputs a series of hourly temperature
	from a file, and outputs a bar chart (using stars) of the temperatures for the day. The
	temperature should be printed to the left of the corresponding bar, and there should be
	a heading that gives the scale of the chart. The range of temperatures should be from
	-30 to 120. Because it is hard to display 150 characters on the screen, you should have
	each star represent a range of 3 degrees. That way, the bars will be at most 50
	characters wide. Use meaningful variable names, proper indentation, and appropriate
	comments. Thoroughly test the program using your own data sets. Make sure to vet the
	values from the input file.
*/
//Libraries necessary for program to run
#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
//standard namespace is used for cout/ifstream/etc
using namespace std;
//Function prototypes
void scale(); // displays the "-30 to 120" degree scale
int input(); //inputs the numbers from file. calculates values and outputs to "display()"
int display(int playerNum); //prints out stars as per the temperature requires to the screen
bool invalidInput(bool fail); //function that outputs a failed state has occured and closes

int main() { //entry point main function calls other functions when if input == 1 it closes

	scale();//function call
	if (input() == 1)//function call. if value evaluated is 1 closes with code 1
		return 1;
	cout << "Program complete.";
	return 0;
}

void scale() { // displays the "-30 to 120" degree scale
	cout << "	-30       0         30        60        90      120" << endl;
}

int input() { //reads the numbers from file. Calculates values and outputs to "display()" has several failure conditions
	//bool trueTest = true;
	float playerNum; //Creates variable to store file inputted values
	ifstream inFile; //Creates file stream
	inFile.open("C:/Users/Doubl/source/repos/TemperatureOutput/TemperatureOutput/input.dat"); //Opens file by file path defined
	if (!inFile) {//If no file is found closes program with message
		cout << "cannot find file!";
		return 1;
	}
	inFile >> playerNum; //Primes file with first value.
	while (inFile) {
		if (playerNum > 120 || playerNum < -30) { // if the number is above or below max and min values it skips that number and tells the user
			cout << "The number " << playerNum << " is invalid!" << endl;
			inFile >> playerNum;
		}
		else {
			cout << setprecision(5) << playerNum; //limits max numbers in a decimal
			playerNum = round(playerNum);//rounds each number to the closest whole number
			display(playerNum); // function call to display with resultant number from THIS function
			cout << endl;
			inFile >> playerNum; //cycles through the list of numbers until EOF
		}
	}
	if (!playerNum) { //if the number becomes invalid program stops with function call to display this info
		invalidInput(true);
		return 1;
	}

	inFile.close();// closes file stream
	return 0;
}

int display(int playerNum) {//Function in charge of displaying information to screen and calculating stars to display
	float numInput = playerNum;//assigns local variable to variable inputted by input()
	string stars; // creates a blank string
	if (numInput < 0) { // if the number is <0 
		numInput = round(numInput / -3);//divides by -3, to calculate how many stars should be displayed, in a positive value
		while (numInput > 0) { //as long as the number of stars is yet to reach 0 
			numInput--; // subtracts 1 from the number of stars that need to be suffixed on to the string
			stars = stars + "*"; // suffexes * to the end of the stars string
		}
		stars.resize(10);// changes the length of "stars" to 10 regardless of # of stars		
		reverse(stars.begin(), stars.end()); // flips the string around so that spaces are first and stars last
		cout << "	" << stars << "|"; // spacing and vertical bar displayed
	}
	if (numInput > 0) {//if the number is >0 
		numInput = round(numInput / 3); //divides by 3 to calculate how many stars should be displayed
		while (numInput > 0) {//as long as the number of stars is yet to reach 0
			numInput--; // subtracts 1 from the number of stars that need to be suffixed to the string
			stars = stars + "*"; // suffixes * to the end of the string
		}
		cout << "		  " << "|" << stars; // prints out the vertical bar and spacing before the bar
	}	
	return 0;
}

bool invalidInput(bool fail) {//function that is run each time failure conditions are met (failure conditions defined above)
	if (fail) {
		cout << "Please enter a valid input. Closing program";
		return true;
	}
	else
		return false;
}