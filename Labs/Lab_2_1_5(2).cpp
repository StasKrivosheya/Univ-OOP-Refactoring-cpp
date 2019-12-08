#include <iostream>

void calculateTax(float grossPrice, float taxRate)
{
	std::cout << "grossprice = " << grossPrice
						<< "\ttaxrate = " << taxRate << std::endl;

	if (grossPrice > 0)
	{
		if ((taxRate > 0) && (taxRate <= 100))
		{
			float netPrice, taxValue;

			netPrice = grossPrice / (1 + (taxRate / 100));
			taxValue = netPrice * (taxRate / 100);

			std::cout << "Net price: " << netPrice << std::endl;
			std::cout << "Tax value: " << taxValue << std::endl;
			std::cout << std::endl;

			return;
		}
	}
	std::cout << "Wrong info!";
	std::cout << std::endl;
}

int main(void)
{
	calculateTax(123, 23);
	calculateTax(123, 50);
	calculateTax(123, 98);
	calculateTax(11, 10);

	system("pause");

	return 0;
}
