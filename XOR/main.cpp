#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int XOR1(int a, int b)
{
    return ((~a & b) | (a & ~b));
}
int XOR2(int a, int b)
{
    return ((a | b) & ~(a & b));
}
int XOR3(int a, int b)
{
    return ((a | b) & (~a | ~b));
}
int XOR4(int a, int b)
{
    int temp = ~(a & b);
    return ~(~(temp & b) & ~(temp & a));
}

void add(int a, int &sum)
{
    int c = 0;
    while (sum > 0)
    {
        c = a & sum;
        a = XOR1(a, sum);
        sum = c << 1;
    }

    if (sum == 0)
        sum = a;

    return;
}
int main(int argv, char **argc)
{
    if (argv < 3)
    {
        cout << "No arguments";
        return 0;
    }
    else if (argv > 3)
        cout << "Gave more arguments than needed\n";

    int a = stoi(argc[1]), b = stoi(argc[2]);

    ofstream dataToCSV("rez.csv", ios::trunc);
    dataToCSV.clear();

    // XOR
    cout << "XOR-1: " << XOR1(a, b) << '\n';
    cout << "XOR-2: " << XOR2(a, b) << '\n';
    cout << "XOR-3: " << XOR3(a, b) << '\n';
    cout << "XOR-4: " << XOR4(a, b) << '\n';

    char s = ',';
    dataToCSV << s << s << s << s << "XOR-1:" << s << "XOR-2:" << s << "XOR-3:" << s << "XOR-4: \n";
    dataToCSV << a << s << '^' << s << b << s << '=' << s << XOR1(a, b) << s << XOR2(a, b) << s << XOR3(a, b) << s << XOR4(a, b) << "\n\n\nSandauga\n";
    dataToCSV << a << s << '*' << s << b << s << '=' << s;

    // sandauga
    int sum = 0, safeA = a, safeB = b;
    while (b > 0)
    {
        if (b & 0b1 == 1)
            add(a, sum);

        b >>= 1;
        a <<= 1;
    }
    cout << safeA << " * " << safeB << " = " << sum;
    dataToCSV << sum;
    dataToCSV.close();

    return 0;
}
