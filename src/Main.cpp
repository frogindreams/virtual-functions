#include <iostream>
#include <cstdlib>

class CStr
{ 
    char *string = NULL;

    char *generateRandomString(int lengthOfString)
    {
        srand(time(0));
        char letters[] = "abcdefghijklmnopqrstuvwxyz0";

        string = new char[lengthOfString]; 
        string[lengthOfString] = { 0 };

        for (int idx = 0; idx < lengthOfString; idx++)
        {
            string[idx] = letters[rand() % 27];
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

        CStr(int lengthOfString)
        {
            if ( lengthOfString <= 20 )
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

        CStr(const CStr &refer)
        {
            this -> string = (char *) refer.string;
        }

        char *getString()
        {
            return string;
        }
};

int main()
{
    CStr defaultString;
    CStr generatedStringOnDefault( defaultString );
    CStr generatedStringLength( 20 );
    CStr copiedString = defaultString;


    std::cout << "Default String: " << defaultString.getString() << "\n";
    std::cout << "Generated String on default: " << generatedStringOnDefault.getString() << "\n";
    std::cout << "Generated String with given length: " << generatedStringLength.getString() << "\n";
    std::cout << "Copied String from default: " << copiedString.getString() << "\n";

    return 0;
}
