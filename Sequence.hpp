#ifndef Sequence_h
#define Sequence_h

using namespace std;
template <typename T>
class Sequence
{
public:
    virtual T GetFirst()                                                     const = 0;
    virtual T GetLast()                                                      const = 0;
    virtual T Get_(int index)                                                const = 0;
    virtual int GetLength_()                                                  const = 0;
    virtual void Remove_(int index)                                                = 0;
    virtual void Append_(T item)                                                   = 0;
    virtual void Prepend_(T item)                                                  = 0;
    virtual void InsertAt_(T item, int index)                                      = 0;
    virtual void Set_(T item, int index)                                           = 0;
    virtual void SwapData_(int index1, int index2)                                 = 0;
    virtual T* Getadress_(int index)                                         const = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list)                                 = 0;
    virtual Sequence<T>* GetSubSequence(int start_index, int end_index)      const = 0;
    virtual void Print_()                                                    const = 0;
   
   
    
};


#endif /* Sequence_h */
