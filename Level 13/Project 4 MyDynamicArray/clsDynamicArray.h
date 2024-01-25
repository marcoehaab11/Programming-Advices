#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
    private:
    short _size=0;
    
    protected:
    T* _Temparr;
    public:
    T* arr;
    clsDynamicArray(short iteam)
    {   
        _size=iteam;
        arr=new T[_size];
    }
     
    
    void SetIteam(short index,short value)
    {   if(index<_size)
        arr[index]=value;
    }
    short size()
    {
        return _size;
    }
    void PrintIteam()
    {
        for(short i=0;i<_size;i++)
        cout<<arr[i]<<" ";
        
        cout<<endl;
    }
    bool isEmpty()
    {
        return (_size==0)?true:false;
    }
    void Resize(short Resize )
    {   
        if(Resize<0)
        {
            Resize=0;
        }
        
        _Temparr=new T[Resize];
        _size=Resize;
        //copy date from Orgarr to temparr 
        for(int i=0;i<_size;i++)
        {
            _Temparr[i]=arr[i];
        }
        
        
        _size=Resize;
        delete arr;
        arr =_Temparr;
        
        
        _size=Resize;
    }
    void Revesre()
    {   _Temparr=new T[_size];
        for(short i=0;i<_size;i++)
        {
            _Temparr[_size-1-i]=arr[i];
        }
        delete arr;
        arr=_Temparr;
    }
    void Clear()
    {
        Resize(0);
    }
    
    void DeleteIteam(short index)
    {
        _Temparr=new T[_size-1];
        short counter=0;
        for(short i=0;i<_size;i++)
        {
            if(i!=index)
            {   
               _Temparr[counter]=arr[i]; 
               counter++;
            }
            
        }
        _size-=1;
        delete arr;
        arr=_Temparr;
    }
    T GetIteam(short index)
    {
        return arr[index];
    }
    void DeleteFirstIteam()
    {
        DeleteIteam(0);
    }
     void DeleteLastIteam()
    {
        DeleteIteam(_size-1);
    }
    short GetIndex(T value)
    {
        for(short i=0;i<_size;i++)
        {
            if(arr[i]==value)
            return i;
        }
        return -1;
    }
    short Find(T value)
    {   
        if(GetIndex(value)==-1)
        return -1;
        
        return GetIndex(value);      
    }
    bool DeleteByValue(T value)
    {   if(GetIndex(value)==-1)
        return -1;
        
        DeleteIteam(GetIndex(value));
        return 1;
    }
    
    bool InsertAt(short index,T value)
    {   
        if(index>_size||index<0)
        {
            return 0;
        }
        
        _Temparr=new T[_size+1];
        
        //copybeforindex
        for(int i =0;i<index;i++)
        {
            _Temparr[i]=arr[i];
        }
        
        //in Index
        _Temparr[index]=value;
        
        //after Index
        for(int i=index;i<_size;i++)
        {
            _Temparr[i+1]=arr[i];
        }
        
        delete[] arr;
        _size++;
        arr=_Temparr;
        return 1;
        
    }
    
    void InsertAtBegin(T value)
    {
        InsertAt(0,value);
    }
       
    void InsertAtEnd(T value)
    {
        InsertAt(_size,value);
    }
    
    void InsertBefor(short index,T value)
    {   if(index<1)
        {
            InsertAt(index-1,value);
        }
        else
        {
            InsertAt(index-1,value);
        }
    }
       
    void InsertAfer(short index,T value)
    {   if(index>=size)
        InsertAt(_size-1,value);
        else
        InsertAt(index+1,value);
    }
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};