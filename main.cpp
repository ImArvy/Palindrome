#include <iostream>
#include <stack>

using namespace std;

class Solution {
private:
	stack<char> palindromeStack;
public:
	bool isPalindrome(string);
};

bool Solution::isPalindrome(string input) {
	// Base cases where string is size 0 or 1
	if (input.size() == 0 || input.size() == 1) {
		cout << "Is a palindrome."; // Output that the string is a palindrome
		return true; // Return true
	}
	
	for (int i = 0; i < input.size(); i++) {
		palindromeStack.push(input[i]); // Push forward traversal of the string to the stack
	}

	for (int i = 0; i < input.size(); i++) {
		// If the char in input at index i is the same as the char at the top of the stack and the stack contains at least one char
		if (input[i] == palindromeStack.top() && palindromeStack.size() > 0) {
			palindromeStack.pop(); // Pop this char from the stack
		// If the char in input at index i is not the same as the char at the top of the stack
		} else {
			cout << "Not a palindrome."; // Output that the string is not a palindrome
			return false; // Return false
		}
	}

	// If the stack is empty
	if (palindromeStack.size() == 0) {
		cout << "Is a palindrome."; // Output that the string is a palindrome
		return true; // Return true
	// If the stack is not empty
	} else {
		cout << "Not a palindrome."; // Output that the string is not a palindrome
		return false; // Return false
	}
}

int main() {
	Solution solution;

	string input = "racecar";

	solution.isPalindrome(input);

	return 0;
}