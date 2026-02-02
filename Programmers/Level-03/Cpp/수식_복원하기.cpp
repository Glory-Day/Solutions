#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

struct Expression 
{
    int a, b, c;
    char op;
    bool unknown;
    string original;
};

inline int get_maximum_digit(const string& number) 
{
    int result = 0;
    for (char c : number) 
    {
        if (isdigit(c)) 
        {
            result = max(result, c - '0');
        }
    }

    return result;
}

int to_decimal(int number, int base) 
{
    int result = 0;
    int multiplier = 1;
    while (number > 0) 
    {
        result += (number % 10) * multiplier;
        number /= 10;

        multiplier *= base;
    }

    return result;
}

string to_base(int number, int base) 
{
    if (number == 0)
    {
        return "0";
    }

    string result = "";
    while (number > 0) 
    {
        result = char('0' + number % base) + result;
        number /= base;
    }

    return result;
}

bool is_valid(int number, int base) 
{
    while (number > 0) 
    {
        if (number % 10 >= base)
        {
            return false;
        }

        number /= 10;
    }

    return true;
}

vector<string> solution(vector<string> expressions) 
{
    vector<string> answer;

    vector<Expression> caches;
    int min = 2;

    for (const string& expression: expressions) 
    {
        istringstream stream(expression);
        string a, op, b, eq, c;
        stream >> a >> op >> b >> eq >> c;
        
        Expression cache;
        cache.a = stoi(a);
        cache.op = op[0];
        cache.b = stoi(b);
        cache.unknown = (c == "X");
        cache.c = cache.unknown ? 0 : stoi(c);
        cache.original = expression;
        
        caches.push_back(cache);
        
        min = max(min, get_maximum_digit(a) + 1);
        min = max(min, get_maximum_digit(b) + 1);
        if (cache.unknown == false) 
        {
            min = max(min, get_maximum_digit(c) + 1);
        }
    }
    
    set<int> candidates;
    for (int base = min; base <= 9; base++) 
    {
        candidates.insert(base);
    }
    
    for (const Expression& cache: caches) 
    {
        if (cache.unknown) continue;
        
        set<int> bases;
        for (int base : candidates) 
        {
            if (is_valid(cache.a, base) == false || is_valid(cache.b, base) == false || is_valid(cache.c, base) == false)
            {
                continue;
            }
            
            int a = to_decimal(cache.a, base);
            int b = to_decimal(cache.b, base);
            int c = to_decimal(cache.c, base);
            
            int result = (cache.op == '+') ? (a + b) : (a - b);
            if (result == c)
            {
                bases.insert(base);
            }
        }
        
        candidates = bases;
    }
    
    for (const Expression& cache : caches) 
    {
        if (cache.unknown == false)
        {
            continue;
        }
        
        set<string> results;
        for (int base : candidates) 
        {
            if (is_valid(cache.a, base) == false || is_valid(cache.b, base) == false)
            {
                continue;
            }
            
            int a = to_decimal(cache.a, base);
            int b = to_decimal(cache.b, base);
            int result = (cache.op == '+') ? (a + b) : (a - b);
            
            if (result < 0)
            {
                continue;
            }
            
            results.insert(to_base(result, base));
        }

        string y = (int)results.size() == 1 ? *results.begin() : "?";
        string expression = to_string(cache.a) + " " + cache.op + " " + to_string(cache.b) + " = " + y;
        answer.push_back(expression);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> expressions;
    for (int i = 0; i < n; i++)
    {
        vector<string> expression(5);
        cin >> expression[0] >> expression[1] >> expression[2] >> expression[3] >> expression[4];

        expressions.push_back(expression[0] + " " + expression[1] + " " + expression[2] + " " + expression[3] + " " + expression[4]);
    }

    vector<string> answer = solution(expressions);

    for (const auto& i: answer)
    {
        cout << i << '\n';
    }

    return 0;
}