#include "STRUCT.h"

BUS::BUS(std::ifstream& file)
{
	file >> region;
	file.ignore();
	file.getline(number, m);
	file.getline(firm, m);
	file.getline(FIO, m);
	file >> num_route;
	file.ignore();
	file.getline(status, m);
	file.ignore();
	if (!file.eof())
	{
		char delim_line[255];
		file.getline(delim_line, 255);
	}
}

void BUS::print(std::ostream& stream)
{
	stream<< region << '\n';
	stream << number<< '\n';
	stream << firm<< '\n';
	stream << FIO<< '\n';
	stream << num_route<< '\n';
	stream << status<< '\n';
	stream << "-----------------\n";
}

int BUS::compare(const BUS& bus)
{
	int res{};
	if (bus.firm > firm)
		res = 1;
	else
		if (bus.firm< firm)
			res = -1;
	return res;
}

int BUS::get_region()
{
	return region;
}

char* BUS::get_firm()
{
	return firm;
}

