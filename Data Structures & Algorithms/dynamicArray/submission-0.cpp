class DynamicArray {
private:
    int* nums;
    unsigned int capacity;
    unsigned int size = 0;


public:

    DynamicArray(int capacity) {
        this->nums = new int[capacity];
        this->capacity = capacity;
    }

    int get(int i) {
        return this->nums[i];
    }

    void set(int i, int n) {
        this->nums[i] = n;
    }

    void pushback(int n) {
        this->nums[size] = n;
        size++;
        if (size > capacity){
            this->resize();
        }
    }

    int popback() {
        int temp = this->nums[size - 1];
        this->nums[size - 1] = 0;
        size--;
        return temp;
    }

    void resize() {
        int* resized = new int[capacity*2];
        std::copy(nums, nums + size, resized);
        capacity = capacity * 2;
        delete[] this->nums;
        this->nums = resized;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
};
