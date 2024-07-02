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

    // difining complexs numbers
    Complex c1(3.0 , 2.0);
    Complex c2(4.5 , 7.0);
    Complex c3(3 , 2.8);
    Complex c4(5.7 , 2.1);
    Complex c5(5 , 21.9);
    Complex c6(3.67 , 12.4);
    Complex c7(34 , 22.8);
    Complex c8(6.1 , 8);

    // build a tree with the complex numbers
    Node<Complex> nd1(c1);
    Tree<Complex> treeComp(&nd1);
    Node<Complex> nd2(c2);
    Node<Complex> nd3(c3);
    Node<Complex> nd4(c4);
    Node<Complex> nd5(c5);
    Node<Complex> nd6(c6);
    Node<Complex> nd7(c7);
    Node<Complex> nd8(c8);

    // adding all the node to the tree
    treeComp.addKid(&nd1, &nd2);
    treeComp.addKid(&nd1, &nd3);
    treeComp.addKid(&nd2, &nd4);
    treeComp.addKid(&nd2, &nd5);
    treeComp.addKid(&nd3, &nd6);
    treeComp.addKid(&nd3, &nd7);
    treeComp.addKid(&nd6, &nd8);
    
    // printing the tree
    cout << treeComp;

    treeComp.myHeap(); // turning the treee to mun heap

    cout << treeComp; // printing the tree agin so we can see the change


    // difining new nodes
    Node<double> root_node(1.01);
    Tree<double> tree(&root_node); // Binary tree that contains doubles.
    Node<double> n2(1.02);
    Node<double> n3(1.03);
    Node<double> n4(1.04);
    Node<double> n5(1.05);
    Node<double> n6(1.06);
    Node<double> n7(1.07);
    Node<double> n8(1.08);
    Node<double> n9(1.09);
    Node<double> n10(1.10);
    Node<double> n11(1.11);
    Node<double> n12(1.12);
    Node<double> n13(1.13);
    Node<double> n14(1.14);
    Node<double> n15(1.15);
    Node<double> n16(1.16);
    Node<double> n17(1.17);
    Node<double> n18(1.18);
    Node<double> n19(1.19);
    Node<double> n20(1.20);
    Node<double> n21(1.21);

    // adding all the nodes to the tree
    tree.addKid(&root_node, &n2);
    tree.addKid(&root_node, &n3);
    tree.addKid(&n2, &n4);
    tree.addKid(&n2, &n5);
    tree.addKid(&n3, &n6);
    tree.addKid(&n3, &n7);
    tree.addKid(&n4, &n8);
    tree.addKid(&n4, &n9);
    tree.addKid(&n5, &n10);
    tree.addKid(&n5, &n11);
    tree.addKid(&n6, &n12);
    tree.addKid(&n6, &n13);
    tree.addKid(&n7, &n14);
    tree.addKid(&n8, &n15);
    tree.addKid(&n9, &n16);
    tree.addKid(&n9, &n17);
    tree.addKid(&n10, &n18);
    tree.addKid(&n16, &n19);
    tree.addKid(&n16, &n20);
    tree.addKid(&n20, &n21);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */
    cout << "pre order" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    // setting all the node befor the next i scanning
    n6.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();
    n7.setNode();
    n8.setNode();
    n9.setNode();
    n10.setNode();
    n11.setNode();
    n12.setNode();
    n13.setNode();
    n14.setNode();
    n15.setNode();
    n16.setNode();
    n17.setNode();
    n18.setNode();
    n19.setNode();
    n20.setNode();
    n21.setNode();


    cout << "post order" << endl;

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;

    // setting all the node befor the next i scanning
    n6.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();
    n7.setNode();
    n8.setNode();
    n9.setNode();
    n10.setNode();
    n11.setNode();
    n12.setNode();
    n13.setNode();
    n14.setNode();
    n15.setNode();
    n16.setNode();
    n17.setNode();
    n18.setNode();
    n19.setNode();
    n20.setNode();
    n21.setNode();

    cout << "in order" << endl;

    // setting all the node befor the next i scanning
    n21.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    n8.setNode();
    n9.setNode();
    n10.setNode();
    n11.setNode();
    n12.setNode();
    n13.setNode();
    n15.setNode();
    n14.setNode();
    n16.setNode();
    n17.setNode();
    n18.setNode();
    n19.setNode();
    n20.setNode();
    root_node.setNode();

    cout << "BFS" << endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    // setting all the node befor the next i scanning
    n21.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    n8.setNode();
    n9.setNode();
    n10.setNode();
    n11.setNode();
    n12.setNode();
    n13.setNode();
    n15.setNode();
    n14.setNode();
    n16.setNode();
    n17.setNode();
    n18.setNode();
    n19.setNode();
    n20.setNode();
    root_node.setNode();

    cout << "BFS but not telling" << endl;

    for (auto node : tree)
    {
        cout << node.get_value() << ", ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    // setting all the node befor the next i scanning
    n21.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    n8.setNode();
    n9.setNode();
    n10.setNode();
    n11.setNode();
    n12.setNode();
    n13.setNode();
    n15.setNode();
    n14.setNode();
    n16.setNode();
    n17.setNode();
    n18.setNode();
    n19.setNode();
    n20.setNode();
    root_node.setNode();

    cout << "DFS" << endl;

    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    }// prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    cout << tree; // Should print the graph using GUI.

    n21.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    n8.setNode();
    n9.setNode();
    n10.setNode();
    n11.setNode();
    n12.setNode();
    n13.setNode();
    n15.setNode();
    n14.setNode();
    n16.setNode();
    n17.setNode();
    n18.setNode();
    n19.setNode();
    n20.setNode();
    root_node.setNode();

    // removing all the nodes connections from the first tree
    n21.removeFromTree();
    n2.removeFromTree();
    n3.removeFromTree();
    n5.removeFromTree();
    n4.removeFromTree();
    n6.removeFromTree();
    n7.removeFromTree();
    n8.removeFromTree();
    n9.removeFromTree();
    n10.removeFromTree();
    n11.removeFromTree();
    n12.removeFromTree();
    n13.removeFromTree();
    n15.removeFromTree();
    n14.removeFromTree();
    n16.removeFromTree();
    n17.removeFromTree();
    n18.removeFromTree();
    n19.removeFromTree();
    n20.removeFromTree();
    root_node.removeFromTree();

    
    // adding all the nodes to new tree
    Tree<double> three_ary_tree(&root_node, 4); // 3-ary tree.
    three_ary_tree.addKid(&root_node, &n2);
    three_ary_tree.addKid(&root_node, &n3);
    three_ary_tree.addKid(&root_node, &n4);
    three_ary_tree.addKid(&root_node, &n5);
    three_ary_tree.addKid(&n2, &n6);
    three_ary_tree.addKid(&n2, &n7);
    three_ary_tree.addKid(&n2, &n8);
    three_ary_tree.addKid(&n2, &n9);
    three_ary_tree.addKid(&n3, &n10);
    three_ary_tree.addKid(&n3, &n11);
    three_ary_tree.addKid(&n3, &n12);
    three_ary_tree.addKid(&n4, &n13);
    three_ary_tree.addKid(&n4, &n14);
    three_ary_tree.addKid(&n4, &n15);
    three_ary_tree.addKid(&n4, &n16);
    three_ary_tree.addKid(&n5, &n17);
    three_ary_tree.addKid(&n5, &n18);
    three_ary_tree.addKid(&n10, &n19);
    three_ary_tree.addKid(&n10, &n20);
    three_ary_tree.addKid(&n10, &n21);


     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    

    cout << "BFS k=3" << endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    // setting all the node befor the next i scanning
    n21.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    n8.setNode();
    n9.setNode();
    n10.setNode();
    n11.setNode();
    n12.setNode();
    n13.setNode();
    n15.setNode();
    n14.setNode();
    n16.setNode();
    n17.setNode();
    n18.setNode();
    n19.setNode();
    n20.setNode();
    root_node.setNode();

    cout << "DFS k=3" << endl;

    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    }// prints: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4
    cout << endl;

    cout << three_ary_tree; // Should print the graph using GUI.
}