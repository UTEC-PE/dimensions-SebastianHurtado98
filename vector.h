//
// Created by Sebastian on 12/09/2018.
//
#ifndef VECTOR_H
#define VECTOR_H

template <typename Tr>
class Vector {
public:
    typedef typename Tr::T T;
    typedef typename Tr::Operation Operation;

private:
    T* data;
    int dataSize;

    int dimensions;
    int* dimensionSizes;
    Operation op;

public:
    Vector() : data(nullptr) {};

    Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions), dimensionSizes(dimensionSizes) {
        dataSize= 1;
        for (int i= 0; i<dimensions; i++){
            dataSize= dataSize*dimensionSizes[i];
        }
        data= new T[dataSize];

    }

    void set(T datum, int* coordinates){
        data[op(coordinates, dimensionSizes, dimensions)]= datum;
    };

    T get(int* coordinates){
        return data[op(coordinates, dimensionSizes, dimensions)];

    };
    ~Vector(){
        delete data;
    }
};

#endif
