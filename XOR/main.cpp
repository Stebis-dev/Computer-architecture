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
    int c;
    while (sum != 0)
    {
        c = a & sum;
        a = XOR1(a, sum);
        sum = c << 1;
        cout << a << " " << sum << " " << c << endl;
    }

    if (sum == 0)
    {
        sum = a;
    }
}
int main(int argv, char **argc)
{
    if (argv < 3)
    {
        cout << "No arguments";
        return 0;
    }
    int a = stoi(argc[1]), b = stoi(argc[2]);

    ofstream dataToCSV("rez.csv", ios::trunc);
    dataToCSV.clear();

    // XOR
    cout << "XOR-1: " << XOR1(a, b) << '\n';
    cout << "XOR-2: " << XOR2(a, b) << '\n';
    cout << "XOR-3: " << XOR3(a, b) << '\n';
    cout << "XOR-4: " << XOR4(a, b) << '\n';

    dataToCSV << ";;;;XOR-1: ;XOR-2: ;XOR-3: ;XOR-4: \n";
    dataToCSV << a << ";^;" << b << ";=;" << XOR1(a, b) << ';' << XOR2(a, b) << ';' << XOR3(a, b) << ';' << XOR4(a, b) << "\n\n\nSandauga\n";
    dataToCSV << a << ";*;" << b << ";=;";
    // sandauga
    int sum = 0;
    while (b > 0)
    {
        if (b & 0b1 == 1)
        {
            add(a, sum);
        }
        b >>= 1;
        a <<= 1;
    }
    cout << sum;
    dataToCSV << sum;
    dataToCSV.close();

    return 0;
}
