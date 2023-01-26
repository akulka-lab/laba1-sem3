#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

template<typename T>
class Nudl
{
private:
    Nudl<T>* next;
    Nudl<T>* prev;
    T value;
public:
    Nudl() : next(NULL), prev(NULL), value(NULL) {}
    Nudl(T data) : next(NULL), prev(NULL), value(data) {}
    
    Nudl<T>* GetNext() { return this->next; }
    Nudl<T>* GetPrev() { return this->prev; }
    T GetValue()       { return this->value; }

    void SetNext(Nudl<T>* NextPointer) {  this->next  = NextPointer; }
    void SetPrev(Nudl<T>* PrevPointer) {  this->prev  = PrevPointer; }
    void SetValue(T data)              {  this->value = data; }
    void Set(Nudl<T>* NextPointer, Nudl<T>* PrevPointer, T data)
    {
        this->next  = NextPointer;
        this->prev  = PrevPointer;
        this->value = data;
    }
};

template<typename T>
class LinkedList
{
private:
    Nudl<T>* begin;
    Nudl<T>* end;
    int length;
    void CheckCountRange(int count);
    void CheckCountRange2(int count);
    void CheckTPointer(T * pointer);
    void CheckNudlPointer(Nudl<T> * pointer);
    void CheckIndexlSUblist(int indexA, int indexB);
    
public:
    void SetBegin(Nudl<T>* BeginPointer);
    void SetEnd(Nudl<T>* EndPointer);
    void SetLength(int count);

    Nudl<T>* GetBegin() const;
    Nudl<T>* GetEnd() const;
    int GetLength() const;
    
    
    LinkedList();
    LinkedList(T* items, int count);
    LinkedList(T item, int count);
    LinkedList(const LinkedList<T>* list);
    LinkedList(const LinkedList<T>& list);
//    ~LinkedList();
    
public:
    Nudl<T>* PointerWithIndex(int index);
    
    T Get(int index);
    T GetFirst();
    T GetLast();
    void InsertAt(T item, int index);
    void Append(T item);
    void Prepend(T item);
    LinkedList<T>* GetSubList(int startIndex, int endIndex);
    void CatSubListInline(int startIndex, int endIndex);
    LinkedList<T>* Concat(LinkedList<T>* list);
    void Remove(int index);
    void Print();
    void PrintFull();
    

};
template<typename T>
void LinkedList<T>::CheckCountRange(int count)
{
    if (count < 0)
        throw invalid_argument ("Lenght out of range LinkedList");
}

template<typename T>
void LinkedList<T>::CheckCountRange2(int count)
{
    if ((count < 0) || (count > this->GetLength()))
        throw invalid_argument ("Lenght out of range LinkedList");
}

template<typename T>
void LinkedList<T>::CheckTPointer(T * pointer)
{
    if (pointer == NULL)
        throw invalid_argument ("Pointer is NULL");
}

template<typename T>
void LinkedList<T>::CheckNudlPointer(Nudl<T> * pointer)
{
    if (pointer == NULL)
        throw invalid_argument ("Pointer Nudl<T> is NULL");
}

template<typename T>
void LinkedList<T>::CheckIndexlSUblist(int indexA, int indexB)
{
    if (indexA > indexB)
        throw invalid_argument ("Error index sublist (indexA > indexB)");
}


template<typename T>
void LinkedList<T>::SetBegin(Nudl<T>* BeginPointer)
{
    this->begin = BeginPointer;
}
template<typename T>
void LinkedList<T>::SetEnd(Nudl<T>* EndPointer)
{
    this->end = EndPointer;
}
template<typename T>
void LinkedList<T>::SetLength(int count)
{
    this->length = count;
}
template<typename T>
Nudl<T>* LinkedList<T>::GetBegin() const
{
    return this->begin;
}
template<typename T>
Nudl<T>* LinkedList<T>::GetEnd() const
{
    return this->end;
}

template<typename T>
int LinkedList<T>::GetLength() const
{
    return this->length;
}

template<typename T>
LinkedList<T>::LinkedList() :begin(NULL), end(NULL), length(0) {}

template<typename T>
LinkedList<T>::LinkedList(T* pointer, int count) : length(count)
{
    try
    {
        CheckCountRange(count);
        CheckTPointer(pointer);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (LinkedList(T* pointer, int count)): "<<error.what()<<endl;
        return;
    }
    
    Nudl<T>* PreviosPointer = new Nudl<T>(pointer[0]);
    
    SetBegin(PreviosPointer);
    for (int i = 1; i < length; i++)
    {
        Nudl<T>* Pointer = new Nudl<T>(pointer[i]);
        Pointer->SetPrev(PreviosPointer);
        PreviosPointer->SetNext(Pointer);
        PreviosPointer = Pointer;
    }
    SetEnd(PreviosPointer);
}

template<typename T>
LinkedList<T>::LinkedList(T item, int count) : length(count)
{
    try
    {
        CheckCountRange(count);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (LinkedList(T item, int count)): "<<error.what()<<endl;
        return;
    }
    
    Nudl<T>* PreviosPointer = new Nudl<T>(item);
    
    SetBegin(PreviosPointer);
    for (int i = 1; i < length; i++)
    {
        Nudl<T>* Pointer = new Nudl<T>(item);
        Pointer->SetPrev(PreviosPointer);
        PreviosPointer->SetNext(Pointer);
        PreviosPointer = Pointer;
    }
    SetEnd(PreviosPointer);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>* list)
{
    try
    {
        CheckNudlPointer(list->GetBegin());
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (LinkedList(const LinkedList<T>* list)): "<<error.what()<<endl;
        this->SetBegin(nullptr);
        this->SetEnd(nullptr);
        this->SetLength(0);
        return;
    }

   
    this->SetLength(list->GetLength());
    Nudl<T>* SourcePointer = list->GetBegin();
    Nudl<T>* CopyPointer = new Nudl<T>(SourcePointer->GetValue());
    this->SetBegin(CopyPointer);
    while (SourcePointer != list->GetEnd())
    {
        Nudl<T>* PreviousCopyPointer = CopyPointer;
        SourcePointer = SourcePointer->GetNext();
        CopyPointer = new Nudl<T>(SourcePointer->GetValue());
        CopyPointer->SetPrev(PreviousCopyPointer);
        PreviousCopyPointer->SetNext(CopyPointer);
    }
    this->SetEnd(CopyPointer);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
    try
    {
        CheckNudlPointer(list.GetBegin());
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (LinkedList(const LinkedList<T>& list)): "<<error.what()<<endl;
        this->SetBegin(nullptr);
        this->SetEnd(nullptr);
        this->SetLength(0);
        return;
    }
    
   
    this->SetLength(list.GetLength());
    Nudl<T>* SourcePointer = list.GetBegin();
    Nudl<T>* CopyPointer = new Nudl<T>(SourcePointer->GetValue());
    this->SetBegin(CopyPointer);
    while (SourcePointer != list.GetEnd())
    {
        Nudl<T>* PreviousCopyPointer = CopyPointer;
        SourcePointer = SourcePointer->GetNext();
        CopyPointer = new Nudl<T>(SourcePointer->GetValue());
        CopyPointer->SetPrev(PreviousCopyPointer);
        PreviousCopyPointer->SetNext(CopyPointer);
    }
    this->SetEnd(CopyPointer);
}

/*
template<typename T>
LinkedList<T>::~LinkedList()
{
    int len =  this->GetLength();
    Nudl<T>* tempPointer = this->GetBegin();
    Nudl<T>* nextPointer = nullptr;
    for (int i=0; i< len;i++)
    {
        nextPointer = tempPointer->GetNext();
        delete tempPointer;
        tempPointer = nextPointer;
    }
    return;
}
*/


template<typename T>
Nudl<T>* LinkedList<T>::PointerWithIndex(int index)
{
    try
    {
        CheckNudlPointer(this->GetBegin());
        CheckCountRange2(index);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (PointerWithIndex(int index)): "<<error.what()<<endl;
        return NULL;
    }
    
    int counter;
    Nudl<T>* temporaryPointer;
    if (index <= this->GetLength() / 2)
    {
        counter = 0;
        temporaryPointer = this->GetBegin();
        while (counter != index)
        {
            temporaryPointer = temporaryPointer->GetNext();
            counter++;
        }
    }
    else
    {
        counter = this->GetLength() - 1;
        temporaryPointer = this->GetEnd();
        while (counter != index)
        {
            temporaryPointer = temporaryPointer->GetPrev();
            counter--;
        }
    }
    return temporaryPointer;
}

template<typename T>
T LinkedList<T>::Get(int index)
{
    try
    {
        CheckNudlPointer(this->GetBegin());
        CheckCountRange2(index);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (Get(int index)): "<<error.what()<<endl;
        return NULL;
    }

    return this->PointerWithIndex(index)->GetValue();
}

template<typename T>
T LinkedList<T>::GetFirst()
{
    return this->Get(0);
}

template<typename T>
T LinkedList<T>::GetLast()
{
    return this->Get(this->GetLength() - 1);
}

template<typename T>
void LinkedList<T>::InsertAt(T item, int index)
{
    try
    {
        //CheckNudlPointer(this->GetBegin());
        CheckCountRange2(index);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (InsertAt(T item, int index)): "<<error.what()<<endl;
        return;
    }
    
    
    Nudl<T>* oldNudl = NULL;
    Nudl<T>* pastNudl = new Nudl<T>(item);
    if (index == 0 && this->PointerWithIndex(index) == NULL)
    {
        this->SetBegin(pastNudl);
        this->SetEnd(pastNudl);
    }
    else
        if (index == 0)
        {
            oldNudl = this->PointerWithIndex(index);
            oldNudl->SetPrev(pastNudl);
            pastNudl->SetNext(oldNudl);
            this->SetBegin(pastNudl);
        }
        else
        {
            oldNudl = this->PointerWithIndex(index);
            pastNudl->SetPrev(oldNudl->GetPrev());
            oldNudl->SetPrev(pastNudl);
            pastNudl->SetNext(oldNudl);
            pastNudl->GetPrev()->SetNext(pastNudl);
        }
    this->SetLength(this->GetLength() + 1);
}

template<typename T>
void LinkedList<T>::Append(T item)
{
    Nudl<T>* oldNudl = NULL;
    Nudl<T>* pastNudl = new Nudl<T>(item);
    if (this->PointerWithIndex(this->GetLength() - 1) == NULL)
    {
        this->SetBegin(pastNudl);
        this->SetEnd(pastNudl);
    }
    else
    {
        oldNudl = this->PointerWithIndex(this->GetLength() - 1);
        pastNudl->SetPrev(oldNudl);
        oldNudl->SetNext(pastNudl);
        this->SetEnd(pastNudl);
    }
    this->SetLength(this->GetLength() + 1);
}

template<typename T>
void LinkedList<T>::Prepend(T item)
{
    this->InsertAt(item, 0);
    return;
}

template<typename T>
void LinkedList<T>::Remove(int index)
{
    try
    {
        CheckNudlPointer(this->GetBegin());
        CheckCountRange2(index);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (Remove(int index)): "<<error.what()<<endl;
        return;
    }
    

    Nudl<T>* uselessItemPoiner = this->PointerWithIndex(index);
    if (index == 0)
    {
        uselessItemPoiner->GetNext()->SetPrev(NULL);
        this->SetBegin(uselessItemPoiner->GetNext());
    }
    else if (index == this->GetLength() - 1)
    {
        uselessItemPoiner->GetPrev()->SetNext(NULL);
        this->SetEnd(uselessItemPoiner->GetPrev());
    }
    else
    {
        uselessItemPoiner->GetNext()->SetPrev(uselessItemPoiner->GetPrev());
        uselessItemPoiner->GetPrev()->SetNext(uselessItemPoiner->GetNext());
    }
    delete uselessItemPoiner;
    this->SetLength(this->GetLength() - 1);;

}

template<typename T>
void LinkedList<T>::Print()
{
    if (this->GetBegin() == nullptr)
        return;
    Nudl<T>* example = this->GetBegin();
    for (int i = 0; i < this->GetLength(); i++)
    {
        cout << example->GetValue()<<"  ";
        example = example->GetNext();
    }
    cout << endl;
    return;
}

template<typename T>
void LinkedList<T>::PrintFull()
{
    if (this->GetBegin() == nullptr)
        return;
    Nudl<T>* example = this->GetBegin();
    cout<<"################################################"<<endl;
    cout<<"BEGIN= "<<this->GetBegin()<< "  lenght= "<< this->GetLength();
    cout<<"  END= "<<this->GetEnd()<<endl;
    for (int i = 0; i < this->GetLength(); i++)
    {
        cout<< "&prev= "<<example->GetPrev()<< "   &next= " <<example->GetNext()<<endl;
        cout << "value= "<<example->GetValue()<<endl;;
        example = example->GetNext();
    }
    cout<<"################################################"<<endl;
    return;
}



template<typename T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex)
{
    try
    {
        CheckNudlPointer(this->GetBegin());
        CheckCountRange2(startIndex);
        CheckCountRange2(endIndex);
        CheckIndexlSUblist(startIndex, endIndex);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (GetSubList(int startIndex, int endIndex)): "<<error.what()<<endl;
        LinkedList<T>* nullList = new LinkedList<T>();
        nullList->SetLength(0);
        nullList->SetBegin(nullptr);
        nullList->SetEnd(nullptr);
        return nullList;
    }
    
    LinkedList<T>* subList = new LinkedList<T>();
    subList->SetLength(endIndex - startIndex + 1);
    Nudl<T>* SourceNudlPointer = this->PointerWithIndex(startIndex);
    Nudl<T>* CopyNudlPointer = new Nudl<T>(SourceNudlPointer->GetValue());
    subList->SetBegin(CopyNudlPointer);
    while (SourceNudlPointer != PointerWithIndex(endIndex))
    {
        Nudl<T>* PreviousCopyNudlPointer = CopyNudlPointer;
        SourceNudlPointer = SourceNudlPointer->GetNext();
        CopyNudlPointer = new Nudl<T>(SourceNudlPointer->GetValue());
        CopyNudlPointer->SetPrev(PreviousCopyNudlPointer);
        PreviousCopyNudlPointer->SetNext(CopyNudlPointer);
    }
    subList->SetEnd(CopyNudlPointer);
    return subList;
}

template<typename T>
void LinkedList<T>::CatSubListInline(int startIndex, int endIndex)
{
    try
    {
        CheckNudlPointer(this->GetBegin());
        CheckCountRange2(startIndex);
        CheckCountRange2(endIndex);
        CheckIndexlSUblist(startIndex, endIndex);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (GetSubList(int startIndex, int endIndex)): "<<error.what()<<endl;
        return;
    }
    
    
    int newlenght = endIndex - startIndex + 1;
    Nudl<T>* newPointerBegin = this->PointerWithIndex(startIndex);
    Nudl<T>* newPointerEnd = this->PointerWithIndex(endIndex);
    Nudl<T>* tempPointer = this->GetBegin();
    Nudl<T>* nextPointer=nullptr;
    int len = this->GetLength();
    for (int i=0; i < len; i++)
    {
        nextPointer = tempPointer->GetNext();
        if ((i<startIndex) || (i>endIndex))
            delete tempPointer;
        tempPointer=nextPointer;
    }
    newPointerBegin->SetPrev(nullptr);
    newPointerEnd->SetNext(nullptr);
    this->SetBegin(newPointerBegin);
    this->SetEnd(newPointerEnd);
    this->SetLength(newlenght);

    return;
}




template<typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list)
{
    LinkedList<T>* newList = new LinkedList<T>(this);
    newList->SetLength(newList->GetLength() + list->GetLength());
    newList->GetEnd()->SetNext(list->GetBegin());
    list->GetBegin()->SetPrev(newList->GetEnd());
    newList->SetEnd(list->GetEnd());
    return newList;
}


#endif /* LinkedList_hpp */
