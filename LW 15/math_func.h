#pragma once
#include <cmath>
const double pi = 3.1415926535897932384626433832;
double my_abs(std::vector <double> args)
{
	return abs(args[0]);
}
double my_sin(std::vector <double> args)
{
	return sin(args[0]);
}
double my_cos(std::vector <double> args)
{
	return cos(args[0]);
}
double my_tg(std::vector <double> args)
{
	return tan(args[0]);
}
double my_ctg(std::vector <double> args)
{
	return 1 / tan(args[0]);
}
double my_arcsin(std::vector <double> args)
{
	return asin(args[0]);
}
double my_arccos(std::vector <double> args)
{
	return acos(args[0]);
}
double my_arctg(std::vector <double> args)
{
	return atan(args[0]);
}
double my_arcctg(std::vector <double> args)
{
	return pi / 2 - atan(args[0]);
}
double my_exp(std::vector <double> args)
{
	return exp(args[0]);
}
double my_ln(std::vector <double> args)
{
	return log(args[0]);
}
double my_log(std::vector <double> args)
{
	return log(args[1]) / log(args[0]);
}
double my_factorial(std::vector <double> args)
{
	int a = args[0] - trunc(args[0]);
	int answer = 1;
	for (a; a > 1; a--) answer *= a;
	return answer;
}
double my_pow(std::vector <double> args)
{
	return exp(log(args[0]) * args[1]);
}
double my_mult(std::vector <double> args)
{
	return args[0] * args[1];
}
double my_div(std::vector <double> args)
{
	return args[0] / args[1];
}
double my_plus(std::vector <double> args)
{
	return args[0] + args[1];
}
double my_minus(std::vector <double> args)
{
	return args[0] - args[1];
}

bool always_true(std::vector <double> args)
{
	return 1;
}
bool check_tg(std::vector <double> args)
{
	if (cos(args[0]) == 0) return 0;
	else return 1;
}
bool check_ctg(std::vector <double> args)
{
	if (sin(args[0]) == 0) return 0;
	else return 1;
}
bool check_arcsin(std::vector <double> args)
{
	if (abs(args[0]) <= 1) return 1;
	else return 0;
}
bool check_ln(std::vector <double> args)
{
	if (args[0] > 0) return 1;
	else return 0;
}
bool check_logarifm(std::vector <double> args)
{
	if (args[0] > 0 and args[0] != 1 and args[1] > 0) return 1;
	else return 0;
}
bool check_factorial(std::vector <double> args)
{
	if (args[0] > 0 and args[0] - trunc(args[0]) == 0) return 1;
	else return 0;
}
bool check_pow(std::vector <double> args)
{
	if (args[0] > 0) return 1;
	else
	{
		if (args[1] - trunc(args[1]) == 0)
		{
			if (args[0] != 0 or args[1] >= 0)
			{
				return 1;
			}
		}
	}
	return 0;
}
bool check_div(std::vector <double> args)
{
	if (args[1] == 0) return 0;
	else return 1;
}