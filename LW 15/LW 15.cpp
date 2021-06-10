#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdarg>
#include <Windows.h>
const double pi = 3.1415926535897932384626433832;
double my_abs(std::vector <double> args);
double my_sin(std::vector <double> args);
double my_cos(std::vector <double> args);
double my_tg(std::vector <double> args);
double my_ctg(std::vector <double> args);
double my_arcsin(std::vector <double> args);
double my_arccos(std::vector <double> args);
double my_arctg(std::vector <double> args);
double my_arcctg(std::vector <double> args);
double my_exp(std::vector <double> args);
double my_ln(std::vector <double> args);
double my_log(std::vector <double> args);
double my_factorial(std::vector <double> args);
double my_pow(std::vector <double> args); //a^b
double my_mult(std::vector <double> args);
double my_div(std::vector <double> args);
double my_plus(std::vector <double> args);
double my_minus(std::vector <double> args);
bool always_true(std::vector <double> args);
bool check_tg(std::vector <double> args);
bool check_ctg(std::vector <double> args);
bool check_arcsin(std::vector <double> args);
bool check_ln(std::vector <double> args);
bool check_logarifm(std::vector <double> args);
bool check_factorial(std::vector <double> args);
bool check_pow(std::vector <double> args);
bool check_div(std::vector <double> args);
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
bool is_numeral(char a)
{
	if ('0' <= a and a <= '9') return true;
	else return false;
}
enum id_lexemes
{
	//пре-унарные операторы, высший приоритет
	ABS = 1, SIN, COS, TG, CTG, ARCSIN, ARCCOS, ARCTG, ARCCTG, EXP, LN,
	//псевдо пре-унарный оператор
	LOG,
	//пост-унарные операторы, приоритет: 2
	FACTORIAL,
	//бинарные операторы, приоритет: 3
	POW,
	//бинарные операторы, приоритет: 4
	MULT, DIV,
	//бинарные операторы, низший приоритет
	PLUS, MINUS,
	//требуется для определения числа операторов
	NUMBER_OPERATORS,
	//технические вещи
	NUMBER, X, LEFT_BR, RIGHT_BR, COMMA, END
};
enum id_errors
{
	NON_ERROR, UNKNOWN_SYMBOL, UNKNOWN_FUNCTION, ERROR_SIGNS, REDUNDANT_SIGNS, IMPOSSIBLE_COUNT, MORE_RIGHT_BRACKETS, HAVE_OPEN_BRACKETS
};
class Lexeme
{
private:
	id_lexemes id;
	double value;
public:
	Lexeme(id_lexemes id, double value = 0)
	{
		this->id = id;
		this->value = value;
	}
	id_lexemes get_id()
	{
		return id;
	}
	double get_value()
	{
		return value;
	}
};
class Sentence
{
private:
	int pos = 0;
	std::vector <Lexeme> array;
public:
	Sentence()
	{
	};
	Sentence(std::vector <Lexeme> array)
	{
		for (int i = 0; i < array.size(); i++) add_lexeme(array[i]);
	}
	//получить номер лексемы-конца
	int get_end()
	{
		return array.size() - 1;
	}
	//добавить лексему
	void add_lexeme(Lexeme a)
	{
		array.push_back(a);
	}
	//удалить лексему с таким номером
	void delete_lexeme(int i)
	{
		if (pos >= i and pos != 0) pos--; //сейвим местоположение
		array.erase(array.begin() + i);
	}
	//заменить лексему x на значение
	void substitute(double x)
	{
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i].get_id() == X)
			{
				array[i] = Lexeme(NUMBER, x);
			}
		}
	}
	//создать новое предложение из части старого
	Sentence create_lexeme_vector(unsigned int a, unsigned int b)
	{
		std::vector <Lexeme> buffer;
		for (int i = a; i <= b; i++)
		{
			buffer.push_back(array[i]);
		}
		return Sentence(buffer);
	}
	//заменить диапазон на одну лексему
	void replace_sector(unsigned int a, unsigned int b, Lexeme paste)
	{
		for (int i = a; i < b; i++)
		{
			this->delete_lexeme(a);
		}
		array[a] = paste;
	}
	int find_highest_comma(id_errors& error)
	{
		int answer = 0;
		bool found_comma = 0;
		for (int i = 0; array[i].get_id() != END; i++)
		{
			if (array[i].get_id() == COMMA)
			{
				if (found_comma == 0)
				{
					answer = i;
					found_comma = 1;
				}
				else
				{
					error = ERROR_SIGNS;
					return answer;
				}
			}
			else if (array[i].get_id() == LEFT_BR)
			{
				i = find_right_bracket(i) + 1;
			}
		}

	}
	//проверить вектор на ошибки(избыточное использование знаков)
	bool is_correct()
	{
		for (int i = 0; array[i].get_id() != END; i++)
		{
			if (POW <= array[i].get_id() and array[i].get_id() <= MINUS and POW <= array[i + 1].get_id() and array[i + 1].get_id() <= MINUS)
			{
				return 0;
			}
		}
		return 1;
	}
	//найти лексему с определённым id
	int find_id_lexeme(id_lexemes id)
	{
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i].get_id() == LEFT_BR)
			{
				return i;
			}
		}
		return -1;
	}
	//найти закрывающую скобку для открывающей
	int find_right_bracket(unsigned int a)
	{
		int count_open_brackets = 1;
		for (int i = a + 1; ; i++)
		{
			if (array[i].get_id() == LEFT_BR) count_open_brackets++;
			else if (array[i].get_id() == RIGHT_BR) count_open_brackets--;
			if (count_open_brackets == 0)
			{
				return i;
			}
		}
	}
	//посчитать значение предложения
};
class Operator
{
private:
	id_lexemes id;
	unsigned int left_argue;
	unsigned int right_argue;
	int priority;
	std::vector <std::string> decode_base;
public:
	int get_id()
	{
		return (int)id;
	}
	int get_left_argue()
	{
		return left_argue;
	}
	int get_right_argue()
	{
		return right_argue;
	}
	int is_it(std::string input)
	{
		int max_code = 0;
		for (int i = 0; i < decode_base.size(); i++)
		{
			if (decode_base[i].length() == input.length() and decode_base[i] == input) return 2;
			else if (decode_base[i].length() >= input.length())
			{
				bool k = 1;
				for (int j = 0; j < input.length(); j++) if (decode_base[i][j] != input[j]) k = 0;
				max_code = k;
			}
		}
		return max_code;
	}
	int get_priority()
	{
		return priority;
	}
	//id, количество аргументов слева, количество аргументов справа, приоритет, количество кодовых слов, кодовые слова
	Operator(id_lexemes id, int left_argue, int right_argue, int priority, int code_words, ...)
	{
		this->id = id;
		this->left_argue = left_argue;
		this->right_argue = right_argue;
		this->priority = priority;
		va_list list_of_words;
		va_start(list_of_words, code_words);
		for (int i = 0; i < code_words; i++)
		{
			char* a = va_arg(list_of_words, char*);
			std::string buffer;
			int j = 0;
			while (a[j] != 0) buffer.push_back(a[j++]);
			decode_base.push_back(buffer);
		}
		va_end(list_of_words);
	}
	Operator()
	{
		priority = -INFINITY;
	}
};
class Archieve
{
private:
	std::vector <Operator> base;

	std::vector <double(*)(std::vector <double>)> func;
	std::vector <bool(*)(std::vector <double>)> check_count;
public:
	Archieve()
	{
		base.resize(int(NUMBER_OPERATORS));
		func.resize(int(NUMBER_OPERATORS));
		check_count.resize(int(NUMBER_OPERATORS));
	}
	void add_operator(Operator A, double(*func)(std::vector <double>), bool(*check_count)(std::vector <double>))
	{
		int n = A.get_id();
		base[n] = A;
		this->func[n] = func;
		this->check_count[n] = check_count;
	}
	std::vector <int> decode(std::string input, std::vector <int> verif = std::vector <int>(0))
	{
		std::vector <int> answer;
		if (verif.empty() == 1)
		{
			for (int i = 0; i < NUMBER_OPERATORS; i++)
			{
				int check = base[i].is_it(input);
				if (check == 2)
				{
					answer.push_back(i);
				}
				else if (check == 1)
				{
					answer.push_back(-i);
				}
			}
		}
		else
		{
			for (int i = 0; i < verif.size(); i++)
			{
				int b = abs(verif[i]);
				int check = base[b].is_it(input);
				if (check == 2)
				{
					answer.push_back(b);
				}
				else if (check == 1)
				{
					answer.push_back(-b);
				}
			}
		}
		return answer;

	}
};
Sentence convert_to_lexemes(std::string input, id_errors& error, Archieve* archieve)
{
	Sentence answer;
	int pos = 0;
	int left_brs = 0;
	int right_brs = 0;
	while (pos < input.length())
	{
		if (input[pos] == ',')
		{
			answer.add_lexeme(Lexeme(COMMA));
			pos++;
		}
		else if (input[pos] == '(')
		{
			left_brs++;
			answer.add_lexeme(Lexeme(LEFT_BR));
			pos++;
		}
		else if (input[pos] == ')')
		{
			right_brs++;
			if (left_brs >= right_brs)
			{
				answer.add_lexeme(Lexeme(RIGHT_BR));
				pos++;
			}
			else
			{
				error = MORE_RIGHT_BRACKETS;
				return answer;
			}

		}
		else if (is_numeral(input[pos]) == 1)
		{
			std::string buffer;
			bool use_point = 0;
			while (pos < input.length() and (input[pos] == '.' or is_numeral(input[pos])))
			{
				if (input[pos] == '.')
				{
					if (use_point == 0)
					{
						use_point++;
						buffer.push_back(input[pos++]);
					}
					else
					{
						error = ERROR_SIGNS;
						return answer;
					}
				}
				else
				{
					buffer.push_back(input[pos++]);
				}
			}
			answer.add_lexeme(Lexeme(NUMBER, stof(buffer)));
		}
		else
		{
			std::string buffer;
			std::vector <int> a = { -1 };
			int max_id = -1;
			int pos_max = pos;
			while (a.empty() == 0 and pos < input.length())
			{
				buffer.push_back(input[pos++]);
				a = archieve->decode(buffer);
				for (int i = 0; i < a.size(); i++)
				{
					if (a[i] > 0)
					{
						max_id = a[i];
						pos_max = pos;
						break;
					}
				}
			}
			if (max_id == -1)
			{
				if (buffer == "x")
				{
					answer.add_lexeme(Lexeme(X));
				}
				else
				{
					error = UNKNOWN_FUNCTION;
					return answer;
				}
			}
			else
			{
				pos = pos_max;
				answer.add_lexeme(Lexeme((id_lexemes)max_id));
			}
		}
	}
	if (left_brs == right_brs)
	{
		return answer;
	}
	else
	{
		error = HAVE_OPEN_BRACKETS;
		return answer;
	}
}
int main()
{
	Archieve archieve;
	{
		Operator cur_op;
		int prior_func = 5;
		int prior_pow = 4;
		int prior_mult_div = 3;
		int prior_plus_minus = 2;
		cur_op = Operator(ABS, 0, 1, prior_func, 1, "abs");
		archieve.add_operator(cur_op, my_abs, always_true);
		cur_op = Operator(SIN, 0, 1, prior_func, 1, "sin");
		archieve.add_operator(cur_op, my_sin, always_true);
		cur_op = Operator(COS, 0, 1, prior_func, 1, "cos");
		archieve.add_operator(cur_op, my_cos, always_true);
		cur_op = Operator(TG, 0, 1, prior_func, 2, "tg", "tan");
		archieve.add_operator(cur_op, my_tg, check_tg);
		cur_op = Operator(CTG, 0, 1, prior_func, 3, "ctg", "cot", "cotan");
		archieve.add_operator(cur_op, my_ctg, check_ctg);
		cur_op = Operator(ARCSIN, 0, 1, prior_func, 1, "arcsin");
		archieve.add_operator(cur_op, my_arcsin, check_arcsin);
		cur_op = Operator(ARCCOS, 0, 1, prior_func, 1, "arccos");
		archieve.add_operator(cur_op, my_arccos, check_arcsin);
		cur_op = Operator(ARCTG, 0, 1, prior_func, 2, "arctg", "arctan");
		archieve.add_operator(cur_op, my_arctg, always_true);
		cur_op = Operator(ARCCTG, 0, 1, prior_func, 3, "arcctg", "arccot", "arccotan");
		archieve.add_operator(cur_op, my_arcctg, always_true);
		cur_op = Operator(EXP, 0, 1, prior_func, 1, "exp");
		archieve.add_operator(cur_op, my_exp, always_true);
		cur_op = Operator(LOG, 0, 2, prior_func, 1, "log");
		archieve.add_operator(cur_op, my_log, check_logarifm);
		cur_op = Operator(POW, 1, 1, prior_pow, 1, "^");
		archieve.add_operator(cur_op, my_pow, check_pow);
		cur_op = Operator(MULT, 1, 1, prior_mult_div, 1, "*");
		archieve.add_operator(cur_op, my_mult, always_true);
		cur_op = Operator(DIV, 1, 1, prior_mult_div, 1, "/");
		archieve.add_operator(cur_op, my_div, check_div);
		cur_op = Operator(PLUS, 1, 1, prior_plus_minus, 1, "+");
		archieve.add_operator(cur_op, my_plus, always_true);
		cur_op = Operator(MINUS, 1, 1, prior_plus_minus, 1, "-");
		archieve.add_operator(cur_op, my_minus, always_true);
	}
	std::string input;
	id_errors error = NON_ERROR;
	std::getline(std::cin, input);
	std::cout << "a";
	Sentence check = convert_to_lexemes(input, error, &archieve);
	std::cout << "a";

}

