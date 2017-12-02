#include <iostream>
#include <fstream>

#include <sstream>
#include <vector>

using namespace std;

bool Divisible(long a, long b, long & res) {
    if (b > a) {
        long tmp = a;
        a = b;
        b = tmp;
    }

    long d = a / b;

    if ((d * b) == a) {
        res = d;
        return true;
    }

    return false;
}

int main(int argc, char* argv[])
{
    std::vector<long> data;
    string saved_line;

    while(getline(cin, saved_line)) {
        if (saved_line == "") break;
        stringstream stream;
        stream << saved_line;

        std::vector<long> line;

        long number;
        stream >> number;
        line.push_back(number);

        while (!stream.eof()) {
            stream >> number;
            line.push_back(number);
        }

        for (long i = 0; i < line.size(); ++i) {
            for (long j = 0; j < line.size(); ++j) {
                if (i == j) continue;
                if (line[i] > line[j]) {
                    cout << "processing " << line[i] << " " << line[j] << endl;
                    long res;
                    if (Divisible(line[i], line[j], res)) {
                        data.push_back(res);
                        cout << line[i] << " " << line[j] << " " << res << endl;
                    }
                }
            }
            cout << endl;
        }



    }

    long result = 0;
    for(auto x : data) {
        result += x;
    }

    cout << result << endl;



    return 0;
}
