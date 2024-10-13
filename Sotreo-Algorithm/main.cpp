#include <iostream>
using namespace std;

int main() {
    // Ask the user for the number of integers
    int arraySize;
    cout << "================================================================" << endl;
    cout << "Enter the number of people attending [Even # between 2 and 30]: ";
    cin >> arraySize;
    
    // Test if input is EVEN and > 0, <= 30
    while( arraySize % 2 != 0 || arraySize < 0 || arraySize > 30) {
            cout << "Invalid Input. Please try again: ";
            cin >> arraySize;
    }

    // Declare an array of size n
    int* arr = new int[arraySize];

    // Take input from the user
    cout << "Enter the " << arraySize << " integers:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        cin >> arr[i];
    }
    cout << endl;

    // Output the contents of the array
    cout << "You entered the following integers:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    int placeHolder;    // Used to swap elements of the array
    int swapCounter = 0;

    // Loop through the array, checking one pair at a time
    for (int i = 0; i < arraySize; i = i + 2) {

        // If a mismatched pair is found, we find the correct number and swap them
        if ((arr[i] % 2 != 0 && arr[i + 1] != arr[i] - 1) ||
                (arr[i] % 2 == 0 && arr[i + 1] != arr[i] + 1)) {
            
            /* Loop through remainder of array to find correct partner
                - Even numbers are always paired with the number above them, so we find their +1
                - Odd numbers are always paired with the number below them, so we find their -1
            */
            for (int j = i + 1; j < arraySize; j++)  {
                if ((arr[i] % 2 != 0 && arr[j] == arr[i] - 1) ||
                (arr[i] % 2 == 0 && arr[j] == arr[i] + 1)) {

                    // Swap the correct partner with the incorrect one
                    placeHolder = arr[i + 1];
                    arr[i + 1] = arr[j];
                    arr[j] = placeHolder;
                }
            }
            
            swapCounter++;
        }
        
        
    }
    
    // Display number of swaps and correctly-paired array
    cout << "The number of swaps: " << swapCounter << endl;
    cout << "The correct pairs are: " << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "================================================================" << endl;
    
    return 0;
}
