#pragma once
#include <iostream>
#include <sstream>
#include "BST.hpp"


template<typename T>
class Node {
    template<typename U>
    friend class BST;
private:
    T data;
    Node<T> *left, *right, *parent;

public:
    Node(const Node<T>& other) = delete;
    explicit Node(T data): left(nullptr), right(nullptr), parent(nullptr), data(data){}
    ~Node(){
        this->left = nullptr;
        this->right = nullptr;
        if (this->parent != nullptr)
        {
            if (this == this->parent->left)
                this->parent->left = nullptr;
            else if (this == this->parent->right)
                this->parent->right = nullptr;
        }
    }
    T getData(){ return data; }
    Node<T>* getLeft(){ return left; }
    Node<T>* getRight(){ return right; }
        /**
		 * @brief swap data between nodes
		 * @param other - node to swap
		*/
    void dataSwap(Node<T>* other){
        auto tmp = this->data;
        this->data = other->data;
        other->data = tmp;
    }
        /**
		 * @brief Operator left shift
		 * @param node - node to output
		 * @return output stream
		*/
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node){
        out << node.data << " ";
        return out;
    }
        /**
		 * @brief Operator equal
		 * @param other - node to compare
		 * @return result of comparison
		*/
    bool operator==(Node<T> const& other) const { return data == other.data; }
        /**
		 * @brief Operator not equal
		 * @param other - node to compare
		 * @return result of comparison
		*/
    bool operator!=(Node<T> const& other) const { return data != other.data; }
        /**
		 * @brief Operator greater
		 * @param other - node to compare
		 * @return result of comparison
		*/
    bool operator>(Node<T> const& other) const { return data > other.data; }
        /**
		 * @brief Operator lower
		 * @param other - node to compare
		 * @return result of comparison
		*/
    bool operator<(Node<T> const& other) const { return data < other.data; }
};
