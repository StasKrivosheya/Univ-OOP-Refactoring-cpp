#include<iostream>

void console_print(int result, int expected)
{
    std::cout << "Result:\t" << result << "\texpected result:\t" << expected << std::endl;
}

int main()
{
    const float V = 2;

    float result = (V + 1) * 2;    
    console_print(result, 6);

    result = (V + 1) * ((V + 2) * 2);    
    console_print(result, 24);

    result = (V - 1) * 2 + 2 * 2;    
    console_print(result, 6);
    
    result = ((V + V) * (V + V)) * 2;    
    console_print(result, 32);
    
    result = ((int)V % 2) * (V + 2 * 2);
    console_print(result, 0);
    
    return 0;
}