#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <set>

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

string lineWithHead(int index, string line);

string getDataFromFile(string fileName, int &startingIndex, vector<ruleGroup> &rule);

void printFileData(string line, int startingIndex, vector<ruleGroup> rule);

int Error(string message);

int main(int argc, char **argv)
{
    bool DEBUGING = false;
    // starts the clock;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    vector<ruleGroup> rule;
    int startingLineIndex = -1, printFromStep = 0;
    string line, fileName, detecionLine;
    // bool isLoopDetectionOn = true;

    // getting variables from arguments
    if (argc > 1)
    {
        fileName = argv[1];

        line = getDataFromFile(fileName, startingLineIndex, rule);
        detecionLine = line;

        if (line == "" || startingLineIndex == -2 || rule.size() == 0)
        {
            return Error("Empty or wrong selected file");
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
        return Error("No argument was given");
    }
    //-------------

    if (DEBUGING)
    {
        printFileData(line, startingLineIndex, rule);
    }
    //
    string currentState = "0", lineForDisplay;
    int step = 1, lineQuantity = 0;
    bool halted = false;
    // set<string> lineCount;

    while (true)
    {
        lineForDisplay = lineWithHead(startingLineIndex, line);

        // Printing line
        if (DEBUGING && step >= printFromStep)
        {
            cout << step << " " << lineForDisplay << " currentState = " << currentState << " Startingindex = "
                 << startingLineIndex << '\n';
        }
        else if (step >= printFromStep)
        {
            cout << step << " " << lineForDisplay << '\n';
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
                        return Error("Wrong direction symbol");
                    }
                }
            }
            else
            {
                halted = true;
            }
        }
        //! loop detection
        // if (isLoopDetectionOn)
        // {
        //     if (lineQuantity < 1000)
        //         lineCount.insert(lineForDisplay);

        //     //!

        //     if (lineQuantity == 1000 && lineCount.size() < 600)
        //         return Error("Detected loop");

        //     if (lineQuantity == 1000)
        //     {
        //         lineCount.clear();
        //         lineQuantity = 0;
        //     }
        //     else
        //         lineQuantity++;
        // }
        //!
        // string temp = lineList.front();
        // for (auto i : lineList)
        // {
        //     if (temp == i)
        //     {
        //         lineQuantity++;
        //     }
        //     {
        //         if (max < lineQuantity)
        //             max = lineQuantity;
        //     }
        // }
        // cout << max << endl;

        // if (detecionLine == line)
        // {
        //     ++lineQuantity;
        // }
        //!

        // lineCount[line]++;

        // for (auto i : lineCount)
        // {
        //     if (i.second >= 40)
        //     {
        //         lineQuantity++;
        //     }
        // }

        // if (lineQuantity >= lineCount.size())
        // {
        //     halted = true;
        //     cout << "Detected loop";
        //     return 0;
        // }

        step++;
        if (halted || startingLineIndex < 0 && startingLineIndex >= line.size())
        {
            // Stops tracking time and makes calculations
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

            cout << "Halted. No rule for state \"" << currentState << "\".\n";
            cout << "Time: " << time.count() << " seconds" << endl;
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
        return "";
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

string lineWithHead(int index, string line)
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

int Error(string message)
{
    cout << message << '\n';
    return 0;
}
