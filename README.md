# BSTree
*Overview*
-
- A C++ Class template that takes in data and automatically inserts it into a Binary Search Tree.
  - A Binary Search Tree is a type of data structure where each value is stored in a node with a left and right child.
  - The left child is always lower than the node, and the right child is always higher than the node.
- This program also supports removal, search, and two types of traversal: in-order and level order.
  
*Search Threshold*
-
- A unique functionality of this program is that each node counts the number of times it is searched.
- When the predetermined search threshold is reached, the tree will do a single rotation.
  - In a rotation, the searched node moves up a tier and its parent node moves down a tier. Other nodes are rerouted accordingly. 
