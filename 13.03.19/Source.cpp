#include<iostream>
#include<cstring>

using namespace std;

void displayStr(char *const);
char *const replaceWords(char *const, char *const, char *const);
char *const replaceWord(char *const, char *const, char *const, int&, const int);
void initialisation(char*, char*, char*);

int main()
{
	char str[256] = { '\0' },
		word[256] = { '\0' },
		newWord[256] = { '\0' };
	initialisation(str, word, newWord);

	displayStr(replaceWords(str, word, newWord));

	return 0;
}

char *const replaceWords(char *const str, char *const word, char *const newWord)
{
	int newStrLen;

	if ((strlen(word) >= strlen(newWord)))
	{
		newStrLen = strlen(str) - (strlen(word) - strlen(newWord)) * (strlen(str) / strlen(word) + 1) + 1;
	}
	else
	{
		newStrLen = strlen(str) + (strlen(newWord) - strlen(word)) * (strlen(str) / strlen(word) + 1) + 1;
	}
	
	char *newStr = new char[newStrLen];

	for (unsigned int i = 0; i < newStrLen; i++)
	{
		newStr[i] = '\0';
	}

	for (unsigned int i = 0; i < strlen(str); i++)
	{
		newStr[i] = str[i];
	}

	int indexToCheck = 0;
	int &index = indexToCheck;

	while(strpbrk(newStr + index, word))
	{
		newStr = replaceWord(newStr, word, newWord, index, newStrLen);
	}
	
	return newStr;
}

char *const replaceWord(char *const str, char *const word, char *const newWord, int &index, const int newStrLen)
{
	index = strpbrk(str + index, word) - str;

	char *newStr = new char[newStrLen];

	for (unsigned int i = 0; i < newStrLen; i++)
	{
		newStr[i] = '\0';
	}

	strncpy_s(newStr, newStrLen, str, index);
	char *toCheck = new char[strlen(word) + 1];
	strncpy_s(toCheck, strlen(word) + 1, str + index, strlen(word));
	bool isWord = !strcmp(toCheck, word);

	if (isWord)
	{
		strncpy_s(newStr + strlen(newStr), newStrLen, newWord, strlen(newWord));
		strncpy_s(newStr + strlen(newStr), newStrLen, str + index + strlen(word), strlen(str) - strlen(word) - index);
		index += strlen(newWord);
	}
	else
	{
		strncpy_s(newStr, newStrLen, str + index, strlen(str) - index);
	}

	return newStr;
}

void displayStr(char *const arr)
{
	for (int i = 0; i < strlen(arr); i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

void initialisation(char* str, char* word, char* newWord)
{
	cout << "String that'll be changed: ";
	cin.getline(str, 256);
	cout << endl << "Word that'll be changed: ";
	cin.getline(word, 256);
	cout << endl << "New word: ";
	cin.getline(newWord, 256);
}

