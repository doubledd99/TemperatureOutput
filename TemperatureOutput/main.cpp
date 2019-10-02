#include <iostream>
#include <limits>

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
	int numInput = input();
	int temperature;
	string stars;
	//cin >> temperature;
	temperature = numInput;
	if (numInput < 0) {
		numInput = numInput / -3;
		while (numInput > 0) {
			numInput--;
			stars = stars + "*";
			
			
		}
		stars.resize(10);		
		reverse(stars.begin(), stars.end());
		cout << "	" << stars << "|";
	}
	if (numInput > 0) {
		numInput = numInput / 3;
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