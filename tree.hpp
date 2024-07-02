/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "node.hpp"

using namespace std;

namespace noa{

    template<typename T>
    class Tree{

        Node<T>* root;
        int k;
        int nodeNum = 0;
        int maxLevel = 0;
                
    public:

        // constructors
        Tree(){
            root =  nullptr;
            k = 2;
        }

        Tree(Node<T>* head, int num){
            root = head;
            k = num;
            root->setPlace(k);
        }

        Tree(Node<T>* head){
            root = head;
            k = 2;
            root->setPlace(k);
        }

        // adding new kids to the tree by update his kids arry and father pointer 
        void addKid(Node<T>* f, Node<T>* kid){
            if(f->getKidsNum() < k){
                kid->myFather(f);
                kid->setLevel();
                kid->setK(k);
                f->setK(k);
                int index = f->newKid(kid);
                kid->setIndex(index);
                kid->setPlace(k);
                if(kid->getLevel() > maxLevel){
                    maxLevel = kid->getLevel();
                }
                nodeNum++;
            }
            else{
                cout << "you have full kids" << endl;
            }
        }

        // operator that show a GUI of the graph 
        friend ostream& operator<<(ostream& output, Tree<T> tree){ 
            
            // difining vectors to all the parameters
            vector<double> values;
            vector<sf::CircleShape> circles;
            vector<sf::Text> texts;
            vector<sf::VertexArray> lines;

            int hight = 600/(tree.maxLevel +1);
            // difining the window
            sf::RenderWindow window(sf::VideoMode(840, 800), "SFML works!");
            cout << "hai!" << endl;
            window.setVerticalSyncEnabled(true);

            // difining the font
            sf::Font font;
                if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
                {
                    std::cerr << "Error loading font\n";
                    return output;
                }

            for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
            {
                //for each node creat a circle
                sf::CircleShape circle(30);
                circle.setFillColor(sf::Color::White);
                circle.setOutlineThickness(3);
                circle.setOutlineColor(sf::Color::Red);

                // calculate the location of the cicle on the window
                int x = pow(tree.k, node->getLevel());
                x = x +1;
                int w = 800/x;
                int z = w * node->getPlace();

                circle.setPosition(z, hight*(node->getLevel()+1));
                // define a line between the nodes
                sf::VertexArray line(sf::Lines, 2); 

                // Define the start and end points of the line segment
                sf::Vector2f startPoint(z+20, hight*(node->getLevel()+1)+20);
                
                // calculate the point location on the window
                x = pow(tree.k, node->getFatherLevel());
                x = x +1;
                w = 800/x;
                z = w * node->getFatherPlace();
                sf::Vector2f endPoint(z+20, hight*(node->getFatherLevel()+1)+20);

                // Set positions and color for each vertex of the line segment
                line[0].position = startPoint; // First vertex position (start point)
                line[1].position = endPoint;   // Second vertex position (end point)

                // Set color for each vertex of the line segment
                line[0].color = sf::Color::Red;  // Color of the first vertex (start point)
                line[1].color = sf::Color::Blue; // Color of the second vertex (end point)

                lines.push_back(line);

                
                string temp = node->get_value();

                sf::Text text(temp, font);
                // defining the text
                text.setCharacterSize(10); 
                text.setStyle(sf::Text::Bold);
                text.setFillColor(sf::Color::Black);

                sf::FloatRect textBounds = text.getLocalBounds();
                text.setOrigin(textBounds.width / 2, textBounds.height / 2);
                text.setPosition(circle.getPosition().x + circle.getRadius(), circle.getPosition().y + circle.getRadius());
                texts.push_back(text);
                circles.push_back(circle);
            }
            
            
            // opening the window until the user close it
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                // Clear the window with a black color
                window.clear(sf::Color::Black);

                //Draw the shapes
                for(unsigned int i=0; i<lines.size(); i++){
                    window.draw(lines[i]);
                }
                for(unsigned int i=0; i<circles.size(); i++){
                    window.draw(circles[i]);
                }
                for(unsigned int i=0; i<texts.size(); i++){
                    window.draw(texts[i]);
                }
                
                // Display the contents of the window
                window.display();
                
            }
            return output;
        }

        // pre order iterator 
        class PreOrder {

        private:

            Node<T>* pToCurr;

        public:

            PreOrder(Node<T>* ptr = nullptr) : pToCurr(ptr) {}

            // operators
            Node<T>& operator*() const{
                return *pToCurr;
            }

            Node<T>* operator->() const{
                return pToCurr;
            }

            // ++ operator rot , left kid, right kid
            PreOrder& operator++(){
                if(pToCurr == nullptr){
                    return *this;
                }
                if(pToCurr->k > 2){
                    DFS dfs{pToCurr};
                    ++dfs;
                    pToCurr = dfs.getNode();
                    return *this;
                }
                else{
                    while(pToCurr != nullptr && pToCurr->flag== true){
                        if(pToCurr->kids.size() > 0){
                            if(pToCurr->kids[0]->flag == false){
                                pToCurr = pToCurr->kids[0];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == false){
                                pToCurr = pToCurr->kids[1];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == true){
                                pToCurr = pToCurr->father;
                            }
                            else if(pToCurr->kids.size() == 1){
                                pToCurr = pToCurr->father;
                            }
                        }
                        else{
                            pToCurr = pToCurr->father;
                        }
                    }
                }
                return *this;
            }

            // ++ operator rot , left kid, right kid
            const PreOrder operator++(int){
                if(pToCurr == nullptr){
                    return *this;
                }
                PreOrder temp = *this;
                if(pToCurr->k > 2){
                    DFS dfs{pToCurr};
                    ++dfs;
                    pToCurr = dfs.getNode();
                    return temp;
                }
                else{
                    while(pToCurr != nullptr && pToCurr->flag== true){
                        if(pToCurr->kids.size() > 0){
                            if(pToCurr->kids[0]->flag == false){
                                pToCurr = pToCurr->kids[0];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == false){
                                pToCurr = pToCurr->kids[1];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == true){
                                pToCurr = pToCurr->father;
                            }
                            else if(pToCurr->kids.size() == 1){
                                pToCurr = pToCurr->father;
                            }
                        }
                        else{
                            pToCurr = pToCurr->father;
                        }
                    }
                }
                
                return temp;
            }

            bool operator==(const PreOrder& other) const{
                return pToCurr == other.pToCurr;
            }

            bool operator!=(const PreOrder& other) const{
                return pToCurr != other.pToCurr;
            }
        };

        // post order iterator 
        class PostOrder {

        private:

            Node<T>* pToCurr;

        public:

            PostOrder(Node<T>* ptr = nullptr) : pToCurr(ptr) {
                if (pToCurr) {
                    while (pToCurr->kids.size() > 0) {
                        pToCurr = pToCurr->kids[0];
                    }
                }
            }

            // operators
            Node<T>& operator*() const{
                return *pToCurr;
            }

            Node<T>* operator->() const{
                return pToCurr;
            }

            // ++ operator left kid, right kid, root
            PostOrder& operator++(){
                if(pToCurr == nullptr){
                    return *this;
                }
                if(pToCurr->k > 2){
                    DFS dfs{pToCurr};
                    ++dfs;
                    pToCurr = dfs.getNode();
                    return *this;
                }
                else{
                    while(pToCurr != nullptr){
                        if(pToCurr->kids.size() > 0){
                            if(pToCurr->flag == false && pToCurr->kids[0]->flag == false){
                                pToCurr = pToCurr->kids[0];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == false){
                                pToCurr = pToCurr->kids[1];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == true){
                                break;
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == true){
                                pToCurr = pToCurr->father;
                            }
                            else if(pToCurr->kids.size() == 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true){
                                break;
                            }
                            else if(pToCurr->kids.size() == 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true){
                                pToCurr = pToCurr->father;
                            }

                        }
                        else if (pToCurr->flag == false){
                            break;
                        }
                        else if (pToCurr->flag == true){
                            pToCurr = pToCurr->father;
                        }
                    }
                }
                return *this;
            }

            // ++ operator left kid, right kid, root
            const PostOrder operator++(int){
                if(pToCurr == nullptr){
                    return *this;
                }
                PostOrder temp = *this;
                if(pToCurr->k > 2){
                    DFS dfs{pToCurr};
                    ++dfs;
                    pToCurr = dfs.getNode();
                    return temp;
                }
                else{
                    while(pToCurr != nullptr){
                        if(pToCurr->kids.size() > 0){
                            if(pToCurr->flag == false && pToCurr->kids[0]->flag == false){
                                pToCurr = pToCurr->kids[0];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == false){
                                pToCurr = pToCurr->kids[1];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == true){
                                break;
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == true){
                                pToCurr = pToCurr->father;
                            }
                            else if(pToCurr->kids.size() == 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true){
                                break;
                            }
                            else if(pToCurr->kids.size() == 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true){
                                pToCurr = pToCurr->father;
                            }

                        }
                        else if (pToCurr->flag == false){
                            break;
                        }
                        else if (pToCurr->flag == true){
                            pToCurr = pToCurr->father;
                        }
                    }
                }
                return temp;
            }

            bool operator==(const PostOrder& other) const{
                return pToCurr == other.pToCurr;
            }

            bool operator!=(const PostOrder& other) const{
                return pToCurr != other.pToCurr;
            }
        };

        // in order iterator 
        class InOrder {

        private:

            Node<T>* pToCurr;

        public:

            InOrder(Node<T>* ptr = nullptr) : pToCurr(ptr) {
                if (pToCurr) {
                    while (pToCurr->kids.size() > 0) {
                        pToCurr = pToCurr->kids[0];
                    }
                }
            }
            
            // operator 
            Node<T>& operator*() const{
                return *pToCurr;
            }

            Node<T>* operator->() const{
                return pToCurr;
            }
            
            // ++ operator left kid , root , right kid
            InOrder& operator++(){
                if(pToCurr == nullptr){
                    return *this;
                }
                if(pToCurr->k > 2){
                    DFS dfs{pToCurr};
                    ++dfs;
                    pToCurr = dfs.getNode();
                    return *this;
                }
                else{
                    while(pToCurr != nullptr){
                        //cout <<"value: " << pToCurr->value << endl;
                        if(pToCurr->kids.size() > 0){
                            if(pToCurr->flag == false && pToCurr->kids[0]->flag == false){
                                pToCurr = pToCurr->kids[0];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == false){
                                break;
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == false){
                                pToCurr = pToCurr->kids[1];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == true){
                                pToCurr = pToCurr->father;
                            }
                            else if(pToCurr->kids.size() == 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true){
                                break;
                            }
                            else if(pToCurr->kids.size() == 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true){
                                pToCurr = pToCurr->father;
                            }
                        }
                        else if (pToCurr->flag == false){
                            break;
                        }
                        else if (pToCurr->flag == true){
                            pToCurr = pToCurr->father;
                        }
                    }
                }
                return *this;
            }

            // ++ operator left kid , root , right kid
            const InOrder operator++(int){
                if(pToCurr == nullptr){
                    return *this;
                }
                InOrder temp = *this;
                if(pToCurr->k > 2){
                    DFS dfs{pToCurr};
                    ++dfs;
                    pToCurr = dfs.getNode();
                    return temp;
                }
                else{
                    while(pToCurr != nullptr){
                        if(pToCurr->kids.size() > 0){
                            if(pToCurr->flag == false && pToCurr->kids[0]->flag == false){
                                pToCurr = pToCurr->kids[0];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == false){
                                break;
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == false){
                                pToCurr = pToCurr->kids[1];
                            }
                            else if(pToCurr->kids.size() > 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true && pToCurr->kids[1]->flag == true){
                                pToCurr = pToCurr->father;
                            }
                            else if(pToCurr->kids.size() == 1 && pToCurr->flag == false && pToCurr->kids[0]->flag == true){
                                break;
                            }
                            else if(pToCurr->kids.size() == 1 && pToCurr->flag == true &&pToCurr->kids[0]->flag == true){
                                pToCurr = pToCurr->father;
                            }
                        }
                        else if (pToCurr->flag == false){
                            break;
                        }
                        else if (pToCurr->flag == true){
                            pToCurr = pToCurr->father;
                        }
                    }
                }
                return temp;
            }

            bool operator==(const InOrder& other) const{
                return pToCurr == other.pToCurr;
            }

            bool operator!=(const InOrder& other) const{
                return pToCurr != other.pToCurr;
            }
        };

        // DFS iteration
        class DFS {

        private:

            Node<T>* pToCurr;

        public:

            DFS(Node<T>* ptr = nullptr) : pToCurr(ptr) {}

            // operators
            Node<T>& operator*() const{
                return *pToCurr;
            }

            Node<T>* operator->() const{
                return pToCurr;
            }

            Node<T>* getNode(){
                return pToCurr;
            }

            // ++ operator of DFS
            DFS& operator++(){
                if(pToCurr == nullptr){
                    return *this;
                }
                if (pToCurr->getColor() == 0){
                    return *this;
                }
                while(pToCurr != nullptr && pToCurr->flag == true){
                    int i =0 ;
                    if (pToCurr->getColor() == 1){
                        while(i < pToCurr-> getKidsNum() && pToCurr->kids[i]->color == 2){
                            i++;
                        }
                        if(i < pToCurr-> getKidsNum()){
                            pToCurr = pToCurr->kids[i];
                        }
                        else{
                            pToCurr->setColor(2);
                            pToCurr = pToCurr->father;
                        }   
                    }
                    else if(pToCurr->getColor() == 2){
                        pToCurr = pToCurr->father;
                    }
                }
                return *this;
            }

            // ++ operator of DFS
            const DFS operator++(int){
                if(pToCurr == nullptr){
                    return *this;
                }
                if (pToCurr->getColor() == 0){
                    return *this;
                }
                DFS temp = *this;
                while(pToCurr->flag == true){
                    int i =0 ;
                    if (pToCurr->getColor() == 1){
                        while(i < pToCurr-> getKidsNum() && pToCurr->kids[i]->color == 2){
                            i++;
                        }
                        if(i < pToCurr-> getKidsNum()){
                            pToCurr = pToCurr->kids[i];
                        }
                        else{
                            pToCurr->setColor(2);
                            pToCurr = pToCurr->father;
                        }   
                    }
                    else if(pToCurr->getColor() == 2){
                        pToCurr = pToCurr->father;
                    }
                }
                return temp;
            }

            bool operator==(const DFS& other) const{
                return pToCurr == other.pToCurr;
            }

            bool operator!=(const DFS& other) const{
                return pToCurr != other.pToCurr;
            }
        };

        // BFS iteration
        class BFS {
        private:
            Node<T>* pToCurr;
            std::queue<Node<T>*> nodeQueue;

        public:
            BFS(Node<T>* ptr = nullptr) : pToCurr(ptr) {
                if (pToCurr) {
                    nodeQueue.push(pToCurr);
                }
            }

            // operators
            Node<T>& operator*() const {
                return *pToCurr;
            }

            Node<T>* operator->() const {
                return pToCurr;
            }

            // ++ operator of BFS
            BFS& operator++() {
                if (!nodeQueue.empty()) {
                    pToCurr = nodeQueue.front();
                    nodeQueue.pop();
                    for (unsigned int i=0; i< pToCurr->kids.size(); i++) {
                        nodeQueue.push(pToCurr->kids[i]);
                    }
                    if (!nodeQueue.empty()) {
                        pToCurr = nodeQueue.front();
                    } else {
                        pToCurr = nullptr;
                    }
                } else {
                    pToCurr = nullptr;
                }
                return *this;
            }

            // ++ operator of BFS
            const BFS operator++(int) {
                BFS temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const BFS& other) const {
                return pToCurr == other.pToCurr;
            }

            bool operator!=(const BFS& other) const {
                return pToCurr != other.pToCurr;
            }

            string get_value() const {
                return pToCurr ? pToCurr->get_value() : "";
            }
        };

        // Heap iteration
        class Heap {
        private:
            Node<T>* pToCurr;
            int i;

        public:
            Heap(Node<T>* ptr = nullptr) : pToCurr(ptr) {
                i=0;
            }
            
            // operators
            Node<T>& operator*() const {
                return *pToCurr;
            }

            Node<T>* operator->() const {
                return pToCurr;
            }

            Heap& operator++() {
                
                return *this;
            }

            const Heap operator++(int) {
                Heap temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const Heap& other) const {
                return pToCurr == other.pToCurr;
            }

            bool operator!=(const Heap& other) const {
                return pToCurr != other.pToCurr;
            }

            string get_value() const {
                return pToCurr ? pToCurr->get_value() : "";
            }
        };

        // changing all tje node to be min heap
        static void arrayToHeap(Node<T>* root, vector<T>& elements, int& index) {
            if (root == NULL) return;
            root->value = elements[index++];
            if(root->kids.size() == 2){
                arrayToHeap(root->kids[0], elements, index);
                arrayToHeap(root->kids[1], elements, index);
            }
            else if(root->kids.size() == 1){
                arrayToHeap(root->kids[0], elements, index);
            }
            else {
                arrayToHeap(NULL, elements, index);
            }
            
        }

        // turning the tree to min heap and returning Heap iteration
        Heap myHeap(){
            cout << "my heap" << endl;
            vector<T> elements;
            treeToVec(root, elements);
            cout << "after" << endl;
            sort(elements.begin(), elements.end());
            cout << "sorted" << endl;
            int index = 0;
            arrayToHeap(root, elements, index);
            return Heap{root};
        }

        // adding all the nodes of the tree to vector
        static void treeToVec(Node<T>* root, vector<T>& elements) {
            if (root == NULL) return;
            if(root->kids.size() == 2){
                treeToVec(root->kids[0], elements);
                elements.push_back(root->value);
                treeToVec(root->kids[1], elements);
            }
            if(root->kids.size() == 1){
                treeToVec(root->kids[0], elements);
                elements.push_back(root->value);
            }
            if(root->kids.size() == 0){
                elements.push_back(root->value);
            }
            
        }


        //begin and end functions for all the iterations 
        
        PreOrder begin_pre_order(){
            return PreOrder{root};
        }

        PreOrder end_pre_order(){
            return PreOrder{nullptr};
        }

        PostOrder begin_post_order(){
            return PostOrder{root};
        }

        PostOrder end_post_order(){
            return PostOrder{nullptr};
        }

        InOrder begin_in_order(){
            return InOrder{root};
        }

        InOrder end_in_order(){
            return InOrder{nullptr};
        }

        DFS begin_dfs_scan(){
            return DFS{root};
        }

        DFS end_dfs_scan(){
            return DFS{nullptr};
        }

        BFS begin_bfs_scan(){
            return BFS{root};
        }

        BFS end_bfs_scan(){
            return BFS{nullptr};
        }
        
        BFS begin(){
            return BFS{root};
        }

        BFS end(){
            return BFS{nullptr};
        }

    };
}