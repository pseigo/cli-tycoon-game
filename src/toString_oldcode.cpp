/*
 * This is a collection of code that attempts to find a workaround for floating
 * point rounding errors. I'll keep the code archived, as I've decided to use
  * a much simpler solution. I originally wanted to be able to convert a
  * double to a string in order to use my (limited) box drawing method.
  * However, I've decided to instead just represent money with integers as
  * cents rather than as dollars with decimals. I'm dumb.
*/


// ### GETTING THE DECIMAL ###
std::string decimal = ".";

/* trial 2: even worse rounding errors
// decimalNumber is the decimal from numberCopy as an integer
int decimalNumber = 0;
while ((decimalNumber / 100.0) < numberCopy)
    decimalNumber++;

std::cout << decimalNumber << std::endl;
*/

// removing whole numbers
double numberDecimal = number;
while (numberDecimal >= 1)
    numberDecimal--;

std::cout << "before: " << numberDecimal << std::endl;
double numberDecimalPatch = numberDecimal;
std::cout << numberDecimalPatch << std::endl;
for (int i = 0; i < 2; i++) {
    numberDecimalPatch *= 10;
    if (i == 0)
        numberDecimalPatch -= (int)(numberDecimalPatch);
}
std::cout << numberDecimalPatch << std::endl;
std::cout << "after: " << numberDecimal << std::endl;


if (numberDecimalPatch == 10) {
    // numberDecimal += 0.99;
}

int lengthPatch = 0;
for (lengthPatch; pow(10,lengthPatch) < number; lengthPatch++);
std::cout << "length is " << lengthPatch << std::endl;

// if tenth slot of numberDecimal is == 0, then add 0.001 to numberDecimal
do
{

    lengthPatch--;
} while (numberDecimal)


// at this point numberDecimal is either 0 or a decimal between 0 and .99999
if(numberDecimal == 0)
    decimal += "0";
else {
    int counter = 0; // keep decimal to 2 places
    while(numberDecimal > 0 && counter < 8)
    {
        numberDecimal *= 10; // move next decimal up one place
        int temp = (int)numberDecimal; // saves number WITHOUT the decimal
        decimal += (char)(temp + 48); // adds most recent decimal as a char to the string
        numberDecimal -= temp; // removes most recent decimal from one's place

        counter++;
    }
}


// ...

// at the end of the method
/* part of trial 2
    if (decimalNumber != 0)
    {
        answer += ".";

        int currentNumberToAdd = decimalNumber /10;
        answer+=(char)(currentNumberToAdd + 48);
        currentNumberToAdd = decimalNumber %10;
        if(currentNumberToAdd>0)
            answer+=(char)(currentNumberToAdd + 48);
    }
    */

    if (decimal != ".0")
    {
        answer = answer + decimal;
    }

    return answer;
