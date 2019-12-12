#include <iostream>
#include <string>

const int LETTERS_AMOUNT = 26;
const char ALPHABET_BEGIN = 'a';
const char ALPHABET_END = 'z';

int* calculate_letters_amount(std::string str)
{
	int* alphabet = new int[LETTERS_AMOUNT] {0};

	for (int i = 0; i < str.length(); i++)
	{
		char letter = tolower(str[i]);
		if (letter < ALPHABET_BEGIN || letter > ALPHABET_END)
		{
			continue;
		}

		int index = letter - ALPHABET_BEGIN;
		alphabet[index]++;
	}
	return alphabet;
}

bool are_all_letters_used(int* alphabet)
{
	for (int i = 0; i < LETTERS_AMOUNT; ++i)
	{
		if (alphabet[i] == 0)
		{
			return false;
		}
	}
	return true;
}

void pangram_checking(std::string str)
{
	int* alphabet = calculate_letters_amount(str);

	for (int i = 0; i < LETTERS_AMOUNT; i++)
	{
		std::cout << (char)(i + ALPHABET_BEGIN) << " - " << alphabet[i] << std::endl;
	}

	bool is_pangram = are_all_letters_used(alphabet);
	if (is_pangram)
	{
		std::cout << "Pangram" << std::endl;
	}
	else
	{
		std::cout << "Not pangram" << std::endl;
	}
	delete[] alphabet;
}

int main()
{
	std::string input_string;
	getline(std::cin, input_string);

	pangram_checking(input_string);

	system("pause");
	return 0;
}