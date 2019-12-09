#include<iostream>
#include<string>

class Person
{
private:
	std::string name_;
	std::string color_eye_;
	std::string favorite_tv_series_;
	int age_;
public:
	std::string get_name()
	{
		return name_;
	}
	void set_name(std::string name)
	{
		name_ = name;
	}

	std::string get_color_eye()
	{
		return color_eye_;
	}
	void set_color_eye(std::string color_eye)
	{
		color_eye_ = color_eye;
	}

	std::string get_favorite_tv_series()
	{
		return favorite_tv_series_;
	}
	void set_favorite_tv_series(std::string favorite_tv_series)
	{
		favorite_tv_series_ = favorite_tv_series;
	}

	int get_age()
	{
		return age_;
	}
	void set_age(int age)
	{
		age_ = age;
	}

	Person(std::string name, std::string color_eye, std::string favorite_tv_series, int age)
	{
		name_ = name;
		color_eye_ = color_eye;
		favorite_tv_series_ = favorite_tv_series;
		age_ = age;
	}

	void print_console();
};

void Person::print_console()
{
	std::cout << get_name() << " is " << get_age() << " years old.\n"
		<< "He has a " << get_color_eye() << " eye color. "
		<< get_name() << " likes to watch TV series \"" << get_favorite_tv_series() << "\"." << std::endl;
}

int main()
{
	Person person1("Harry", "green", "Black Mirror", 23);
	std::cout << "Meet " << person1.get_name() << "!" << std::endl;
	person1.print_console();

	Person person2("Tim", "blue", "Mr. Robot", 26);
	std::cout << "\nMeet " << person2.get_name() << "!" << std::endl;
	person2.print_console();

	system("pause");
	return 0;
}