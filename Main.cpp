#include <cstdlib>
#include <algorithm>
#include <cwchar>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

class SBase 
{
    public:
        virtual int get() = 0;

    private:
};

class SFile : SBase 
{
    public:
        SFile(const char* filename)
        {
            this -> filename = filename;
        }

        int get() override
        {
            try 
            {
                FILE* fileOpened = fopen(filename, "r");

                int character;
                while ((character = fgetc(fileOpened)) != EOF) 
                {
                    putwchar(character);
                }

                fclose(fileOpened);
                return -1;
            }

            catch (const std::exception& e) 
            {
                std::cout << e.what() << "\n";
                return 0;
            }
        }

    private:
        const char* filename = nullptr;
};

class SKbrd : SBase 
{
    public:
        int get() override
        {
            std::string lineOfNumbers = "";

            getline(std::cin, lineOfNumbers);

            return -1;
        }

    private:
};

class SQueue : SBase
{
    public:
        SQueue(int sizeOfQueue) 
        {
            this -> sizeOfQueue = sizeOfQueue;
        }

        int get() override
        {
            std::queue<int> queueOfNumbers;

            while (queueOfNumbers.size() != sizeOfQueue) 
            {
                queueOfNumbers.push( rand() % 100 );
            }

            return -1;
        }

    private:
        int sizeOfQueue;
};

int main() {
    srand(time(0));

    return 0;
}
