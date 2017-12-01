#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    string saved_input;

    long result = 0;

    cin >> saved_input;

    char last = saved_input[0];

    for (long i = 1 ;i < saved_input.length() ; i++)
    {
        if (last == saved_input[i]) {
            result += static_cast<long>(saved_input[i]) - static_cast<long>('0');
        }
        last = saved_input[i];
    }

    if (last == saved_input[0]) {
        result += static_cast<long>(last) - static_cast<long>('0');
    }

    cout << result << endl;;

    return 0;
}
