#include <iostream>
#include <cstdlib>

class CStr
{ 
    char *string = NULL;

    char *generateRandomString(int lengthOfString)
    {
        srand(time(0));
        char letters[] = "abcdefghijklmnopqrstuvwxyz";

        string = new char[lengthOfString]; 
        string[lengthOfString] = { 0 };

        for (int idx = 0; idx < lengthOfString; idx++)
        {
            string[idx] = letters[rand() % 26];
        }

        return string;
    }

    int generateRandomNumber()
    {
        srand(time(0));

        return rand() % 20;
    }

    public:
        CStr() 
        {
            int lengthOfString = generateRandomNumber();

            generateRandomString( lengthOfString );
        }

        CStr(char *string[])
        {
            size_t lengthOfString = (unsigned) sizeof &string;

            if ( string[lengthOfString] == 0 )
            {
                this -> string = (char *) string; 
            }
        }

        char *getString()
        {
            return string;
        }
};

int main()
{
    CStr defaultString;
    CStr currentString( defaultString );

    std::cout << currentString.getString() << "\n";

    return 0;
}
