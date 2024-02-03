#include <iostream>

void calcumSum(double a, double b);
void calcumSub(double a, double b);
void calcumMul(double a, double b);
void calcumDev(double a, double b);

int main()
{
	double a;
	double b;
	int op;

	std::cout << "Enter first number" << std::endl;
	std::cin >> a;
	std::cout << "Enter second number" << std::endl;
	std::cin >> b;
	std::cout << "Enter the operator choose from (1 for +,2 for -,3 for *,4 for /)" << std::endl;
	std::cin >> op;

	switch (op)
	{
	case 1: calcumSum(a, b);  break;
	case 2: calcumSub(a, b);  break;
	case 3: calcumMul(a, b);  break;
	case 4: calcumDev(a, b);  break;
	default:
		std::cout << "Error" << std::endl;
		break;
	}
	
	return 0;
}

void calcumSum(double a, double b) {
	double result;

	result = a + b;
	std::cout << result;
}
void calcumSub(double a, double b) {
	double result;

	result = a - b;
	std::cout << result;
}
void calcumMul(double a, double b) {
	double result;

	result = a * b;
	std::cout << result;
}
void calcumDev(double a, double b) {
	double result;

	result = a / b;
	std::cout << result;
}