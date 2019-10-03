
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

#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

void scale();
int input();
int display();
int invalidInput(bool fail);


int main() {

	scale();
	display();
	//input();
	return 0;
}

void scale() {
	cout << "	-30       0         30        60        90      120" << endl;

}

int input() {
	float playerNum;
	cin >> playerNum;
	if (cin.fail()) {
		cout << "The input is invalid. Please input a number between -30 and 120." << endl;
		invalidInput(true);
		return 1;
	}
	if (playerNum > 999999) {
		playerNum = 999999;
	}
	if (playerNum < -99999) {
		playerNum = -99999;
	}
	cout << playerNum;
	if (playerNum > 120) {
		playerNum = 120;
	}
	if (playerNum < -30) {
		playerNum = -30;
	}
	playerNum = int(playerNum);
	
	//temp
	//cout << "playerNum" << playerNum;
	//temp
	return playerNum;
}

int display() {
	float numInput = input();
	int temperature;
	string stars;
	//cin >> temperature;
	temperature = numInput;
	if (numInput < 0) {
		numInput = round(numInput / -3);
		while (numInput > 0) {
			numInput--;
			stars = stars + "*";
			
			
		}
		stars.resize(10);		
		reverse(stars.begin(), stars.end());
		cout << "	" << stars << "|";
	}
	if (numInput > 0) {
		numInput = round(numInput / 3);
		while (numInput > 0) {
			numInput--;
			stars = stars + "*";
		}
		cout << "		  " << "|" << stars;
	}	


	return 0;
}

int invalidInput(bool fail) {
	cout << "This shit worked!";
	if (fail == true) {
		return 1;
	}
	else
		return 0;
	
}