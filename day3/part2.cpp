#include <iostream>
#include <fstream>

#include <vector>

using namespace std;

long long getRect(long long num) {

    long long last = 1;

    long long i;
    long long cnt = 1;
    for (i = 1 ;; i += 2, cnt++) {
        long long max = i*i;
        if (num >= last && num <= max) return cnt-1;
        last = max;
    }
}

struct Cell {
    long long number;
    long long value;

    Cell() : number(0), value(0) {};
};

long long CalcValue(Cell *** array, long long x, long long y) {
    long long result = 0;

    long long a[] = {-1, 0, 1};

    //cout << "*checking for " << x << " " << y << endl;

    for (long long i = 0 ; i < 3 ; i++) {
        for (long long j = 0 ; j < 3 ; j++) {

            if (i == 1 && j == 1) continue;
            //cout << "checking for " << x + a[i] << " " << y + a[j] << endl;
            if (array[x + a[i]][y + a[j]]) {
                result += array[x + a[i]][y + a[j]]->value;
            }
        }
    }

    return result;
}

void print(Cell *** array, long long h) {
    cout << endl;
    for (long long i = 0 ; i < h; i++) {
        for (long long j = 0 ; j < h ; j++) {
            if (array[i][j]) {
                cout << /*array[i][j]->number << "-" << array[i][j]->value*/ "X" << " ";
            } else {
                cout << "O" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


enum Direction { LEFT, DOWN, RIGHT, UP };

int main(int argc, char* argv[])
{
    long long  number;
    cin >> number;

    if (number == 1 || number == 2) {
        cout << 1 << endl;
        return 0;
    }

    long long rect = getRect(number);
    long long h = rect * 2 + 1;
    long long h_padded = h +2;

    Cell ***array = nullptr;

    array = new Cell**[h_padded];

    for (long long i = 0 ; i < h_padded ; i++) {
        array[i] = new Cell*[h_padded];
    }

    for (long long i = 0 ; i < h_padded; i++) {
        for (long long j = 0 ; j < h_padded ; j++) {
            array[i][j] = nullptr;
        }
    }

    long long x = h_padded / 2;
    long long y = h_padded / 2;

    array[x][y] = new Cell();
    array[x][y]->number = 1;
    array[x][y]->value = 1;

    y++;

    array[x][y] = new Cell();
    array[x][y]->number = 2;
    array[x][y]->value = 1;

    x--;

    array[x][y] = new Cell();
    array[x][y]->number = 3;
    array[x][y]->value = 2;


    cout << h << " " << h_padded << endl;
    print(array, h_padded);

    long long counter = 4;

    for (long long i = 1 ; i <= rect ; i++) {
        long long a = 0;
        for (long long d = 0 ; d < 4 ; d++) {
            Direction dd = static_cast<Direction>(d);

            bool flag = true;

            for (long long j = 0 ; j < i * 2 + a ; j++) {

                if (dd == Direction::RIGHT && flag) {
                    flag = false;
                    a++;
                }
                //
                // if (dd == Direction::LEFT && flag) {
                //     j--;
                //     flag = false;
                // }
                //
                // if (dd == Direction::DOWN && flag) {
                //     j--;
                //     flag = false;
                // }

                switch (dd)
                {
                case Direction::UP:
                    x--;
                    break;
                case Direction::LEFT:
                    y--;
                    break;
                case Direction::DOWN:
                    x++;
                    break;
                case Direction::RIGHT:
                    y++;
                    break;
                default:
                    /* code */
                    break;
                }

                array[x][y] = new Cell();
                array[x][y]->number = counter;
                array[x][y]->value = CalcValue(array, x, y);
                print(array, h_padded);

                if (array[x][y]->value > number) goto end;
                counter++;
            }
            flag = true;
        }
    }

end:
    cout << array[x][y]->value << endl;


    for (long long i = 0 ; i < h_padded; i++) {
        for (long long j = 0 ; j < h_padded ; j++) {
            delete array[i][j];
        }
    }

    for (long long i = 0 ; i < h_padded ; i++) {
        delete [] array[i];
    }

    delete [] array;


    return 0;
}
