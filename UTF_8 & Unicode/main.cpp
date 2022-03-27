#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cmath>

using namespace std;

string HEX(int number)
{
    int temp, limit = 4;
    char hex[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char hexCode[8];

    if (number > 65535)
        limit = 8;

    for (int i = 0; i < limit; i++)
    {
        temp = number & 0b00001111;
        number = number >> 4;
        hexCode[limit - i - 1] = hex[temp];
    }
    string convertedCode = "";
    for (int i = 0; i < limit; i++)
    {
        convertedCode += hexCode[i];
    }
    return convertedCode;
}
string UTF(int number)
{
    if (number <= 127)
    {
        number = number | 0b00000000;
        return HEX(number);
    }
    else if (number <= 2047)
    {
        int temp = number & 0b00111111;
        string t1[3], rezult = "";
        temp = temp | 0b10000000;
        number = number >> 6;

        t1[0] = HEX(temp);

        temp = number & 0b00011111;
        temp = temp | 0b11000000;
        t1[1] = HEX(temp);

        for (int i = 1; i >= 0; i--)
        {
            rezult += t1[i][2];
            rezult += t1[i][3];
        }
        return rezult;
    }
    else if (number <= 65535)
    {
        int temp;
        string t1[3], rezult;
        for (int i = 0; i < 2; i++)
        {
            temp = number & 0b00111111;
            temp = temp | 0b10000000;
            number = number >> 6;
            t1[i] = HEX(temp);
        }
        temp = number & 0b00001111;
        temp = temp | 0b11100000;
        t1[2] = HEX(temp);

        for (int i = 2; i >= 0; i--)
        {
            rezult += t1[i][2];
            rezult += t1[i][3];
        }
        return rezult;
    }
    else if (number <= 1114111)
    {

        int temp;
        string t1[4], rezult;
        for (int i = 0; i < 3; i++)
        {
            temp = number & 0b00111111;
            temp = temp | 0b10000000;
            number = number >> 6;
            t1[i] = HEX(temp);
        }
        temp = number & 0b00000111;
        temp = temp | 0b11110000;
        t1[3] = HEX(temp);

        for (int i = 3; i >= 0; i--)
        {
            rezult += t1[i][2];
            rezult += t1[i][3];
        }
        return rezult;
    }
}
int DEC(string number)
{
    map<char, int> HexTable = {{'0', 0},
                               {'1', 1},
                               {'2', 2},
                               {'3', 3},
                               {'4', 4},
                               {'5', 5},
                               {'6', 6},
                               {'7', 7},
                               {'8', 8},
                               {'9', 9},
                               {'A', 10},
                               {'B', 11},
                               {'C', 12},
                               {'D', 13},
                               {'E', 14},
                               {'F', 15}};
    int temp = 0;

    if (number.size() == 1)
    {
        temp = HexTable[number[0]];
    }
    else
    {
        for (int i = 0; i < number.size(); i++)
        {
            temp += HexTable[number[number.size() - i - 1]] * pow(16, i);
        }
    }
    return temp;
}
void UTFSymbol(char a[], string t)
{
    int letterSize = 0;

    for (int i = 0; i < t.size(); i += 2)
    {
        string temp = "";
        temp = t[i];
        temp += t[i + 1];
        if (temp != "00")
        {
            a[letterSize] = DEC(temp);
            letterSize++;
        }
    }
    a[letterSize] = 0;
    return;
}
void readCPFile(map<int, string> &a, string fileName)
{
    ifstream data(fileName);

    int temp1;
    string temp2;
    while (!data.eof())
    {
        data >> temp1 >> temp2;
        a[temp1] = temp2;
    }
    data.close();
}

int main(int argv, char **argc)
{
    if (argv > 2)
    {
        //------------------------------ANTRA DALIS
        map<int, string> ascii;
        readCPFile(ascii, argc[3]);

        FILE *file;
        file = fopen(argc[1], "r");
        ofstream dataToFile(argc[2]);

        char final[10]; /// 4
        int temp = 0;
        unsigned char testukas;

        while (!feof(file))
        {
            testukas = fgetc(file);
            temp = int(testukas);
            if (temp > 127 && temp < 255)
            {
                UTFSymbol(final, UTF(DEC(ascii[temp])));
                dataToFile << (char *) final;
            }
            else
            {
                if (temp == 7 || temp == 16 || temp == 17 || temp == 27 || temp == 30 || temp == 31)
                    dataToFile << " ";
                else if (temp == 255)
                    dataToFile << "";
                else
                    dataToFile << testukas;
            }
        }
        fclose(file);
        dataToFile.close();
        //------------------------------ANTROS DALIES PABAIGA
    }
    else if (argv == 2)
    {
        //------------------------------PIRMA DALIS
        int number = stoi(argc[1]);

        string test = UTF(number);
        char utfSymbol[10];
        UTFSymbol(utfSymbol, test);

        cout << "UNICODE: U+" << HEX(number) << '\n';
        cout << "UTF-8: " << test << '\n';
        cout << "CHAR: " << (char *)utfSymbol;

        ofstream data("symbol.txt");

        data << (char *)utfSymbol;
        data.close();
    }
    else
    {
        cout << "No arguments were found";
    }
    return 0;
}