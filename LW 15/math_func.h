#pragma once
#include <cmath>
const double pi = 3.1415926535897932384626433832;
using vector = std::vector <double>;
class Function
{
public:
	virtual bool check(vector) 
	{
		return true; 
	}
	virtual double count(vector) = 0;
};
class Sin : public Function
{
public:
	double count(vector args)
	{
		return sin(args[0]);
	}
};
class Cos : public Function
{
public:
	double count(vector args)
	{
		return cos(args[0]);
	}
};
class Tg : public Function
{
	bool check(vector args) override
	{
		if (cos(args[0]) == 0) return 0;
		else return 1;
	}
	double count(vector args)
	{
		return tan(args[0]);
	}
};
class Ctg : public Function
{
	bool check(vector args) override
	{
		if (sin(args[0]) == 0) return 0;
		else return 1;
	}
	double count(vector args)
	{
		return tan(args[0]);
	}
};
class Abs : public Function
{
	double count(vector args)
	{
		return abs(args[0]);
	}
};
class Arcsin : public Function
{
	bool check(vector args) override
	{
		if (-1 <= args[0] and args[0] <= 1) return true;
		else return false;
	}
	double count(vector args)
	{
		return asin(args[0]);
	}
};
class Arccos : public Function
{
	bool check(vector args) override
	{
		if (-1 <= args[0] and args[0] <= 1) return true;
		else return false;
	}
	double count(vector args)
	{
		return acos(args[0]);
	}
};
class Arctg : public Function
{
	double count(vector args)
	{
		return atan(args[0]);
	}
};
class Arcctg : public Function
{
	double count(vector args)
	{
		return pi/2 - atan(args[0]);
	}
};
class Exp : public Function
{
	double count(vector args)
	{
		return exp(args[0]);
	}
};
class Ln : public Function
{
	bool check(vector args) override
	{
		if (args[0] > 0) return true;
		else return false;
	}
	double count(vector args)
	{
		return log(args[0]);
	}
};
class Log : public Function
{
	bool check(vector args) override
	{
		if (args[0] != 1 and args[0] > 0 and args[1] > 0)
		{
			return true;
		}
		else return false;
	}
	double count(vector args)
	{
		return log(args[1]) / log(args[0]);
	}
};
class Pow : public Function
{
	bool check(vector args) override
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
	double count(vector args)
	{
		return pow(args[0], args[1]);
	}
};
class Mult : public Function
{
	double count(vector args)
	{
		return args[0] * args[1];
	}
};
class Div : public Function
{
	bool check(vector args) override
	{
		if (args[1] == 0) return false;
		else return true;
	}
	double count(vector args)
	{
		return args[0] / args[1];
	}
};
class Plus : public Function
{
	double count(vector args)
	{
		return args[0] + args[1];
	}
};
class Minus : public Function
{
	double count(vector args)
	{
		return args[0] - args[1];
	}
};