#include <iostream>
#include <string>
using namespace std;

long long checkCount(long num);

int main()
{
    long long result = 0;
    long long sum = 0;
    string data =
        "9191896883-9191940271,457499-518693,4952-6512,960-1219,882220-1039699,2694-3465,3818-4790,"
        "166124487-166225167,759713819-759869448,4821434-4881387,7271-9983,1182154-1266413,810784-"
        "881078,802-958,1288-1491,45169-59445,25035-29864,379542-433637,287-398,75872077-75913335,"
        "653953-689335,168872-217692,91-113,475-590,592-770,310876-346156,2214325-2229214,85977-"
        "112721,51466993-51620441,8838997-8982991,534003-610353,32397-42770,17-27,68666227-"
        "68701396,1826294188-1826476065,1649-2195,141065204-141208529,7437352-7611438,10216-13989,"
        "33-44,1-16,49-74,60646-73921,701379-808878,";

    while (!data.empty() && data.find(",") != string::npos)
    {
        long long indexCama = data.find(",");
        string tempCama = data.substr(0, indexCama);

        long long indexDash = tempCama.find("-");
        long long first = stoll(tempCama.substr(0, indexDash));
        long long end = stoll(tempCama.substr(indexDash + 1));

        data.erase(0, indexCama + 1);

        for (long long i = first; i <= end; i++)
        {
            long long countNum = checkCount(i);
            if (countNum % 2 != 0)
                continue;

            string s = to_string(i);
            string firstHalf = s.substr(0, countNum / 2);
            string secondHalf = s.substr(countNum / 2);
            if (firstHalf == secondHalf)
            {
                result++;
                sum += i;
            }
        }
    }

    cout << "numberOfInvalidID :" << result << "\n"
         << "Password is : " << sum << "\n";
}

long long checkCount(long num)
{
    long long temp = num;
    long long count = 0;
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }
    return count;
}
