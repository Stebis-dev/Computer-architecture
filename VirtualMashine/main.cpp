#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    unsigned char regs[16];
    unsigned char progMemory[256] = {0};
    bool eof = false, zero = false; // flags

    ifstream data("1/decryptor.bin", ios::binary);
    ifstream dataFromFile("1/q1_encr.txt");
    ofstream dataToFile("rez.txt");

    int t = 0;

    for (int i = 0; i < 256; i++)
    {
        char temp;
        data.get(temp);
        progMemory[i] = temp;
        if (progMemory[i] > 0)
            t++;
    };
    t++;
    data.close();

    unsigned int i = 0, Rx, Ry;
    unsigned char command;
    while (true)
    {
        command = progMemory[i];
        Rx = progMemory[i + 1] & 0b1111;
        Ry = progMemory[i + 1] >> 4;
        /// cout << i + 1 << " " << int(command) << " " << int(progMemory[i + 1]) << " " << eof << " " << zero << endl;
        {
            if (command == 1)
            {
                regs[Rx]++;
            }
            else if (command == 2)
            {
                regs[Rx]--;
            }
            else if (command == 3)
            {
                regs[Rx] = regs[Ry];
            }
            else if (command == 4)
            {
                regs[0] = progMemory[i + 1];
            }
            else if (command == 5)
            {
                regs[Rx] <<= 1;
            }
            else if (command == 6)
            {
                regs[Rx] >>= 1;
            }
            else if (command == 7)
            {
                if (i + progMemory[i + 1] > t)
                {
                    i = (i + progMemory[i + 1]) - 256;
                }
                else
                {
                    i = progMemory[i + 1];
                }
                continue;
            }
            else if (command == 8)
            {
                if (zero)
                {
                    if (i + progMemory[i + 1] > t)
                    {
                        i = (i + progMemory[i + 1]) - 256;
                    }
                    else
                    {
                        i = i + progMemory[i + 1];
                    }
                    zero = false;
                    continue;
                }
            }
            else if (command == 9)
            {
                if (!zero)
                {
                    if (i + progMemory[i + 1] > t)
                    {
                        i = (i + progMemory[i + 1]) - 256;
                    }
                    else
                    {
                        i = i + progMemory[i + 1];
                    }
                    continue;
                }
            }
            else if (command == 10)
            {
                if (eof)
                {
                    if (i + progMemory[i + 1] > t)
                    {
                        i = (i + progMemory[i + 1]) - 256;
                    }
                    else
                    {
                        i = i + progMemory[i + 1];
                    }
                    eof = false;
                    continue;
                }
            }
            else if (command == 11)
            {
                return 0;
            }
            else if (command == 12)
            {
                regs[Rx] = regs[Rx] + regs[Ry];
            }
            else if (command == 13)
            {
                regs[Rx] = regs[Rx] - regs[Ry];
            }
            else if (command == 14)
            {
                regs[Rx] = regs[Rx] ^ regs[Ry];
            }
            else if (command == 15)
            {
                regs[Rx] = regs[Rx] | regs[Ry];
            }
            else if (command == 16)
            {
                char temp;
                dataFromFile >> temp;
                eof = dataFromFile.eof();
                regs[progMemory[i + 1]] = temp;
            }
            else if (command == 17)
            {
                dataToFile << regs[Rx];
            }
        }
        i += 2;
    }
    dataToFile.close();
    dataFromFile.close();
    return 0;
}