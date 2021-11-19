#include <iostream>
using namespace std;

class Array
{
    int *arr;
    int length;
    int size;

public:
    Array(int size)
    { // creates array of given size with no elements
        arr = new int[size];
        this->size = size;
        length = 0;
    }
    Array()
    { // creates array of given size with no elements
        size = 10;
        arr = new int[size];
        length = 0;
    }
    ~Array() { delete[] arr; } // destructor

    void add(int val)
    { // add element at last
        if (length < size)
        {
            arr[length] = val;
            length++;
        }
        else
        {
            cout << "no space\n";
        }
    }
    void display()
    { // prints the array
        if (length > 0)
        {
            for (int i = 0; i < length; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else
            cout << "no elemetns\n";
    }

    void insert(int index, int val) // inserts at a given index
    {
        if ((index >= 0) && (index <= length) && (length < size))
        {
            int temp = length;
            while (temp != index)
            {
                arr[temp] = arr[temp - 1];
                temp--;
            }
            arr[index] = val;
            length++;
        }
        else
            cout << "Invalid index\n";
    }
    void remove(int index)
    { // removes the element whose index is given
        if (index >= 0 && index < length)
        {
            for (int i = index; i < length - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }
    int search(int val)
    { // linear search ,returns the index at where the val is
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    int binarySearch(int val)
    { // for sorted array only
        int s = 0, e = length - 1, mid;
        while (s <= e)
        {
            mid = (s + e) / 2;
            if (val < arr[mid])
            {
                e = mid - 1;
            }
            else if (val > arr[mid])
                s = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    int get(int index)
    { // gets value of given index
        if (index >= 0 && index < length)
        {
            return arr[index];
        }
        else
            return -1;
    }
    void set(int index, int val)
    { // sets value of given index
        if (index >= 0 && index < length)
        {
            arr[index] == val;
        }
        else
            cout << "Enter valid index\n";
    }
    int max()
    { // retrurns max element
        int max = arr[0];
        for (int i = 1; i < length; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }
    int min()
    { // returns min element
        int min = arr[0];
        for (int i = 1; i < length; i++)
        {
            if (arr[i] < min)
                min = arr[i];
        }
        return min;
    }
    void reverse()
    { // reverses the array
        for (int i = 0; i < length / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[length - 1 - i];
            arr[length - 1 - i] = temp;
        }
    }
    void shiftLeft()
    { // shifts elements to one space left and last element becomes 0
        int temp = arr[0];
        for (int i = 0; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = 0;
    }
    void Rearrange()
    { // all negative elements shift towards left and positive ones on right
        int i, j;
        i = 0;
        j = length - 1;

        while (i < j)
        {
            while (arr[i] < 0)
                i++;
            while (arr[j] >= 0)
                j--;
            if (i < j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
};

int main()
{
    Array a(10);
    a.add(2);
    a.add(3);
    a.add(4);
    a.insert(2, 3);
    a.display();
    a.remove(2);
    a.display();
    a.reverse();
    a.display();
    a.reverse();
    a.add(23);
    a.display();
    cout << a.binarySearch(23) << "\n";
    a.shiftLeft();
    a.display();

    return 0;
}