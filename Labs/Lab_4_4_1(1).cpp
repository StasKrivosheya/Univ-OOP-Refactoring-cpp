#include <iostream>
#include <string>

int main()
{
	std::string input_string;
	getline(std::cin, input_string);

	const int LETTERS_AMOUNT = 26;
	int different_letters = 0;
	int alphabet[LETTERS_AMOUNT];
	bool is_pangram = false;

	for (int i = 0; i < LETTERS_AMOUNT; i++)
	{
		alphabet[i] = 0;
	}

	for (int i = 0; i < input_string.length(); i++)
	{
		int letter_index = (tolower(input_string[i]) - 'a');

		if (letter_index < 0 || letter_index > LETTERS_AMOUNT - 1)
		{
			continue;
		}

		if (alphabet[letter_index] == 0)
		{
			different_letters++;
		}

		if (different_letters >= LETTERS_AMOUNT)
		{
			is_pangram = true;
		}
		alphabet[letter_index]++;
	}

	for (int i = 0; i < LETTERS_AMOUNT; i++)
	{
		std::cout << (char)(i + 97) << " - " << alphabet[i] << std::endl;
	}

	if (is_pangram)
		std::cout << "Pangram" << std::endl;
	else
		std::cout << "Not pangram" << std::endl;

	system("pause");
	return 0;
}