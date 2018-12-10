// Anonymous
// Write a function that checks if a given sentence is a palindrome. A palindrome is a word, phrase, 
// verse, or sentence that reads the same backward or forward. Only the order of English alphabet 
// letters (A-Z and a-z) should be considered, other characters should be ignored.
// For example, isPalindrome("Noel sees Leon.") should return true as spaces, period, 
// and case should be ignored resulting with "noelseesleon" which is a palindrome since it reads same backward and forward.
// https://www.testdome.com/questions/cpp/palindrome/2316

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

class Palindrome
{
public:
	static bool isPalindrome(std::string str)
	{
		//throw std::logic_error("Waiting to be implemented");
        str.erase(remove_if(str.begin(), str.end(), [](char c) { return !isalpha(c); }), str.end());
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str == std::string(str.rbegin(), str.rend());
	}
};

/*int main(int argc, const char* argv[])
{
	std::cout << Palindrome::isPalindrome("Noel sees Leon.");
}*/