//#include "tree.hh" //is this necessary when tree.cpp already includes it? no.
#include "tree.cpp"
#include <iostream>
#include <cassert>

using namespace std;
/*
This file needs to have a main() function, as well as any tester functions you like. These tester functions will create various test trees by creating Tree structures and filling the members with test data (you can combine Tree variables to create an entire test tree, either by modifying left_ / right_ members directly, or by passing completed tree nodes to the create_tree function). Then, test the four public API functions and verify you're getting the output you expected. You may use any testing framework you like, such as Catch2 or plain asserts. Make sure to write thorough tests that cover all legitimate test cases. Also make sure to run your test program under valgrind to ensure no memory bugs.
*/

int main()
{
	//Tree Creation Tests
	tree_ptr_t centerN = create_tree(1,2);
	cout << "Created tree centerN at " << centerN << " with key " << centerN->key_ << " and value " << centerN->value_ <<"\n";
    assert(
    centerN!=nullptr && 
    centerN->key_==1 && 
    centerN->value_==2 && 
    centerN->left_==nullptr &&
    centerN->right_==nullptr
    );
    tree_ptr_t leftN = create_tree(1,1);
	cout << "Created tree leftN at " << leftN << " with key " << leftN->key_ << " and value " << leftN->value_ <<"\n";
    assert(
    leftN!=nullptr && 
    leftN->key_==1 && 
    leftN->value_==1 && 
    leftN->left_==nullptr &&
    leftN->right_==nullptr
    );
    tree_ptr_t rightN = create_tree(1,3);
	cout << "Created tree rightN at " << rightN << " with key " << rightN->key_ << " and value " << rightN->value_ <<"\n";
    assert(
    rightN!=nullptr && 
    rightN->key_==1 && 
    rightN->value_==3 && 
    rightN->left_==nullptr &&
    rightN->right_==nullptr
    );

    centerN->left_=leftN;
    centerN->right_=rightN;

    assert(centerN->left_==leftN);
    assert(centerN->right_==rightN);


    // Tests node_at
    cout << "Node at LRLLLLL " << node_at(centerN, "LRLLLLL") << "\n";
    assert(node_at(centerN, "LRLLLLL")==nullptr);

    cout << "Node at L " << node_at(centerN, "L") << "\n";
    assert(node_at(centerN, "L")!=nullptr);

    cout << "Node at R " << node_at(centerN, "R") << "\n";
    assert(node_at(centerN, "R")!=nullptr);

    cout << "Node at \"\" " << node_at(centerN, "") << "\n";
    assert(node_at(centerN, "")==centerN);

    cout << "Node at -1543j%klsdfa " << node_at(centerN, "-1543j%klsdfa") << "\n";
    assert(node_at(centerN, "-1543j%klsdfa")==nullptr);

    //destroy_tree(centerN);


    // Tests path_to
    cout << "Path to key 1 is " << path_to(centerN, 1) << "\n";
    assert(path_to(centerN, 1)=="L");

    cout << "Path to key 3 is " << path_to(centerN, 3) << "\n";
    assert(path_to(centerN, 3)=="-");

    cout << "Path to key -3 is " << path_to(centerN, -3) << "\n";
    assert(path_to(centerN, 3)=="-");

    destroy_tree(centerN);
    cout << "Tree Deleted, program complete!";
	return 0;
}