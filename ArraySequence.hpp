#ifndef ArraySequence_h
#define ArraySequence_h

#include "Sequence.hpp"
#include "DynamicArray.hpp"

template <typename T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* items;
    //int count;
    //int size;
public:
    ArraySequence();
    ArraySequence(T it, int count);
    ArraySequence(T* its, int count);
    ArraySequence(const ArraySequence<T> * arraySequence); //  работает 
    ArraySequence(const ArraySequence<T> & arraySequence);//  работает 
    ~ArraySequence();
public:
    virtual T GetFirst()const override;
    virtual T GetLast()const override;
    virtual T Get_(int index)const override;
    virtual int GetLength_()const override;
    virtual void Remove_(int index)override;
    virtual void  Append_(T it)override;
    virtual void Prepend_(T it)override;
    virtual void InsertAt_(T it, int index)override;
    virtual void Set_(T it, int index)override;
    virtual void SwapData_(int index1, int index2)override;
    virtual T* Getadress_(int index)const override;
    virtual void Print_()const override;
    virtual Sequence<T>* Concat(Sequence<T>* sequence_array)override;
    virtual Sequence<T>* GetSubSequence(int start_index, int end_index)const override;
    
};

template <typename T>
ArraySequence<T>::ArraySequence()
{
    this->items = new DynamicArray<T>();
}
    
template  <typename T>
ArraySequence<T>::ArraySequence(T it,  int count)
{
    this->items = new DynamicArray<T>(it, count);
}

template <typename T>
ArraySequence<T>::ArraySequence(T* its, int counnt)
{
    this->items = new DynamicArray<T>(its, count);
}

template <typename T>
ArraySequence<T>::ArraySequence(const ArraySequence<T>* arraySequence)
{
    this->items = new DynamicArray<T>(arraySequence);
}

template <typename T>
ArraySequence<T>::ArraySequence(const ArraySequence<T>& arraySequence)
{
    this->items = new DynamicArray<T>(arraySequence);
}

template<typename T>
ArraySequence<T>::~ArraySequence()
{
    delete this->items;
}

template<typename T>
T ArraySequence<T>::GetFirst() const
{
    return this->items->Get(0);
}

template<typename T>
T ArraySequence<T>::GetLast() const
{
    return this->items->Get(this->items->GetCount()-1);
}

template<typename T>
T ArraySequence<T>::Get_(int index) const
{
    return this->items->Get(index);
}

template<typename T>
int ArraySequence<T>::GetLength_() const
{
    return this->items->GetCount();
}

template<typename T>
void ArraySequence<T>::Remove_(int index)
{
    this->items->Remove(index);
    return;
}

template<typename T>
void ArraySequence<T>::Append_(T data)
{
    DynamicArray<T> temp = DynamicArray<T>(data, 1);
    this->items->Append(temp);
    return;
}

template<typename T>
void ArraySequence<T>::Prepend_(T data)
{
    this->items->Insert(0, data);
    return;
}

template<typename T>
void ArraySequence<T>::InsertAt_(T data, int index)
{
    this->items->Insert(index, data);
    return;
}

template<typename T>
void ArraySequence<T>::Set_(T data, int index)
{
    this->items->Set(index, data);
    return;
}

template<typename T>
void ArraySequence<T>::SwapData_(int index1, int index2)
{
    this->items->SwapData(index1, index2);
    return;
}

template<typename T>
T* ArraySequence<T>::Getadress_(int index)const
{
    return this->items->Getad(index);
}

template<typename T>
void ArraySequence<T>::Print_()const
{
    this->items->Print();
    return;
}


template<typename T>
Sequence<T>* ArraySequence<T>::Concat(Sequence<T>* sequence_array)
{
    sequence_array = (ArraySequence*)sequence_array;
    ArraySequence<T>* temp = new ArraySequence();
    for (int i = 0; i < this->GetLength_(); i++)
        temp->Append_(this->Get_(i));
    for (int i = 0; i < sequence_array->GetLength_(); i++)
        temp->Append_(sequence_array->Get_(i));
    return temp;
}

template<typename T>
Sequence<T>* ArraySequence<T>::GetSubSequence(int start_index, int end_index)  const
{
    Sequence<T>* subSequence = new ArraySequence();
    if (start_index>end_index)
        return subSequence;
    for (int i = start_index; i < end_index + 1; i++)
        subSequence->Append_(this->Get_(i));
    return subSequence;
}


#endif /* ArraySequence_h */
