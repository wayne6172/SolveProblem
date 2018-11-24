//correct 

#include <iostream>
#include <cstring>

bool choose[20];
int total;

using namespace std;

bool find(int array[],int i,int size,int max, bool finalAns){

    if(max < 0)return false;
    else if(max == 0){
        if(finalAns)
            return true;

        int array1[20], size1 = 0, array2[20], size2 = 0;
        for(int j = 0; j < size; j++){
            if(choose[j])array1[size1++] = array[j];
            else array2[size2++] = array[j];
        }

        if(find(array1,0,size1,total / 4, true) && find(array2,0,size2,total / 4, true))
            return true;
        else 
            return false;
    }
    else if(i == size)return false;

    if(!finalAns)choose[i] = false;
    if(find(array, i + 1, size, max, finalAns))
        return true;


    if(!finalAns)choose[i] = true;
    if(find(array, i + 1, size, max - array[i], finalAns))
        return true;
    

    if(!finalAns)
        choose[i] = false;
    return false;
}

int main(int argc, char const *argv[])
{
    int t, length;
    int array[20];
    cin >> t;

    while(t--){
        total = 0;
        cin >> length;
        for(int i = 0;i < length; i++){
            cin >> array[i];
            total += array[i];
        }

        if(total % 4 == 0){
            memset(choose,0,sizeof(choose));
            if(find(array,0,length,total / 2, false))
                cout << "yes" << endl;
            else 
                cout << "no" << endl;
        }
        else cout << "no" << endl;

    }

    

    return 0;
}
