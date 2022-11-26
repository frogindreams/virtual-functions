#include <iostream>

class CStr
{
    private:
        int value;

    public:
        CStr(int value)
        {
            this -> value = value;
        }

        int getValue()
        {
            return value;
        }
        
};

int main()
{
    CStr object(55);

    std::cout << object.getValue() << "\n";

    return 0;
}
