#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Massivin random ədədlərlə doldurulması (overloading)
void fillRandom(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Random integer (0-99)
    }
}

void fillRandom(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 10000) / 100.0;  // Random double (0.00-99.99)
    }
}

void fillRandom(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 10000) / 100.0f;  // Random float (0.00-99.99)
    }
}

void fillRandom(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 'A' + rand() % 26;  // Random char (A-Z)
    }
}

// 2. Massivin verilən diapazonda ədədlərlə doldurulması
void fillWithRange(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

// 3. Massivi ekrana çıxaran funksiya (overloading)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 4. Bubble sort (overloading ilə)
void bubbleSort(int arr[], int size, bool descending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((descending && arr[j] < arr[j + 1]) || (!descending && arr[j] > arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 5. Massivdə elementi axtaran funksiya (overloading ilə)
int findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// 6. Massivdəki ən kiçik elementi tapan funksiya
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// 7. Massivdəki ən böyük elementi tapan funksiya
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 8. Massivin sağa dövrü sürüşməsi
void rotateRight(int arr[], int size, int shift) {
    shift = shift % size;  // Sürüşməni ölçüyə uyğunlaşdırırıq
    for (int i = 0; i < shift; i++) {
        int last = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;
    }
}

int main() {
    srand(time(0));  // Random generatoru işə salırıq

    const int size = 5;
    int arr[size];

    // Random integer massivini doldurmaq
    fillRandom(arr, size);
    cout << "Randomly filled array: ";
    printArray(arr, size);

    // Verilən diapazonda massiv doldurmaq
    fillWithRange(arr, size, 10, 50);
    cout << "Array filled with range (10-50): ";
    printArray(arr, size);

    // Massivi sıralamaq (azalan sırada)
    bubbleSort(arr, size, true);
    cout << "Array after sorting (descending): ";
    printArray(arr, size);

    // Element axtarmaq
    int target = 25;
    int index = findElement(arr, size, target);
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    }
    else {
        cout << "Element " << target << " not found in array." << endl;
    }

    // Ən kiçik element
    cout << "Smallest element: " << findMin(arr, size) << endl;

    // Ən böyük element
    cout << "Largest element: " << findMax(arr, size) << endl;

    // Massivin sağa sürüşdürülməsi
    int shiftBy = 2;
    rotateRight(arr, size, shiftBy);
    cout << "Array after right rotation by " << shiftBy << ": ";
    printArray(arr, size);

    return 0;
}
