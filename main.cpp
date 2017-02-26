/*
 * De_Leon_Adam_PA3.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Adam C. De Leon
 *      Class: CS2308
 *      Section number: 1
 *      Roster number: 6
 *      Program number: 3
 *      Program Description: This program creates one array of size 25 and
 *      fills it with random numbers. Then it creates a second array of size
 *      50 and fills the first ten elements with random numbers and proceeds
 *      to fill the rest of that array with zeros. The program then passes the
 *      addresses of each array, using pointers, to the DisplayArray function,
 *      which displays the values stored in each array. After this the program
 *      passes the address of the first, array using pointers, to the MinArray
 *      function which determines and displays the minimum value stored in the
 *      first array. Then the program passes the address of the first array,
 *      using pointers, to the MaxArray function that determines which index
 *      holds the largest element stored in that array. Next the program
 *      passes the addresses of both arrays, using pointers, to the
 *      AppendArray function in order to append the values of the first array
 *      into the second array; beginning at the eleventh index of the second
 *      array. Then the program uses pointers to pass the address of the
 *      second array back to the DisplayArray function which displays the
 *      values stored in the second array after it has been appended with the
 *      values from the first array. After this the array is sent to the
 *      Rotate function which shifts the values in the array over one spot.
 *      Finally the array is passed with pointers to the DisplayArray function
 *      to display array2 after the being rotated.
 */
#include <iostream>  // Libraries needed for program
#include <cstdlib>
#include <ctime>

using namespace std;

void DisplayArray(int *, int);  // Prototypes for each funtion
void MinArray(int *, int);

void MaxArray(int *, int);

void AppendArray(int *, int *, int);

void RotateArray(int *, int);

int LinearSearch(int *, int, int);

const int SIZE1 = 25;  // Size allocated for Array1
const int SIZE2 = 50;  // Size allocated for Array2
const int MAX_INT = 100;  // Limit for random number generator

int main() {
    int array1[SIZE1];  // Array declarations
    int array2[SIZE2];

    // Program Author output
    cout << "This program was written by Adam C. De Leon." << endl;
    cout << endl;

    // create array1 and load it with random numbers
    srand(time(0));
    for (int i = 0; i < SIZE1; i++) {
        array1[i] = rand() % MAX_INT;
    }

    cout << "Array 1 is: ";  // Title for displaying array1
    DisplayArray(array1, SIZE1); // Function for displaying array1
    cout << endl;

    for (int i = 0; i < SIZE2; i++) {
        array2[i] = rand() % MAX_INT;
        if (i > 9)                   // Limit for loading only first 10 indexes
        {
            array2[i] = 0;
        }
    }

    cout << "Array 2 is: ";    // Title for displaying array2
    DisplayArray(array2, SIZE2);  // Function for displaying array2
    cout << endl;

    MinArray(array1, SIZE1);  // Function for finding and displaying min value

    MaxArray(array1, SIZE1);  // Function for finding and displaying max index
    cout << endl;

    cout << "Array 2 after append is: "; // Title for appended array2
    AppendArray(array1, array2, SIZE1); // Function for appending array values
    DisplayArray(array2, SIZE2);
    cout << endl;

    RotateArray(array2, SIZE2); // Function for rotating array2
    cout << "Array 2 after Rotate is: "; // Title for Rotated array2
    DisplayArray(array2, SIZE2);  // Function for displaying rotated array2

    return 0;
}

/*****************************************************************************
 * DisplayArray - This function displays the array.
 */
void DisplayArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

/*****************************************************************************
 * MinArray - This function finds the minimum value stored in the array.
 */
void MinArray(int *array, int size) {
    int min_int = MAX_INT;
    for (int i = 0; i < size; i++) {
        if (array[i] < min_int) {
            min_int = array[i];
        }
    }
    cout << "Min element in array 1 is: " << min_int << endl;
}

/*****************************************************************************
 * LinearSearch - Performs a linear search in the array to find the inquired
 * value.
 */
int LinearSearch(int *array, int size, int value) {
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < size && !found) {
        if (array[index] == value) {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

/*****************************************************************************
 * MaxArray - This function finds the index of the element that stores the
 * maximum value in the array.
 */
void MaxArray(int *array, int size) {
    int position;
    int max_int = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > max_int) {
            max_int = array[i];
            position = LinearSearch(array, size, max_int);
        }
    }
    cout << "Index to max element in array 1 is: " << position;
}

/*****************************************************************************
 * AppendArray - This function appends the values of the first array to the
 * second array beginning at the eleventh index of the second array.
 */
void AppendArray(int *firstarray, int *secondarray, int size) {
    for (int i = 0; i < size; i++) {
        secondarray[i + 10] = firstarray[i];
    }
}

/*****************************************************************************
 * RotateArray - This function shifts the values of the array over one spot.
 */
void RotateArray(int *array, int size) {
    int temp = array[0];
    for (int i = 0; i < (size - 1); i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = temp;
}
