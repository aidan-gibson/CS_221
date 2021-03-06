#include "tree.hh"
#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Create a tree object. allocates space for a new tree node and fills it with the given data parameters. By default, the tree is a leaf, so its children point to nullptr, but you may override with actual pointers to other nodes.
 */
tree_ptr_t create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
    tree_ptr_t created_tree = new Tree{key, value, left, right};
    return created_tree;
    /*
    alternatively, could've done
    created_tree = new Tree();
    created_tree -> key_ = key;
    created_tree -> value_ = value;
    created_tree -> left_ = left;
    created_tree -> right_ = right;
    return created_tree;
    */
}


/**
 * @brief Deallocate all space consumed by this tree and its children.
 * 
 */
void destroy_tree(tree_ptr_t tree) //given pointer to tree being destroyed
{
    if (tree->left_!=nullptr) //if left branch exists
    {
        destroy_tree(tree->left_); //recurse over there & delete
    }
    if (tree->right_!=nullptr) //ditto for right branch
    {
        destroy_tree(tree->right_);
    }
    delete tree; //delete the initial node for every recursive step
    tree = nullptr; //tidy good practice
}


/**
 * @brief return a string representing the path taken from a given tree root
// to a given key in the tree. For each left child taken along the path, the
// string contains an 'L' character, and 'R' for a right child, in order.
// So for example for the following tree (only keys depicted, values omitted):

            126
           /   \
          /     \
        -5       12
        / \     /
      12   6   3
          /
         9

// path_to(tree, 9) will return "LRL", path_to(tree, 3) will return "RL", and
// path_to(126) will return "".
//
// If the key isn't found in the tree, path_to should return the string "-".
//
// If multiple matches to key exist in the tree, return the path to the
// leftmost match. For the tree above, path_to(tree, 12) returns "LL".
 * 
 */
string path_to(tree_ptr_t tree, key_type key)
{
    
    if (tree->left_ != nullptr) //check left first; if multiple matches exist we want the leftmost one
    {
        if (path_to(tree->left_, key)!="-") //(if left isn't nullptr) recursive search left, if key found on left trail ("" is returned) THEN "L" is returned, as well as the rest of the trail
        {
            return("L"+ path_to(tree->left_, key));
        }
    }
    if(tree->key_ == key) //if this is placed as the first if statement of the function, you will get the Upper-leftmost node containing the key. But "Left" is Bottom-leftmost for this problem.
    {
        return(""); //KEY FOUND.
    }
    if (tree->right_ != nullptr) //ditto but right
    {
        if (path_to(tree->right_, key)!="-") 
        {
            return("R"+ path_to(tree->right_, key));
        }
    }
    return ("-"); //KEY NOT FOUND ):
}


/**
 * @brief Follow a path from a given root node and return the node that is
// at the end of the path. For example, for the root of the tree above,
// node_at("LR") will return a pointer to the node whose key is 6.
// If the path leads to an invalid or empty child, or contains any character
// other than 'L' or 'R', return nullptr (don't crash)
 * 
 * This will return an addr. To get the value do node_at(test_tree, "LR")->value_ or node_at(test_tree, "LR")->key_ for key
 */
tree_ptr_t node_at(tree_ptr_t tree, string path)
{
    if (path=="" || tree == nullptr) //tree == nullptr necessary. ie if given a path that goes too far. 
    {
        return tree;
    }
    if (path[0]=='L') //path[0] accesses string @ 0. path.at(0) does the same thing but with better error checking, however, in this case, i've checked for an empty string, so string must have some length, so i can use the faster []
    {
        return node_at(tree->left_, path.substr(1)); // path.substr(1) cuts off first char of path. ie "ABCDEF" -> "BCDEF" 
    }
    else if (path[0]=='R')
    {
        return node_at(tree->right_, path.substr(1));
    }

    return nullptr; //in all other cases (ie invalid cases)
}

