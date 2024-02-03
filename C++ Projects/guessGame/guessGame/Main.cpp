#include <iostream>

int main()
{
    int guess = 0;
    int num = 0;
    int tries = 3;

    srand(time(NULL));
    num = (rand() % 12 + 1);

    std::cout << "Debug " << num << std::endl;

    std::cout << "Pick a number between 1-12" << std::endl;

    do
    {
        std::cout << "You have " << tries << " tries" << std::endl;
        std::cin >> guess;

        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "You can use only numbers from 1 to 12!" << std::endl;
            std::cin >> guess;
        }

        if (guess < num && tries > 1)
        {
            std::cout << "Too LOW aim higher" << std::endl;
        }
        else if (guess > num && tries > 1)
        {
            std::cout << "Too HIGH aim lower" << std::endl;
        }

        tries--;

        if (tries == 0)
        {
            break;
        }

    } while (guess != num);

    if (guess == num)
    {
        std::cout << "Congratz" << std::endl;
    }
    else
    {
        std::cout << "No more tries left" << std::endl;
    }

    return 0;
}