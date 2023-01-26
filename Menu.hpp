#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include <chrono> // замер времени работы функции

#include "Menu.hpp"
#include "Tests.hpp"
#include "Sequence.hpp"
#include "LinkedList.hpp"
#include "random_all.hpp"
#include "Sort&Compare.hpp"
#include "DynamicArray.hpp"
#include "ArraySequence.hpp"

using namespace std;
int menu_count(int count);
int main_menu ();
int second_menu ();
int third_menu ();
int input_count ();

int input_print();


void menu();

int menu_count(int count)
{
    int a;
    cin >> a;
    while (a < 0 || a > count) 
    {
        cout << ("ERROR!") << endl << ("Enter a new number: ");

        cin >> a;
    }

    return a;
}

int main_menu ()
{
    cout << " _______________________________________________________________________  \n" << 
        "|                                                                       | \n" << 
        "|                ~WELCOME TO MENU 1 OF LAB WORK!~                       | \n" << 
        "|                                                                       | \n" << 
        "|____  _________________________________________________________________| \n" << 
        "     |/                                                                   \n" << endl <<
        " _______________________________________________________________________  \n" << 
        "|                                                                       | \n" << 
        "|                      Choose a further action:                         | \n" << 
        "|                                                                       | \n" << 
        "|   1 - Creating acreating a Sequence object and sorting                | \n" << 
        "|   2 - Tests - Sequence                                                | \n" << 
        "|                                                                       | \n" << 
        "|   0 - finish work                                                     | \n" << 
        "|____  _________________________________________________________________| \n" << 
        "     |/                                                                   \n" << endl;

    cout << "Enter the selected number: ";

    int r = menu_count(3);
    if (r == 2)
        cout << "Let's start testing!~ ";

    return r;
}

int second_menu()
{
    cout << " _______________________________________________________________________  \n" << 
        "|                                                                       | \n" << 
        "|                      Choose a further action:                         | \n" << 
        "|                                                                       | \n" << 
        "|   1 - Create a random object ArraySequence                            | \n" << 
        "|   2 - Create a random object LinkeListSequence                        | \n" << 
        "|                                                                       | \n" << 
        "|   0 - go back                                                         | \n" << 
        "|____  _________________________________________________________________| \n" << 
        "     |/                                                                   \n" << endl;
    int n = menu_count(2);

    cout << " _______________________________________________________________________  \n" << 
        "|                                                                       | \n" << 
        "|                      Choose a further action:                         | \n" << 
        "|                                                                       | \n" << 
        "|   0 - Int object                                                      | \n" << 
        "|   2 - Double object                                                   | \n" << 
        "|                                                                       | \n" << 
        "|____  _________________________________________________________________| \n" << 
        "     |/                                                                   \n";
    int m = menu_count(2);

    return n + m;
}

int third_menu ()
{
    int r;
    cout << " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|       WELCOME TO MENU OF SORTING SEQUENCE OBJECTS                     | \n" <<
        "|                                                                       | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl <<
        " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|                      Choose a further action:                         | \n" <<
        "|                                                                       | \n" <<
        "|   1 - Displaying the current Sequence object                          | \n" <<
        "|   2 - Execute the sorting program to the Sequence object              | \n" <<
        "|   3 - Copy the sorting result to the Sequence object                  | \n" <<
        "|   4 - Perform reverse sorting and copy to the object                  | \n" <<
        "|                                                                       | \n" <<
        "|   0 - go back                                                         | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl;

    cout << "Enter the selected number: ";

    r = menu_count(4);
    return r;
}


int input_count ()
{
    int a;
    cout<<"Enter the size of the array: ";
    cin>> a;
    while (a  <= 0)
    {
        cout << ("ERROR!") << endl << ("Enter a new number: ") << endl;
        cin >> a;
    }
    return a;
}


int input_print ()
{
    int result;
    cout << " _______________________________________________________________________  \n" << 
        "|                                                                       | \n" << 
        "|      Do you want to display the sorting result on the screen:         | \n" << 
        "|                                                                       | \n" << 
        "|   1 - Yes                                                             | \n" << 
        "|   2 - No                                                              | \n" <<
        "|                                                                       | \n" << 
        "|____  _________________________________________________________________| \n" << 
        "     |/                                                                   \n" << endl;
    
    cin >> result;
    while (result < 0 || result > 1)
    {
        cout << ("ERROR!") << endl << ("Enter a new number: ") << endl;
        cin>> result;
    }
    return result;
}




void menu()
{
    int c;
    while (1 == 1)
    {
        c = main_menu();
        switch (c)
        {
            case 0:
                return;
                
            case 2:
            {
                TestDynamicArray();
                TestLinkedList();
                TestArraySequence();
            }
                break;
                
                
            case 1:  //  создание объекта
            {
                int c2,q2 = 1;
                while (q2)
                {
                    c2 = second_menu();
                    switch (c2)
                    {
                        case 0:
                            q2=0;
                            break;
                            
                        case 1: // создать случайный объект ArraySequence <Int>
                        {
                            int c3,q3=1, item_random;
                            int count = input_count();
                            ArraySequence<int> obj_0 = ArraySequence<int>(0, count);
                            for (int i = 0; i < count; i++)
                            {
                                item_random = random_int(10000, -10000);
                                obj_0.Set_(item_random, i);
                            }
                            obj_0.Print_();
                            
                            ArraySequence<int> obj_1 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_2 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_3 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_4 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_5 = ArraySequence<int>(0, obj_0.GetLength_());
                            for (int i = 0; i < obj_0.GetLength_(); i++)
                            {
                                obj_1.Set_(obj_0.Get_(i), i);
                                obj_2.Set_(obj_0.Get_(i), i);
                                obj_3.Set_(obj_0.Get_(i), i);
                                obj_4.Set_(obj_0.Get_(i), i);
                                obj_5.Set_(obj_0.Get_(i), i);
                            }
                            
                            
                            while (q3)
                            {
                                c3 = third_menu();
                                switch (c3) {
                                    case 0:
                                        q3 = 0;
                                        break;
                                    
                                    case 1: // печать объекта
                                    {
                                        cout << "Displaying the current object (obj_0), the amount of data = " << obj_0.GetLength_() << endl;
                                        cout << endl;
                                        obj_0.Print_();
                                        cout << endl;
                                    }
                                        break;
                                        
                                    case 2:  // проведение 3-4 сортировок - создание соотвествующих объектов
                                        
                                    {
                                        auto begin1 = chrono::steady_clock::now();
                                        selectionSort<int>(&obj_1); //сортировка выбором
                                        auto end1 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
                                        cout<<"Sorting execution time SelectionSort = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er1 = test_sort(&obj_1);
                                        if (input_print())
                                            obj_1.Print_();
                                        
                                        auto begin2 = chrono::steady_clock::now();
                                        shellSort<int>(&obj_2); //сортировка выбором
                                        auto end2 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
                                        cout<<"Sorting execution time ShellSort = " <<  elapsed_ms_selectionSort2.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er2 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_2.Print_();
                                        
                                        auto begin4 = chrono::steady_clock::now();
                                        BubbleSort<int>(&obj_4); //сортировка выбором
                                        auto end4 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
                                        cout<<"Sorting execution time BubleSort = " <<  elapsed_ms_selectionSort4.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er4 = test_sort(&obj_4);
                                        if (input_print())
                                            obj_4.Print_();
                                        
                                    }
                                        
                                        break;
                                        
                                    case 3:  // перезапись объекта оnсротированным объектом
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_1.Get_(i), i);
                                        }
                                        
                                        break;
                                    case 4:
                                    {
                                        auto begin5 = chrono::steady_clock::now();

                                        BubbleSortDown <int>(&obj_5); //сортировка выбором
                                        auto end5 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort5 = chrono::duration_cast<chrono::milliseconds>(end5 - begin5);
                                        cout<<"Sorting execution time BubleSortDown2 = " <<  elapsed_ms_selectionSort5.count() <<" ms" <<endl;
                                        
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_5.Get_(i), i);
                                        }
                                    }
                                        break;
                                        
                                    default:
                                        break;
                                }
                            }
                            
                        }
                            break;
                            
                        case 3: // cоздать случайный объект ArraySequence <Double>
                        {
                            
                            int c3,q3=1;
                            double item_random;
                            int count = input_count();
                            ArraySequence<double> obj_0 = ArraySequence<double>(0.0, count);
                            for (int i = 0; i < count; i++)
                            {
                                item_random = random_double(10000.0, -10000.0);
                                obj_0.Set_(item_random, i);
                            }
                            obj_0.Print_();
                            
                            ArraySequence<double> obj_1 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_2 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_3 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_4 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_5 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            
                            for (int i = 0; i < obj_0.GetLength_(); i++)
                            {
                                obj_1.Set_(obj_0.Get_(i), i);
                                obj_2.Set_(obj_0.Get_(i), i);
                                obj_3.Set_(obj_0.Get_(i), i);
                                obj_4.Set_(obj_0.Get_(i), i);
                                obj_5.Set_(obj_0.Get_(i), i);
                                
                            }
                            
                            
                            while (q3)
                            {
                                c3 = third_menu();
                                switch (c3) {
                                    case 0:
                                        q3 = 0;
                                        break;
                                        
                                    case 1: // печать объекта
                                    {
                                        cout << "Displaying the current object (obj_0), the amount of data = " << obj_0.GetLength_() <<endl;
                                        cout << endl;
                                        obj_0.Print_();
                                        cout << endl;
                                    }
                                        break;
                                        
                                    case 2:  // проведение 3-4 сортировок - создание соотвествующих объектов
                                        
                                    {
                                        auto begin1 = chrono::steady_clock::now();
                                        selectionSort<double>(&obj_1); //сортировка выбором
                                        auto end1 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
                                        cout<<"Sorting execution time SelectionSort = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er1 = test_sort(&obj_1);
                                        if (input_print())
                                            obj_1.Print_();
                                        
                                        auto begin2 = chrono::steady_clock::now();
                                        shellSort<double>(&obj_2); //сортировка выбором
                                        auto end2 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
                                        cout<<"Sorting execution time ShellSort = " <<  elapsed_ms_selectionSort2.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er2 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_2.Print_();
                                        
                                       
                                        
                                        auto begin4 = chrono::steady_clock::now();
                                        BubbleSort<double>(&obj_4); //сортировка выбором
                                        auto end4= chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
                                        cout<<"Sorting execution time BubbleSort = " <<  elapsed_ms_selectionSort4.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er4 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_4.Print_();
                                    }
                                        
                                        break;
                                        
                                    case 3:  // перезапись объекта оnсротированным объектом
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_1.Get_(i), i);
                                        }
                                        
                                        break;
                                        
                                    case 4:
                                    {
                                        auto begin5 = chrono::steady_clock::now();
                                        BubbleSortDown <double>(&obj_5); //сортировка выбором
                                        auto end5 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort5 = chrono::duration_cast<chrono::milliseconds>(end5 - begin5);
                                        cout<<"Sorting execution time BubleSort = " <<  elapsed_ms_selectionSort5.count() <<" ms" <<endl;
                                        
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_5.Get_(i), i);
                                        }
                                    }
                                        break;
                                        
                                        
                                    default:
                                        break;
                                }
                            }
                            
                        }
                        
                            break;
                            
                        case 2: // cоздать случайный объект LinkcedList <int>
                        {
                            int c3,q3=1, item_random;
                            int count = input_count();
                            ArraySequence<int> obj_0 = ArraySequence<int>(0, count);
                            for (int i = 0; i < count; i++)
                            {
                                item_random = random_int(10000, -10000);
                                obj_0.Set_(item_random, i);
                            }
                            obj_0.Print_();
                            
                            ArraySequence<int> obj_1 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_2 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_3 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_4 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_5 = ArraySequence<int>(0, obj_0.GetLength_());
                            for (int i = 0; i < obj_0.GetLength_(); i++)
                            {
                                obj_1.Set_(obj_0.Get_(i), i);
                                obj_2.Set_(obj_0.Get_(i), i);
                                obj_3.Set_(obj_0.Get_(i), i);
                                obj_4.Set_(obj_0.Get_(i), i);
                                obj_5.Set_(obj_0.Get_(i), i);
                            }
                            
                            
                            while (q3)
                            {
                                c3 = third_menu();
                                switch (c3) {
                                    case 0:
                                        q3 = 0;
                                        break;
                                    
                                    case 1: // печать объекта
                                    {
                                        cout << "Displaying the current object (obj_0), the amount of data = " << obj_0.GetLength_() << endl;
                                        cout << endl;
                                        obj_0.Print_();
                                        cout << endl;
                                    }
                                        break;
                                        
                                    case 2:  // проведение 3-4 сортировок - создание соотвествующих объектов
                                        
                                    {
                                        auto begin1 = chrono::steady_clock::now();
                                        selectionSort<int>(&obj_1); //сортировка выбором
                                        auto end1 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
                                        cout<<"Sorting execution time SelectionSort = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er1 = test_sort(&obj_1);
                                        if (input_print())
                                            obj_1.Print_();
                                        
                                        auto begin2 = chrono::steady_clock::now();
                                        shellSort<int>(&obj_2); //сортировка выбором
                                        auto end2 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
                                        cout << "Sorting execution time ShellSort = " <<  elapsed_ms_selectionSort2.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er2 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_2.Print_();

                                        auto begin4 = chrono::steady_clock::now();
                                        BubbleSort<int>(&obj_4); //сортировка выбором
                                        auto end4 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
                                        cout << "Sorting execution time BubleSort = " <<  elapsed_ms_selectionSort4.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er4 = test_sort(&obj_4);
                                        if (input_print())
                                            obj_4.Print_();
                                        
                                    }
                                        
                                        break;
                                        
                                    case 3:  // перезапись объекта оnсротированным объектом
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_1.Get_(i), i);
                                        }
                                        
                                        break;
                                    case 4:
                                    {
                                        auto begin5 = chrono::steady_clock::now();
                                        BubbleSortDown <int>(&obj_5);
                                        auto end5 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort5 = chrono::duration_cast<chrono::milliseconds>(end5 - begin5);
                                        cout << "Sorting execution time BubleSortDown = " <<  elapsed_ms_selectionSort5.count() <<" ms" <<endl;
                                        
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_5.Get_(i), i);
                                        }
                                    }
                                        break;
                                        
                                    default:
                                        break;
                                }
                            }
                            
                            
                        }
                            break;
                            
                        case 4: // cоздать случайный объект LinkeListSequence <Double>
                        {
                            int c3,q3=1;
                            double item_random;
                            int count = input_count();
                            ArraySequence<double> obj_0 = ArraySequence<double>(0.0, count);
                            for (int i = 0; i < count; i++)
                            {
                                item_random = random_double(100000.0, -100000.0);
                                obj_0.Set_(item_random, i);
                            }
                            obj_0.Print_();
                            
                            ArraySequence<double> obj_1 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_2 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_3 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_4 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_5 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            for (int i = 0; i < obj_0.GetLength_(); i++)
                            {
                                obj_1.Set_(obj_0.Get_(i), i);
                                obj_2.Set_(obj_0.Get_(i), i);
                                obj_3.Set_(obj_0.Get_(i), i);
                                obj_4.Set_(obj_0.Get_(i), i);
                                obj_5.Set_(obj_0.Get_(i), i);
                            }
                            
                            
                            while (q3)
                            {
                                c3 = third_menu();
                                switch (c3) {
                                    case 0:
                                        q3 = 0;
                                        break;
                                    
                                    case 1: // печать объекта
                                    {
                                        cout << "Displaying the current object (obj_0), the amount of data = " << obj_0.GetLength_() << endl;
                                        cout << endl;
                                        obj_0.Print_();
                                        cout << endl;
                                    }
                                        break;
                                        
                                    case 2:  // проведение 3-4 сортировок - создание соотвествующих объектов
                                        
                                    {
                                        auto begin1 = chrono::steady_clock::now();
                                        selectionSort<double>(&obj_1); //сортировка выбором
                                        auto end1 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
                                        cout << "Sorting execution time SelectionSort = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er1 = test_sort(&obj_1);
                                        if (input_print())
                                            obj_1.Print_();
                                        
                                        auto begin2 = chrono::steady_clock::now();
                                        shellSort<double>(&obj_2); //сортировка выбором
                                        auto end2 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
                                        cout << "Sorting execution time ShellSort = " <<  elapsed_ms_selectionSort2.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er2 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_2.Print_();
                                        
                                        
                                        auto begin4 = chrono::steady_clock::now();
                                        BubbleSort<double>(&obj_4); //сортировка выбором
                                        auto end4= chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
                                        cout << "Sorting execution time BubbleSort = " <<  elapsed_ms_selectionSort4.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er4 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_4.Print_();
                                    }
                                        
                                        break;
                                        
                                    case 3:  // перезапись объекта оnсротированным объектом
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_1.Get_(i), i);
                                        }
                                        
                                        break;
                                    
                                    case 4:
                                    {
                                        auto begin5 = chrono::steady_clock::now();
                                        BubbleSortDown <double>(&obj_5); //сортировка выбором
                                        auto end5 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort5 = chrono::duration_cast<chrono::milliseconds>(end5 - begin5);
                                        cout << "Sorting execution time BubleSortDown = " <<  elapsed_ms_selectionSort5.count() <<" ms" <<endl;
                                        
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_5.Get_(i), i);
                                        }
                                    }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            
                        }
                            break;
                            
                            
                        default:
                            break;
                    }
                }
            }
                break;
                
            default:
                break;
        }
    }
}

#endif /* Menu_hpp */
