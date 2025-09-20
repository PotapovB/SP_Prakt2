#pragma once
#include <stdexcept>
using namespace std;

class Queue {
private:
    int* elements;
    int capacity;
    int front;
    int back;
    int size;

public:
    Queue(int capacity = 10) {
        this->capacity = capacity;
        elements = new int[capacity];
        front = 0;
        back = -1;
        size = 0;
    }

    ~Queue() {
        delete[] elements;
    }

    void enqueue(int value) {
        if (isFull()) {
            resize();
        }

        back = (back + 1) % capacity;
        elements[back] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Очередь пуста, нельзя удалить элемент.");
        }

        int value = elements[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int peek() const {
        if (isEmpty()) {
            throw runtime_error("Очередь пуста!");
        }
        return elements[front];
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    int getSize() const {
        return size;
    }

private:
    void resize() {
        int new_capacity = capacity * 2;
        int* new_elements = new int[new_capacity];

        for (int i = 0; i < size; i++) {
            new_elements[i] = elements[(front + i) % capacity];
        }

        delete[] elements;
        elements = new_elements;
        capacity = new_capacity;
        front = 0;
        back = size - 1;
    }
};

