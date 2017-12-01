#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    string saved_input;

    long result = 0;

    cin >> saved_input;

    long len = saved_input.length();

    long dist = len / 2;

    for (long i = 0 ; i < len ; i++)
    {

        if (saved_input[i] == saved_input[(i + dist) % len]) {
            result += static_cast<long>(saved_input[i]) - static_cast<long>('0');
        }
    }

    cout << result << endl;;

    return 0;
}
