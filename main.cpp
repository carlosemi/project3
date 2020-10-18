#include <iostream>

using namespace std;

class Algorithms
{

public:
    //This function is for selection sort
    void selectionSort(int numbers[], int numbersSize)
    {

        int i = 0;
        int j = 0;

        int indexSmallest = 0;
        int temp = 0;

        for (i = 0; i < numbersSize; i++)
        {

            //Find index of smallest remaining element
            indexSmallest = i;

            for (j = i + 1; j < numbersSize; j++)
            {

                if (numbers[j] < numbers[indexSmallest])
                {
                    indexSmallest = j;
                }
            }

            //Swap numbers[i] and numbers[indexSmallest]
            temp = numbers[i];
            numbers[i] = numbers[indexSmallest];
            numbers[indexSmallest] = temp;
        }

        //Print the sorted array
        cout << "Selection Sort: ";
        for (int z = 0; z < numbersSize; z++)
        {

            cout << numbers[z] << " ";
        }

        cout << endl;
    }

    void insertionSort(int numbers[], int numbersSize)
    {
        int i = 0;
        int j = 0;

        int temp = 0; //Temporary variable for swap

        for (i = 1; i < numbersSize; i++)
        {

            j = i;
            //Insert numbers[i] into sorted array
            //stopping once numbers[i] in correct position

            while (j > 0 && numbers[j] < numbers[j - 1])
            {

                //Swap numbers[j] and numbers[j - 1]
                temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;

                --j;
            }
        }

        //Print the Insertion array
        cout << "Insertion Sort: ";
        for (int z = 0; z < numbersSize; z++)
        {

            cout << numbers[z] << " ";
        }

        cout << endl;
    }

    void shellSort()
    {
    }

    void quickSort()
    {
    }

    void mergeSort(int numbers[], int i, int k)
    {

        // void merge(int numbers[], i, j, k){
        //     int mergedSize = k - i + 1;
        //     int mergePos = 0;
        //     int leftPos = 0;
        //     int rightPos = 0;

        // }
    }
};

int main()
{

    //cout << ("Starting Program") << endl;

    int array[] = {4, 3, 8, 5, 6};

    int size = sizeof(array) / sizeof(array[0]);
    cout << "Size of array: " << size << endl;
    cout << "Unsorted array: ";

    for (int z = 0; z < 5; z++)
    {

        cout << array[z] << " ";
    }

    cout << endl;

    Algorithms algo;

    //algo.selectionSort(array, size);
    algo.insertionSort(array, size);
}