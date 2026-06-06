#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
    double num1;
    double num2;
    char oper;
    double result;
} operation;

operation stringToOper(string input);
double converter(string input);
vector<string> splitString(string input, char spliter);
long long power(int base, int exp);
bool validatorOperation(char input);
bool validatorNumber(char input);

/*
Restrictions:
only one operator
works only positive values
works only with integer values
 */
int main()
{
    string input;
    vector<operation> history;

    cout << "Welcome to the calculator app!\n";

    do
    {
        cin >> input;
        if (input[0] == 'h')
        {
            for (const operation o : history)
            {
                cout << "history: " << o.num1 << o.oper << o.num2 << " = " << o.result << endl;
            }
        }
        else if (input[0] != 'q')
        {
            operation op = stringToOper(input);
            cout << op.num1 << endl;
            cout << op.oper << endl; // + or - or * or /
            cout << op.num2 << endl;
            switch (op.oper)
            {
            case '+':
                op.result = op.num1 + op.num2;
                break;
            case '-':
                op.result = op.num1 - op.num2;
                break;
            case '*':
                op.result = op.num1 * op.num2;
                break;
            case '/':
                op.result = op.num1 / op.num2;
                break;
            case '^':
                op.result = power(op.num1, op.num2);
                break;
            default:
                cout << "invalid operation" << endl;
                break;
            }
            cout << "result: " << op.result << endl;
            history.push_back(op);
        }
    } while (input[0] != 'q');
    cout << "closing the program" << endl;
}

operation stringToOper(string input)
{
    operation op;
    string numb1 = "";
    string numb2 = "";
    bool flagSecondNumber = false;
    for (int i = 0; i < input.size(); i++)
    {
        if (validatorOperation(input[i]))
        {
            op.oper = input[i];
            flagSecondNumber = true;
        }
        if (validatorNumber(input[i]))
        {
            if (flagSecondNumber)
            {
                numb2 += input[i];
            }
            else
            {
                numb1 += input[i];
            }
        }
    }

    op.num1 = converter(numb1);
    op.num2 = converter(numb2);

    return op;
}

double converter(string input) // 123.12
{
    double value = 0;
    vector<string> splitedString = splitString(input, '.');
    string integerPart = splitedString[0];
    for (int i = 0; i < integerPart.size(); i++)
    {
        value += (integerPart[i] - '0') * power(10, integerPart.size() - i - 1); // '123' -> 1 * 100 + 2 * 10 + 3 * 1
        // '123' -> 1 * 10 ^ 2 + 2 * 10 ^ 1  + 3 * 10 ^ 0
    }

    if (splitedString.size() >= 2)
    {
        string decimalPart = splitedString[1];
        for (int i = 0; i < decimalPart.size(); i++)
        {
            value += (decimalPart[i] - '0') * power(10, -i - 1); 
        }
    }
    return value;
}

vector<string> splitString(string input, char spliter)
{
    vector<string> result;
    string aux = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == spliter)
        {
            result.push_back(aux);
            aux = "";
        }
        else
        {
            aux += input[i];
        }
    }
    result.push_back(aux);
    return result;
}

long long power(int base, int exp)
{
    long long result = 1;
    if (exp == 0)
    {
        return 1;
    }
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

bool validatorOperation(char input)
{
    return input == '+' || input == '-' || input == '*' || input == '/' || input == '^';
}

bool validatorNumber(char input)
{
    return input >= '0' && input <= '9';
}

// 754.96
/*

7 * 10 ^ 2 = 700
5 * 10 ^ 1 = 50
4 * 10 ^ 0 = 4
9 * 10 ^ -1 = 0.9
6 * 10^ -2 = 0.06

700 + 50 + 4 + 0.9 + 0.06
*/