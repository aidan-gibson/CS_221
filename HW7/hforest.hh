/*
 * HForest: a class to represent a collection of independent HTrees. Each HTree in the collection is the root of its own tree.
 */

#pragma once

#include <vector>
#include "htree.hh"
// not allowed to use namespace std in header files

class HForest
{
public:
    // return how many trees are in the forest.
    std::size_t size() const; // std::size_t is sizeof(unsigned int), this is nicely portable across systems.

    // Take a pointer to an HTree (of type HTree::tree_ptr_t) and add it to the forest.
    void add_tree(HTree::tree_ptr_t tree);

    // return a pointer to the HTree with the lowest value in the root node, and remove it from the forest.
    HTree::tree_ptr_t pop_tree();

private:
    std::vector<HTree::tree_ptr_t> tree_vector;
};
