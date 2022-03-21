/*
 * HForest: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "hforest.hh"

using namespace std;

// Returns True if t2 value < t1 value; given by Eitan, but I swapped the < for a > for a min heap instead of a max heap
bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2)
{
    return t1->get_value() > t2->get_value();
}

// returns how many trees are in the forest
size_t HForest::size() const
{
    return tree_vector.size(); // vector size fnc
}

// Take a pointer to an HTree (of type HTree::tree_ptr_t) and add it to the forest.
void HForest::add_tree(HTree::tree_ptr_t tree)
{
    tree_vector.push_back(tree);                                      // push_back vector method, adds tree to back
    push_heap(tree_vector.begin(), tree_vector.end(), compare_trees); // places new tree (trees.end()) appropriately in the min heap
}

// return a pointer to the HTree with the lowest value in the root node, and remove it from the forest.
HTree::tree_ptr_t HForest::pop_tree()
{
    if (tree_vector.empty())
    { // check for empty
        return nullptr;
    }
    HTree::tree_ptr_t front = tree_vector.front(); // grabs front elem pointer to return
    tree_vector.erase(tree_vector.begin());        // removes first elem in vector
    return front;                                  // returns back elem pointer which was popped
}
