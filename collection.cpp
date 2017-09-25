//
// Created by Quinn on 9/19/2017.
//Sites used were SO, cpluplus.com, leadtools.com, and a little microsoft docs

#include <iostream>
//class declaration
template <typename T>
class collection
{
public:
    collection();
    bool isEmpty() const;
    void clear();
    void insert(T x);
    void remove(T x);
    bool notContained(T x) const;
    void removeRandom();
    size_t size;
    T* col;
};

template <typename T>
collection<T>::collection() :size(20)
{
    col = new T[size];
}
template <typename T>
bool collection<T>::isEmpty() const
{
    for(size_t z =0; z < size; z++)
    {
        col[z] = NULL;
    }
}

//insert an element
template <typename T>
void collection<T>::insert(T x)
{
    //quite a bit of run around here but whatever works
    T tem;
    T holder;
    holder = tem;

    for(size_t v = 0; v < size; v++)
    {
        if(col[v] != NULL)
            tem++;
    }
    if(tem >= size)
    {

        tem = col[size * 2];
        for(size_t b = 0; b < size; b++)
            tem = col[b];


        holder = *col;
        delete col;



    }
    else
    {
        //having to cast to an int because i kept getting the error 'array subscript is not an int'
        col[static_cast<int>(holder)] = x;
    }
}


//removing the specified element from the list
template <typename T>
void collection<T>::remove(T x)
{
    for(size_t w = 0; w < size; w++)
    {
        if(col[w] == x)
        {
            for(size_t y = w; y <size-1; y++)
            {
                col[y] = col[y+1];
            }
            col[size-1] = NULL;
            return;
        }
    }
}

template <typename T>
void collection<T>::removeRandom()
{
    T empty = 0;
    for(size_t s =0; s < size; s++)
    {
        col[s] = empty;
    }
}

//checking the container for whether or not a certain element is found
template <typename T>
bool collection<T>::notContained(T x) const
{
    for(size_t m = 0; m < size; m++)
    {
        if(col[m] == x)
            return true;
    }
    return false;
}


//clearing the collection by setting it to 0 elements
template <typename T>
void collection<T>::clear()
{
    T *empty = 0;
    while(col != NULL)
    {
        col  = empty;
    }
}




using namespace std;
int main()
{

    collection<double> myCollection;


    //add some doubles into my list
    myCollection.insert(40);
    myCollection.insert(50);
    myCollection.insert(60);
    myCollection.insert(30); // add in 30 to my list of doubles
    myCollection.isEmpty(); // return false

    //remove a couple of doubles from my list
    myCollection.remove(30);
    myCollection.remove(50);

    //remove an item from the list
    myCollection.removeRandom();
    //now check if its in the list still
    myCollection.notContained(55); // should return false because I know what is in the list


    //set a statement to clear the loop

    if(myCollection.isEmpty() == false)
    {
        myCollection.clear();
    }

    return 0;
}



