#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Gallows
{
	string word;
	string cypher;
	int tries;
	vector <char> usedLetters;
	const int wordAmount = 3;
	const int maxMistakes = 6;
	int mistakes;

public:
	Gallows() : word{ "\0" }, cypher{ "\0" }, tries{ 0 }, mistakes{ 0 } {}
	~Gallows() {}

	string chooseWord();
	string cypherInit();
	void display();
	void move(char letter);
	void final();
	bool isEnd();
};

