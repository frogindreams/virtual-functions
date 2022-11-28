#include <iostream>
#include <cstdlib>
#include <string.h>

using std::cout;

class CStr
{ 
    char *string = nullptr;
    int lengthOfString;

    char *generateRandomString(int lengthOfString)
    {
        srand(time(0));
        const char letters[] = "abcdefghijklmnopqrstuvwxyz0";

        this -> string = new char[lengthOfString + 1]; 
        string[lengthOfString] = '\0';

        for (int idx = 0; idx < lengthOfString; idx++)
        {
            string[idx] = letters[rand() % 27];
        }

        return string;
    }

    int generateRandomNumber()
    {
        srand(time(0));

        return 1 + rand() % 19;
    }

    public:
        CStr() 
        {
            this -> lengthOfString = generateRandomNumber();

            generateRandomString( lengthOfString );
        }

        CStr(char *string)
        {
            this -> lengthOfString = strlen(string);

            if ( string[lengthOfString] == '\0' )
            {
                this -> string = (char *) string; 
            }
        }

        CStr(int lengthOfString)
        {
            this -> lengthOfString = lengthOfString;

            if ( lengthOfString <= 20 )
            {
                generateRandomString( lengthOfString );
            }
        }

        CStr(const CStr &refer)
        {
            this -> string = new char[refer.lengthOfString];

            for (int idx = 0; idx < refer.lengthOfString; idx++)
            {
                this -> string[idx] = refer.string[idx];
            }

            this -> lengthOfString = refer.lengthOfString;
        }

        ~CStr()
        {
            delete[] string;
        }

        CStr& operator = (const CStr &object)
        {
            if (this == &object)
            {
                return *this;
            }

            int objLength = object.lengthOfString;
            this -> lengthOfString = objLength;

            if (this -> string != nullptr)
            {
                delete[] this -> string;
            }

            this -> string = new char[objLength];

            for (int idx = 0; idx < objLength; idx++)
            {
                this -> string[idx] = object.string[idx]; 
            }

            return *this;
        }

        CStr& operator = (const char *string)
        {
            if (this -> string == string) 
            {
                return *this;
            }

            int lengthOfAnotherString = strlen(string);
            this -> lengthOfString = lengthOfAnotherString;

            if (this -> string != nullptr)
            {
                delete[] this -> string;
            }

            this -> string = new char[lengthOfAnotherString];

            for (int idx = 0; idx < lengthOfAnotherString; idx++)
            {
                this -> string[idx] = string[idx]; 
            }

            return *this;
        }

        char *getString()
        {
            return string;
        }

        int getLengthOfString()
        {
            return lengthOfString;
        }
};

int main()
{    
    CStr randomString;
    CStr stringLength(14);
    randomString = stringLength.getString();

    cout << randomString.getString() << "\n";
    cout << stringLength.getString() << "\n";

    return 0;
}
