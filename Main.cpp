#include <fstream>
#include <iostream>
#include <map>

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
            if (std::cin.peek() == '\n') 
            { 
                return -1; 
            }

            int inputNumber;
            std::cin >> inputNumber;

            return inputNumber;
        }

    private:
};

class SFile : public SBase 
{
    public:
        SFile() 
        {
            file.open("file.txt");
        }

        ~SFile()
        {
            file.close();
        }

        int get() override
        {
            if (!file.is_open()) 
            { 
                return -1; 
            }

            if (file.eof()) 
            {
                file.close();
                return -1;
            }

            int inputNumber;
            file >> inputNumber;

            return inputNumber;
        }

    private:
        std::ifstream file;
};

class SQueue : public SBase
{
    public:
        SQueue(int lengthOfQueue) 
        {
            int* arrayWithRandomNumbers = new int[lengthOfQueue];

            for (int idx = 0; idx < lengthOfQueue; idx++) 
            {
                arrayWithRandomNumbers[idx] = rand() % 100;
            }

            this -> lengthOfQueue = lengthOfQueue;
            queue = arrayWithRandomNumbers;
            currentItem = 0;
        }

        int get() override 
        {
            if (currentItem >= lengthOfQueue) 
            {
                return -1;
            }

            else 
            {
                return queue[currentItem++];
            } 
        }

    private:
        int* queue, lengthOfQueue, currentItem;
};

class Freq {
    public:
        void calc(SBase* plainObject) 
        {
            int summaryOfAllEnteredNumbers = 0;
            int plainObjectNumber = (*plainObject).get();

            while (plainObjectNumber != -1) 
            {
                numberItselfAndCounter[plainObjectNumber]++;
                summaryOfAllEnteredNumbers += plainObjectNumber;
                plainObjectNumber = (*plainObject).get();
            }

            printf("Summary of all numbers: %d", summaryOfAllEnteredNumbers);
        }

        friend std::ostream& operator << (std::ostream &os, const Freq &pobj)
        {
            auto begin = pobj.numberItselfAndCounter.begin();
            auto end = pobj.numberItselfAndCounter.end();

            for (auto queue = begin; queue != end; queue++) 
            {
                os << (*queue).first << " " << (*queue).second;
            }

            return os;
        }

    private:
        std::map<int, int> numberItselfAndCounter;
};

class Diap : Freq {
    public:
        void calc(SBase* plainObject)
        { 
            int plainObjectNumber = (*plainObject).get();

            while (plainObjectNumber != -1) 
            {
                numberItselfAndCounter[plainObjectNumber]++;
                summaryOfAllEnteredNumbers += plainObjectNumber;

                if (plainObjectNumber > maxNumber) 
                    maxNumber = plainObjectNumber;

                if (plainObjectNumber < minNumber) 
                    minNumber = plainObjectNumber;


                quantityOfEnteredNumbers++;
                plainObjectNumber = (*plainObject).get();
            }
        }

        friend std::ostream& operator << (std::ostream &os, const Diap &pobj)
        {
            auto begin = pobj.numberItselfAndCounter.begin();
            auto end = pobj.numberItselfAndCounter.end();

            for (auto queue = begin; queue != end; queue++) 
            {
                os << (*queue).first << " " << (*queue).second;
            }

            return os;
        }

    private:
        std::map<int, int> numberItselfAndCounter;
        int maxNumber = -1;
        int minNumber = 1e9;
        int quantityOfEnteredNumbers = 0;
        int summaryOfAllEnteredNumbers = 0;
};

int main() {
    srand(time(0));

    SKbrd input;

    return 0;
}
