#include <iostream>
#include <cctype>
//declare functions
void getSentence(char sentence[], const int size, std::istream& inStream);
//precondition: inStream is an opened input stream, size is equal to the max size - 1 (to account for the null character) of sentence
//postcondition: fills sentence[] with values from the input stream, until either a newline character is reached or the max size is reached.
void fixSentence(char input[], const int size);
//precondition: size is equal to the max size - 1 (to account for null character) of input[]
//postcondition: replaces all integers (words consisting solely of digits) with x's
void newLine(std::istream& inStream);
//clears extra input
//main
int main()
{
	using namespace std;
	//initialize variables
	char sentence[101], prompt;
	const int PROPER_SIZE = 100;
	//greet user and get input
	do
	{
		cout << "This security program will remove integers from a line of text.\n"
			<< "Please enter a line of text under 100 characters long and press ENTER to finish.\n";
		getSentence(sentence, PROPER_SIZE, cin);
		//fix sentence
		fixSentence(sentence, PROPER_SIZE);
		//output
		cout << "Your censored sentence is:\n" << sentence << endl
			<< "Would you like to continue? y/n\n";
		cin >> prompt;
		newLine(cin);
	} while (prompt == 'y' || prompt == 'Y');
	cout << "Goodbye!\n";
	return 0;
}

//define functions
void getSentence(char sentence[], const int size, std::istream& inStream)
{
	int counter = 0;
	char next;
	while (counter < size && inStream.get(next) && next != '\n')
	{
		sentence[counter] = next;
		counter++;
	}
	sentence[counter] = '\0';
	return;
}

void fixSentence(char input[], const int size)
{
	using namespace std;
	int counter = 0, wordStart;
	bool allDigits = false;
	while (counter < size && input[counter] != '\0')
	{
		if (!(isspace(input[counter])))
		{
			wordStart = counter;
			allDigits = true;
			while ((isspace(input[counter])) == false && counter < size && input[counter] != '\0')
			{
				if (!(isdigit(input[counter])))
					allDigits = false;
				counter++;
			}
		}
		else
			counter++;
		if (allDigits)
		{
			for (wordStart; wordStart < counter - 1; wordStart++)
				input[wordStart] = 'x';
		}
	}
	//end cstring
	if (counter < size)
	{
		input[counter + 1] = '\0';
	}
	else
		input[counter] = '\0';
	return;
}

void newLine(std::istream& inStream)
{
	char symbol;
	do
	{
		inStream.get(symbol);
	} while (symbol != '\n');
	return;
}