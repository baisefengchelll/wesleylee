#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<string.h>
using namespace std;
// 整型数组，把偶数调整到数组的左边，把奇数调整到数组的右边
void AdjustArray(int arr[], int size) {
    int* p = arr;
    int* q = arr + size - 1;
    while (p < q) {
        // p-> 奇数
        if ((*p & 0x1) == 0) { //位操作
            p++;
            continue;
        }
        // q-< 偶数
        if ((*q & 0x1) == 1) {
            q--;
            continue;
        }
        int temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}
int main()
{
    int arr[10] = { 0 };
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }

    for (int v : arr) {
        cout << v << " ";
    }
    cout << endl;
    AdjustArray(arr, 10);

    for (int v : arr) {
        cout << v << " ";
    }
    return 0;
}
#if 0
char* Reverse(char arr[], int size)
{
    char* p = arr;
    char* q = arr + size - 1;
    while (p < q) {
        char ch = *p;
        *p = *q;
        *q = ch;
        p++;
        q--;
    }
    return arr;
}
int main() {
    char str[] = "hello world";
    cout << "before reverse: " << str << endl;
    cout << "After reverse: " << Reverse(str, strlen(str)) << endl;
    return 0;
}

class Array
{
public:
    Array(int size = 10);
    ~Array();
    void push_back(int val);       // 在末尾添加元素
    void pop_back(int &val);       // 在末尾删除元素
    void insert(int pos, int val); // 插入元素
    void erase(int pos, int &val); // 删除元素
    int find_by_pos(int pos);             // 按位置查找
    int find_by_val(int val);             // 按值查找
    void show() {
        for (int i = 0; i < mCur_; i++) {
            cout << mArr[i] << ' ';
        }
        cout << endl;
    }
private:
    void expand(int size);
    int *mArr;
    int mCap_;
    int mCur_;
};
Array::Array(int size)
{
    cout << "create an array at heap" << endl;
    mArr = new int[size];
    mCap_ = size;
    mCur_ = 0;
}

Array::~Array()
{
    delete[] mArr;
    cout << "release an array at heap" << endl;
    mArr = nullptr;
}

void Array::push_back(int val)
{
    if (mCur_ == mCap_)
        expand(2 * mCap_); // 堆内存不够，需要扩容
    mArr[mCur_] = val;
    mCur_++;
}
void Array::pop_back(int &val)
{
    if (mCur_ == 0)
        return;
    val = mArr[mCur_ - 1];
    mCur_--;
}

void Array::insert(int pos, int val)
{
    if (pos < 0 || pos > mCur_){
        cout << "访问位置越界" <<endl;
        return;
    }
    for (int i = mCur_; i > pos; i--)
    {
        mArr[i] = mArr[i - 1];
    }
    mArr[pos] = val;
    mCur_++;
}
void Array::erase(int pos, int &val)
{
    if (pos < 0 || pos > mCur_ - 1)
        return;
    val = mArr[pos];
    for (int i = pos; i < mCur_; i++)
    {
        mArr[i] = mArr[i+1];
    }
    mCur_--;
}

int Array::find_by_pos(int pos)
{
    if(pos < 0 || pos > mCur_-1){
        cout << "访问位置越界" <<endl;
        return -1;
    }
    return mArr[pos];
}
int Array::find_by_val(int val)
{
    for(int i = 0; i<mCur_; i++){
        if(mArr[i] == val) return i;
    }
    cout << "目标值未找到" <<endl;
    return -1;
}

void Array::expand(int size)
{
    int *p = mArr;
    mArr = new int[size];
    for (int i = 0; i < mCap_; i++)
    {
        mArr[i] = p[i];
    }
    mCap_ = size;
    delete[] p;
}

int main()
{
    Array a1(10);
    time(0);
    srand(time(0));
    for (int i = 0; i < 10; i++) a1.push_back(rand());
    a1.show();

    a1.push_back(100);
    a1.show();
    
    int val1;
    int val2;
    a1.pop_back(val1);
    cout << "val1: " << val1 << endl;
    a1.pop_back(val2);
    cout << "val2: " << val2 << endl;
    a1.show();

    a1.insert(5, 5);
    a1.show();

    int val3;
    a1.erase(2, val3);
    cout << "val3: " << val3 << endl;
    a1.show();

    return 0;
}
#endif
