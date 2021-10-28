// Emerson Racca
// 10/28/21
// Lab 9b - Search a Vector

/*
Create a regular c-type function, called searchVector, that takes in a string vector and a string to search for.  
This function returns the first index where the given string target is found in the vector.  
Return -1 if the integer is not found.  Use the following prototype:

int searchVector(vector<string> vecArg, string target);
1. Populate a 10 element vector with random strings.  Use common first names or something simple.

2. Output the vector contents to the screen.

3. Ask the user what string to search for.

4. Output to the screen whether or not the string is in the vector. Show its index.

5. Ask the user if he wishes to search the same vector again.
*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

int searchVector(vector<string> vecArg, string target);

int main(void) {
	srand((unsigned int) time(0));
	string searchStr;
	char goAgain = 'y';
	int retIndex;

	vector<string> myVector;

	const int size = 14;
	string myStr[size] = { "Azula", "Zuko", "Iroh", "Aang", "Toph", "Sokka", "Mai", "Katar", "Appa", "Ozai", "Bumi", "Azulon", "Hahn", "Roku"};

	cout << "Search a Vector\n\n";

	for (int i = 0; i < 10; i++) {
		myVector.push_back(myStr[rand() % size]);
		cout << "Index "<< i << " contains: "<< myVector.at(i) << endl; // A separate loop isn't necessary to display the vector.
	}

	do{
		cout << "\nEnter a search string: ";
		cin >> searchStr; // getline isn't necessary here.

		retIndex = searchVector(myVector, searchStr);

		if (retIndex == -1)
			cout << "The string was not found.\n";
		else
			cout << "The string was found at index " << retIndex << " .\n";

		cout << "\nSearch again (y or n)? ";
		cin >> goAgain;
		cin.ignore();
	} while (goAgain == 'y');

	return 0;
}

int searchVector(vector<string> vecArg, string target) {
	unsigned int i = 0;
	do {
		if (vecArg.at(i) == target)
			return i;
		i++;
	} while (i < vecArg.size());
	// Not found
	return -1;
}

