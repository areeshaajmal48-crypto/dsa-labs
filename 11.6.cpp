#include <iostream>
using namespace std;

int biggestNum(int arr[], int size, int idx, int currentMax) {

    if (idx == size)
        return currentMax;

    if (arr[idx] > currentMax)
        currentMax = arr[idx];

    return biggestNum(arr, size, idx + 1, currentMax);
}

bool checkSubset(int arr[], int size, int idx, int target) {

    if (target == 0)
        return true;

    if (idx == size || target < 0)
        return false;

    return checkSubset(arr, size, idx + 1, target - arr[idx]) ||
        checkSubset(arr, size, idx + 1, target);
}

int removeLargest(int arr[], int size, int largest, int temp[], int idx, int pos) {

    if (idx == size)
        return pos;

    if (arr[idx] != largest) {
        temp[pos] = arr[idx];
        pos++;
    }

    return removeLargest(arr, size, largest, temp, idx + 1, pos);
}

int findMagic(int arr[], int size) {

    if (size <= 1)
        return -1;

    int maxValue = biggestNum(arr, size, 0, arr[0]);

    int newArr[100];

    int newSize = removeLargest(arr, size, maxValue, newArr, 0, 0);

    if (checkSubset(newArr, newSize, 0, maxValue))
        return maxValue;

    return findMagic(newArr, newSize);
}

int main() {

    int values[] = { 2, 4, 6, 10, 16 };
    int total = 5;

    int answer = findMagic(values, total);

    if (answer != -1)
        cout << "Magic Number: " << answer;
    else
        cout << "No Magic Number Found";

    return 0;
}