#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

char *const keyEncode(char *const, const int, char*(key)(char *const));
char* encryptionMethod(char*);
void toLowerCase(char*);

int main()
{
	const int stringLength = 46;
	const int wordLength = 3;
	char *const string = new char[stringLength] { "In a hole in the ground there lived a hobbit." };

	cout << string << endl;
	cout << "The length of changing word: " << wordLength << endl;
	cout << keyEncode(string, wordLength, encryptionMethod) << endl;
	
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
		int wordToCheckLength = strspn(string + i, symbols);

		if (wordToCheckLength == wordLength)
		{
			char *wordToCheck = new char[wordLength + 1]{ '\0' };
			strncpy(wordToCheck, string + i, wordLength);

			char *const encryptedWord = key(wordToCheck);

			strcpy(encryptedString + j, encryptedWord);

			j += strlen(encryptedWord);
			i += wordLength - 1;

			delete[] wordToCheck;
		}
		else
		{
			for (unsigned int k = i; k < i + wordToCheckLength  + 1; k++)
			{
				strncpy(encryptedString + j++, string + k, 1);
			}

			i += wordToCheckLength;
		}
	}

	delete[] symbols;

	return encryptedString;
}

char* encryptionMethod(char *const word)
{
	unsigned int wordLength = strlen(word);
	char *wordCopy = new char[wordLength + 1];
	strcpy(wordCopy, word);

	char *encryptedWord = new char[wordLength * 4 + 1]{ '\0' };

	toLowerCase(wordCopy);

	unsigned int j = 0;

	for (unsigned int i = 0; i < wordLength; i++)
	{
		int numberEquivalent = 26 - (wordCopy[i] - ('a' - 1));

		encryptedWord[j++] = '[';

		if (numberEquivalent > 10)
		{
			encryptedWord[j++] = '0' + numberEquivalent / 10;
			encryptedWord[j++] = '0' + numberEquivalent % 10;
		}
		else
		{
			encryptedWord[j++] = '0' + numberEquivalent;
		}

		encryptedWord[j++] = ']';
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
