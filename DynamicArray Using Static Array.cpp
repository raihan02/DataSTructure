#include <iostream>
using namespace std;
  
template <typename T>
class Array {
private:
    T *ptr;
    int len = 0;
    int capacity = 0;
    
  
public:
    Array(T arr[], int s);
    void print();
    Array()
    {
        capacity = 16;
    }
    Array(int capacity){
        if(capacity < 0){
            throw invalid_argument("Illegal Capacity: ");
        }
        else{
            this->capacity = capacity;
            ptr = new T[capacity];
        }
    }
    
    int size(){
        return len;
    }
    bool isEmpty()
    {
        return size() == 0;
    }
    
    void clear()
    {
        for(int i = 0; i < len; i++){
            ptr[i] =  NULL;
        }
        len = 0;
    }
    T get (int index){
        return ptr[index];
    }
    void set (int index, int item){
        ptr[index] = item;
    }
    
    void add(int item){
        if(len + 1 >= capacity){
            if(capacity == 0){
                capacity = 1;
            }
            else{
                capacity = capacity * 2;
            }
            T *newArray = new T[capacity];
            for(int  i = 0; i < len; i++){
                newArray[i] = ptr[i];
            }
            
            ptr = newArray;
        }
        ptr[len++] = item;
    }
    
    T removeAt(int index){
        if(index >= len && index < 0){
            throw invalid_argument("Index out of bound");
        }
        
        T data = ptr[index];
        T *newArray = new T[capacity];
        
        for(int i = 0, j = 0; i < len; i++,j++){
            if(i == index){
                j--;
            }
            else{
                newArray[j] = ptr[i];
            }
        }
        ptr = newArray;
        capacity = --len;
        return data;
    }
    
    int indexOf(T obj){
        for(int i = 0; i < len; i++){
            if(obj == NULL){
                if(ptr[i] == NULL){
                    return i;
                }
            }
            else{
                if(obj == ptr[i]){
                    return i;
                }
            }
        }
        
        return -1;
    }
    
    bool remove(T obj){
        int index = indexOf(obj);
        if(index == -1){
            return false;
        }
        removeAt(index);
        return true;
    }
    
    bool contain(T obj){
        return  indexOf(obj) != -1;
    }
    
    void printArray()
    {
        for(int i = 0; i < len; i++){
            cout<< ptr[i] << " ";
        }
        cout<< endl;
    }
    
};
  

int main()
{
    Array<int> A(20);
    A.size();
    A.add(10);
    A.printArray();
    A.add(102);
    A.printArray();
    cout<<A.removeAt(0)<< endl;
    
    for(int i = 0; i < 21;i++){
        A.add(i);
    }
    A.printArray();
    A.removeAt(17);
    A.printArray();
    return 0;
}
