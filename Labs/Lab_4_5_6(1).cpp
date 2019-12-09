#include <iostream>
#include <sstream>
#include <string>

int main()
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

	std::cout << "\nOutput from string variable\n" << sentence << std::endl;

	return 0;
}