// User interface contains two types of user input controls: TextInput, which accepts all characters and NumericInput, which accepts only digits.
// Implement the following methods:
// add on class TextInput - adds the given character to the current value
// getValue on class TextInput - returns the current value
// add on class NumericInput - overrides the base class method so that each non-numeric character is ignored
// For example, the following code should output "10":

// TextInput* input = new NumericInput();
// input->add('1');
// input->add('a');
// input->add('0');
// std::cout << input->getValue();
// https://www.testdome.com/questions/cpp/user-input/11966

#include <iostream>
#include <string>

class TextInput
{
private:
	std::string value;
public:
	virtual void add(char c)
	{
		value = value + c;
	}

	std::string getValue() 
	{ 
		return value;
	}
};

class NumericInput : public TextInput { 
	public:
		void add(char c) {
			if (!isalpha(c)) {
				//is numeric
				return TextInput::add(c);
			}
		}
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif