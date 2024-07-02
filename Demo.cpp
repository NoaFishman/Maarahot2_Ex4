/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "tree.hpp"


using namespace std;
using namespace noa;

int main(){

    Node<double> root_node(1.1);
    Tree<double> tree(&root_node); // Binary tree that contains doubles.
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);
    

    tree.addKid(&root_node, &n1); // adding the kids to the tree
    tree.addKid(&root_node, &n2);
    tree.addKid(&n1, &n3);
    tree.addKid(&n1, &n4);
    tree.addKid(&n2, &n5);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    // running pre order and printing 

    cout << "pre order" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "post order" << endl;
    // running post order and printing 
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "in order" << endl;
    // running in order and printing 
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();


    cout << "BFS" << endl;
    // running BFS and printing 
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "BFS but not telling" << endl;
    // running BFS and printing 
    for (auto node : tree)
    {
        cout << node.get_value() << ", ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "DFS" << endl;
    // running DFS and printing 
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    }// prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();
   
    cout << tree << endl; // Should print the graph using GUI.

    tree.myHeap(); // doing my heap - turrning the tree to mun heap

    cout << tree << endl; // Should print the graph using GUI.

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    // removing all the pointer at each node from the others
    n5.removeFromTree();
    n4.removeFromTree();
    n3.removeFromTree();
    n2.removeFromTree();
    n1.removeFromTree();
    root_node.removeFromTree();

    // mbuild the new tree with 3 kids
    Tree<double> three_ary_tree(&root_node, 3); // 3-ary tree.
    three_ary_tree.addKid(&root_node, &n1);
    three_ary_tree.addKid(&root_node, &n2);
    three_ary_tree.addKid(&root_node, &n3);
    three_ary_tree.addKid(&n1, &n4);
    three_ary_tree.addKid(&n2, &n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    

    cout << "BFS k=3" << endl;
    // running BFS and printing 
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "DFS k=3" << endl;
    // running DFS and printing 
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    }// prints: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4
    cout << endl;

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    // running pre order and printing with 3 kids so should do dfs
    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << "hereeee" << endl;

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "post order" << endl;
    // running post order and printing with 3 kids so should do dfs
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "in order" << endl;
    // running in order and printing with 3 kids so should do dfs
    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    cout << three_ary_tree << endl; // Should print the graph using GUI.

    return 1;
}