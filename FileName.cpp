#include <iostream>
#include <random>
#include <Windows.h>
#include <chrono>
#include <stdio.h>

using namespace std;
using namespace std::chrono;

int L(char* arr) {
    unsigned L = 0;
    while (arr[L] != '\0') {
        L++;
    }
    return L;
}






int main1() {

    //1
    cout
        << "int: " << sizeof(int) << "\n"
        << "short int: " << sizeof(short int) << "\n"
        << "long int: " << sizeof(long int) << "\n"
        << "float: " << sizeof(float) << "\n"
        << "double: " << sizeof(double) << "\n"
        << "long double: " << sizeof(long double) << "\n"
        << "char: " << sizeof(char) << "\n"
        << "bool: " << sizeof(bool) << "\n";


    //2
    cout << endl << "enter int number ";

    int intNumber;
    cin >> intNumber;
    int musk = 1;
    int order = sizeof(int) * 8;

    cout << "\n";

    cout << "intNumber: " << &intNumber << " : " << intNumber << endl;
    //for (int i = 0; i < order; i++) {
    for (int i = order - 1; i >= 0; i--) {
        if (intNumber & (musk << i)) {
            cout << '1';
        }
        else {
            cout << '0';
        }

        if (i == order - 1) {
            cout << '_';
        }
        //if ((i + 1) % 8 == 0) {
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;




    //3
    union {
        float floatNumber;
        int intNumber;
    } c;
    cout << "\n\nenter float nomber ";
    cin >> c.floatNumber;

    cout
        << "\nfloatNumber: " << &(c.floatNumber) << " : " << c.floatNumber << endl
        << "intNumber: " << &(c.intNumber) << " : " << c.intNumber << endl;


    int orderF = sizeof(float) * 8;
    //int muskF = 1 << (orderF - 1);
    int muskF = 1;

    // число: 101011
    // маска: 100000
    // резул: 100000

    for (int i = orderF - 1; i >= 0; i--) {
        if (c.intNumber & (muskF << i)) {
            cout << '1';
        }
        else {
            cout << '0';
        }

        if (i == orderF - 1) {
            cout << '_';
        }
        if (i == orderF - 1 - 8) {
            cout << '_';
        }
        //if ((i + 1) % 8 == 0) {
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }


    //4
    union {
        double doubleNumber;
        int intNumber[2];
        long long int longNumber;
    } d;

    cout << "\n\nenter double nomber ";
    cin >> d.doubleNumber;

    cout
        << "\n\ndoubleNumber: " << &(d.doubleNumber) << " : " << d.doubleNumber << endl
        << "intNumber[0]: " << &(d.intNumber[0]) << " : " << d.intNumber[0] << endl
        << "intNumber[1]: " << &(d.intNumber[1]) << " : " << d.intNumber[1] << endl
        << "longNumber:   " << &(d.longNumber) << " : " << d.longNumber << endl;


    int orderD = sizeof(double) * 8;
    long long int muskD = 1;

    // -3.14
    // double: 11000000 00001001 00011110 10111000    01010001 11101011 10000101 00011111
    // int[0]: 01010001 11101011 10000101 00011111
    // int[1]: 11000000 00001001 00011110 10111000
    // маска : 10000000 00000000 00000000 00000000
    // резул : 10000000 00000000 00000000 00000000

    cout << "int[]: ";
    for (int i = orderD - 1; i >= 0; i--) {
        if (i >= orderF) {
            if (d.intNumber[1] & (muskF << (i - orderF))) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }
        else {
            if (d.intNumber[0] & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }

        if (i == orderD - 1) {
            cout << "_";
        }
        if (i == orderD - 1 - 11) {
            cout << "_";
        }
        //if ((i + 1) % 8 == 0) {
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;

    cout << "long:  ";
    for (int i = orderD - 1; i >= 0; i--) {
        if (d.longNumber & (muskD << i)) {
            cout << '1';
        }
        else {
            cout << '0';
        }

        if (i == orderD - 1) {
            cout << "_";
        }
        if (i == orderD - 1 - 11) {
            cout << "_";
        }
        //if ((i + 1) % 8 == 0) {
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;

    //    for (int i = 0; i < orderF; i++) {
    //        putchar(c.intNumber & muskF >> i ? '1' : '0');
    //        if ((i + 1) % 8 == 0) {
    //            cout << ' ';
    //        }
    //        }


        //5
    cout << endl;

    int type;

    cout << "enter a type number (int = 1, float = 2, double or long double = 3, short int = 4, char = 5, bool = 6): ";
    cin >> type;

    switch (type)
    {
    case 1: {
        int bitToChange;
        int intNumberToChange;

        cout << "\nenter a number (int): ";
        cin >> intNumberToChange;

        for (int i = order - 1; i >= 0; i--) {
            if (intNumberToChange & (musk << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        int maskToChange = 1;
        if (bitToChange > 0) {
            intNumberToChange = intNumberToChange ^ (maskToChange << (bitToChange - 1));
        }
        cout << "intNumberToChange: " << &intNumberToChange << " : " << intNumberToChange << endl;

        for (int i = order - 1; i >= 0; i--) {
            if (intNumberToChange & (musk << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;
        break;
    }

    case 2: {
        union {
            float floatNumberToChange;
            int intNumber;
        } c1;

        int bitToChange;

        cout << "\nenter a number (float): ";
        cin >> c1.floatNumberToChange;

        for (int i = orderF - 1; i >= 0; i--) {
            if (c1.intNumber & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == orderF - 1) {
                cout << '_';
            }
            if (i == orderF - 1 - 8) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;


        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        int maskToChange = 1;
        if (bitToChange > 0) {
            c1.intNumber = c1.intNumber ^ (maskToChange << (bitToChange - 1));
        }
        cout << "floatNumberToChange: " << &c1.floatNumberToChange << " : " << c1.floatNumberToChange << endl;


        for (int i = orderF - 1; i >= 0; i--) {
            if (c1.intNumber & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == orderF - 1) {
                cout << '_';
            }
            if (i == orderF - 1 - 8) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;
        break;
    }
    case 3: {
        union {
            double doubleNumberToChange;
            int intNumber[2];
        } d1;

        int bitToChange;
        int maskToChange = 1;

        cout << "\nenter a number (double): ";
        cin >> d1.doubleNumberToChange;

        for (int i = orderD - 1; i >= 0; i--) {
            if (i >= orderF) {
                if (d1.intNumber[1] & (muskF << (i - orderF))) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }
            else {
                if (d1.intNumber[0] & (muskF << i)) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }

            if (i == orderD - 1) {
                cout << "_";
            }
            if (i == orderD - 1 - 11) {
                cout << "_";
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        if (bitToChange > 0) {
            if (bitToChange > orderF) {
                d1.intNumber[1] = d1.intNumber[1] ^ (maskToChange << (bitToChange - 1));
            }
            else {
                d1.intNumber[0] = d1.intNumber[0] ^ (maskToChange << (bitToChange - 1));
            }

        }



        for (int i = orderD - 1; i >= 0; i--) {
            if (i >= orderF) {
                if (d1.intNumber[1] & (muskF << (i - orderF))) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }
            else {
                if (d1.intNumber[0] & (muskF << i)) {
                    cout << '1';
                }
                else {
                    cout << '0';
                }
            }

            if (i == orderD - 1) {
                cout << "_";
            }
            if (i == orderD - 1 - 11) {
                cout << "_";
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;
        break;
    }
    case 4: {
        short int bitToChange;
        short int intNumberToChange;
        short int shortMuskToChange = 1;

        cout << "\nenter a number (short int): ";
        cin >> intNumberToChange;

        for (short int i = 16 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        short int maskToChange = 1;
        if (bitToChange > 0) {
            intNumberToChange = intNumberToChange ^ (maskToChange << (bitToChange - 1));
        }
        cout << "intNumberToChange: " << &intNumberToChange << " : " << intNumberToChange << endl;

        for (short int i = 16 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;
        break;
    }

    case 5: {
        int bitToChange;
        char intNumberToChange;
        char shortMuskToChange = 1;

        cout << "\nenter a number (char): ";
        cin >> intNumberToChange;

        for (char i = 8 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        char maskToChange = 1;
        if (bitToChange > 0) {
            intNumberToChange = intNumberToChange ^ (maskToChange << (bitToChange - 1));
        }
        cout << "charNumberToChange: " << intNumberToChange << endl;

        for (char i = 8 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        break;
        cout << endl;
    }
    case 6: {
        int bitToChange;
        bool intNumberToChange;
        char shortMuskToChange = 1;

        cout << "\nenter a number (bool): ";
        cin >> intNumberToChange;

        for (char i = 8 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }

            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        cout << endl;

        cout << "\nbit to change (0 - no change): ";
        cin >> bitToChange;
        cout << endl;

        char maskToChange = 1;
        if (bitToChange > 0) {
            intNumberToChange = intNumberToChange ^ (maskToChange << (bitToChange - 1));
        }
        cout << "boolNumberToChange: " << intNumberToChange << endl;

        for (char i = 8 - 1; i >= 0; i--) {
            if (intNumberToChange & (shortMuskToChange << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }

            if (i == order - 1) {
                cout << '_';
            }
            if ((i) % 8 == 0) {
                cout << ' ';
            }
        }
        break;
        cout << endl;
    }
          /*case 7: {
              union {
                  double doubleNumberToChange;
                  int intNumber[3];
              } d2;

              int bitToChange;
              int maskToChange = 1;
              int orderLD = 12;

              cout << "\nenter a number (long double): ";
              cin >> d2.doubleNumberToChange;

              for (int i = orderLD - 1; i >= 0; i--) {
                  if (i >= orderD) {
                      if (d2.intNumber[2] & (muskF << (i - orderF))) {
                          cout << '1';
                      }
                      else {
                          cout << '0';
                      }
                  }
                  if ((i >= orderF) && (i < orderD)) {
                      if (d2.intNumber[1] & (muskF << (i - orderF))) {
                          cout << '1';
                      }
                      else {
                          cout << '0';
                      }
                  }
                  else {
                      if (d2.intNumber[0] & (muskF << i)) {
                          cout << '1';
                      }
                      else {
                          cout << '0';
                      }
                  }

                  if (i == orderLD - 1) {
                      cout << "_";
                  }
                  if (i == orderLD - 1 - 11) {
                      cout << "_";
                  }

                  if ((i) % 8 == 0) {
                      cout << ' ';
                  }
              }
              cout << endl;

              cout << "\nbit to change (0 - no change): ";
              cin >> bitToChange;
              cout << endl;

              if (bitToChange > 0) {
                  if (bitToChange > orderD) {
                      d2.intNumber[2] = d2.intNumber[2] ^ (maskToChange << (bitToChange - 1));
                  }
                  if ((bitToChange > orderF) && (bitToChange <= orderD)) {
                      d2.intNumber[1] = d2.intNumber[1] ^ (maskToChange << (bitToChange - 1));
                  }
                  else {
                      d2.intNumber[0] = d2.intNumber[0] ^ (maskToChange << (bitToChange - 1));
                  }

              }



              for (int i = orderLD - 1; i >= 0; i--) {
                  if (i >= orderD) {
                      if (d2.intNumber[2] & (muskF << (i - orderF))) {
                          cout << '1';
                      }
                      else {
                          cout << '0';
                      }
                  }
                  if ((i >= orderF) && (i < orderD)) {
                      if (d2.intNumber[1] & (muskF << (i - orderF))) {
                          cout << '1';
                      }
                      else {
                          cout << '0';
                      }
                  }
                  else {
                      if (d2.intNumber[0] & (muskF << i)) {
                          cout << '1';
                      }
                      else {
                          cout << '0';
                      }
                  }

                  if (i == orderLD - 1) {
                      cout << "_";
                  }
                  if (i == orderLD - 1 - 11) {
                      cout << "_";
                  }

                  if ((i) % 8 == 0) {
                      cout << ' ';
                  }
              }
              cout << endl;
              break;
          }*/
    default:
        cout << "\nyou entered not 1, 2, 3, 4, 5 or 6" << endl;

    }




    //ИДЗ 18

    union {
        double double18Number = 0.0;
        int int18Number[2];
    } z;

    cout
        << "\n\ndouble18Number: " << &(z.double18Number) << " : " << z.double18Number << endl;

    for (int i = orderD - 1; i >= 0; i--) {
        if (i >= orderF) {
            if (z.int18Number[1] & (muskF << (i - orderF))) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }
        else {
            if (z.int18Number[0] & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }

        if (i == orderD - 1) {
            cout << "_";
        }
        if (i == orderD - 1 - 11) {
            cout << "_";
        }
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;

    int mask18 = 1;


    for (int i = orderD - 1; i >= 0; i--) {
        if ((i >= 62) || (i < 51)) {
            z.int18Number[1] = z.int18Number[1] ^ (mask18 << i);
        }


    }

    cout
        << "\ndouble18Number: " << &(z.double18Number) << " : " << z.double18Number << endl;

    for (int i = orderD - 1; i >= 0; i--) {
        if (i >= orderF) {
            if (z.int18Number[1] & (muskF << (i - orderF))) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }
        else {
            if (z.int18Number[0] & (muskF << i)) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }

        if (i == orderD - 1) {
            cout << "_";
        }
        if (i == orderD - 1 - 11) {
            cout << "_";
        }
        if ((i) % 8 == 0) {
            cout << ' ';
        }
    }
    cout << endl;

	return 0;
}

//Bubble Sort
void bubbleSort(int* arr1, int N) {
    for (int i = (N - 1); i > 0; i--) {
        for (int n = 0; n < i; n++) {
            if (arr1[n] > arr1[n + 1])
                swap(arr1[n], arr1[n + 1]);
        }
    }

}


//Shaker Sort
void shakerSort(int* arr2, int N) {
    int left = 0, right = N - 1;
    while (left <= right) {
        for (int i = left; i < right; ++i)
        {
            if (arr2[i] > arr2[i + 1])
                swap(arr2[i], arr2[i + 1]);
        }
        --right;

        for (int i = right; i > left; --i)
        {
            if (arr2[i] < arr2[i - 1])
                swap(arr2[i], arr2[i - 1]);
        }
        ++left;
    }

}


//Insertion Sort
void insertionSort(int* arr3, int N) {
    for (int i = 1; i < N; ++i) {
        int key = arr3[i];
        int j = i - 1;
        while (j >= 0 && arr3[j] > key) {
            arr3[j + 1] = arr3[j];
            --j;
        }
        arr3[j + 1] = key;
    }
}


//SelectionSort
void selectionSort(int* arr4, int N) {
    for (int i = 0; i < N - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < N; ++j) {
            if (arr4[j] < arr4[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr4[i], arr4[minIdx]);
    }

}


//Merge Sort
void merge(int* arr5, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* left = new int[n1], * right = new int[n2];
    for (int i = 0; i < n1; ++i) left[i] = arr5[l + i];
    for (int j = 0; j < n2; ++j) right[j] = arr5[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr5[k++] = left[i++];
        else arr5[k++] = right[j++];
    }
    while (i < n1) arr5[k++] = left[i++];
    while (j < n2) arr5[k++] = right[j++];
    delete[] left;
    delete[] right;
}

void mergeSort(int* arr5, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr5, l, m);
        mergeSort(arr5, m + 1, r);
        merge(arr5, l, m, r);
    }
}

void mergeSortWrapper(int* arr5, int N) {
    mergeSort(arr5, 0, N - 1);

}


//Алгоритм бинарного поиска
int binarySearch(int arr1[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr1[mid] == value) {
            return mid;
        }

        if (arr1[mid] > value) {
            return binarySearch(arr1, value, start, mid - 1);
        }

        return binarySearch(arr1, value, mid + 1, end);
    }

    return -1;
}

//Для float
int binarySearch1(int arr1[], float value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        float fl = 1;
        float p = arr1[mid] / fl;
        float epsilon = 1e-6f;
        if (abs(p - value) < epsilon) {
            return mid;
        }

        if (abs(p - value) > epsilon) {
            return binarySearch(arr1, value, start, mid - 1);
        }

        return binarySearch(arr1, value, mid + 1, end);
    }

    return -1;
}

int main2() {

    //1

    const int N = 100;
    int arr[N];

    for (int a = 0; a < N; a++) {
        arr[a] = rand() % 199 - 99;
    };

    for (int a = 0; a < N; a++) {
        cout << arr[a] << " ";
    };
    cout << "\n\n";


    //Копии массива для разных сортировок
    int arr1[N];
    for (int a = 0; a < N; a++) {
        arr1[a] = arr[a];
    };

    int arr2[N];
    for (int a = 0; a < N; a++) {
        arr2[a] = arr[a];
    };

    int arr3[N];
    for (int a = 0; a < N; a++) {
        arr3[a] = arr[a];
    };

    int arr4[N];
    for (int a = 0; a < N; a++) {
        arr4[a] = arr[a];
    };

    int arr5[N];
    for (int a = 0; a < N; a++) {
        arr5[a] = arr[a];
    };



    //2
    /*
    bubbleSort(arr1, N);

    shakerSort(arr2, N);

    insertionSort(arr3, N);

    selectionSort(arr4, N);

    mergeSortWrapper(arr5, N);
    */


    //1)
    auto begin = steady_clock::now();
    bubbleSort(arr1, N);
    auto end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr1[a] << ' ';
    };
    cout << "\n\n";

    auto time1_ms = duration_cast<microseconds>(end - begin);
    cout << "The time BubbleSort: " << time1_ms.count() << " microseconds\n\n";


    //2)
    begin = steady_clock::now();
    shakerSort(arr2, N);
    end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr2[a] << ' ';
    };
    cout << "\n\n";

    auto time2_ms = duration_cast<microseconds>(end - begin);
    cout << "The time ShakerSort: " << time2_ms.count() << " microseconds\n\n";


    //3)
    begin = steady_clock::now();
    insertionSort(arr3, N);
    end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr3[a] << ' ';
    };
    cout << "\n\n";

    auto time3_ms = duration_cast<microseconds>(end - begin);
    cout << "The time InsertionSort: " << time3_ms.count() << " microseconds\n\n";


    //4)
    begin = steady_clock::now();
    selectionSort(arr4, N);
    end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr4[a] << ' ';
    };
    cout << "\n\n";

    auto time4_ms = duration_cast<microseconds>(end - begin);
    cout << "The time SelectionSort: " << time4_ms.count() << " microseconds\n\n";


    //5)
    begin = steady_clock::now();
    mergeSortWrapper(arr5, N);
    end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr5[a] << ' ';
    };
    cout << "\n\n";

    auto time5_ms = duration_cast<microseconds>(end - begin);
    cout << "The time MergeSort: " << time5_ms.count() << " microseconds\n\n";



    //3

    //Неотсортированный:
    // Поиск максимального элемента
    begin = steady_clock::now();
    int max = arr[0];
    for (int j = 1; j < N; ++j) {
        if (arr[j] > max) {
            max = arr[j];
        }
    }
    end = steady_clock::now();
    cout << "UnsortedMax: " << max << "\n";
    auto timeUnsortedMax = duration_cast<nanoseconds>(end - begin);
    cout << "The time UnsortedMax: " << timeUnsortedMax.count() << " nanoseconds\n\n";

    // Поиск минимального элемента
    begin = steady_clock::now();
    int min = arr[0];
    for (int j = 1; j < N; ++j) {
        if (arr[j] < min) {
            min = arr[j];
        }
    }
    end = steady_clock::now();
    cout << "UnsortedMin: " << min << "\n";
    auto timeUnsortedMin = duration_cast<nanoseconds>(end - begin);
    cout << "The time UnsortedMin: " << timeUnsortedMin.count() << " nanoseconds\n\n";

    //Отсортированный:
    // Поиск максимального элемента
    begin = steady_clock::now();
    int maxS = arr1[N - 1];
    end = steady_clock::now();
    cout << "SortedMax: " << maxS << "\n";
    auto timeSortedMax = duration_cast<nanoseconds>(end - begin);
    cout << "The time SortedMax: " << timeSortedMax.count() << " nanoseconds\n\n";

    // Поиск минимального элемента
    begin = steady_clock::now();
    int minS = arr1[0];
    end = steady_clock::now();
    cout << "SortedMin: " << minS << "\n";
    auto timeSortedMin = duration_cast<nanoseconds>(end - begin);
    cout << "The time SortedMin: " << timeSortedMin.count() << " nanoseconds\n\n";



    //4

    //Неотсортированный:
    begin = steady_clock::now();
    float f = 2;
    float UnsortedSr = (max + min) / f;
    cout << "UnsortedSr: " << UnsortedSr << "\n";
    int k = 0;
    cout << "indices of elements = UnsortedSr: ";
    for (int i = 0; i < N; i++) {
        if (UnsortedSr == arr[i]) {
            cout << i << " ";
            k++;
        }
    }
    if (k == 0) {
        cout << "0";
    }
    cout << "\nNumber of elements = UnsortedSr: " << k;
    end = steady_clock::now();

    auto timeUnsortedSr = duration_cast<microseconds>(end - begin);
    cout << "\nThe time UnsortedSr: " << timeUnsortedSr.count() << " microseconds\n\n";

    //Через бинарный поиск сделать так, чтобы в отсорт. не перебирать все
    //Oтсортированный:
    begin = steady_clock::now();
    float SortedSr = (maxS + minS) / f;
    cout << "SortedSr: " << SortedSr << "\n";

    int result4 = binarySearch1(arr1, SortedSr, 0, N - 1);
    if (result4 == -1) {
        cout << "indices of elements = SortedSr: 0" << endl << "Number of elements = SortedSr: 0" << endl;
    }
    else {
        k = 1;
        cout << "indices of elements = SortedSr: ";
        for (int h = 1; arr1[result4 - h] == arr1[result4]; h++) {
            cout << result4 - h << " ";
            k++;
        }
        cout << result4 << " ";
        for (int h = 1; arr1[result4 + h] == arr1[result4]; h++) {
            cout << result4 + h << " ";
            k++;
        }
        cout << endl << "Number of elements = SortedSr: " << k << endl;
    }
    end = steady_clock::now();

    auto timeSortedSr = duration_cast<microseconds>(end - begin);
    cout << "The time SortedSr: " << timeSortedSr.count() << " microseconds\n\n";
    //binarySearch(int arr1[], int value, int start, int end)


    //5
    int a;
    cout << "Enter a number a (from -99 to 99) ";
    cin >> a;
    k = 0;
    int t = 0;
    while ((arr1[t] < a) && (t < N)) {
        k++;
        t++;
    }
    cout << k << "\n\n";



    //6
    int b;
    cout << "Enter a number b (from -99 to 99) ";
    cin >> b;
    k = 0;
    t = N - 1;
    while ((arr1[t] > a) && (t >= 0)) {
        k++;
        t--;
    }
    cout << k << "\n\n";




    //7
    int value;
    cout << "Enter a number (from -99 to 99) ";
    cin >> value;

    begin = steady_clock::now();
    int result = binarySearch(arr1, value, 0, N - 1);
    if (result == -1) {
        cout << "Item not found" << endl;
    }
    else {
        cout << "The item is in position " << result << endl;
    }
    end = steady_clock::now();
    auto timeSearchBin = duration_cast<microseconds>(end - begin);
    cout << "The time SearchBin: " << timeSearchBin.count() << " microseconds\n\n";


    begin = steady_clock::now();
    for (int i = 0; i < N; i++) {
        if (arr1[i] == value) {
            cout << "The item is in position " << i << endl;
            break;
        }
        if (i == N - 1)
            cout << "Item not found" << endl;
    }
    end = steady_clock::now();
    auto timeSearch = duration_cast<microseconds>(end - begin);
    cout << "The time Search: " << timeSearch.count() << " microseconds\n\n";



    //8
    int n1, n2;
    cout << "Enter a number 1 (from -99 to 99) ";
    cin >> n1;
    cout << "Enter a number 2 (from -99 to 99) ";
    cin >> n2;
    begin = steady_clock::now();
    swap(arr[n1], arr[n2]);
    end = steady_clock::now();
    for (int a = 0; a < N; a++) {
        cout << arr[a] << ' ';
    };
    cout << "\n";
    auto timeSwap = duration_cast<nanoseconds>(end - begin);
    cout << "The time Swap: " << timeSwap.count() << " nanoseconds\n\n";



    //18 ИДЗ
    int u = 0, d = 0;
    int arrU[N], arrD[N];
    for (int a = 0; a < N; a++) {
        arrD[a] = 0;
    };
    for (int a = 0; a < N; a++) {
        arrU[a] = 0;
    };
    for (int i = 0; i < N; i++) {
        if (arr1[i] == arr1[i + 1]) {
            arrD[d] = arr1[i];
            arrD[d + 1] = arr1[i + 1];
            d += 2;
            i++;
        }
        else if (i > 0 && arr1[i] == arr1[i - 1]) {
            arrD[d] = arr1[i];
            d++;
        }
        else {
            arrU[u] = arr1[i];
            u++;
        }
    }
    for (int a = 0; a < N; a++) {
        cout << arrD[a] << ' ';
    };
    cout << "\n\n";
    for (int a = 0; a < N; a++) {
        cout << arrU[a] << ' ';
    };
    cout << "\n\n";


    return 0;
}

void erase1str() {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	destCoord.X = 0;
	destCoord.Y = 0;
	SetConsoleCursorPosition(hStdout, destCoord);
	cout << "                                                                               ";
	SetConsoleCursorPosition(hStdout, destCoord);
}

void consoleErase(int N) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0, k = 0; i < N; i++, k = k + 4) {
		if ((i + 2) % 2 == 0) {
			for (int j = 0; j < N; j++) {
				destCoord.X = k;
				destCoord.Y = j + 1;
				SetConsoleCursorPosition(hStdout, destCoord);
				cout << "    " << '\r';
				cout.flush();
				Sleep(100);
			}
		}
		else {
			for (int j = N - 1; j >= 0; j--) {
				destCoord.X = k;
				destCoord.Y = j + 1;
				SetConsoleCursorPosition(hStdout, destCoord);
				cout << "    " << '\r';
				cout.flush();
				Sleep(100);
			}
		}
	}
	destCoord.X = 4 * N + 1;
	destCoord.Y = N;
	SetConsoleCursorPosition(hStdout, destCoord);
	cout << endl;
}


template<int row, int col>
void consoleOut(int(&arr)[row][col], int N) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0, k = 0; i < N; i++, k = k + 4) {
		if ((i + 2) % 2 == 0) {
			for (int j = 0; j < N; j++) {
				destCoord.X = k;
				destCoord.Y = j + 1;
				SetConsoleCursorPosition(hStdout, destCoord);
				printf("%3d", arr[i][j]);
				cout << '\r';
				//cout << arr[i][j] << '\r';
				cout.flush();
				Sleep(100);
			}
		}
		else {
			for (int j = N-1; j >= 0; j--) {
				destCoord.X = k;
				destCoord.Y = j + 1;
				SetConsoleCursorPosition(hStdout, destCoord);
				printf("%3d", arr[i][j]);
				cout << '\r';
				//cout << arr[i][j] << '\r';
				cout.flush();
				Sleep(100);
			}
		}
	}
	destCoord.X = 4*N + 1;
	destCoord.Y = N;
	SetConsoleCursorPosition(hStdout, destCoord);
	cout << endl;
}

void eraseN2str(int N) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	destCoord.X = 0;
	destCoord.Y = N + 1;
	SetConsoleCursorPosition(hStdout, destCoord);
	cout << "                                                                               ";
	SetConsoleCursorPosition(hStdout, destCoord);
}

template<int Nrow, int Ncol>
void arrayFilling(int(&arr)[Nrow][Ncol], int N, int z) {
	if (z==1) {
		int* end = *arr + N * N - 1;
		for (int* ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = rand() % N * N + 1;
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = rand() % N*N + 1;
			}
		}*/
	}
	else {
		int* end = *arr + N * N - 1;
		for (int* ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = 0;
		}
	}
}

template<int N1row, int N1col>
void array1Filling(int(&arr)[N1row][N1col], int(&arr1)[N1row][N1col], int N) {
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			arr1[a][b] = arr[a][b];
		};
	};
}

template<int T21row, int T21col>
void task21(int(&arr)[T21row][T21col], int(&arr1)[T21row][T21col], int N) {
	Sleep(1000);
	cout << "Task 2.1 (1[N*N] -> 2[N*N] -> 3[N*N] -> 4[N*N] -> 1[N*N]): ";
	Sleep(1000);
	/*
	int* end = *arr + (N * N - 1)/4;
	int i = 0, j = N/2;
	for (int* ptr = *arr; ptr <= end; ptr++)
	{
		*ptr = *(*(arr1 + i) + (j + N / 2));
		i++;
		if (i = N / 2) {
			i = 0;
			j++;
		}
	}
	*/
	//4 в 1
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + i) + (j + N / 2));
		}
	}
	//1 во 2
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + (i - N / 2)) + j);
		}
	}
	//2 в 3
	for (int i = N / 2; i < N; i++) {
		for (int j = N / 2; j < N; j++) {
			arr[i][j] = *(*(arr1 + i) + (j - N / 2));
		}
	}
	//3 в 4
	for (int i = 0; i < N / 2; i++) {
		for (int j = N / 2; j < N; j++) {
			arr[i][j] = *(*(arr1 + (i + N / 2)) + j);
		}
	}
	//consoleErase(N);
	consoleOut(arr, N);
}

template<int T22row, int T22col>
void task22(int(&arr)[T22row][T22col], int(&arr1)[T22row][T22col], int N) {
	Sleep(1000);
	cout << "Task 2.2 (1[N*N] <-> 3[N*N], 2[N*N] <-> 4[N*N]): ";
	Sleep(1000);
	//1 и 3
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + (i+N/2)) + (j + N / 2));
			arr[i + N / 2][j + N / 2] = *(*(arr1 + i) + j);
		}
	}
	//2 и 4
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + (i - N / 2)) + (j + N / 2));
			arr[i - N / 2][j + N / 2] = *(*(arr1 + i) + j);
		}
	}
	consoleOut(arr, N);
}

template<int T23row, int T23col>
void task23(int(&arr)[T23row][T23col], int(&arr1)[T23row][T23col], int N) {
	Sleep(1000);
	cout << "Task 2.3 (1[N*N] <-> 4[N*N], 2[N*N] <-> 3[N*N]): ";
	Sleep(1000);
	//1 и 4
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + i) + (j + N / 2));
			arr[i][j + N / 2] = *(*(arr1 + i) + j);
		}
	}
	//2 и 3
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + i) + (j + N / 2));
			arr[i][j + N / 2] = *(*(arr1 + i) + j);
		}
	}
	consoleOut(arr, N);
}

template<int T24row, int T24col>
void task24(int(&arr)[T24row][T24col], int(&arr1)[T24row][T24col], int N) {
	Sleep(1000);
	cout << "Task 2.4 (1[N*N] <-> 2[N*N], 3[N*N] <-> 4[N*N]): ";
	Sleep(1000);
	//1 и 2
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + (i + N / 2)) + j);
			arr[i + N / 2][j] = *(*(arr1 + i) + j);
		}
	}
	//4 и 3
	for (int i = 0; i < N / 2; i++) {
		for (int j = N / 2; j < N; j++) {
			arr[i][j] = *(*(arr1 + (i + N / 2)) + j);
			arr[i + N / 2][j] = *(*(arr1 + i) + j);
		}
	}
	consoleOut(arr, N);
}

template<int T2row, int T2col>
void task2(int(&arr)[T2row][T2col], int (&arr1)[T2row][T2col], int N) {
	cout << "Task 2. Enter a number (1, 2, 3, 4 or 0 (to finish task 2)): ";
	int t2;
	cin >> t2;
	eraseN2str(N);
	switch (t2) {
	case 1: {
		task21(arr, arr1, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		task2(arr, arr1, N);
		break;
	}
	case 2: {
		task22(arr, arr1, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		task2(arr, arr1, N);
		break;
	}
	case 3: {
		task23(arr, arr1, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		task2(arr, arr1, N);
		break;
	}
	case 4: {
		task24(arr, arr1, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		task2(arr, arr1, N);
		break;
	}
	case 0: {
		return;
		break;
	}
	default: {
		cout << "You entered not 1, 2, 3, 4 or 0";
		Sleep(3000);
		eraseN2str(N);
		task2(arr, arr1, N);
		return;
		break;
	}
	}
}

//Shaker Sort
template<int Shrow, int Shcol>
void shakerSort(int(&arr)[Shrow][Shcol], int N) {
	int* right = *arr + N * N - 1;
	int* left = *arr;
	while (left <= right) {
		for (int *i = left; i < right; ++i)
		{
			if (*i > *(i + 1))
				swap(*i, *(i + 1));
		}
		--right;

		for (int *i = right; i > left; --i)
		{
			if (*i < *(i - 1))
				swap(*i, *(i - 1));
		}
		++left;
	}

}

template<int T4row, int T4col>
void task4(int(&arr4)[T4row][T4col], int N) {
	cout << "Task 4. Choose (1(+), 2(-), 3(*), 4(/)) ";
	int t4s, t4n;
	cin >> t4s;
	eraseN2str(N);
	cout << "Task 4. Enter a number ";
	cin >> t4n;
	eraseN2str(N);
	switch (t4s) {
	case 1: {
		cout << "Task 4. arr[N][N] + " << t4n;
		int* end = *arr4 + N * N - 1;
		for (int* ptr = *arr4; ptr <= end; ptr++)
		{
			*ptr = *ptr+t4n;
		}
		consoleOut(arr4, N);
		break;
	}
	case 2: {
		cout << "Task 4. arr[N][N] - " << t4n;
		int* end = *arr4 + N * N - 1;
		for (int* ptr = *arr4; ptr <= end; ptr++)
		{
			*ptr = *ptr - t4n;
		}
		consoleOut(arr4, N);
		break;
	}
	case 3: {
		cout << "Task 4. arr[N][N] * " << t4n;
		int* end = *arr4 + N * N - 1;
		for (int* ptr = *arr4; ptr <= end; ptr++)
		{
			*ptr = *ptr * t4n;
		}
		consoleOut(arr4, N);
		break;
	}
	case 4: {
		if (t4n != 0) {
			cout << "Task 4. arr[N][N] / " << t4n;
			int* end = *arr4 + N * N - 1;
			for (int* ptr = *arr4; ptr <= end; ptr++)
			{
				*ptr = *ptr / t4n;
			}
			consoleOut(arr4, N);
		}
		else {
			cout << "Task 4. You choose /0";
			Sleep(2000);
			eraseN2str(N);
			task4(arr4, N);
		}
		break;
	}
	default: {
		cout << "You entered not 1, 2, 3 or 4";
		Sleep(3000);
		eraseN2str(N);
		task4(arr4, N);
		return;
		break;
	}
	}
}

void arrayOrder(int* PN) {
	cout << "choose the array order (6, 8, 10) ";
	cin >> *PN;
	cout << endl;
	switch (*PN) {
	case 6: {
		const int N = 6;
		int arr[N][N];
		int z = 0;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		z = 1;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		Sleep(1000);
		int arr1[N][N];
		array1Filling(arr, arr1, N);
		task2(arr, arr1, N);
		cout << "Task 3. Shaker Sort";
		Sleep(1000);
		int arr3[N][N];
		array1Filling(arr1, arr3, N);
		shakerSort(arr3, N);
		consoleOut(arr3, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		//4
		int arr4[N][N];
		array1Filling(arr1, arr4, N);
		task4(arr4, N);
		break;
	}
	case 8: {
		const int N = 8;
		int arr[N][N];
		int z = 0;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		z = 1;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		Sleep(1000);
		int arr1[N][N];
		array1Filling(arr, arr1, N);
		task2(arr, arr1, N);
		cout << "Task 3. Shaker Sort";
		Sleep(1000);
		int arr3[N][N];
		array1Filling(arr1, arr3, N);
		shakerSort(arr3, N);
		consoleOut(arr3, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		//4
		int arr4[N][N];
		array1Filling(arr1, arr4, N);
		task4(arr4, N);
		break;
	}
	case 10: {
		const int N = 10;
		int arr[N][N];
		int z = 0;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		z = 1;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		Sleep(1000);
		int arr1[N][N];
		array1Filling(arr, arr1, N);
		task2(arr, arr1, N);
		cout << "Task 3. Shaker Sort";
		Sleep(1000);
		int arr3[N][N];
		array1Filling(arr1, arr3, N);
		shakerSort(arr3, N);
		consoleOut(arr3, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		//4
		int arr4[N][N];
		array1Filling(arr1, arr4, N);
		task4(arr4, N);
		break;
	}
	default: {
		cout << "You entered not 6, 8 or 10\n\n";
		arrayOrder(PN);
		break;
	}
	}
}


int main3() {
	
	int PN = 0;
	arrayOrder(&PN);
	
	/*
	//ИДЗ 18
	int const n = 10;
	int arrI[n][n], m = 1, nm;
	arrayFilling(arrI, n, m);
	consoleOut(arrI, n);
	int* end = *arrI + n * n - 1;
	for (int* ptr = *arrI; ptr <= end; ptr++)
	{
		*ptr = *ptr * 2;
	}
	consoleOut(arrI, n);
	cout << "Erase? (any number) ";
	cin >> nm;
	consoleErase(n);
	eraseN2str(n);
	*/
	return 0;
}

void sdvig(char* arr, int i, int N) {
    for (i; i < N - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

vector<int> computeLps(char* pattern, int Ls) {
    vector<int> lps(Ls, 0);
    int len = 0;
    int i = 1;

    while (i < Ls) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> kmp(char* text, char* pattern, int L, int Ls) {
    vector<int> lps = computeLps(pattern, Ls);
    vector<int> occurrences;
    int i = 0;
    int j = 0;

    while (i < L) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == Ls) {
            occurrences.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < L && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return occurrences;
}


int main4() {
    const int N = 551;
    char s1[N];
    cout << "Введите текст, в конце текста введите '/' ";
    cin.getline(s1, N, '/');
    sdvig(s1, 0, N);
    cout << s1 << endl;

    

    for (int i=0; i < N-1; i++) {
        if ((s1[i] == ' ') && (s1[i+1] == ' ')) {
            sdvig(s1, i + 1, N);
            i--;
        }
        if ((s1[i] == ',') && (s1[i + 1] == ',')) {
            sdvig(s1, i + 1, N);
            i--;
        }
        if ((s1[i] == ';') && (s1[i + 1] == ';')) {
            sdvig(s1, i + 1, N);
            i--;
        }
        if ((i<N-3) && (s1[i] == '.') && (s1[i + 1] == '.') && (s1[i + 2] == '.') && (s1[i + 3] == '.')) {
            sdvig(s1, i + 3, N);
            i--;
        }
        if ((s1[i] == ' ') && ((s1[i + 1] == ';') || (s1[i + 1] == ',') || (s1[i + 1] == '.'))) {
            sdvig(s1, i + 1, N);
            i--;
        }
    }
    cout << s1 << endl;
    char arrAZ[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    char arraz[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    
    for (int i = 1; i < N; i++) {
        int k = 0, l = 0, m = 0;
        for (int n = 0; n < 26; n++) {
            if (arrAZ[n] == s1[i]) {
                k = 1;
                m = n;
            }
        }
        for (int n = 0; n < 26; n++) {
            if ((arrAZ[n] == s1[i-1]) || (arraz[n] == s1[i-1])) {
                l = 1;
            }
        }
        if ((k == 1) && (l == 1)) {
            s1[i] = arraz[m];
        }
    }
    cout << s1 << endl << endl;

    unsigned L = 0;
    while (s1[L]) {
        ++L;
    }
    //cout << L << endl << endl;

    //3.1
    for (int r = L - 1, l; r > 0; r--) {
        while ((s1[r] == ' ') || (s1[r] == '.') || (s1[r] == ',') || (s1[r] == ';') || (s1[r] == ':') && (r > 0)) {
            r--;
        }
        l = r;
        while ((s1[l] != ' ') && (s1[l] != '.') && (s1[l] != ',') && (s1[l] != ';') && (s1[l] != ':') && (l>-1)) {
            l--;
        }
        l++;
        for (int l1 = l; l1 <= r; l1++) {
            cout << s1[l1];
        }
        cout << " ";
        r = l;
    }
    cout << endl;

    //4.1
    for (int i = 0; i < L; i++) {
        int p = 0, m = 0;
        for (int n = 0; n < 26; n++) {
            if (arraz[n] == s1[i]) {
                p = 1;
                m = n;
            }
        }
        if (((i==0) || (s1[i-1] == ' ')) && (p==1)) {
            s1[i] = arrAZ[m];
        }
    }
    cout << s1 << endl << endl;

    //5
    char p1[N];
    cout << "Введите строку, которую надо найти (последний символ - '/') ";
    cin.getline(p1, N, '/');
    sdvig(p1, 0, N);
    //cout << p1 << endl << endl;
    unsigned Ls = 0;
    while (p1[Ls]) {
        ++Ls;
    }
    //cout << Ls << endl << endl;
    
    vector<int> occurrences = kmp(s1, p1, L, Ls);

    if (occurrences.empty()) {
        cout << "Подстрока не найдена." << endl;
    }
    else {
        cout << "Подстрока найдена в позициях: ";
        for (int i : occurrences) {
            cout << i << " ";
        }
        cout << endl;
    }
    

    //dKjhSAsi     dhdAh....... fkf,,,, do dJOd doj  d, , hfhi .... 555;;; 9jdk./
    
    return 0;
}

int main() {
	//setlocale(0, " ");
	setlocale(LC_ALL, "Russian");
	int nlab;
	cout << "Какую лабу сделать? (1, 2, 3, 4) ";
	cin >> nlab;
    erase1str();
	switch (nlab) {
	case 1: {
		main1();
		break;
	}
	case 2: {
		main2();
		break;
	}
	case 3: {
		main3();
		break;
	}
	case 4: {
		main4();
		break;
	}
	default: {
		cout << "Вы ввели не 1, 2, 3 или 4\n\n";
		break;
	}
	}
	return 0;
}