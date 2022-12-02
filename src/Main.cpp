#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string.h>

using std::cout;
using std::ostream;
using std::sort;

class CStr
{ 
    char *string = nullptr;
    int lengthOfString;

    char *generateRandomString(int lengthOfString)
    { 
        const char letters[] = "abcdefghijklmnopqrstuvwxyz0";

        this -> string = new char[lengthOfString + 1]; 
        string[lengthOfString] = '\0';
        
        for (int idx = 0; idx < lengthOfString; idx++)
        {
            string[idx] = letters[rand() % 26];
        }

        return string;
    }

    int generateRandomNumber()
    {
        return rand() % 20;
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

        bool operator < (const CStr &object )
        {
            const char *otherString = object.string;

            for (int idx = 0; idx < this -> lengthOfString; idx++)
            {
                if (this -> string[idx] < otherString[idx])
                {
                    return true; 
                }
            }

            return false;
        }

        char *getString()
        {
            return string;
        }

        int getLengthOfString()
        {
            return lengthOfString;
        }

        friend ostream& operator << (ostream &os, const CStr &object);
};

ostream& operator << (ostream &os, const CStr &object)
{
    os << object.string << "\n";

    return os;
}

class CStrArray
{
    CStr *array = nullptr; 
    int lengthOfCStrArray;

    public:
        CStrArray(int lengthOfCStrArray)
        {
            this -> lengthOfCStrArray = lengthOfCStrArray;
            this -> array = new CStr[lengthOfCStrArray]; 
        }

        ~CStrArray()
        {
            delete[] array;
        }

        CStr& operator [] (int index)  
        {
            return array[index];
        }

        void sortByContent()
        {
            sort(array, array + lengthOfCStrArray);
        }

        void sortByLength()
        {
            sort(array, array + lengthOfCStrArray, [](CStr object_1, CStr object_2) -> bool
            {
                return object_1.getLengthOfString() < object_2.getLengthOfString(); 
            });
        }

        int binarySearch(CStr targetString)
        {
            return std::lower_bound(array, array + lengthOfCStrArray, targetString) - array;
        }
};

int main()
{    
    srand(time(0));

    CStr string_1, string_2, string_3;
    CStrArray array(3);

    array[0] = string_1; 
    array[1] = string_2; 
    array[2] = string_3; 

    cout << array[0] << array[1] << array[2] << "\n";
    array.sortByLength();
    cout << array[0] << array[1] << array[2];

    int resultOfBinarySearch = array.binarySearch(string_2);

    cout << resultOfBinarySearch << "\n";

    return 0;
}
