#include<iostream>

#include<iomanip>

#include<fstream>

using namespace std;

// Declaring the constants
int const PLAYERS = 10;

bool GetBowlingData(char bowlerNames[][100], int bowlerScores[][5], int& n) { // created function with 3 parameters

	ifstream in("BowlingScoresGit.txt"); // File to be read from

	if (!in.fail()) { // if file reading does not fail then return the file

		while (!in.eof()) {

			in >> bowlerNames[n] >> bowlerScores[n][0] >> bowlerScores[n][1] >> bowlerScores[n][2] >> bowlerScores[n][3] >> bowlerScores[n][4];

			n++;

		}

		return true;

	}

	return false; // returns false if the file reading is a failure

}

void GetAverageScore(int bowlerScores[][5], double avgScores[], int n) { // created this function to get average scores

	for (int i = 0; i < n; i++) {

		avgScores[i] = 0;

		for (int j = 0; j < 5; j++) {

			avgScores[i] += bowlerScores[i][j];

		}

		avgScores[i] /= 5.0;

	}

}

// Function created to print the results 
void PrettyPrintResults(char bowlerNames[][100], int bowlerScores[][5], double avgScores[], int n) {

	cout << left << setw(15) << "Name" << "Score1\tScore2\tScore3\tScore4\tScore5\tAvgScore" << endl; //Displaying scores in column format

	//For a single iteration of bowlerNames, bowlerScores are iterated 5 times
	for (int i = 0; i < n; i++) {

		cout << left << setw(15) << bowlerNames[i] << "\t";

		for (int j = 0; j < 5; j++) // one bowler has 5 different scores 

			cout << bowlerScores[i][j] << "\t";

		cout << avgScores[i] << endl;

	}

}

int main() {

	cout << setfill('*');  //setfill() fills character based on the specified character
	cout << setw(60) << "*" << endl; //setw() helps set the field width used for output operations
	cout << setfill('*');
	cout << setw(11) << "*" << " Program to calculate bowling scores " << setw(12) << "*" << endl;
	cout << setfill('*');
	cout << setw(60) << "*" << endl;
	cout << endl;

	cout << setfill(' '); // Reseting the specified character

	//declaring the array variables 
	char bowler_Names[PLAYERS][100];

	int bowler_Scores[PLAYERS][5];

	double avg_Scores[PLAYERS];

	int n = 0;

	//Calling all the functions created above
	if (GetBowlingData(bowler_Names, bowler_Scores, n)) {

		GetAverageScore(bowler_Scores, avg_Scores, n);

		PrettyPrintResults(bowler_Names, bowler_Scores, avg_Scores, n);

	}

	return 0;

}