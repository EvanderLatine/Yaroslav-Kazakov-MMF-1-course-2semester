#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

char *const keyEncode(char *const, const int, char*(key)(char *const));
char* encryptionMethod(char*);
void toLowerCase(char*);
void consoleString(char *const);
void consoleResult(char *const, const int);

int main()
{
	const int stringLength = 46;
	const int wordLength = 2;
	char *const string = new char[stringLength] { "In a hole in the ground there lived a hobbit." };

	consoleResult(string, wordLength);
	
	return 0;
}

char *const keyEncode(char *const string, const int wordLength, char*(key)(char *const))
{
	char *const symbols = new char[53]{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	unsigned int stringLength = strlen(string);
	char *encryptedString = new char[(stringLength + wordLength) * 4 + 1]{ '\0' };

	unsigned int j = 0;

	for (unsigned int i = 0; i < stringLength; i++)
	{
		char *wordToCheck = new char[wordLength + 1] { '\0' };
		char *symbolBeforeCheck = new char[2] { '\0' };
		char *symbolAfterCheck = new char[wordLength + 2] { '\0' };
		strncpy(wordToCheck, string + i, wordLength);
		strncpy(symbolAfterCheck, string + i, wordLength + 1);
		strncpy(symbolBeforeCheck, string + i - 1, 1);

		if (i == 0 || !strspn(symbolBeforeCheck, symbols) && strspn(symbolAfterCheck, symbols) == wordLength && strspn(wordToCheck, symbols) == wordLength)
		{
			char *const encryptedWord = key(wordToCheck);

			strcpy(encryptedString + j, encryptedWord);

			j += strlen(encryptedWord);
			i += wordLength - 1;
		}
		else
		{
			strncpy(encryptedString + j, string + i, 1);

			j++;
		}

		delete[] wordToCheck;
		delete[] symbolBeforeCheck;
		delete[] symbolAfterCheck;
	}

	delete[] symbols;

	return encryptedString;
}

char* encryptionMethod(char *const word)
{
	unsigned int wordLength = strlen(word);
	char *encryptedWord = new char[wordLength * 4 + 1]{ '\0' };

	toLowerCase(word);

	unsigned int j = 0;

	for (unsigned int i = 0; i < wordLength; i++)
	{
		int numberEquivalent = 26 - (word[i] - ('a' - 1));

		if (numberEquivalent > 10)
		{
			encryptedWord[j] = '[';
			encryptedWord[j + 1] = '0' + numberEquivalent / 10;
			encryptedWord[j + 2] = '0' + numberEquivalent % 10;
			encryptedWord[j + 3] = ']';

			j += 4;
		}
		else
		{
			encryptedWord[j] = '[';
			encryptedWord[j + 1] = '0' + numberEquivalent;
			encryptedWord[j + 2] = ']';

			j += 3;
		}
	}

	return encryptedWord;
}

void toLowerCase(char *word)
{
	unsigned int wordLength = strlen(word);

	for (unsigned int i = 0; i < wordLength; i++)
	{
		if (word[i] >= 'A' && 'Z' >= word[i])
		{
			word[i] -= abs('A' - 'a');
		}
	}
}

void consoleString(char *const string)
{
	unsigned int stringLength = strlen(string);

	for (unsigned int i = 0; i < stringLength; i++)
	{
		cout << string[i];
	}

	cout << endl;
}

void consoleResult(char *const string, const int wordLength)
{
	consoleString(string);
	cout << "The length of changing word: " << wordLength << endl;
	consoleString(keyEncode(string, wordLength, encryptionMethod));
}