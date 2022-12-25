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

class SKbrd : public SBase 
{
    public:
        int get() override
        {
            int inputNumber;
            std::cin >> inputNumber;

            return -1;
        }

    private:
};

class SFile : public SBase 
{
    public:
        int get() override
        {
            int isOk = 0;
            char inputNumber[255];
            const char* filename = "file.txt";
            FILE* openedFile = fopen(filename, "r+");

            if (!openedFile) 
            {
                perror("File opening failed");
                return isOk;
            }

            printf("Enter your number for file: ");
            fgets(inputNumber, 255, stdin);
            fputs(inputNumber, openedFile);
            rewind(openedFile);

            int ch;
            while ((ch = fgetc(openedFile)) != EOF) 
            {
                putchar(ch);
            }

            if (ferror(openedFile)) 
            {
                puts("I/O error when reading");
            } 
            
            else if (feof(openedFile))
            {
                isOk = -1;
            }

            fclose(openedFile);
            return isOk;
        }

    private:
};

class SQueue : public SBase
{
    int *queue, sizeOfQueue;

    void initQueue() 
    {
        queue = new int[sizeOfQueue];
        for (int idx = 0; idx < sizeOfQueue - 1; idx++) 
        {
            queue[idx] = rand() % 100;
        }
    }

    public:
        SQueue(int sizeOfQueue) 
        {
            this -> sizeOfQueue = sizeOfQueue;
        }

        ~SQueue() 
        {
            delete[] queue;
        }

        int get() override
        {
            initQueue();

            int inputNumber;
            printf("Enter your number for queue: ");
            std::cin >> inputNumber;

            queue[sizeOfQueue - 1] = inputNumber;

            return -1;
        }

        void showQueue() 
        {
            for (int idx = 0; idx < sizeOfQueue; idx++) 
            {
                std::cout << queue[idx] << " ";
            }

            std::cout << "\n";
        }
};

int main() {
    srand(time(0));

    SQueue queue(5);
    queue.get();
    queue.showQueue();

    return 0;
}
