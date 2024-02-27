#include <iostream>
#include <string>
#include <sstream>

/*
    public functions
*/

//constructor
template <typename T>
BST<T>::BST(int th/*=default_threshold_value*/)
{
    root = new BSTNode{T(), nullptr, nullptr, 0};
    threshold = th;
}

//parameter constructor
template <typename T>
BST<T>::BST(const std::string input, int th/*=default_threshold_value*/)
{
    root = new BSTNode{T(), nullptr, nullptr, 0};
    threshold = th;
    buildFromInputString(input);
}

//copy constructor
template <typename T>
BST<T>::BST(const BST& rhs) :root{nullptr}
{
    root = clone(rhs.root);
}

//move constructor
template <typename T>
BST<T>::BST(BST&& rhs) :root{nullptr}
{
    std::swap(root, rhs.root);
}

//destructor
template <typename T>
BST<T>::~BST()
{
    makeEmpty();
}

//build tree from input
template <typename T>
void BST<T>::buildFromInputString(const std::string input)
{
    if (!empty()) 
        makeEmpty();
    
    std::stringstream ss(input);
    T hold;
    while (ss >> hold)
    {   
        insert(hold);
    }
}

//copy assignment op
template <typename T>
const BST<T>& BST<T>::operator=(const BST &rhs)
{
    root = clone(rhs.root);
    return *this;
}

//move assignment op
template <typename T>
const BST<T>& BST<T>::operator=(BST &&rhs)
{
    std::swap(root, rhs.root);
    return *this;
}

//returns whether tree is empty
template <typename T>
bool BST<T>::empty()
{
    return root == nullptr;
}

//public print in order
template <typename T>
void BST<T>::printInOrder() const
{
    printInOrder(root);
    std::cout << std::endl;
}

//public print level order
template <typename T>
void BST<T>::printLevelOrder() const
{
    printLevelOrder(root);
    std::cout << std::endl;
}

//public node counter
template <typename T>
int BST<T>::numOfNodes() const
{
    return numOfNodes(root);
}

//public height check
template <typename T>
int BST<T>::height() const
{
    return height(root);
}

//public make empty
template <typename T>
void BST<T>::makeEmpty()
{
    makeEmpty(root);
}

//public copy insert
template <typename T>
void BST<T>::insert(const T& v)
{
    insert(v, root);
}

//public move insert
template <typename T>
void BST<T>::insert(T &&v)
{
    insert(v, root);
}

//public remove
template <typename T>
void BST<T>::remove(const T& v)
{
    remove(v, root);
}


//public contains
template <typename T>
bool BST<T>::contains(const T& v)
{
    return contains(v, root);
}

/*
    private functions
*/

//print in order
template <typename T>
void BST<T>::printInOrder(BSTNode *t) const
{
    if (t == nullptr)
        return;
    else
    {
        printInOrder(t->left);
        std::cout << t->element << " ";
        printInOrder(t->right);
    }
}

//print level order
template <typename T>
void BST<T>::printLevelOrder(BSTNode *t) const
{
    int h = height(t);
    for (int i = 1; i <= h; i++)
    {
        getLevel(t, i);
    }
}

//print current level
template <typename T>
void BST<T>::getLevel(BSTNode* t, int level) const
{
    if (t == nullptr)
        return;
    else if (level == 1)
        std::cout << t->element << " ";
    else if (level > 1)
        {
            getLevel(t->left, level - 1);
            getLevel(t->right, level - 1);
        }
}

//delete all nodes from subtree
template <typename T>
void BST<T>::makeEmpty(BSTNode* &t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

//private copy insert
template <typename T>
void BST<T>::insert(const T& v, BSTNode *&t)
{
    if(t == nullptr)
        t = new BSTNode{v, nullptr, nullptr, 0};
    else if (v < t->element)
        insert(v, t->left);
    else if (v > t->element)
        insert(v, t->right);
    else
        return;
}

//private move insert
template <typename T>
void BST<T>::insert(T&& v, BSTNode *&t)
{
    if(t == nullptr)
        t = new BSTNode{std::move(v), nullptr, nullptr, 0};
    else if (v < t->element)
        insert(std::move(v), t->left);
    else if (v > t->element)
        insert(std::move(v), t->right);
    else
        return;
}

//private remove
template <typename T>
void BST<T>::remove(const T& v, BSTNode *&t)
{
    if (t == nullptr)
        return;
    else if (v < t->element)
        remove(v, t->left);
    else if (v > t->element)
        remove(v, t->right);
    else if (t->left != nullptr && t->right != nullptr)
    {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else
    {
        BSTNode* prevNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete prevNode;
    }
}

//private contains
template <typename T>
bool BST<T>::contains(const T& v, BSTNode *&t /*...other parameters if necessary...*/)
{

    BSTNode* p = nullptr; //parent node
    if (t == nullptr)
        return false;
    else if (v < t->element)
    {
        p = t;
        return contains(v, t->left);
    }
    else if (v > t->element)
    {
        p = t;
        return contains(v, t->right);
    }
    else 
    {
        t->count++;
        if (t->count >= threshold)
        {
            if (p != nullptr)
            {
                if (p->element > t->element)
                    rotateLeft(p);
                else
                    rotateRight(p);
            }
            t->count = 0;
        }
        return true;
    }
}

//private node counter
template <typename T>
int BST<T>::numOfNodes(BSTNode *t) const
{
   if (t == nullptr)
        return 0;
    else 
        return (1 + numOfNodes(t->left) + numOfNodes(t->right));
}

//private height
template <typename T>
int BST<T>::height(BSTNode *t) const
{
    if (t == nullptr)
        return 0;
    else
    {
        int leftHeight = height(t->left);
        int rightHeight = height(t->right);
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

//clone
template <typename T>
typename BST<T>::BSTNode* BST<T>::clone(BSTNode *t) const
{
    if (t == nullptr)
        return nullptr;
    else  
        return new BSTNode{t->element, clone(t->left), clone(t->right), t->count};
}

//find minimum
template <typename T>
typename BST<T>::BSTNode* BST<T>::findMin(BSTNode* t) const
{
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    else
        return findMin(t->left);
}

//single left rotation
template <typename T>
void BST<T>::rotateLeft (BSTNode*& p)
{
    BSTNode* t = p->left;
    p->left = t->right;
    t->right = p;
    p = t;
    std::cout << "left rotation was performed, as node " << t->element << " reached threshold\n";
}

//single right rotation
template <typename T>
void BST<T>::rotateRight (BSTNode*& p)
{
    BSTNode* t = p->right;
    p->right = t->left;
    t->left = p;
    p = t;
    std::cout << "right rotation was performed, as node " << t->element << " reached threshold\n";
}

#endif
