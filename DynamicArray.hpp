#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class DynamicArray
{
private:
    T* pointer;
    int size;    // размер массива с учетом буфера
    int count;   // кол-во занятых элементов массива
    void CheckIndexRange1(int index)const;
    void CheckIndexRange2(int index)const;
public:
    DynamicArray();
    DynamicArray(int size);
    DynamicArray(T item, int count);
    DynamicArray(T* items, int count);
    DynamicArray(const DynamicArray<T>* dynamicArray);
    DynamicArray(const DynamicArray<T> & dynamicArray);
    ~DynamicArray();
public:
    int GetSize()const ;
    int GetCount() const ;
    T Get(int index) const ;
    void Set(int index, T data);
    void Insert(int index, T data);
    void Append(const DynamicArray<T> & dynamicArray);
    void Resize(int size_new);
    void Remove(int index);
    void Print() const;
    T& operator[](int index);
    void SwapData(int index1, int index2);
    T* Getad(int index) const;
    DynamicArray<T>& operator=(const DynamicArray<T> & right);
    
};

template<typename T>
void DynamicArray<T>::CheckIndexRange1(int index)const
{
    if ((index >= this->count) || (index < 0))
        throw invalid_argument ("Index out of range DynamicArray");
}

template<typename T>
void DynamicArray<T>::CheckIndexRange2(int index)const
{
    if ((index < 0))
        throw invalid_argument ("Index out of range DynamicArray");
}

// создание по умолчанию пустого массива с буфером 10
template<typename T>
DynamicArray<T>::DynamicArray() : count(0)
{
    this->pointer = new T[10];
    this->size = 10;
}

// создаие пустого массива с заданным размером буфера
template<typename T>
DynamicArray<T>::DynamicArray(int size) : count(0), size(size)
{
    this->pointer = new T[size];
}

// создание массива и заполнение одинаковыми значениями
template<typename T>
DynamicArray<T>::DynamicArray(T item, int count): size(count * 2), count(count)
{
    this->pointer = new T[this->size];
    for (int i = 0; i < count; i++)
    {
        this->pointer[i] = item;
    }
}

// создание массива размером count и копирование значений из массива
template<typename T>
DynamicArray<T> ::DynamicArray(T* items, int count) : size(count * 2), count(count)
{
    this->pointer = new T[this->size];
    for (int i = 0; i < count; i++)
    {
        this->pointer[i] = items[i];
    }
}

// копирующий конструктор по указателю...
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>* dynamicArray) : size(dynamicArray->size), count(dynamicArray->count)
{
    pointer = new T[size];
    for (int i = 0; i < count; i++)
    {
        this->pointer[i] = dynamicArray->pointer[i];
    }
}

// копирующий конструктор
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> & dynamicArray) : size(dynamicArray.size), count(dynamicArray.count)
{
    pointer = new T[size];
    for (int i = 0; i < count; i++)
    {
        this->pointer[i] = dynamicArray.pointer[i];
    }
}


template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete [] this->pointer;
}

// размер буфера массива
template<typename T>
int DynamicArray<T>::GetSize() const
{
    return this->size;
}

// размер заполненного массива
template<typename T>
int DynamicArray<T>::GetCount() const
{
    return this->count;
}

template<typename T>
T DynamicArray<T>::Get(int index) const
{
    return this->pointer[index];
}

// меняет значение (присваивает новое значение)  элемента массива по индексу

template<typename T>
void DynamicArray<T>::Set(int index, T data)
{
    try {
        CheckIndexRange1(index);
    } catch (invalid_argument& error)
    {
        cout<<"Error (Set(int index, T data)): "<<error.what()<<endl;
        return;
    }
    this->pointer[index] = data;
    return;
}



//предповставка значения в элементе по индексу (увеличивает массив на 1 элемент)
template<typename T>
void DynamicArray<T>::Insert(int index, T data)
{
    try {
        CheckIndexRange1(index);
    } catch (invalid_argument& error)
    {
        cout<<"Error (Insert(int index, T data)) "<<error.what()<<endl;
        return;
    }
    if (this->size == this->count)
    {
        Resize(this->size * 2);
    }
    for (int i=this->count; i > index; i--)
    {
        this->pointer[i]=this->pointer[i-1];
    }
    this->pointer[index] = data;
    this->count += 1;
    return;
}

template<typename T>
void DynamicArray<T>::Append(const DynamicArray<T>& right)
{
    int new_count = count + right.count;
    int new_size = size + right.size;
    Resize(new_size);
    for (int i=count; i < new_count; i++)
        pointer[i] = right.pointer[i-count];
    count = new_count;
    return;
}


template<typename T>
void DynamicArray<T>::Resize(int size_new)
{
    try {
        CheckIndexRange2(size_new);
    } catch (invalid_argument& error)
    {
        cout<<"Error (Resize(int size_new)): "<<error.what()<<endl;
        return;
    }
    T* new_pointer = new T[size_new];
    int copySize = size_new > (this->count) ? this->count : size_new;
    for (int i=0; i < copySize; i++)
    {
        new_pointer[i] = this->pointer[i];
    }
    this->count = copySize;
    this->size = size_new;
    delete[] this->pointer;
    this->pointer = new_pointer;
    return;
}

template<typename T>
void DynamicArray<T>::Remove(int index)
{
    try {
        CheckIndexRange1(index);
    } catch (invalid_argument& error)
    {
        cout<<"Error (Remove(int index)): "<<error.what()<<endl;
        return;
    }
    for (int i=index; i<this->count; i++)
        this->pointer[i] = this->pointer[i+1];
    this->count -= 1;
}

template<typename T>
void DynamicArray<T>::Print() const
{
    for (int i=0; i< this->count; i++)
        cout<< this->pointer[i]<<"  ";
    cout<<endl;
}

template<typename T>
T& DynamicArray<T>::operator[](int index)
{
    try {
        CheckIndexRange1(index);
    } catch (invalid_argument& error)
    {
        cout<<"Error (operator[](int index)): "<<error.what()<<endl;
        return this->pointer [0];
    }
    return this->pointer [index];
}

// меняем местами 2 элемента массива с индекусами 1 и 2
template<typename T>
void DynamicArray<T>::SwapData(int index1, int index2)
{
    try {
        CheckIndexRange1(index1);
    } catch (invalid_argument& error)
    {
        cout<<"Error (SwapData(int index1, int index2)): "<<error.what()<<endl;
        return;
    }
    try {
        CheckIndexRange1(index2);
    } catch (invalid_argument& error)
    {
        cout<<"Error (SwapData(int index1, int index2)): "<<error.what()<<endl;
        return;
    }
    T temp = this->pointer[index1];
    this->pointer[index1] = this->pointer[index2];
    this->pointer[index2] = temp;
    return;
}

//возвращаем адрес элемнта массива по инднексу
template <class T>
T* DynamicArray<T> ::Getad(int index) const
{
    try {
        CheckIndexRange1(index);
    } catch (invalid_argument& error)
    {
        cout<<"Error (Getad(int index)): "<<error.what()<<endl;
        return nullptr;
    }
    return &pointer[index];
}


template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& right)
{
    
    T* temp=pointer;
    size = right.size;
    count = right.count;
    pointer = new T[size];
    for (int i=0; i < count; i++)
        pointer[i] = right.pointer[i];
    delete [] temp;
    return *this;
}
#endif /* DynamicArray_hpp */
