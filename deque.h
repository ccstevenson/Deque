#include <cstddef>

class Deque {
    Deque(const Deque&) = delete;
    Deque& operator=(const Deque&) = delete;
private:
    enum {CHUNK = 10, FRONT=0, BACK=1};
    int *arr = new int[CHUNK];
    //int arr[CHUNK];
    int fr;
    int ba;
    size_t arrSize;
    size_t vals;
    void expandArr(int);
public:
    Deque();
    ~Deque();
    void push_front(int); 
    void push_back(int); 
    int& front(); 
    int& back(); 
    int& at(size_t pos); 
    void pop_front(); 
    void pop_back(); 
    size_t size() const; 
    int* begin(); 
    int* end(); 
};
