#include <iostream>

using namespace std;

//Time converter
void Task1() {
	int timeInSeconds;
	cout << "Enter seconds: ";
	cin >> timeInSeconds;

	double timeInMinutes = timeInSeconds / 60;
	double timeInHours = timeInMinutes / 60;

	cout << "Seconds: " << timeInSeconds << "\n"
		<< "Minutes: " << timeInMinutes << "\n"
		<< "Hours: " << timeInHours << "\n";
}

//Cash converter
void Task2() {
	float cash;
	cout << "Enter value: ";
	cin >> cash;

	int wholePartOfcash = static_cast<int>(floor(cash));

	cout << wholePartOfcash << " грн. " << (cash - wholePartOfcash) * 100 << " коп.\n";
}


//Caluculation of run speed
void Task3() {
	int speed;
	float time;
	int distance;

	cout << "Calculation speed of run...\n";

	cout << "Enter a distance (metres): ";
	cin >> distance;

	cout << "Enter a time (min. sec): ";
	cin >> time;

	cout << "Distance: " << distance << "\n";

	int minutes = static_cast<int>(floor(time));
	int seconds = static_cast<int>(round((time - minutes) * 100));
	int secondsTime = (60 * minutes) + seconds;

	cout << "Time: " <<  minutes << "min. " << seconds << "sec. = " << secondsTime << "sec.\n";
	cout << "You running with average speed: " << (distance / 1000.0f) / (secondsTime / 3600.0f) << "km / h\n";
}

//Day converter
void Task4() {
	int days;
	cout << "Enter days count: ";
	cin >> days;

	int weeks = static_cast<int>(floor(days / 7));

	cout << "Weeks: " << weeks << " Days: " << days - (weeks * 7);
}

int main() {
	Task1();
	Task2();
	Task3();
	Task4();

	return 0;
}