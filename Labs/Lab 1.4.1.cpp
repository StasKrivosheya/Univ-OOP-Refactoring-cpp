#include<iostream>

void consolePrint(int result, int expected)
{
    std::cout << "Result:\t" << result << "\texpected result:\t" << expected << std::endl;
}

int main()
{
    const float V = 2;

    float result = (V + 1) * 2;    
    consolePrint(result, 6);

    result = (V + 1) * ((V + 2) * 2);    
    consolePrint(result, 24);

    result = (V - 1) * 2 + 2 * 2;    
    consolePrint(result, 6);
    
    result = ((V + V) * (V + V)) * 2;    
    consolePrint(result, 32);
    
    result = ((int)V % 2) * (V + 2 * 2);
    consolePrint(result, 0);
    
    return 0;
}