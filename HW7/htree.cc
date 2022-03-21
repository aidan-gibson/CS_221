/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"

using namespace std;

// Constructor
HTree::HTree(
    HTree::key_t key,
    HTree::value_t value,
    HTree::tree_ptr_t left,
    HTree::tree_ptr_t right)
{
  key_ = key;
  value_ = value;
  left_ = left;
  right_ = right;
}

// Return key in current node
HTree::key_t
HTree::get_key() const
{
  return key_;
}

// Return value in current node
HTree::value_t
HTree::get_value() const
{
  return value_;
}

// Return the child of this node indicated by dir.
// If the child is nullptr (current node is a leaf), returns nullptr.
HTree::tree_ptr_t
HTree::get_child(HTree::Direction dir) const
{

  if (dir == HTree::Direction::LEFT)
  {
    return left_; // it'll return nullptr if there's nothing there
  }
  if (dir == HTree::Direction::RIGHT)
  {
    return right_;
  }
  return nullptr;
}

// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr
HTree::possible_path_t
HTree::path_to(key_t key) const
{
  if (key == get_key())
  { // base case, use get_key() instead of key_
    return make_unique<HTree::path_t>();
  }
  else
  {
    if (get_child(Direction::LEFT)) // if left exists
    {
      auto left_path = get_child(Direction::LEFT)->path_to(key);
      if (left_path)
      {                                         // if left_path exists
        left_path->push_front(Direction::LEFT); // pushes to front of list
        return left_path;
      }
    }
    if (get_child(Direction::RIGHT))
    { // if right exists
      auto right_path = get_child(Direction::RIGHT)->path_to(key);
      if (right_path)
      {                                           // if right_path exists
        right_path->push_front(Direction::RIGHT); // pushes to front of list
        return right_path;
      }
    }
    return nullptr;
  }
}
