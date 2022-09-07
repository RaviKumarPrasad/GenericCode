

#include <iostream>
#include <string.h>

#define size 10

#define SWAP(VAL1,VAL2)   ({VAL1 ^= VAL2; VAL2 ^= VAL1; VAL1 ^= VAL2;})

/*  
 *  Best to Worst case according to size
 *  O(1)            -       val == 1
 *  O(log n)        -       val > 1 && val < size
 *  O(n)            -       val == size
 *  O(n log n)      -       val > size && val < size^2
 *  O(n^2)          -       val == size^2
 */

typedef enum
{
    ORDER_1         = 1,
    ORDER_LOG_N     = size-1,
    ORDER_N         = size,
    ORDER_N_LOG_N   = ((size*4) - 1),
    ORDER_N_2       = ((size*4) + 1)
}ORDER;

char COMPLEXCITY[size+size] = "";
int order = 0;

typedef enum
{
    bubble,
    insertion,
    selection,
    merge,
    heap,
    quick
}SORT_LEVEL;

void printOrder(int val)
{
    if (val > 1 && val < size)  
    {
        val = ORDER_LOG_N;
    } else if (val > size && val < (size*4))
    {
        val = ORDER_N_LOG_N;
    } else if (val > (size*4)) 
    {
        val = ORDER_N_2;
    }

    switch (val)
    {
        case ORDER_1        : strcpy(COMPLEXCITY, ("__O(1)"));     
                              break;
        case ORDER_LOG_N    : strcpy(COMPLEXCITY, ("__O(Log n)"));  
                              break;
        case ORDER_N        : strcpy(COMPLEXCITY, ("__O(n)"));       
                              break;
        case ORDER_N_LOG_N  : strcpy(COMPLEXCITY, ("__O(n Log n)")); 
                              break;
        case ORDER_N_2      : strcpy(COMPLEXCITY, ("__O(n^2)")); 
                              break;
        default :   std::cout<<"\n Val = "<<val<<" Unable to calculate Time Complexcity!!";
        
    }
    std::cout<<std::endl;
    std::cout<<"Complexity "<<COMPLEXCITY;
    
}

int * bubble_s(int arr[])
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            order++;
            if (arr[i] > arr[j])
                SWAP(arr[i], arr[j]);
        }
    }
    std::cout<<std::endl<<" Number ----> "<<order;
    printOrder(order);
    order = 0;
    return  arr;
}

int * selection_s(int arr[])
{
    for (int i=0; i<size-1; i++)
    {
        int min = i;
        for (int j=i+1; j<size; j++)
        {
            order++;
            if (arr[min] > arr[j])
                min = j;
        }
        if (i != min)
            SWAP(arr[min], arr[i]);
    }    

    std::cout<<std::endl<<" Number ----> "<<order;
    printOrder(order);
    order = 0;
    return  arr;
}

int main()
{
    int arr[size] = {5,8,1,9,3,4,2,6,10,7};
//    int arr[size] = {1,2,3,4,5,6,7,8,9,10};

//    int * sort = bubble_s(arr);
    int * sort = selection_s(arr);
    std::cout<<std::endl;
    
    for (int i=0; i<size; i++)
    {
        std::cout<<" "<<sort[i];
    }
}
