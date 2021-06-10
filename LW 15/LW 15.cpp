#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdarg>
#include <Windows.h>

const double pi = 3.1415926535897932384626433832;

double go_to_base_trig_arg(double x);

double my_abs(double x);
double my_sin(double x);
double my_cos(double x);
double my_tg(double x);
double my_ctg(double x);
double my_arcsin(double x);
double my_arccos(double x);
double my_arctg(double x);
double my_arcctg(double x);
double my_exp(double x);
double my_ln(double x);
double my_log(double base, double x);
double my_factorial(int a);
double my_pow(double a, double b); //a^b
double my_mult(double a, double b);
double my_division(double a, double b);
double my_plus(double a, double b);
double my_minus(double a, double b);

bool always_true(double x);
bool check_tg(double x);
bool check_ctg(double x);
bool check_arcsin(double x);
bool check_ln(double x);
bool check_logarifm(double a, double b);
bool check_factorial(double x);
bool two_always_true(double a, double b);
bool check_pow(double a, double b);
bool check_division(double a, double b);


double go_to_base_trig_arg(double x)
{
    while (abs(x) > 2 * pi)
    {
        if (x > 0) x -= 2 * pi;
        else x += 2 * pi;
    }
    return x;
}

double my_abs(double x)
{
    return abs(x);
}
double my_sin(double x)
{
    x = go_to_base_trig_arg(x);
    const double eps = 0.0000000001;
    double element = x, sum = element;
    x = -x * x;
    double i = 3;
    while (abs(element) > eps)
    {
        element *= x / (i * (i - 1));
        sum += element;
        i += 2;
    }
    return sum;
}
double my_cos(double x)
{
    x = go_to_base_trig_arg(x);
    const double eps = 0.0000000001;
    double element = 1, sum = element;
    x = -x * x;
    double i = 2;
    while (abs(element) > eps)
    {
        element *= x / (i * (i - 1));
        sum += element;
        i += 2;
    }
    return sum;
}
double my_tg(double x)
{
    return my_sin(x) / my_cos(x);
}
double my_ctg(double x)
{
    const double eps = 0.0000000001;
    return my_cos(x) / my_sin(x);
}
double my_arcsin(double x)
{
    if (x == 1)
    {
        return pi / 2;
    }
    else if (x == -1)
    {
        return -pi / 2;
    }
    else if(abs(x) > 0.8)
    {
        return my_arctg(x / sqrt(1 - x * x));
    }
    else
    {
        const double eps = 0.0000000000000001;
        double element = x, sum = element;
        x = x * x;
        double i = 1;
        while (abs(element) > eps)
        {
            element *= x * (2 * i + 1) / ((2 * i + 2) * (2 * i + 3));
            sum += element;
            i++;
        }
        return sum;
    }
}
double my_arccos(double x)
{
    return pi / 2 - my_arcsin(x);
}
double my_arctg(double x)
{
    const double eps = 0.000001;
    if (abs(x) < 1)
    {
        double element = x, sum = element;
        double sqx = -x * x;
        int i = 2;
        while (abs(element) > eps)
        {
            element = element * sqx * (2 * i + 1) / (2 * i + 3);
            sum += element;
            i++;
        }
        return sum;
    }
    else
    {
        int i = 2;
        double element = -1/x, sum = (pi/2)*abs(x)/(x) + element;
        double sqx = -1/ (x * x);
        while (abs(element) > eps)
        {
            element = element * sqx * (2 * i - 1) / (2 * i + 1);
            sum += element;
            i++;
        }
        return sum;
    }
}
double my_arcctg(double x)
{
    return my_arctg(1/x);
}
double my_exp(double x)
{
    const double eps = 0.0000000001;
    double sum, element = 1;
    sum = element;
    int i = 1;
    while (abs(element) > eps)
    {
        element = element * x / i;
        sum += element;
        i++;
    }
    return sum;
}
double my_ln(double x)
{
    const double eps = 0.0000000001;
    if (x < 2)
    {
        double element = x - 1;
        double sum = element;
        double i = 2;
        while (abs(element) > eps)
        {
            element *= (1 - x) * (i - 1) / i;
            sum += element;
            i++;
        }
        return sum;
    }
    else if (x == 2) return 0.693147180559945309;
    else
    {
        double element = 1 / (x - 1);
        double sum = element;
        double i = 2;
        while (abs(element) > eps)
        {
            element *= -1 / (x - 1) * (i - 1) / i;
            sum += element;
            i++;
        }
        return sum + my_ln(x - 1);
    }
}
double my_log(double base, double x)
{
    return my_ln(x) / my_ln(base);
}
double my_factorial(int a)
{
    int answer = 1;
    for (a; a > 1; a--) answer *= a;
    return answer;
}
double my_pow(double a, double b)
{
    const double eps = 0.0000000001;
    if (b - trunc(b) == 0)
    {
        if (b == 0) return 1;
        else if (b > 0)
        {
            double answer = 1;
            for (; b > 0; b--)answer *= a;
            return answer;
        }
        else
        {
            double answer = 1;
            for (; b > 0; b--)answer /= a;
            return answer;
        }
    }
    else if (a > 0)
    {
        return my_exp(b * my_ln(a));
    }
}
double my_mult(double a, double b)
{
    return a * b;
}
double my_division(double a, double b)
{
    return a / b;
}
double my_plus(double a, double b)
{
    return a + b;
}
double my_minus(double a, double b)
{
    return a - b;
}

bool always_true(double x)
{
    return 1;
}
bool check_tg(double x)
{
    if (cos(x) == 0) return 0;
    else return 1;
}
bool check_ctg(double x)
{
    if (sin(x) == 0) return 0;
    else return 1;
}
bool check_arcsin(double x)
{
    if (abs(x) <= 1) return 1;
    else return 0;
}
bool check_ln(double x)
{
    if (x > 0) return 1;
    else return 0;
}
bool check_logarifm(double a, double b)
{
    if (a > 0 and a != 1 and b > 0) return 1;
    else return 0;
}
bool check_factorial(double x)
{
    if (x > 0 and x - trunc(x) == 0) return 1;
    else return 0;
}
bool two_always_true(double a, double b)
{
    return 1;
}
bool check_pow(double a, double b)
{
    if (a > 0) return 1;
    else
    {
        if (b - trunc(b) == 0)
        {
            if (a != 0 or b >= 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool check_division(double a, double b)
{
    if (b == 0) return 0;
    else return 1;
}

enum id_lexemes
{
    //пре-унарные операторы, высший приоритет
    ABS, SIN, COS, TG, CTG, ARCSIN, ARCCOS, ARCTG, ARCCTG, EXP, LN, 
    //псевдо пре-унарный оператор
    LOG,
    //пост-унарные операторы, приоритет: 2
    FACTORIAL,
    //бинарные операторы, приоритет: 3
    POW,
    //бинарные операторы, приоритет: 4
    MULT, DIVISION,
    //бинарные операторы, низший приоритет
    PLUS, MINUS,
    //требуется для определения числа операторов
    NUMBER_OPERATORS,
    //технические вещи
    NUMBER, X, LEFT_BR, RIGHT_BR, COMMA, END
};
enum errors
{
    NON_ERROR, UNKNOWN_SYMBOL, UNKNOWN_FUNCTION, ERROR_SIGNS, REDUNDANT_SIGNS, IMPOSSIBLE_COUNT
};
class Lexeme
{
private:
    id_lexemes id;
    double value;
    int priority;
public:
    Lexeme(id_lexemes id, int priority = -99, double value = 0)
    {
        this->id = id;
        this->priority = priority;
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
    int get_priority()
    {
        return priority;
    }
};
class Sentence
{
private:
    int pos = 0;
    std::vector <Lexeme> array;
    std::vector <int> stat;
    std::vector <int> stat_priority;
public:
    Sentence()
    {
        stat.resize(24);
    };
    Sentence(std::vector <Lexeme> array)
    {
        stat.resize(24);
        for (int i = 0; i < array.size(); i++) add_lexeme(array[i]);
    }
    //возвращает количество лексем определённого вида
    int get_stat(id_lexemes i)
    {
        return stat[i];
    }
    //получить сумму видов лексем с id лежащими внутри (a,b)
    int get_stat(id_lexemes a, id_lexemes b)
    {
        int answer = 0;
        for (int i = a; i <= b; i++)
        {
            answer += stat[i];
        }
        return answer;
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
        stat[a.get_id()]++;
        int n = a.get_priority();
        if (stat_priority.size() > n) stat_priority[n]++;
        else {
            stat_priority.resize(n + 1);
            stat_priority[n]++;
        }
    }
    //удалить лексему с таким номером
    void delete_lexeme(int i)
    {
        stat[array[i].get_id()]--;
        if (pos >= i and pos != 0) pos--; //сейвим местоположение
        array.erase(array.begin() + i);
    }
    //заменить лексему x на значение
    void substitute(double x)
    {
        if (stat[X] > 0)
        {
            for (int i = 0; i < array.size(); i++)
            {
                if (array[i].get_id() == X)
                {
                    array[i] = Lexeme(NUMBER, x);
                }
            }
            stat[NUMBER] += stat[X];
            stat[X] = 0;
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
        stat[array[a].get_id()]--;
        array[a] = paste;
        stat[paste.get_id()]++;
    }
    int find_highest_comma(errors& error)
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
            if (POW <= array[i].get_id() and array[i].get_id() <= MINUS and POW <= array[i + 1].get_id() and array[i+1].get_id() <= MINUS)
            {
                return 0;
            }
        }
        return 1;
    }
    //найти лексему с определённым id
    int find_id_lexeme(id_lexemes id)
    {
        if (stat[id] > 0)
        {
            for (int i = 0; i < array.size(); i++)
            {
                if (array[i].get_id() == LEFT_BR)
                {
                    return i;
                }
            }
        }
        else return -1;
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
    Lexeme count(errors& error, std::vector<void*>& functions, std::vector<void*>& check_countable)
    {
        Lexeme Answer = Lexeme(NUMBER);
        //избавляемся от скобок
        pos = 0;
        while (stat[LEFT_BR] > 0 and array[pos].get_id() != END)
        {
            if (array[pos].get_id() == LEFT_BR)
            {
                int a = pos;
                int b = find_right_bracket(a);
                if (pos == 0 or array[pos-1].get_id() != LOG)
                {
                    Sentence temp = create_lexeme_vector(a+1, b-1);
                    Lexeme temp2 = temp.count(error, functions, check_countable);
                    replace_sector(a, b, temp2);
                    if (error != NON_ERROR)
                    {
                        return Answer;
                    }
                }
                else
                {
                    Sentence temp = create_lexeme_vector(a + 1, b - 1);
                    int border = temp.find_highest_comma(error);
                    if (error == 0)
                    {
                        replace_sector(a + 1, a + border, create_lexeme_vector(a + 1, a + border).count(error,functions, check_countable));
                        replace_sector(a + border + 2, b - 1, create_lexeme_vector(a + border + 2, b - 1).count(error,functions, check_countable));
                    }
                    else
                    {
                        return Answer;
                    }
                }
            }
            pos++;
        }
        //избавляемся от функций
        pos = 0;
        while (get_stat(ABS, LN) > 0 and array[pos].get_id() != END)
        {
            if (ABS <= array[pos].get_id() and array[pos].get_id() <= LN and array[pos+1].get_id() == NUMBER)
            {
                double arguement = array[pos+1].get_value();
                double value;
                if (reinterpret_cast<bool(*)(double)>(check_countable[array[pos].get_id()])(arguement) == 1)
                {
                    value = reinterpret_cast<double(*)(double)>(functions[array[pos].get_id()])(arguement);
                    replace_sector(pos, pos + 1, Lexeme(NUMBER, value));
                    //возвращемся назад, возможно мы сможем что-то ещё посчитать
                    if (pos > 0) pos--;
                }
                else
                {
                    error = IMPOSSIBLE_COUNT;
                    return Answer;
                }
            }
            else if (array[pos].get_id() == LOG)
            {
                double a = array[pos + 2].get_value();
                double b = array[pos + 4].get_value();
                if (reinterpret_cast<bool(*)(double, double)>(check_countable[array[pos].get_id()])(a, b) == 1)
                {
                    double value = reinterpret_cast<double(*)(double, double)>(functions[array[pos].get_id()])(a, b);
                    replace_sector(pos, pos + 6, Lexeme(NUMBER, value));
                    //возвращемся назад, возможно мы сможем что-то ещё посчитать
                    if (pos > 0) pos--;
                }
            }
            else pos++;
        }
        //избавляемся от факториалов
        pos = 0;
        while (get_stat(FACTORIAL) > 0 and array[pos].get_id() != END)
        {
            if (array[pos].get_id() == NUMBER and array[pos+1].get_id() == FACTORIAL)
            {
                double arguement = array[pos].get_value();
                if (reinterpret_cast<bool(*)(double)>(check_countable[array[pos+1].get_id()])(arguement) == 1)
                {
                    double value = reinterpret_cast<double(*)(double)>(functions[array[pos+1].get_id()])(arguement);
                    replace_sector(pos, pos + 1, Lexeme(NUMBER, value));
                    //возвращаемся назад
                    pos = 0;
                }
                else
                {
                    error = IMPOSSIBLE_COUNT;
                    return Answer;
                }
            }
            else pos++;
        }
        //избавляемся от возведения в степень
        pos = 1;
        while (get_stat(POW) > 0 and array[pos].get_id() != END)
        {
            if (pos > 0 and array[pos-1].get_id() == NUMBER and array[pos].get_id() == POW and array[pos+1].get_id() == NUMBER)
            {
                double a = array[pos-1].get_value();
                double b = array[pos+1].get_value();
                if (reinterpret_cast<bool(*)(double, double)>(check_countable[array[pos].get_id()])(a, b) == 1)
                {
                    double value = reinterpret_cast<double(*)(double, double)>(functions[array[pos].get_id()])(a, b);
                    replace_sector(pos - 1, pos + 1, Lexeme(NUMBER, value));
                    //возвращемся назад, возможно мы сможем что-то ещё посчитать
                    pos = 1;
                }
            }
            else pos++;
        }
        //избавляемся от умножения и деления
        pos = 1;
        while (get_stat(MULT, DIVISION) > 0 and array[pos].get_id() != END)
        {
            if (pos > 0 and array[pos-1].get_id() == NUMBER and (array[pos].get_id() == MULT or array[pos].get_id() == DIVISION) and array[pos+1].get_id() == NUMBER)
            {
                double a = array[pos-1].get_value();
                double b = array[pos+1].get_value();
                if (reinterpret_cast<bool(*)(double, double)>(check_countable[array[pos].get_id()])(a, b) == 1)
                {
                    double value = reinterpret_cast<double(*)(double, double)>(functions[array[pos].get_id()])(a, b);
                    replace_sector(pos-1, pos + 1, Lexeme(NUMBER, value));
                    //возвращемся назад, возможно мы сможем что-то ещё посчитать
                    pos = 1;
                }
            }
            else pos++;
        }
        //избавляемся от сложения и вычитания
        pos = 1;
        while (get_stat(PLUS, MINUS) > 0 and array[pos].get_id() != END)
        {
            if (pos > 0 and array[pos-1].get_id() == NUMBER and (array[pos].get_id() == PLUS or array[pos].get_id() == MINUS) and array[pos+1].get_id() == NUMBER)
            {
                double a = array[pos-1].get_value();
                double b = array[pos+1].get_value();
                if (reinterpret_cast<bool(*)(double, double)>(check_countable[array[pos].get_id()])(a, b) == 1)
                {
                    double value = reinterpret_cast<double(*)(double, double)>(functions[array[pos].get_id()])(a, b);
                    replace_sector(pos - 1, pos + 1, Lexeme(NUMBER, value));
                    //возвращемся назад, возможно мы сможем что-то ещё посчитать
                    if (pos > 0) pos--;
                }
            }
            else pos++;
        }
        pos = 0;
        Answer = array[pos];
        return Answer;
    }
};
class Operator
{
private:
    id_lexemes id;
    bool binare;
    bool post;
    unsigned int argue;
    int priority;
    std::vector <std::string> decode_base;
public:
    int get_id()
    {
        return (int)id;
    }
    bool is_it(std::string input)
    {
        for (int i = 0; i < decode_base.size(); i++)
        {
            if (decode_base[i] == input) return 1;
        }
        return 0;
    }
    int get_priority()
    {
        return priority;
    }
    int get_argue()
    {
        return argue;
    }
    bool get_binare()
    {
        return binare;
    }
    bool get_post()
    {
        return post;
    }
    Operator(bool sign, bool binare, bool post, unsigned int argue, bool priority, int code_words, ...)
    {
        this->sign = sign;
        this->post = post;
        this->argue = argue;
        this->priority = priority;
        va_list list_of_words;
        va_start(list_of_words, code_words);
        for (int i = 0; i < code_words; i++)
        {
            decode_base.push_back(va_arg(list_of_words, std::string));
        }
        va_end(list_of_words);
    }
};

class Archieve
{
private:
    std::vector <Operator> base;
    std::vector <void*> func;
    std::vector <void*> check_count;
public:
    Archieve()
    {
        base.resize(int(NUMBER_OPERATORS));
        func.resize(int(NUMBER_OPERATORS));
        check_count.resize(int(NUMBER_OPERATORS));
    }
    void add_operator(Operator A, void* func, void* check_count)
    {
        int n = A.get_id();
        base[n] = A;
        this->func[n] = func;
        this->check_count[n] = check_count;
    }
    std::vector <int> decode(std::string input, int& error)
    {
        for (int i = 0; i < NUMBER_OPERATORS; i++)
        {
            if (base[i].is_it(input))
            {
                
            }
        }
        error = UNKNOWN_FUNCTION;
    }
};

Sentence convert_to_lexemes(std::string input, errors& error)
{
    Sentence answer;
    int pos = 0;
    while (pos < input.length())
    {
        if (answer.get_stat(LEFT_BR) >= answer.get_stat(RIGHT_BR))
        {
            while (pos < input.length() and input[pos] == ' ') pos++;
            if (input[pos] == '+')
            {
                answer.add_lexeme(Lexeme(PLUS));
                pos++;
            }
            else if (input[pos] == '-')
            {
                answer.add_lexeme(Lexeme(MINUS));
                pos++;
            }
            else if (input[pos] == '*')
            {
                answer.add_lexeme(Lexeme(MULT));
                pos++;
            }
            else if (input[pos] == '/')
            {
                answer.add_lexeme(Lexeme(DIVISION));
                pos++;
            }
            else if (input[pos] == '^')
            {
                answer.add_lexeme(Lexeme(POW));
                pos++;
            }
            else if (input[pos] == '!')
            {
                answer.add_lexeme(Lexeme(FACTORIAL));
                pos++;
            }
            else if (input[pos] == '(')
            {
                answer.add_lexeme(Lexeme(LEFT_BR));
                pos++;
            }
            else if (input[pos] == ')')
            {
                answer.add_lexeme(Lexeme(RIGHT_BR));
                pos++;
            }
            else if (input[pos] == ',')
            {
                answer.add_lexeme(Lexeme(RIGHT_BR));
                pos++;
            }
            else if ('0' <= input[pos] and input[pos] <= '9')
            {
                std::string buffer;
                bool use_point = 0;
                while (pos < input.length() and (input[pos] == '.' or ('0' <= input[pos] and input[pos] <= '9')))
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
                while (pos < input.length() and 'a' <= input[pos] and input[pos] <= 'z' or pos < input.length() and 'A' <= input[pos] and input[pos] <= 'Z')
                {
                    buffer.push_back(input[pos++]);
                }
                if (buffer == "abs")
                {
                    answer.add_lexeme(Lexeme(ABS));
                }
                else if (buffer == "sin")
                {
                    answer.add_lexeme(Lexeme(SIN));
                }
                else if (buffer == "cos")
                {
                    answer.add_lexeme(Lexeme(COS));
                }
                else if (buffer == "tg" or buffer == "tan")
                {
                    answer.add_lexeme(Lexeme(TG));
                }
                else if (buffer == "ctg" or buffer == "cot")
                {
                    answer.add_lexeme(Lexeme(CTG));
                }
                else if (buffer == "arcsin")
                {
                    answer.add_lexeme(Lexeme(ARCSIN));
                }
                else if (buffer == "arccos")
                {
                    answer.add_lexeme(Lexeme(ARCCOS));
                }
                else if (buffer == "arctg" or buffer == "arctan")
                {
                    answer.add_lexeme(Lexeme(ARCTG));
                }
                else if (buffer == "arcctg" or buffer == "arccot")
                {
                    answer.add_lexeme(Lexeme(ARCCTG));
                }
                else if (buffer == "log")
                {
                    answer.add_lexeme(Lexeme(LOG));
                }
                else if (buffer == "ln")
                {
                    answer.add_lexeme(Lexeme(LN));
                }
                else if (buffer == "exp" or buffer == "e")
                {
                    answer.add_lexeme(Lexeme(EXP));
                }
                else if (buffer == "x" or buffer == "X")
                {
                    answer.add_lexeme(Lexeme(X));
                }
                else
                {
                    error = UNKNOWN_FUNCTION;
                    return answer;
                }
            }
        }
        else
        {
            error = UNKNOWN_SYMBOL;
            return answer;
        }
    }
    answer.add_lexeme(Lexeme(END));
    if (answer.get_stat(LEFT_BR) == answer.get_stat(RIGHT_BR) and answer.is_correct() == 1)
    {
        return answer;
    }
    else
    {
        error = ERROR_SIGNS;
        return answer;
    }
}

Sentence new_convert_to_lexemes(std::string input, errors& error, Archieve* archieve)
{
    Sentence answer;
    int pos = 0;
    while (pos < input.length())
    {
        std::string buffer;
        
    }
    answer.add_lexeme(Lexeme(END));
    if (answer.get_stat(LEFT_BR) == answer.get_stat(RIGHT_BR) and answer.is_correct() == 1)
    {
        return answer;
    }
    else
    {
        error = ERROR_SIGNS;
        return answer;
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    errors error = NON_ERROR;
    double x;
    std::vector<void*> functions;
    {
        functions.push_back(reinterpret_cast<void*>(my_abs));
        functions.push_back(reinterpret_cast<void*>(my_sin));
        functions.push_back(reinterpret_cast<void*>(my_cos));
        functions.push_back(reinterpret_cast<void*>(my_tg));
        functions.push_back(reinterpret_cast<void*>(my_ctg));
        functions.push_back(reinterpret_cast<void*>(my_arcsin));
        functions.push_back(reinterpret_cast<void*>(my_arccos));
        functions.push_back(reinterpret_cast<void*>(my_arctg));
        functions.push_back(reinterpret_cast<void*>(my_arcctg));
        functions.push_back(reinterpret_cast<void*>(my_exp));
        functions.push_back(reinterpret_cast<void*>(my_ln));
        functions.push_back(reinterpret_cast<void*>(my_log));
        functions.push_back(reinterpret_cast<void*>(my_factorial));
        functions.push_back(reinterpret_cast<void*>(my_pow));
        functions.push_back(reinterpret_cast<void*>(my_mult));
        functions.push_back(reinterpret_cast<void*>(my_division));
        functions.push_back(reinterpret_cast<void*>(my_plus));
        functions.push_back(reinterpret_cast<void*>(my_minus));    
    }
    std::vector<void*> check_countable;
    {
        for (int i = 0; i < 3; i++) check_countable.push_back(reinterpret_cast<void*>(always_true));
        check_countable.push_back(reinterpret_cast<void*>(check_tg));
        check_countable.push_back(reinterpret_cast<void*>(check_ctg));
        check_countable.push_back(reinterpret_cast<void*>(check_arcsin));
        check_countable.push_back(reinterpret_cast<void*>(check_arcsin));
        for (int i = 0; i < 3; i++) check_countable.push_back(reinterpret_cast<void*>(always_true));
        check_countable.push_back(reinterpret_cast<void*>(check_ln));
        check_countable.push_back(reinterpret_cast<void*>(check_logarifm));
        check_countable.push_back(reinterpret_cast<void*>(check_factorial));
        check_countable.push_back(reinterpret_cast<void*>(check_pow));
        check_countable.push_back(reinterpret_cast<void*>(two_always_true));
        check_countable.push_back(reinterpret_cast<void*>(check_division));
        check_countable.push_back(reinterpret_cast<void*>(always_true));
        check_countable.push_back(reinterpret_cast<void*>(always_true));
    }
    std::string buffer;
    std::getline(std::cin, buffer);
    std::cin >> x;
    for (double i = 0; i <= 200; i++) std::cout << i << " " << abs(my_arcsin(-1 + i / 100) - std::asin(-1 + i / 100)) << std::endl;
    Sentence Base = convert_to_lexemes(buffer, error);
    Sentence Current = Base;
    Current.substitute(x);
    Lexeme Test = Current.count(error, functions, check_countable);
    if (error == NON_ERROR)
    {
        std::cout << "Значение в точке " << x << " равно: " << Test.get_value() << std::endl;
    }
    else if (error == UNKNOWN_SYMBOL)
    {
        std::cout << "В вводе допущена ошибка." << std::endl;
    }
    else if (error == UNKNOWN_FUNCTION)
    {
        std::cout << "Использована неизвестная функция" << std::endl;
    }
    else if (error == ERROR_SIGNS)
    {
        std::cout << "В знаках операций допущена ошибка." << std::endl;
    }
    else if (error == REDUNDANT_SIGNS)
    {
        std::cout << "Знаки операций использованы избытычно." << std::endl;
    }
    else if (error == IMPOSSIBLE_COUNT)
    {
        std::cout << "Функцию невозможно вычислить в точке " << x << std::endl;
    }

}

