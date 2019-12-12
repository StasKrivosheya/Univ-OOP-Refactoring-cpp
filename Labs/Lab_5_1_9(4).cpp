#include <iostream>
#include <string>

class ShopItemOrder
{
private:
	std::string name_;
	float unit_price_;
	int number_ordered_;

	/* There will be access methods allowing to:
			-get and set all of the above information;
			-get the total price for the order; */

public:
	std::string get_name()
	{
		return name_;
	}
	void set_name(std::string name)
	{
		name_ = name;
	}

	float get_unit_price()
	{
		return unit_price_;
	}
	void set_unit_price(float unit_price)
	{
		unit_price_ = unit_price;
	}

	int get_number_ordered()
	{
		return number_ordered_;
	}
	void set_number_ordered(int number_ordered)
	{
		number_ordered_ = number_ordered;
	}

	float get_total_prise()
	{
		return number_ordered_ * unit_price_;
	}

	ShopItemOrder(std::string name, float unit_price, int number_ordered)
	{
		name_ = name;
		unit_price_ = unit_price;
		number_ordered_ = number_ordered;
	}

	void print_console();
};

void ShopItemOrder::print_console()
{
	std::cout << "Ordered: " << get_name() << std::endl
		<< "Number: " << get_number_ordered() << std::endl
		<< "Price: " << get_unit_price() << std::endl;
	std::cout << "================" << std::endl;
	std::cout << "Total price: " << this->get_total_prise() << std::endl;

}

int main()
{
	ShopItemOrder item_1("MacBook", 2000.0, 2);
	item_1.print_console();

	system("pause");
	return 0;
}