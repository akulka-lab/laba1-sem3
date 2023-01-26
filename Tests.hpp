#ifndef Tests_hpp
#define Tests_hpp

#include <iostream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "Sort&Compare.hpp"

#include <stdio.h>
using namespace std;
/*
int Tests_()
{
    int a[]={1,5,2,9,3,3,1,7,5,99,7,8};
    int *b=a;
    cout<<BubbleSort<int>(&a);
    return 0;
}
*/
int TestDynamicArray()
{
    cout << "~verification tests DynamicArray~" << endl;
    int t[] = { 11, 10, 8, 6, 5, 3, 2, 1, 9, 7, 4 };

    DynamicArray<int> f0;
    cout<< f0.GetSize()<<"   ";
    cout<< f0.GetCount()<<endl;
    DynamicArray<int> f1 = DynamicArray<int>(1, 10);
    f1.Set(5, 2);
    cout<<"f1 = DynamicArray<int>(1, 10) = ";
    f1.Print();
    cout<< f1.GetSize()<<"   ";
    cout<< f1.GetCount()<<endl;

    DynamicArray<int> f2 = DynamicArray<int>(t, 9);
    cout<<"f2 = DynamicArray<int>(t, 9) = ";
    f2.Print();
    cout<< f2.GetSize()<<"   ";
    cout<< f2.GetCount()<<endl;

    DynamicArray<int> f3 = DynamicArray<int>(f2);
    cout<< "f3 = DynamicArray<int>(f2) = ";
    f3.Print();
    cout<< f3.GetSize()<<"   ";
    cout<< f3.GetCount()<<endl;

    f3 = DynamicArray<int>(f1);
    cout<<"f3 = DynamicArray<int>(f1) = ";
    f3.Print();
    cout<< f3.GetSize()<<"   ";
    cout<< f3.GetCount()<<endl;

    f3[1] = 99;
    f3.Set(4,5);
    f3.Insert(7, 33);
    cout<<"f3 ( f3[1] = 99; f3.Set(4,5); f3.Insert(7, 33)) = ";
    f3.Print();
    cout<< f3.GetSize()<<"   ";
    cout<< f3.GetCount()<<endl;

    f3.Resize(11);
    cout<<"f3 ( f3.Resize(11) ) = ";
    f3.Print();
    cout<< f3.GetSize()<<"   ";
    cout<< f3.GetCount()<<endl;

    f3.Insert(8, 7);
    cout<<"f3 ( f3.Insert(8, 7) ) = ";
    f3.Print();
    cout<< f3.GetSize()<<"   ";
    cout<< f3.GetCount()<<endl;

    f3.Remove(1);
    f3.Remove(4);
    cout<<"f3 ( f3.Remove(1); f3.Remove(4) ) = ";
    f3.Print();
    cout<< f3.GetSize()<<"   ";
    cout<< f3.GetCount()<<endl;

    f3.Append(f2);
    cout<<"f3 ( f3.Append(f2) ) = ";
    f3.Print();
    cout<< f3.GetSize()<<"   ";
    cout<< f3.GetCount()<<endl;


    f3=f1;
    cout<<"f3 ( f3=f1 ) = ";
    f3.Print();
    cout<< f3.GetSize()<<"   ";
    cout<< f3.GetCount()<<endl;
    
    cout << "~DynamicArray tests passed~" << endl;
    
    return 0;
}


int TestLinkedList()
{
    cout << "~verification tests LinkedList~" << endl;
    
    int t[] = { 11, 10, 8, 6, 5, 3, 2, 1, 9, 7, 4 };

    LinkedList<int> l0;
    cout<< "l0 : GetBegin() = "<<l0.GetBegin()<<";  l0.GetEnd() = "<< l0.GetEnd()<< "; GetLength() = " <<l0.GetLength() << endl;

    LinkedList<int> l1=LinkedList<int>();
    cout<< "l1=LinkedList<int>() : GetBegin() = "<<l1.GetBegin()<<";  GetEnd() = "<< l1.GetEnd()<< "; GetLength() = " <<l1.GetLength() << endl;

    LinkedList<int> l2=LinkedList<int>(t,9);
    cout<< "l2=LinkedList<int>(t,9) : GetBegin() = "<<l2.GetBegin()<<";  GetEnd() = "<< l2.GetEnd()<< "; GetLength() = " <<l2.GetLength() << endl;
    l2.Print();

    LinkedList<int> l3=LinkedList<int>(7,12);
    cout<< "l3=LinkedList<int>(7,12) : GetBegin() = "<<l3.GetBegin()<<";  GetEnd() = "<< l3.GetEnd()<< "; GetLength() = " <<l3.GetLength() << endl;
    l3.Print();


    LinkedList<int> l4 = LinkedList<int>(&l2);
    cout<< "l4 = LinkedList<int>(&l2) : GetBegin() = "<<l4.GetBegin()<<";  GetEnd() = "<< l4.GetEnd()<< "; GetLength() = " <<l4.GetLength() << endl;
    l4.Print();

    LinkedList<int> l5 = LinkedList<int>(l3);
    cout<< "l5 = LinkedList<int>(l3) : GetBegin() = "<<l5.GetBegin()<<";  GetEnd() = "<< l5.GetEnd()<< "; GetLength() = " <<l5.GetLength() << endl;
    l5.Print();

    //l0.Print();
    l5=l4;
    cout<< "l5=l4 : GetBegin() = "<<l5.GetBegin()<<";  GetEnd() = "<< l5.GetEnd()<< "; GetLength() = " <<l5.GetLength() << endl;
    l5.Print();

    l5=l3;
    cout<< "l5=l3 : GetBegin() = "<<l5.GetBegin()<<";  GetEnd() = "<< l5.GetEnd()<< "; GetLength() = " <<l5.GetLength() << endl;
    l5.Print();

    l5.InsertAt(9, 5);
    l5.Append(8);
    l5.Prepend(5);
    cout<< "l5.InsertAt(9, 5); l5.Append(8); l5.Prepend(5) : GetBegin() = "<<l5.GetBegin()<<";  GetEnd() = "<< l5.GetEnd()<< "; GetLength() = " <<l5.GetLength() << endl;
    l5.Print();

    LinkedList<int> l6;
    l6 = l5.GetSubList(4, 7);
    cout<< "l6 = l5.GetSubList(3, 7) : GetBegin() = "<<l6.GetBegin()<<";  GetEnd() = "<< l6.GetEnd()<< "; GetLength() = " <<l6.GetLength() << endl;
    l6.Print();

    l6.Remove(3);
    cout<< "l6.Remove(3) : GetBegin() = "<<l6.GetBegin()<<";  GetEnd() = "<< l6.GetEnd()<< "; GetLength() = " <<l6.GetLength() << endl;
    l6.Print();

    l5.CatSubListInline(2, 7);
    cout<< "l5.GetSubList(2, 7) : GetBegin() = "<<l5.GetBegin()<<";  GetEnd() = "<< l5.GetEnd()<< "; GetLength() = " <<l5.GetLength() << endl;
    l5.Print();

    LinkedList<int> l7;
    l7 = l4.Concat(&l5);
    cout<< "l7 = l4.Concat(&l5) : GetBegin() = "<<l7.GetBegin()<<";  GetEnd() = "<< l7.GetEnd()<< "; GetLength() = " <<l7.GetLength() << endl;
    l7.Print();
    
    cout << "~LinkedList tests passed~" << endl;
    return 0;
}
/*

 */

int TestArraySequence()
{
    int t[] = {11, 10, 8, 6, 5, 3, 2, 1, 9, 7, 4};
    int erors =0;

    cout << "~verification tests ArraySequence~" << endl;
    ArraySequence<int> a0 = ArraySequence<int>();
    cout<<"a0.Print_() = ";
    a0.Print_();
    cout<< "a0.GetLength() = "<<a0.GetLength_()<<"  ||  ";
    cout<< "a0.GetFirst() = "<<a0.GetFirst()<<"  ||  ";
    cout<< "a0.GetLast() = "<<a0.GetLast()<<endl<<endl;;
    

    ArraySequence<int> a1 = ArraySequence<int>(1, 10);
    cout<<"a1.Print_() = ";
    a1.Print_();
    cout<< "a1.GetLength() = "<<a1.GetLength_()<<"  ||  ";
    cout<< "a1.GetFirst() = "<<a1.GetFirst()<<"  ||  ";
    cout<< "a1.GetLast() = "<<a1.GetLast()<<endl<<endl;

    a1.Set_(5, 2);
    cout<<"a1.Set_(5, 2).Print_() = ";
    a1.Print_();
    cout<< "a1.GetLength() = "<<a1.GetLength_()<<"  ||  ";
    cout<< "a1.GetFirst() = "<<a1.GetFirst()<<"  ||  ";
    cout<< "a1.GetLast() = "<<a1.GetLast()<<endl<<endl;

    a1.Prepend_(9);
    cout<<"a1.Prepend_(9).Print_() = ";
    a1.Print_();
    cout<< "a1.GetLength() = "<<a1.GetLength_()<<"  ||  ";
    cout<< "a1.GetFirst() = "<<a1.GetFirst()<<"  ||  ";
    cout<< "a1.GetLast() = "<<a1.GetLast()<<endl<<endl;

    a1.Append_(77);
    cout<<"a1.Append_(77).Print_() = ";
    a1.Print_();
    cout<< "a1.GetLength() = "<<a1.GetLength_()<<"  ||  ";
    cout<< "a1.GetFirst() = "<<a1.GetFirst()<<"  ||  ";
    cout<< "a1.GetLast() = "<<a1.GetLast()<<endl<<endl;

    a1.InsertAt_(55, 5);
    cout<<"a1.InsertAt_(55, 5).Print_() = ";
    a1.Print_();
    cout<< "a1.GetLength() = "<<a1.GetLength_()<<"  ||  ";
    cout<< "a1.GetFirst() = "<<a1.GetFirst()<<"  ||  ";
    cout<< "a1.GetLast() = "<<a1.GetLast()<<endl<<endl;

    a1.SwapData_(5, 0);
    cout<<"a1.SwapData_(5, 0).Print_() = ";
    a1.Print_();
    cout<< "a1.GetLength() = "<<a1.GetLength_()<<"  ||  ";
    cout<< "a1.GetFirst() = "<<a1.GetFirst()<<"  ||  ";
    cout<< "a1.GetLast() = "<<a1.GetLast()<<endl<<endl;

    a1.SwapData_(5, 33);
    cout<<"a1.SwapData_(5, 33).Print_() = ";
    a1.Print_();
    cout<< "a1.GetLength() = "<<a1.GetLength_()<<"  ||  ";
    cout<< "a1.GetFirst() = "<<a1.GetFirst()<<"  ||  ";
    cout<< "a1.GetLast() = "<<a1.GetLast()<<endl<<endl;

    for (int i=0; i<a1.GetLength_(); i++)
    {
        cout<<i<<"   adress = "<<a1.Getadress_(i)<<"   data = "<<a1.Get_(i)<<endl;
    }

    ArraySequence<int> a2 = ArraySequence<int>(3, 5);
    cout<<"a2.Print_() = ";
    a2.Print_();
    cout<< "a2.GetLength() =  "<<a2.GetLength_()<<endl;
    cout<< "a2.GetFirst()  =  "<<a2.GetFirst()<<endl;
    cout<< "a2.a0.GetLast()=  "<<a2.GetLast()<<endl;
    cout<<"a1.Print_() = ";
    a1.Print_();
    cout<< "a1.GetLength() = "<<a1.GetLength_()<<endl;
    cout<< "a1.GetFirst()  = "<<a1.GetFirst()<<endl;
    cout<< "a1.a0.GetLast()= "<<a1.GetLast()<<endl<<endl;
    Sequence<int> * a3 = a2.Concat(&a1);
    a3 = (ArraySequence<int>*)a3;
    cout<<"a3 = a2.Concat(&a1).Print_() = ";
    a3->Print_();
    cout<< "a3->GetLength() =  "<<a3->GetLength_()<<endl;
    cout<< "a3->GetFirst()  =  "<<a3->GetFirst()<<endl;
    cout<< "a3->a0.GetLast()=  "<<a3->GetLast()<<endl;

    Sequence<int> * a4 = a1.GetSubSequence(3,7);
    a4 = (ArraySequence<int>*)a4;
    cout<< "a4->GetSubSeq()=  "<<a4<<endl;
    cout<<"a4.Print_() = ";
    a4->Print_();
    cout<< "a4.GetLength() =  "<<a4->GetLength_()<<endl;
    cout<< "a4.GetFirst()  =  "<<a4->GetFirst()<<endl;
    cout<< "a4.a0.GetLast()=  "<<a4->GetLast()<<endl;
    

    cout << "~ArraySequence tests passed~" << endl;
    return erors;
}

#endif /* Tests_hpp */
