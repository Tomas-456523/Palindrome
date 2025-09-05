#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
	bool conditiono = true;
	while (conditiono) {
		cout << "Give me some text and I will tell you if it is a palindrome!\n> ";
		char text[80];

		cin.get(text, 80);
		cin.get();
		
		int i = 0;
		for (char c : text) {
			if (isalnum(c)) {
				text[i] = tolower(c);
				i++;
			}
			if (c == '\0') {
				break;
			}
		}
		text[i] = '\0';

		bool palindrome = true;
		for (int j = 0; j < strlen(text) / 2; j++) {
			if (text[j] != text[strlen(text) - j - 1]) {
				palindrome = false;
				break;
			}
		}

		if (palindrome) {
			cout << "Yes palindrome.";
		} else {
			cout << "Not a palindrome.";
		}
	}
}