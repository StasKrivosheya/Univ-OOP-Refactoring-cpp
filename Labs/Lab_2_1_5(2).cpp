#include <iostream>

void calculate_tax(float gross_price, float tax_rate)
{
	std::cout << "grossprice = " << gross_price
						<< "\ttaxrate = " << tax_rate << std::endl;

	if (gross_price > 0)
	{
		if ((tax_rate > 0) && (tax_rate <= 100))
		{
			float net_price, tax_value;

			net_price = gross_price / (1 + (tax_rate / 100));
			tax_value = net_price * (tax_rate / 100);

			std::cout << "Net price: " << net_price << std::endl;
			std::cout << "Tax value: " << tax_value << std::endl;
			std::cout << std::endl;

			return;
		}
	}
	std::cout << "Wrong info!";
	std::cout << std::endl;
}

int main(void)
{
	calculate_tax(123, 23);
	calculate_tax(123, 50);
	calculate_tax(123, 98);
	calculate_tax(11, 10);

	system("pause");

	return 0;
}