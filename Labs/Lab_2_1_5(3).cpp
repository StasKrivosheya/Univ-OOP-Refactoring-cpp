#include <iostream>

void measurement_system_converter()
{
	int sys;
	float m, ft, in;
	const int INCHES_IN_FOOT = 12;
	const float FEET_IN_METRE = 3.28084;
	const float METRES_IN_INCH = 0.0254;

	std::cout << "For Metric, enter 0. For Imperial, enter 1." << std::endl;
	std::cin >> sys;

	if (sys == 0)
	{
		std::cout << "Metric method. How many Meters?" << std::endl;
		std::cin >> m;

		float to_feet = FEET_IN_METRE * m;

		ft = floor(to_feet);
		in = ((to_feet - ft) * INCHES_IN_FOOT);

		std::cout << ft << "' " << in << "''" << std::endl;
	}
	else if (sys == 1)
	{
		std::cout << "Imperial method. How many Feet?" << std::endl;
		std::cin >> ft;
		std::cout << "How many Inches?" << std::endl;
		std::cin >> in;

		m = ((ft * INCHES_IN_FOOT) + in) * METRES_IN_INCH;
		std::cout << m << "m" << std::endl;
	}
	else
		std::cout << "Wrong option!" << std::endl;
}

int main(void)
{
	measurement_system_converter();

	system("pause");
	return 0;
}