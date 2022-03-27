#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <string>

using namespace std;

// 0 A A r 1
struct ruleGroup
{
    string currentState;
    char currentSymbol;
    char newSymbol;
    char direction;
    string newState;
};

string print(int index, string line);

string getDataFromFile(string fileName, int &startingIndex, vector<ruleGroup> &rule);

void printFileData(string line, int startingIndex, vector<ruleGroup> rule);

int main(int argc, char **argv)
{
    vector<ruleGroup> rule;
    int startingLineIndex = -1, printFromStep = 0;
    string line, fileName;

    bool DEBUGING = false;

    if (argc > 1)
    {
        fileName = argv[1];
        line = getDataFromFile(fileName, startingLineIndex, rule);
        if (line == "" || startingLineIndex == -2 || rule.size() == 0)
        {
            cout << "Empty file or wrong selected file\n";
            return 0;
        }
        if (argc > 2)
        {
            string temp = argv[2];
            if (temp == "d")
            {
                DEBUGING = true;
            }
            else
            {
                printFromStep = stoi(argv[2]);
            }
            if (argc > 3)
            {
                printFromStep = stoi(argv[3]);
            }
        }
    }
    else
    {
        cout << "No argument was given";
        return 0;
    }
    //------

    if (DEBUGING)
        printFileData(line, startingLineIndex, rule);

    string currentState = "0", displayLine;
    int step = 1;
    bool halted = false;

    while (true)
    {
        // Printing line
        displayLine = print(startingLineIndex, line);
        if (DEBUGING)
        {
            if (step >= printFromStep)
                cout << step << " " << displayLine << " currentState = " << currentState << " Startingindex = "
                     << startingLineIndex << " halted = " << halted << '\n';
        }
        else
        {
            if (step >= printFromStep)
                cout << step << " " << displayLine << '\n';
        }
        //-----------

        for (int i = 0; i < rule.size(); ++i)
        {
            if (rule[i].currentState == currentState)
            {
                halted = false;
                if (line[startingLineIndex] == rule[i].currentSymbol)
                {
                    currentState = rule[i].newState;
                    line[startingLineIndex] = rule[i].newSymbol;
                    if (rule[i].direction == 'R')
                    {
                        startingLineIndex++;
                        break;
                    }
                    else if (rule[i].direction == 'L')
                    {
                        startingLineIndex--;
                        break;
                    }
                    else
                    {
                        cout << "Wrong direction symbol";
                        return 0;
                    }
                }
            }
            else
            {
                halted = true;
            }
        }
        if (GetKeyState(VK_ESCAPE) & 0x8000)
        {
            cout << "User halted";
            return 0;
        }

        step++;
        if (halted || startingLineIndex < 0 && startingLineIndex >= line.size())
        {
            cout << "Halted. No rule for state \"" << currentState << "\".";
            return 0;
        }
    }
}

string getDataFromFile(string fileName, int &startingIndex, vector<ruleGroup> &rule)
{
    ifstream data(fileName);
    if (data.is_open())
    {
        string line;
        data >> line;

        data >> startingIndex;
        startingIndex--;

        int i = 0;
        ruleGroup temp;
        while (!data.eof())
        {
            data >> temp.currentState;
            data >> temp.currentSymbol;
            data >> temp.newSymbol;
            data >> temp.direction;
            data >> temp.newState;
            rule.push_back(temp);
            ++i;
        }
        data.close();
        return line;
    }
    else
    {
        return "";
    }
}

void printFileData(string line, int startingIndex, vector<ruleGroup> rule)
{
    cout << "\nData:\n\n";
    cout << line << "\n";
    cout << startingIndex << "\n";

    for (int i = 0; i < rule.size(); ++i)
    {
        cout << rule[i].currentState << " ";
        cout << rule[i].currentSymbol << " ";
        cout << rule[i].newSymbol << " ";
        cout << rule[i].direction << " ";
        cout << rule[i].newState << "\n";
    }
    return;
}

string print(int index, string line)
{
    string newWord;
    for (int i = 0; i < line.size(); ++i)
    {
        if (i == index)
        {
            newWord += "[";
        }
        else if (i == index + 1)
        {
            newWord += "]";
        }
        newWord += line[i];
    }
    if (index == line.size() - 1)
    {
        newWord += "]";
    }
    return newWord;
}
