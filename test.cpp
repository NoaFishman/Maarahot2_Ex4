/*
ID: 319055430
Email: noa.fishman@gmail.com
*/

#include "doctest.h"
#include "tree.hpp"
#include <sstream>

using namespace std;
using namespace noa;


TEST_CASE("check the algorithm tree1")
{
    // checking that all the algorithms work on double tree
    Node<double> root_node(1.1);
    Tree<double> tree(&root_node); // Binary tree that contains doubles.
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.addKid(&root_node, &n1);
    tree.addKid(&root_node, &n2);
    tree.addKid(&n1, &n3);
    tree.addKid(&n1, &n4);
    tree.addKid(&n2, &n5);

    string ans;

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
        ans = ans + node->get_value() + " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout <<  endl;

    CHECK(ans.compare("1.1 1.2 1.3 1.4 1.5 1.6 ") == true);

    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "post order" << endl;

    string ans2 = "";

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
        ans2 = ans2 + node->get_value() + " ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl << ans2 << endl;

    CHECK(ans2 == "1.4 1.5 1.2 1.6 1.3 1.1 ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "in order" << endl;

    string ans3;

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
        ans3 = ans3 + node->get_value() + " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    CHECK(ans3 == "1.4 1.2 1.5 1.1 1.6 1.3 ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();


    string ans4;
    cout << "BFS" << endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
        ans4 = ans4 + node->get_value() + " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    CHECK(ans4 == "1.1 1.2 1.3 1.4 1.5 1.6 ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "BFS but not telling" << endl;
    string ans5;

    for (auto node : tree)
    {
        cout << node.get_value() << ", ";
        ans5 = ans5 + node.get_value() + " ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    CHECK(ans5 == "1.1 1.2 1.3 1.4 1.5 1.6 ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "DFS" << endl;
    string ans6;

    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
        ans6 = ans6 + node->get_value() + " ";
    }// prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    CHECK(ans6 == "1.1 1.2 1.4 1.5 1.3 1.6 ");
    
}

TEST_CASE("check the algorithm tree2")
{
    // checking that all the algorithms work for string tree
    Node<string> root_node("Anthony");
    Tree<string> tree(&root_node); // Binary tree that contains doubles.
    Node<string> n1("Benedict");
    Node<string> n2("Coline");
    Node<string> n3("Daphnie");
    Node<string> n4("Eloise");
    Node<string> n5("Francesca");
    Node<string> n6("Gregory");
    Node<string> n7("Hyacinth");

    tree.addKid(&root_node, &n1);
    tree.addKid(&root_node, &n2);
    tree.addKid(&n1, &n3);
    tree.addKid(&n1, &n4);
    tree.addKid(&n2, &n5);
    tree.addKid(&n2, &n6);
    tree.addKid(&n3, &n7);

    string ans;

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
        ans = ans + node->get_value() + " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout <<  endl;

    CHECK(ans == "Anthony Benedict Daphnie Hyacinth Eloise Coline Francesca Gregory ");

    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    root_node.setNode();

    cout << "post order" << endl;

    string ans2 = "";

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
        ans2 = ans2 + node->get_value() + " ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl << ans2 << endl;

    CHECK(ans2 == "Hyacinth Daphnie Eloise Benedict Francesca Gregory Coline Anthony ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    root_node.setNode();

    cout << "in order" << endl;

    string ans3;

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
        ans3 = ans3 + node->get_value() + " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;

    CHECK(ans3 == "Hyacinth Daphnie Benedict Eloise Anthony Francesca Coline Gregory ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    root_node.setNode();


    string ans4;
    cout << "BFS" << endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
        ans4 = ans4 + node->get_value() + " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    CHECK(ans4 == "Anthony Benedict Coline Daphnie Eloise Francesca Gregory Hyacinth ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    root_node.setNode();

    cout << "BFS but not telling" << endl;
    string ans5;

    for (auto node : tree)
    {
        cout << node.get_value() << ", ";
        ans5 = ans5 + node.get_value() + " ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    CHECK(ans5 == "Anthony Benedict Coline Daphnie Eloise Francesca Gregory Hyacinth ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n6.setNode();
    n7.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "DFS" << endl;
    string ans6;

    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
        ans6 = ans6 + node->get_value() + " ";
    }// prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    CHECK(ans6 == "Anthony Benedict Daphnie Hyacinth Eloise Coline Francesca Gregory ");
    
}

TEST_CASE("check my heap"){

    // checking that my heap realy working
    Node<double> root_node(1.1);
    Tree<double> tree(&root_node); // Binary tree that contains doubles.
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.addKid(&root_node, &n1);
    tree.addKid(&root_node, &n2);
    tree.addKid(&n1, &n3);
    tree.addKid(&n1, &n4);
    tree.addKid(&n2, &n5);

    tree.myHeap();

    CHECK(root_node.value < n1.value);
    CHECK(root_node.value < n2.value);
    CHECK(n1.value < n3.value);
    CHECK(n1.value < n4.value);
    CHECK(n2.value < n5.value);
}

TEST_CASE("check the algorithm tree3"){
    // checking that all the algorithms work for complex treee with 3 kids 
    Complex c1(3 , 4);
    Complex c2(2 , 7);
    Complex c3(1 , 1);
    Complex c4(8 , 3);
    Complex c5(5 , 9);
    Complex c6(4 , 6);
    Complex c7(9 , 3);
    Complex c8(5 , 7);

    Node<Complex> root_node(c1);
    Tree<Complex> tree(&root_node, 3); // Binary tree that contains doubles.
    Node<Complex> n1(c2);
    Node<Complex> n2(c3);
    Node<Complex> n3(c4);
    Node<Complex> n4(c5);
    Node<Complex> n5(c6);
    Node<Complex> n6(c7);
    Node<Complex> n7(c8);

    tree.addKid(&root_node, &n1);
    tree.addKid(&root_node, &n2);
    tree.addKid(&root_node, &n3);
    tree.addKid(&n1, &n4);
    tree.addKid(&n1, &n5);
    tree.addKid(&n1, &n6);
    tree.addKid(&n2, &n7);

    string ans;

    // should run DFS !!!
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
        ans = ans + node->get_value() + " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout <<  endl;

    CHECK(ans == "3 + 4i 2 + 7i 5 + 9i 4 + 6i 9 + 3i 1 + 1i 5 + 7i 8 + 3i ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    root_node.setNode();


    string ans4;
    cout << "BFS" << endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
        ans4 = ans4 + node->get_value() + " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    CHECK(ans4 == "3 + 4i 2 + 7i 1 + 1i 8 + 3i 5 + 9i 4 + 6i 9 + 3i 5 + 7i ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n4.setNode();
    n6.setNode();
    n7.setNode();
    root_node.setNode();

    cout << "BFS but not telling" << endl;
    string ans5;

    for (auto node : tree)
    {
        cout << node.get_value() << ", ";
        ans5 = ans5 + node.get_value() + " ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;

    CHECK(ans5 == "3 + 4i 2 + 7i 1 + 1i 8 + 3i 5 + 9i 4 + 6i 9 + 3i 5 + 7i ");

    // setting all the node befor the next i scanning
    n1.setNode();
    n2.setNode();
    n3.setNode();
    n5.setNode();
    n6.setNode();
    n7.setNode();
    n4.setNode();
    root_node.setNode();

    cout << "DFS" << endl;
    string ans6;

    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
        ans6 = ans6 + node->get_value() + " ";
    }// prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;

    CHECK(ans6 == "3 + 4i 2 + 7i 5 + 9i 4 + 6i 9 + 3i 1 + 1i 5 + 7i 8 + 3i ");
    
}