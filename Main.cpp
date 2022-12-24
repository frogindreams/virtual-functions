#include <algorithm>
#include <cwchar>
#include <exception>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
        int get() override
        {
            return -1;
        }

    private:
};

int main() {
    std::string sfilename = "file.txt";
    const char* cfilename = sfilename.c_str();

    SFile file(cfilename);
    std::cout << file.get() << "\n";

    SKbrd input;
    std::cout << input.get() << "\n";

    return 0;
}
