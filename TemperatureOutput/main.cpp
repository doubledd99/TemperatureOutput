#include <iostream>
#include <limits>

using namespace std;

void scale();
int input();
int display();


int main() {
	scale();
	if (input() == 1) {
		return 1;
	}
	display();
	return 0;
}

void scale() {
	cout << "	-30       0          30          60          90          120" << endl;

}

int input() {
	float playerNum;
	cin >> playerNum;
	if (cin.fail()) {
		cout << "The input is invalid. Please input a number between -30 and 120." << endl;
		return 1;
	}
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
	return 0;
}

int display() {
	int numInput;
	int temperature;
	string stars;
	cin >> temperature;
	numInput = temperature;
	numInput = numInput / -3;
	//cout << numInput;
	while (numInput > 0) {
		numInput--;
		stars = stars + "*";
	}
	stars.resize(10);
	//cout << stars << "|";
	/*string negNum="hello";
	if (inputfullNum <= -3) {
		reverse(negNum.begin(), negNum.end());
		cout << negNum;
	}*/
	//cout <<"20" <<"			|									" << endl;
	reverse(stars.begin(), stars.end());

	cout << temperature << "	" << stars << "|";

	return 0;
}