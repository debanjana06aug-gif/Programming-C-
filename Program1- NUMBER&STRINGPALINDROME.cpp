#include <iostream>
using namespace std;

int main()
{
    int n, r, sum = 0, temp;

    cout << "Enter the Number: ";
    cin >> n;

    temp = n;

    while (n > 0)
    {
        r = n % 10;
        sum = (sum * 10) + r;
        n = n / 10;
    }

    if (temp == sum)
        cout << "Number is Palindrome";
    else
        cout << "Number is not Palindrome";

    return 0;
}

OUTPUT
Enter the Number: 121
Number is Palindrome


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char string[20];
    int i, length;
    int flag = 0;

    cout << "Enter a string: ";
    cin >> string;

    length = strlen(string);

    for (i = 0; i < length; i++)
    {
        if (string[i] != string[length - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        cout << string << " is not a palindrome";
    else
        cout << string << " is a palindrome";

    return 0;
}

OUTPUT 
Enter a string: madam
madam is a palindrome
