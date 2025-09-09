/*
Tomas Carranza Echaniz
9/9/2025
This program reads in a string of characters from the user, and (ignoring all punctuation and spaces) checks
if it is a palindrome (read the same backwards and forwards). If it is, it tells the user, "Palindrome." If
not, it tells the user, "Not a palindrome."
*/

#include <iostream> //import necessary modules
#include <cstring>
#include <cctype>
using namespace std;

//the main loop
int main() {
	//greets the user
	cout << "What's popping I am Pablo the Potential Palindrome Processor.\n";
	//gives the users instructions for quitting
	cout << "(Enter nothing to quit.)\n\n";

	//keeps going until the user inputs nothing
	bool continuing = true;
	while (continuing) {
		//prompts the user to enter some text
		cout << "Give me some text and I will tell you if it is a palindrome!\n> ";

		//the character array for the player to input into (takes at most 80 characters; after that, it pretty much just treats each chunk of 80 characters as its own input)
		char text[80];

		//gets the text input from the character
		cin.get(text, 80);
		cin.get();

		//i is the position of the character it's currently checking
		int i = 0;
		//changes the string to a string of all alphanumeric characters 
		for (char c : text) {
			if (isalnum(c)) { //if current character is a letter or number
				//adds the character to the end of the reworked char array
				text[i] = tolower(c);
				i++; //increments i so we don't overwrite the last good character
			}//no need to keep checking once we reach the null terminator (the end of the string)
			if (c == '\0') {
				break;
			}
		}
		//adds the null terminator to the intended end of the array; all characters after this will be ignored
		text[i] = '\0';

		//if the text is indeed a palindrome
		bool palindrome = true;
		//compares the first character with the last, the second character with the penultimate, etc.
		//uses i as the string length since it incremented once per character
		for (int j = 0; j < strlen(text) / 2; j++) {
			//if the characters don't compare
			if (text[j] != text[strlen(text) - j - 1]) {
				palindrome = false;
				break;
			}
		}

		//as far as I could tell, the only way to cause an error was to enter nothing (including punctuation), so I used that flag as the quit command
		//who would want to check if "" is a palindrome, anyway?
		if (!cin) {
			continuing = false;
		//says palindrome if it was a palindrome, and not a palindrome if it was not a palindrome.
		} else if (palindrome) {
			cout << "\nPalindrome.\n";
		} else {
			cout << "\nNot a palindrome.\n";
		}
	}
	//bids the user farewell
	cout << "\nGoodbye!";
}