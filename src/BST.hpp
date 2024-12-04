#pragma once
#include "Node.hpp"
template<typename T>
class Node;
template<typename T>
class BST {
private:
    Node<T>* root = nullptr;
        /**
		 * @brief func to insert node in tree
		 * @param node - node to insert
		 * @param current - buffer for recursion (default = root)
		 * @param parent - revers link in hierarchy (default = nullptr)
		 * @return pointer on current obj
		*/
    Node<T>* inserter(Node<T>* node, Node<T>* current, Node<T>* parent) {
        if (current == nullptr){
            current = node;
            current->parent = parent;
            return current;
        }
        if (*node < *current)
            current->left = inserter(node, current->left, current);
        else if (*node > *current)
            current->right = inserter(node, current->right, current);
        return current;
    }
        /**
		 * @brief func to find node in tree
		 * @param node - node to find
		 * @param current - buffer for recursion (default = root)
		 * @return pointer on current obj
		*/
    bool contains(Node<T> *node, Node<T> *current) {
        if (current == nullptr)
            return false;
        else if (*node == *current)
            return true;
        else if (*node < *current)
            contains(node,current->left);
        else
            contains(node,current->right);
    }
        /**
		 * @brief func to find minimum node in (sub)tree
		 * @param node - root node of (sub)tree (default = root)
		 * @return pointer on minimum node
		*/
    Node<T>* findMin(Node<T>* node) {
        if (node == nullptr || node->left == nullptr)
            return node;

        return findMin(node->left);
    }
        /**
		 * @brief func to find maximum node in (sub)tree
		 * @param node - root node of (sub)tree (default = root)
		 * @return pointer on maximum node
		*/
    Node<T>* findMax(Node<T>* node) {
        if (node == nullptr || node->right == nullptr)
            return node;

        return findMax(node->right);
    }
        /**
		 * @brief output in increasing order
		 * @param node - root node of (sub)tree (default = root)
         * @param out - output stream
         * @return string of nodes in increasing order
		*/
    std::string inOrderTraversal(Node<T>* node, std::ostringstream& out) {
        if (node != nullptr) {
            inOrderTraversal(node->left, out);
            out << *node;
            inOrderTraversal(node->right, out);
        }
        return out.str();
    }
        /**
		 * @brief output in post order
		 * @param node - root node of (sub)tree (default = root)
         * @param out - output stream
         * @return string of nodes in post order
		*/
        std::string postOrderTraversal(Node<T>* node, std::ostringstream& out) {
        if (node != nullptr) {
            postOrderTraversal(node->left, out);
            postOrderTraversal(node->right, out);
            out << *node;
        }
        return out.str();
    }
        /**
		 * @brief func to convert subtree root into leaf
		 * @param current - root of subtree
		 * @return pointer on leaf
		*/
    Node<T>* subtreeToLeaf(Node<T>* current){
        if (current->left == nullptr || current->right == nullptr)
            return current;
        else if (current->left != nullptr) {
            current->dataSwap(current->left);
            subtreeToLeaf(current->left);
        } else if (current->right != nullptr) {
            current->dataSwap(current->right);
            subtreeToLeaf(current->right);
        }
    }
        /**
		 * @brief func to delete node from tree
		 * @param data - key to delete
         * @param root - root node of (sub)tree (default = root)
		*/
    void nodeRemover(Node<T>* node, Node<T>* current) {
        if (contains(node, current) == false)
            return;
        else{
            if (node->data > current->data)
                nodeRemover(node, current->right);
            else if (node->data < current->data)
                nodeRemover(node, current->left);
            else{
                delete subtreeToLeaf(current);
            }
        }
    }
        /**
		 * @brief func to delete tree
         * @param root - root node of (sub)tree (default = root)
		*/
    void treeRemover(Node<T>* node){
        if (node) {
            treeRemover(node->left);
            treeRemover(node->right);
            delete node;
        }
    }
public:
    BST() { this->root = nullptr; }
    Node<T>* getRoot() { return this->root; }
    Node<T>* getMin() { return findMin(this->root); }
    Node<T>* getMax() { return findMax(this->root); }
        /**
		 * @brief interface for inserter
		 * @param newData - key to insert
		*/
    void insertNode(const T& newData) {
        this->root = inserter(new Node<T>(newData), this->root, nullptr);
    }
        /**
		 * @brief interface for contains
		 * @param dataToFind - key to search
         * @return bool - flag - is tree contains it or not
		*/
    bool isContains (T dataToFind) {
        Node<T>* tmp = new Node<T>(dataToFind);
        bool is = contains(tmp, this->root);
        delete tmp;
        return is;
    }
        /**
		 * @brief interface for in increase order output
         * @return string of nodes in increasing order
		*/
        std::string inOrderPrint() {
            std::ostringstream buffer{};
            inOrderTraversal(this->root, buffer);
            return buffer.str();
        }
        /**
		 * @brief interface for in decrease order output
         * @return string of nodes in increasing order
		*/
        std::string postOrderPrint() {
            std::ostringstream buffer{};
            postOrderTraversal(this->root, buffer);
            return buffer.str();
        }
        /**
		 * @brief interface for deleting node from tree
		*/
    void deleteNode(const T& data) {
        Node<T>* tmp = new Node<T>(data);
        nodeRemover(tmp, this->root);
        delete tmp;
    }
        /**
		 * @brief tree destructor
		*/
    ~BST() { treeRemover(this->root); }
};