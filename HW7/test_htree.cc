/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <cassert>
#include <iostream>

using namespace std;

// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree()
{
  auto tree_0 = make_shared<HTree>(7, 4);
  auto tree_1 = make_shared<HTree>(2, 11, tree_0);
  auto tree_2 = make_shared<HTree>(9, 32);
  auto tree_3 = make_shared<HTree>(5, -4);
  auto tree_4 = make_shared<HTree>(16, 40, tree_2, tree_1);
  auto tree_5 = make_shared<HTree>(100, 100, tree_3);

  return make_unique<HTree>(126, 1, tree_4, tree_5);
}

void test_htree(const HTree::tree_ptr_t root)
{
  // tests get_key()
  assert(root->get_key() == 126);
  // tests get_value()
  assert(root->get_value() == 1);
  // tests get_child()
  assert((root->get_child(HTree::Direction::LEFT))->get_key() == 16);
  // tests path_to()
  assert(*(root->path_to(126)) == HTree::path_t({}));
  assert(*(root->path_to(16)) == HTree::path_t({HTree::Direction::LEFT}));
  assert(*(root->path_to(9)) == HTree::path_t({HTree::Direction::LEFT, HTree::Direction::LEFT}));
  assert(*(root->path_to(100)) == HTree::path_t({HTree::Direction::RIGHT}));
  assert(*(root->path_to(5)) == HTree::path_t({HTree::Direction::RIGHT, HTree::Direction::LEFT}));
  assert(*(root->path_to(2)) == HTree::path_t({HTree::Direction::LEFT, HTree::Direction::RIGHT}));
  assert(*(root->path_to(7)) == HTree::path_t({HTree::Direction::LEFT, HTree::Direction::RIGHT, HTree::Direction::LEFT}));
}

int main()
{
  cout << "Attempt create_test_tree()\n";
  auto root = create_test_tree();
  cout << "Successful create_test_tree()\n";
  cout << "Attempt test_htree()\n";
  test_htree(root);
  cout << "Successful test_htree()\n";
  return 0;
}
