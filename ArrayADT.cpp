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

    void insert(int index, int val)//inserts at a given index
    {
        if ((index >= 0) && (index < length) && (length<size))
        {
            int temp = length;
            while (temp != index)
            {
                arr[temp] = arr[temp-1];
                temp--;
            }
            arr[index]=val;
            length++;
        }
        else cout<<"Invalid index\n";
    }
    void remove(int index){//removes the element whose index is given
         if (index >= 0 && index < length){
             for(int i=index;i<length-1;i++){
                 arr[i]=arr[i+1];
             }
             length--;
         }
    }
    int search(int val){//linear search ,returns the index at where the val is
        for(int i=0;i<length;i++){
            if(arr[i]==val){
                return i;
            }
        }            
        return -1;
    }
    int binarySearch(int val){//for sorted array only
        int s=arr[0],e=arr[length-1],mid;
        while(s<=e){
            mid=(s+e)/2;
            if(val<arr[mid]){
                e=mid-1;
            }
            else if(val>arr[mid]) s=mid+1;
            else return mid; 

        }
        return -1;
    }
    int get(int index){//gets value of given index
        if(index>=0 && index<length){
            return arr[index];
        }
        else return -1;
    }
    void set(int index,int val){//sets value of given index
        if(index>=0 && index<length){
            arr[index]==val;
        }
        else cout<<"Enter valid index\n";
    }

};

int main()
{
    Array a(10);
    a.add(2);
    a.add(3);
    a.add(4);
    a.insert(2,3);
    a.display();
    a.remove(2);
    a.display();


    return 0;
}