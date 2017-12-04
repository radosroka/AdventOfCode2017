#include <iostream>
#include <fstream>

using namespace std;

long getRect(long num) {

    long last = 1;

    long i;
    long cnt = 1;
    for (i = 1 ;; i += 2, cnt++) {
        long max = i*i;
        if (num >= last && num <= max) return cnt-1;
        last = max;
    }
}

int main(int argc, char* argv[])
{
    long number;
    cin >> number;

    long rect = getRect(number);
    long h = rect * 2 + 1;

    long max_num = h * h;
    long size = h * 2 + h * 2 - 4;

    cout << number <<  " " << rect << " " << h << endl;

    for (long i = 3 ; i >= 0 ; i--) {

        long higher_corner = max_num - i * (h-1);

        cout << number << " " << higher_corner << endl;

        if (number <= higher_corner) {


            long mid = higher_corner - rect;

            cout << number << " " << higher_corner << " " << mid << endl;

            long dist = rect;
            long cursor = mid;
            for (long i = 0 ; i <= rect ; i++) {
                if (cursor + i == number) {
                    cout << dist + i << endl;
                    return 0;
                }
                if (cursor - i == number) {
                    cout << dist - i << endl;
                    return 0;
                }

            }


            break;
        }
    }

    return 0;
}
