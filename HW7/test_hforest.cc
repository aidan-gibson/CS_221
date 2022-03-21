/*
 * test_tree: A simple unit test for the Forest data structure.
 */
#include "hforest.hh"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
  HForest forest{};
  auto tree_0 = make_shared<HTree>(1, 2);
  forest.add_tree(tree_0);
  auto tree_1 = make_shared<HTree>(10, 20);
  forest.add_tree(tree_1);
  assert(forest.pop_tree() == tree_0); // eliminates tree_0, the smaller value tree
  assert(forest.size() == 1);
  auto tree_2 = make_shared<HTree>(5, 11);
  auto tree_3 = make_shared<HTree>(15, 10);
  auto tree_4 = make_shared<HTree>(77, 377);
  auto tree_5 = make_shared<HTree>(2, 98);
  auto tree_6 = make_shared<HTree>(11, 19);
  auto tree_7 = make_shared<HTree>(7, 456);
  auto tree_8 = make_shared<HTree>(8, 567);
  auto tree_9 = make_shared<HTree>(99, 500);
  auto tree_10 = make_shared<HTree>(1000, 27);
  forest.add_tree(tree_2);
  forest.add_tree(tree_3);
  forest.add_tree(tree_4);
  forest.add_tree(tree_5);
  forest.add_tree(tree_6);
  forest.add_tree(tree_7);
  forest.add_tree(tree_8);
  forest.add_tree(tree_9);
  forest.add_tree(tree_10);
  assert(forest.pop_tree() == tree_3);
  return 0;
}
