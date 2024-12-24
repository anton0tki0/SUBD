// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "Stack.h"
#include <stdexcept>
#include <sstream>

Stack::Stack() {
    // Конструктор
}

Stack::~Stack() {
    // Деструктор
}

void Stack::push(int value) {
    data_.push_back(value);
}

int Stack::pop() {
    if (data_.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    int val = data_.back();
    data_.pop_back();
    return val;
}

int Stack::top() const {
    if (data_.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data_.back();
}

bool Stack::empty() const {
    return data_.empty();
}

size_t Stack::size() const {
    return data_.size();
}

bool Stack::contains(int value) const {
    for (int elem : data_) {
        if (elem == value) return true;
    }
    return false;
}

std::string Stack::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < data_.size(); ++i) {
        oss << data_[i];
        if (i + 1 < data_.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}
