#include <iostream>

int main()
{
	int answer = 0;
	int temperature = 0;
	int toConvert = 0;

	std::cout << "Enter the temperature you want to convurt" << std::endl;
	std::cin >> temperature;

	std::cout << "Please choose FROM what TO what type of temperature you want to convert" << std::endl;
	std::cout << "Please choose 1 for " << temperature << "C Celsius to Fahrenheit" << std::endl;
	std::cout << "Please choose 2 for " << temperature << "C Fahrenheit to Celsius" << std::endl;
	std::cout << "Please choose 3 for " << temperature << "C Celsius to kelvin" << std::endl;
	std::cout << "Please choose 4 for " << temperature << "C Fahrenheit to Kelvin" << std::endl;
	std::cout << "Please choose 5 for " << temperature << "C Kelvin to Fahrenheit" << std::endl;
	std::cout << "Please choose 6 for " << temperature << "C Kelvin to Celsius" << std::endl;
	std::cin >> toConvert;

	switch (toConvert) {

	case 1:
	{
		answer = (1.8 * temperature) + 32;
		std::cout << answer << "F" << std::endl;
		break;
	}
	case 2:
	{
		answer = (temperature - 32) * 5 / 9;
		std::cout << answer << "C" << std::endl;
		break;
	}
	case 3:
	{
		answer = temperature + 273.15;
		std::cout << answer << "K" << std::endl;
		break;
	}
	case 4:
	{
		answer = (temperature - 32) * 5 / 9 + 273.15;
		std::cout << answer << "K" << std::endl;
		break;
	}
	case 5:
	{
		answer = (temperature * 9 / 5) - 459.67;
		std::cout << answer << "F" << std::endl;
		break;
	}
	case 6:
	{
		answer = temperature - 273.15;
		std::cout << answer << "C" << std::endl;
		break;
	}
	default:
	{
		std::cout << "Please enter the temperature you want to convert and then choose only between numbers (1-6)" << std::endl;
		break;
	}
	}

	return 0;
}