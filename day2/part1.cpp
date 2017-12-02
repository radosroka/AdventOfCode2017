#include <iostream>
#include <fstream>

#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    std::vector<long> data;
    string saved_line;

    while(getline(cin, saved_line)) {
        if (saved_line == "") break;
        stringstream stream;
        stream << saved_line;

        long number;
        stream >> number;
        long max = number;
        long min = number;

        while (!stream.eof()) {
            stream >> number;
            if (number > max) max = number;
            if (number < min) min = number;
        }

        data.push_back(max - min);
    }

    long result = 0;
    for(auto x : data) {
        result += x;
    }

    cout << result << endl;



    return 0;
}
