// Program: Anagram
// bayusetiaji@amikom.ac.id, 2022

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

// daftar kata, boleh diganti
vector<string> words = { "spongebob", "patrick", "squidwards", "sandy", "garry", "plankton", "crab" };

void swap(char&, char&);
string get_word();
string randomize(string);

int main()
{
	int score = 0;

	while (true)
	{
		system("cls");
		string sel_word = get_word();
		string rnd_word = randomize(sel_word);
		string guess_word;

		cout << " Anagram Game. Score: " << score << endl;
		cout << " ---------------------------" << endl;
		cout << " >>>>> " << rnd_word << endl;
		cout << " guess: ";
		getline(cin, guess_word);

		if (guess_word == "")
			break;

		if (guess_word == sel_word)
		{
			score += 5;
			cout << " True..   +5\n";
			Beep(400, 500);
		}
		else
		{
			--score;
			cout << "  False..   -1\n";
			Beep(200, 500);
		}
	}
	
	return 0;
}

void swap(char& a, char& b)
{
	char c = a;
	a = b;
	b = c;
}

string get_word()
{
	srand((unsigned)time(NULL));

	return words[rand() % words.size()];
}

string randomize(string str)
{
	auto result = str;
	auto len = result.length();

	srand((unsigned)time(NULL));
	
	for (int i = 0; i < len / 2; ++i)
	{
		int idx1 = rand() % len;
		int idx2 = rand() % len;
		swap(result[idx1], result[idx2]);
	}

	return result;
}