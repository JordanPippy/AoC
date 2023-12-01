#include <iostream>
#include <ctype.h>
#include <string>
using std::cin, std::cout, std::endl, std::string;


void replaceWords(string &data)
{
    string words[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    bool foundOne = true;
    while (foundOne)
    {
        foundOne = false;
        for (int i = 0; i < 9; i++)
        {
            string currentWord = words[i];
            int n = data.find(currentWord);
            if (n != string::npos)
            {
                foundOne = true;
                data.replace(n+1, currentWord.size()-2, std::to_string(i+1));
            }
        }
    }
}

int main()
{
    string dataText;
    int sum = 0;
    while (cin >> dataText)
    {
        int first = -1, last = -1;
        cout << dataText << endl;
        replaceWords(dataText);
        cout << dataText << endl;
        for (int i = 0; i < dataText.size(); i++)
        {
            if (isdigit(dataText[i]))
            {
                if (first == -1)
                    first = dataText[i] - '0';
                else
                    last = dataText[i] - '0';
            }
        }
        if (last == -1)
            last = first;
        sum += (first * 10) + last;
        cout << first << " " << last << endl;
    }
    cout << sum << endl;
}