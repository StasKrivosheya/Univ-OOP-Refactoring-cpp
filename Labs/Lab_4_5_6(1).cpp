#include <iostream>
#include <sstream>
#include <string>

std::string str_parcer()
{
	std::string sentence, line;

	std::cout << "Input your line:\n";

	while (getline(std::cin, sentence))
	{
		std::istringstream tr(sentence);

		std::cout << "\nOutput from stream:\n";

		while (tr >> line)
			std::cout << line << ' ';

		std::cout << std::endl;
		break;
	}

	return sentence;
}

int main()
{
	std::string sentence = str_parcer();

	std::cout << "\nOutput from string variable\n" << sentence << std::endl;

	return 0;
}