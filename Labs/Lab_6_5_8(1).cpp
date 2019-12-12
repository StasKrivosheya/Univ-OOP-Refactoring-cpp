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

class Network
{
private:
	IPAddress* items;
	int capacity;
	int amount = 0;
public:
	Network(int capacity) : capacity(capacity)
	{
		items = new IPAddress[capacity];
	}

	Network()
	{
		capacity = 10000;
		items = new IPAddress[capacity];
	}

	~Network()
	{
		if (items)
			delete[] items;
	}

	void add_to_array(IPAddress ip_adress);

	friend std::ostream& operator<<(std::ostream& out, const Network ip_adresses);
};

std::ostream& operator<<(std::ostream& out, const Network ip_adresses)
{
	for (int i = 0; i < ip_adresses.amount; i++)
		out << ip_adresses.items[i];
	return out;
}

void Network::add_to_array(IPAddress ip_adress)
{
	items[amount] = ip_adress;
	amount++;
}

void initialize_networks(Network* net1, Network* net2)
{
	const int IP_AMOUNT = 5;
	const int DELIMITER = 2;
	std::string str;
	std::cout << "Enter text:" << std::endl;

	for (int i = 0; i < IP_AMOUNT; i++)
	{
		getline(std::cin, str);
		IPAddress ipAdress(str);

		if (i < DELIMITER)
		{
			net1->add_to_array(ipAdress);
		}
		else if (i == DELIMITER)
		{
			net1->add_to_array(ipAdress);
			net2->add_to_array(ipAdress);
		}
		else
		{
			net2->add_to_array(ipAdress);
		}

	}
}

int main()
{
	Network* net1 = new Network();
	Network* net2 = new Network();

	initialize_networks(net1, net2);

	std::cout << "\nNetwork 1\n" << *net1 << std::endl;
	std::cout << "\nNetwork 2\n" << *net2 << std::endl;

	system("pause");
	return 0;
}