#include <iostream>
#include <fstream>

#include <sstream>

#include <map>

using namespace std;


int main(int argc, char* argv[])
{
    string line;

    long valid = 0;

    while (getline(cin, line)) {
        stringstream ss;
        ss << line;

        string word;
        map<string, long> m;
        while (ss >> word) {
            m[word]++;
        }
        bool inv = false;
        for (auto i : m) {
            if (i.second > 1) {
                inv = true;
                break;
            }
        }

        if (!inv) {
            valid++;
        }
    }

    cout << valid << endl;

    return 0;
}
