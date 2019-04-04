#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

char* stringEncryption(char *const, const unsigned int, char* (key)(char*, const unsigned int));
char* encryptionMethod(char*, const unsigned int);
void toLowerCase(char*);
void stringConsole(char*);

void main()
{
	const unsigned int wordLength = 3;
	char string[59] = "We are the music makers, and we are the dreamers of dreams";
	
	stringConsole(string);

	stringConsole(stringEncryption(string, wordLength, encryptionMethod));
}

char* stringEncryption(char * const string, const unsigned int wordLength, char* (key)(char*, const unsigned int))
{
	const unsigned int stringLength = strlen(string);
	const char symbols[55] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char *stringCopy = new char[stringLength];
	strcpy(stringCopy, string);

	char *encryptedString = new char[stringLength * 2]{ '\0' };

	unsigned int i = 0, j = 0;

	while (j < stringLength)
	{
		if (strspn(stringCopy + j, symbols) == wordLength && strcspn(stringCopy + j + wordLength, symbols) > 0 && (strcspn(stringCopy + j - 1, symbols) > 0 || j == 0 || j == stringLength))
		{
			char * encryptedWord = key(stringCopy + j, wordLength);
			strcat(encryptedString + i , encryptedWord);
			i += strlen(encryptedWord);
			j += wordLength - 1;
		}
		else
		{
			char a = encryptedString[i];
			encryptedString[i] = stringCopy[j];
			i++;
		}

		j++;
	}

	return encryptedString;
}

char* encryptionMethod(char* wordPointer, const unsigned int wordLength)
{
	toLowerCase(wordPointer);
	char symbols[27] = "abcdefghijklmnopqrstuvwxyz";
	unsigned int symbolsLength = strlen(symbols);
	char *encryptedWord= new char[wordLength * 6 + 1]{ '\0' };
	int numberEquivalent;

	for (unsigned int i = 0; i < wordLength; i++)
	{
		for (unsigned int j = 0; j < symbolsLength; j++)
		{
			if (symbols[j] == wordPointer[i])
			{
				numberEquivalent = symbolsLength - j;
				break;
			}
		}

		if (numberEquivalent > 10)
		{
			char *encryptedLetter = new char[5]{ '\0' };
			int numberEquivalents[2];
			numberEquivalents[0] = numberEquivalent / 10;
			numberEquivalents[1] = numberEquivalent % 10;

			int k = 0;

			encryptedLetter[0] = '[';

			for (unsigned int j = 1; j < 3; j++)
			{				
				encryptedLetter[j] = '0' + numberEquivalents[k++];
			}

			encryptedLetter[3] = ']';

			strcat(encryptedWord, encryptedLetter);
		}
		else
		{
			char *encryptedLetter = new char[7]{ '\0' };

			encryptedLetter[0] = '[';
			encryptedLetter[1] = '0' + numberEquivalent;
			encryptedLetter[2] = ']';

			strcat(encryptedWord, encryptedLetter);
		}

	}

	return encryptedWord;
}

void toLowerCase(char *string)
{
	unsigned int stringLength = strlen(string);

	for (unsigned int i = 0; i < stringLength; i++)
	{
		if (string[i] > 'A' && string[i] < 'Z')
		{
			string[i] += 'a' - 'A';
		}
	}
}

void stringConsole(char* string)
{
	unsigned int stringLength = strlen(string);

	for (unsigned int i = 0; i < stringLength; i++)
	{
		cout << string[i];
	}

	cout << endl;
}