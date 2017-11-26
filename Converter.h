#include <string>

const std::string baseItem = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Converter
{
private:
    static int getDigit(char let, int base)
    {
        for(int i = 0; i < base; i++)
        {
            if(let == baseItem[i])
            {
                return i;
            }
        }
        return -1;
    }

    static int pow(int in, int pow)
    {
        int out = 1;
        for(int i = 0; i < pow; i++)
        {
            out *= in;
        }
        return out;
    }

public:
    static std::string convert(unsigned int inputBase, std::string input, unsigned int outBase)
    {
        // Output and calculating vars
        const int length = input.length();
        unsigned long long inputNum = 0;
        std::string out = "";

        // Check For Errors
        if(inputBase > 62 || inputBase < 2){ return "Starting Base Error!"; }
        if(outBase > 62 || outBase < 2){ return "Output Base Error!"; }

        // Make Input A Number
        for(unsigned int i = 0; i < length; i++)
        {
            const unsigned int digit = getDigit(input[i], inputBase);

            if(digit == -1){ return "Input Error!"; } // Non Normal Number

            inputNum += digit * pow(inputBase, (length - 1) - i);
        }

        // Translate to output
        while(inputNum > 0)
        {
            out = baseItem[inputNum%outBase] + out;

            inputNum -= inputNum%outBase;
            inputNum /= outBase;
        }

        return out;
    }

};

