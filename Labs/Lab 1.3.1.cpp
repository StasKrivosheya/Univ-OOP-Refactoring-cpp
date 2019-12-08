#include <iostream>

int main()
{        
    const int SEC_IN_THREE_MIN = 3 * 60; 
    //const int SEC_IN_FIVE_MIN = 6 * 60;  
    //const float PI = 3.141526;

    int secondsThreeHours = SEC_IN_THREE_MIN * 60;

    std::cout << "The amount of seconds in 3 hours:\t" << secondsThreeHours <<  std::endl;

    return 0;
}