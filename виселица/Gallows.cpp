#include "Gallows.h"

string Gallows::chooseWord()
{
	int numberOfStr = rand() % wordAmount;
	int count = 0;

	const string path = "words.txt";

	ifstream fin;
	fin.open(path);

	while (!fin.eof() && count <= numberOfStr)
	{
		fin >> word;
		count++;
	}
	fin.close();

	return word;
}

string Gallows::cypherInit()
{
	for (int i = 0; i < word.length(); i++)
	{
		cypher.push_back('_');
	}

	return cypher;
}

void Gallows::display()
{
	const vector<string> images
	{
		{
		"        $$$$$$$$$$$$$$$\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		},

		{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		},

		{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"        |             $\n"
		"        |             $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		},

		{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"      / |             $\n"
		"        |             $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		},

		{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"      / | \\           $\n"
		"        |             $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		},

		{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"      / | \\           $\n"
		"        |             $\n"
		"       /              $\n"
		"      /               $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		},

		{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"      / | \\           $\n"
		"        |             $\n"
		"       / \\            $\n"
		"      /   \\           $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		}
	};

	system("cls");
	cout << images[mistakes] << endl;
	cout << cypher << endl;
}

void Gallows::move(char letter)
{
	int count = 0;

	for (int i = 0; i < word.length(); i++)
	{
		if (letter == word[i])
		{
			cypher[i] = word[i];
			count++;
		}
	}
	if (count == 0)
		mistakes++;

	display();

	tries++;
	usedLetters.push_back(letter);
}

void Gallows::final()
{
	if (mistakes >= maxMistakes)
	{
		cout << "===================" << endl;
		cout << "You loose :c" << endl;
		cout << "Your tries: " << tries << "\nWord: " << word << "\nUsed letters: ";

		for (int i = 0; i < usedLetters.size(); i++)
		{
			cout << usedLetters[i] << ", ";
		}
		cout << endl;
		cout << "===================" << endl;
	}
	else
	{
		cout << "===================" << endl;
		cout << "You WIN!!!" << endl;
		cout << "Your tries: " << tries << "\nWord: " << word << "\nUsed letters: ";

		for (int i = 0; i < usedLetters.size(); i++)
		{
			cout << usedLetters[i] << ", ";
		}
		cout << endl;
		cout << "===================" << endl;
	}
}

bool Gallows::isEnd()
{
	bool isFinal = false;

	if (mistakes >= maxMistakes || cypher == word)
		isFinal = true;

	return isFinal;
}


