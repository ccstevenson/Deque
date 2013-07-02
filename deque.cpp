#include "deque.h"
#include <iostream>
#include <stdexcept>

Deque::Deque() {
    vals = 0;
    fr = CHUNK / 2;
    ba = CHUNK / 2;
    arrSize = CHUNK;
}

Deque::~Deque() {
    delete[] arr;
}

void Deque::push_front(int val) { 
    if (fr == ba) { ba++; } // The array was empty.

    if (fr < 0) { // Room remains in the left half of the array.
        expandArr(FRONT);
    }

    arr[fr] = val;
    fr--;
    vals++;
}

void Deque::push_back(int val) { 
    if (fr == ba) { fr--; } // The array was empty.


    if (ba >= arrSize) {
        expandArr(BACK);
    }

    arr[ba] = val;
    ba++;
    vals++;
}

void Deque::expandArr(int side) {
    int newSize = arrSize + CHUNK;
    int *temp = new int[newSize];
    int startIndex;

    if (side == FRONT) { // Copy the values from arr[0] to arr[vals - 1].
        startIndex = (newSize / 2) - (vals / 2);
        int j = 0;

        for (int i = startIndex; i < startIndex + vals-1; i++) {
            temp[i] = arr[j];
            j++;
        }
    }
    else { // Copy the values from arr[arrSize - vals] to arr[arrSize-1]
        startIndex = (newSize / 2) - (vals / 2);
        int j = arrSize - vals;

        for (int i = startIndex; i < startIndex + vals; i++) {
            temp[i] = arr[j];
            j++;
        }
    }

    arrSize = newSize;
    fr = startIndex - 1;
    ba = startIndex + vals;

    delete[] arr;
    arr = temp;
}

int& Deque::front(){ 
    if (vals > 0) { // The array is not empty.
        return arr[fr+1];
    }
    else {
        throw std::logic_error("logic error");
    }
}

int& Deque::back(){ 
    if (vals > 0) { // The array is not empty.
        return arr[ba-1];
    }
    else {
        throw std::logic_error("logic error");
    }
}

int& Deque::at(size_t pos) { 
    if (pos < 0 || pos > vals-1 || vals == 0) {
        throw std::logic_error("logic error");
    }
    else {
        return arr[pos+fr+1];
    }
}

void Deque::pop_front() { 
    if (vals > 0) { // The array is not empty.
        fr++;
        vals--;
    }
}

void Deque::pop_back() { 
    if (vals > 0) { // The array is not empty.
        ba--;
        vals--;
    }
}

size_t Deque::size() const { // NOTE: size_t is defined in <cstddef>
    return vals;
}

int* Deque::begin() { 
    int *first = arr;
    first += fr + 1;
    return first;
}

int* Deque::end() { 
    int *last = arr;
    last += ba - 1;
    return last;
}



