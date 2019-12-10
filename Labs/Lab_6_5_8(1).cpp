#include <iostream>
#include <string>

class IPAddress
{
protected:
	std::string value;
public:
	IPAddress(const std::string& value) : value(value) { }
	IPAddress(const IPAddress& other)
	{
		this->value = other.value;
	}

	IPAddress() { }

	~IPAddress()
	{
		value = "";
	}

	friend std::ostream& operator<<(std::ostream& out, const IPAddress ip);
};

std::ostream& operator<<(std::ostream& out, const IPAddress ip)
{
	out << ip.value << std::endl;
	return out;
}

class IPAddresses
{
private:
	IPAddress* items;
	int capacity;
	int amount = 0;
public:
	IPAddresses(int capacity) : capacity(capacity)
	{
		items = new IPAddress[capacity];
	}

	IPAddresses()
	{
		capacity = 10000;
		items = new IPAddress[capacity];
	}

	void add_to_array(IPAddress ip_adress);

	friend std::ostream& operator<<(std::ostream& out, const IPAddresses ip_adresses);
};

std::ostream& operator<<(std::ostream& out, const IPAddresses ip_adresses)
{
	//out << "Network " << ip_adresses.n << std::endl;
	for (int i = 0; i < ip_adresses.amount; i++)
		out << ip_adresses.items[i];
	return out;
}

void IPAddresses::add_to_array(IPAddress ip_adress)
{
	items[amount] = ip_adress;
	amount++;
}

int main(void)
{
	std::string str;
	std::cout << "Enter text:" << std::endl;

	IPAddresses* ip_as_1 = new IPAddresses();
	IPAddresses* ip_as_2 = new IPAddresses();

	const int IP_AMOUNT = 5;
	const int DELIMITER = 2;

	for (int i = 0; i < IP_AMOUNT; i++)
	{
		getline(std::cin, str);
		IPAddress* ipAdress = new IPAddress(str);

		if (i < DELIMITER)
		{
			ip_as_1->add_to_array(*ipAdress);
		}
		else if (i == DELIMITER)
		{
			ip_as_1->add_to_array(*ipAdress);
			ip_as_2->add_to_array(*ipAdress);
		}
		else
		{
			ip_as_2->add_to_array(*ipAdress);
		}

	}

	std::cout << "\nNetwork 1\n" << *ip_as_1 << std::endl;
	std::cout << "\nNetwork 2\n" << *ip_as_2 << std::endl;

	system("pause");
	return 0;
}