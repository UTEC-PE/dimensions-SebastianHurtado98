#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>

struct Dimensions {
    int operator()(int* coordinates, int* sizes, int dimensions) {

        int n = 0;
        for (int i = dimensions - 1; i >= 0; i--) {
            n *= sizes[i];
            n += coordinates[i];
        }
        return n;
    }
};


void function(){
    //solo es una funcion de prueba
    //doble loop
    int array_pos[2]= {2, 2};
    int array_size[2]= {5, 5};
    int cnt= array_pos[0];
    int cnt2;
    for(int i=1; i<2; i++){
        cnt2= array_pos[i];
        for (int j=0; j<i; j++){
            cnt2=cnt2*array_size[j];
        }
        cnt=cnt+cnt2;
    }
    cout << cnt;
}

struct Integer {
    typedef int T;
    typedef Dimensions<T> Operation;
};


int main(int argc, char *argv[]) {
    int DimSize[3] = {2, 2, 2};
    int coordinates[3] = {0, 0, 0};
    Vector<Integer> test(3, DimSize);
    test.set(10,coordinates);
    cout << endl << test.get(coordinates);

    system("pause");
    function();

    return EXIT_SUCCESS;
}
