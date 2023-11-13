
#include <iostream>
#include <iomanip>

int main()
{
    char outputChar;
    int count = 0;
    unsigned int lowerVal = 32, upperVal = 126;
    do
    {
        if (lowerVal < 32 || lowerVal > 126)    {
            std::cout << "error: Your input is invalid!" << std::endl;
        }
        std::cout << "Enter the ASCII code that is the lower bound [32 through 126]: ";
        std::cin >> lowerVal;
    }
    while (lowerVal < 32 || lowerVal > 126);
    do  {
        if (upperVal < lowerVal || upperVal > 126)  {
            std::cout << "error: Your input is invalid!" << std::endl;
        }
        std::cout << "Enter the ASCII code that is the upper bound [" << lowerVal << " through 126]: ";
        std::cin >> upperVal;
    }
    while (upperVal < lowerVal || upperVal > 126);
    std::cout << std::endl;
    std::cout << "The characters with ASCII values in range " << lowerVal << " through " << upperVal << " are:" << std::endl;
    for (int i = lowerVal; i <= upperVal; i++)
    {
        if (count % 15 == 0)
            std::cout << std::endl;
            outputChar = i;
            std::cout << outputChar;
            count++;
        }
    std::cout << std::endl;
    return 0;
}
