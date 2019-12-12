#include <string>
#include <iostream>
#include <sstream>

//changed parse_sentence function

std::string parse_sentence(std::string sentence)
{
	std::string line;

	std::istringstream parser(sentence);
	
	sentence = "";
	while (parser >> line)
	{
		sentence += line;
		sentence += ' ';
	}

	return sentence;
}

int main()
{
	std::string sentence;
	getline(std::cin, sentence);

	sentence = parse_sentence(sentence);

	std::cout << sentence;

	return 0;
}