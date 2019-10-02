#include <iostream>
#include <limits>

using namespace std;

void scale();
int input();


int main() {
	scale();
	if (input() == 1) {
		return 1;
	}

	return 0;
}

void scale() {
	cout << "	-30		0		30		60		90		120" << endl;

}

int input() {
	float playerNum;
	cin >> playerNum;
	if (cin.fail()) {
		cout << "The input is invalid. Please input a number between -30 and 120." << endl;
		return 1;
	}
	if (playerNum < -30 || playerNum > 120) {
		cout << "That is an invalid temperature please enter a number between -30 and 120." << endl;
	}
	else
	playerNum = int(playerNum);
	
	return 0;
}

int display() {


	return 0;
}