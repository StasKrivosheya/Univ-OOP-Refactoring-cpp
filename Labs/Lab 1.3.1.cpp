#include <iostream>

int main()
{     
    const int SECONDS_IN_MINUTE = 60;
    const int SEC_IN_THREE_MIN = 3 * SECONDS_IN_MINUTE;

    int seconds_in_three_hours = SEC_IN_THREE_MIN * SECONDS_IN_MINUTE;

    std::cout << "The amount of seconds in 3 hours:\t" << seconds_in_three_hours
              <<  std::endl;

    return 0;
}