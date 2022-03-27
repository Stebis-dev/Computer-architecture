#include <iostream>
#include <thread>

void someFunction()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "i = " << i << "\n";
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void add(int a, int b)
{
    std::cout << "Sum = " << a + b << "\n";
}

void infLoop()
{
    while (true)
    {
        std::cout << "A******";
        std::cout << " ----- ";
        std::cout << " +++++B \n";
    }
}

int main()
{
    std::thread Thread1(infLoop);
    std::thread Thread2(someFunction);

    std::cout << "Started the threads\n";

    // littleThread.join();
    // anotherLittleThread.join();

    std::cout << "End of the program\n";
}
