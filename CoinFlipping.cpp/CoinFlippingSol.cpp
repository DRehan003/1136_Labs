#include <iostream>
#include <iomanip>
int main()
{
    int heads = 1;
    int computerChoice;
    double headsPercentage, tailsPercentage;
    double totalHeads = 0;
    double totalTails = 0;
    double totalFlip = 0;
    char userChoice;
    unsigned int seed;
    std::cin >> seed;
    srand(seed);
    do  {
        computerChoice = rand() % 2 + 1;
        if (computerChoice == heads)    {
            std::cout << "Flip = Heads" << std::endl;
            totalHeads++;
        }   else    {
            std::cout << "Flip = Tails" << std::endl;
            totalTails++;
        }
        totalFlip++;
        std::cout << "Do you want to flip again? Enter Y for Yes or N for No ";
        std::cin >> userChoice;
        while (userChoice != 'N' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'y')    {
            std::cout << "Your input is not valid ";
            std::cin >> userChoice;
        }
    } while (userChoice == 'Y' || userChoice == 'y');
    std::cout << std::endl;
    headsPercentage = (totalHeads / totalFlip) * 100;
    tailsPercentage = (totalTails / totalFlip) * 100;
    std::cout << totalHeads << " of the " << totalFlip << " flips were Heads or " << std::setprecision(1) << std::fixed << headsPercentage << "% were Heads." << std::endl;
    std::cout << std::setprecision(0) << totalTails << " of the " << totalFlip << " flips were Tails or " << std::setprecision(1) << std::fixed << tailsPercentage << "% were Tails." << std::endl;
    return 0;
}
