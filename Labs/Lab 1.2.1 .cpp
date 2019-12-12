#include <iostream>
#include <string>

int main()
{
    std::string name;
    const int NAMES_COUNT = 3;

    for(int i = 0; i < NAMES_COUNT; i++)
    {
        std::cout << "What is your name? ";
        std::getline (std::cin, name);
        
        std::cout << "Hello, " << name << "!\n";
        std::cout << std::endl;
    }
}