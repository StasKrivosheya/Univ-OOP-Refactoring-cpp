#include <iostream>

bool validate_grossprice(float grossprice)
{
	const int GROSS_PRICE_MIN = 0;

	return grossprice > GROSS_PRICE_MIN;
}

bool validate_taxrate(float taxrate)
{
	const int TAXRATE_MIN = 0;
	const int TAXRATE_MAX = 100;

	return taxrate > TAXRATE_MIN && taxrate <= TAXRATE_MAX;
}

void calculate_tax(float gross_price, float tax_rate)
{
	std::cout << "grossprice = " << gross_price
						<< "\ttaxrate = " << tax_rate << std::endl;

	bool isDataValid =	validate_grossprice(grossprice) &&
						validate_taxrate(taxrate);

	if (isDataValid)
	{
		float netprice = grossprice / (1 + (taxrate / 100));
		float taxvalue = netprice * (taxrate / 100);

		cout << "Net price: " << netprice << endl;
		cout << "Tax value: " << taxvalue << endl << endl;
	}
	else
	{
		std::cout << "Wrong info!";
		std::cout << std::endl;
	}
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