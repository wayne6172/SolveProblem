#include <ctime>
#include <cstdio>
#include <cstdlib>
#define DATA_SIZE 100000000

int data[DATA_SIZE];

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int array[],int size){
    for(int i = 1; i < size; i++)
        for(int j = i; j > 0; j--)
            if(array[j] < array[j - 1])
                swap(array[j - 1],array[j]);
}

int *_mergeSort(int *array,int left,int right){
    if(right == left){
        int *k = (int *)malloc(sizeof(int));
        k[0] = array[right];
        return k;    
    }
    else {
        int mid = (left + right) / 2;
        int *leftA = _mergeSort(array, left, mid);
        int *rightA = _mergeSort(array,mid + 1,right);
        int leftLen = mid - left + 1;
        int rightLen = right - mid;
        int i = 0,j = 0,x = 0;

        int *k = (int *)malloc(sizeof(int) * (right - left + 1));

        while(leftLen > i && rightLen > j){
            if(leftA[i] < rightA[j])
                k[x++] = leftA[i++];
            else 
                k[x++] = rightA[j++];
        }

        while(leftLen > i)
            k[x++] = leftA[i++];
        while(rightLen > j)
            k[x++] = rightA[j++];
        
        free(leftA);
        free(rightA);

        return k;
    }
}

void mergeSort(int *array,int size){
    int *k = _mergeSort(array,0,size - 1);

    for(int i = 0; i < size; i++)
        array[i] = k[i];
    

    free(k);
}

void _quickSort(int *array,int left,int right){
    if(right <= left)return;
    if(right - 1 == left){
        if(array[left] > array[right])
            swap(array[left],array[right]);
    }

    int key = array[left];
    int i = left + 1, j = right;
    
    while(true){
        while(i <= j && array[i] < key)
            i++;
        while(i <= j && array[j] > key)
            j--;
        
        if(i < j){
            swap(array[i],array[j]);
        }
        else break;
    }

    swap(array[left], array[i - 1]);

    _quickSort(array,left, i - 1);
    _quickSort(array,i , right);
}

void quickSort(int *array,int size){
    _quickSort(array, 0, size - 1);
}

int main(int argc, char const *argv[])
{
    clock_t start, stop;
    
    FILE *fp = fopen("data.txt","rb");
    
    start = clock();

    fread(data,sizeof(int),DATA_SIZE,fp);
    
    //bubbleSort(data,DATA_SIZE); //100000 sec = 21.86
    //mergeSort(data,DATA_SIZE);   //100000 sec = 0.028,1000000 sec = 0.308, 10000000 sec = 3.577
    quickSort(data,DATA_SIZE);   //100000 sec = 0.017, 1000000 sec = 0.210, 10000000 sec = 2.399

    stop = clock();

    for(int i = 0; i < 100; i++)
        printf("%d\n",data[i]);

    printf("%.3lf\n",((double) stop - start) / CLOCKS_PER_SEC);
    fclose(fp);
    return 0;
}
