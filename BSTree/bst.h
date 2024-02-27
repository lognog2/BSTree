#include <iostream>
#include <string>
#include <sstream>

template <typename T>
class BST
{
    struct BSTNode
    {
        T element;
        BSTNode* left;
        BSTNode* right;
        int count;
        BSTNode(const T& theElement, BSTNode* lt, BSTNode* rt, int count)
            :element{theElement}, left{lt}, right{rt}, count{count} {}
        BSTNode(const T&& theElement, BSTNode* lt, BSTNode* rt, int count)
            :element{std::move(theElement)}, left{lt}, right{rt}, count{count} {}
    };
    public:
    BST(int th=default_threshold_value); //constructor
    BST(const std::string input, int th=default_threshold_value); //parameter constructor
    BST(const BST& rhs); //copy constructor
    BST(BST&& rhs); //move constructor
    ~BST(); //destructor
    void buildFromInputString(const std::string input); //build tree from input
    const BST & operator=(const BST& rhs); //copy assignment op
    const BST & operator=(BST&& rhs); //move assignment op
    bool empty(); //returns whether tree is empty or not
    void printInOrder() const;
    void printLevelOrder() const;
    int numOfNodes() const;
    int height() const;
    void makeEmpty();
    void insert(const T& v); //copy insert
    void insert(T &&v); //move insert
    void remove(const T& v);
    bool contains(const T& v);

    private:
    BSTNode* root;
    int threshold;
    static const int default_threshold_value = 1;

    void printInOrder(BSTNode *t) const;
    void printLevelOrder(BSTNode *t) const;
    void getLevel(BSTNode* t, int level) const;
    void makeEmpty(BSTNode* &t);
    void insert(const T& v, BSTNode *&t);
    void insert(T&& v, BSTNode *&t);
    void remove(const T& v, BSTNode *&t);
    bool contains(const T& v, BSTNode *&t /*...other parameters if necessary...*/);
    int numOfNodes(BSTNode *t) const;
    int height(BSTNode *t) const;
    BSTNode * clone(BSTNode *t) const;
    BSTNode* findMin(BSTNode* t) const;
    void rotateLeft (BSTNode*& p);
    void rotateRight (BSTNode*& p);

}; //end class
#include "bst.hpp"
