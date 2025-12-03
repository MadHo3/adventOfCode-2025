#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    int numTemp = 50, counter = 0;
    string address, line, order;
    fstream data;
    getline(cin, address);
    data.open(address);
    if (!data.is_open())
    {
        cout << "File not found!";
        return 0;
    }
    int Left[100] = {99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80,
                     79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60,
                     59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40,
                     39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
                     19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0};
    int Right[100] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16,
                      17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
                      34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                      51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
                      68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84,
                      85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    while (getline(data, order))
    {
        char rotation;
        string numStr = "";
        for (char rotationTemp : order)
        {
            if (rotationTemp == 'R' || rotationTemp == 'L')
            {
                rotation = rotationTemp;
            }
            else
            {
                numStr += rotationTemp;
            }
        }
        int num = stoi(numStr);
        if (rotation == 'R')
        {
            while ((numTemp + num) >= 100)
            {
                if ((numTemp + num) != 100)
                {
                    counter++;
                }
                numTemp -= 100;
            }
            for (int i = 0; i < 100; i++)
            {
                if (Right[i] == numTemp + num)
                {
                    numTemp = Right[i];
                    break;
                }
            }
        }
        else
        {
            while ((numTemp - num) < 0)
            {
                if (numTemp != 0)
                {

                    counter++;
                }
                numTemp += 100;
            }
            for (int i = 0; i < 100; i++)
            {
                if (Left[i] == numTemp - num)
                {
                    numTemp = Left[i];
                    break;
                }
            }
        }
        if (numTemp == 0)
        {
            counter++;
        }
    }
    cout << "Password is : " << counter << "\n";
    data.close();
}
