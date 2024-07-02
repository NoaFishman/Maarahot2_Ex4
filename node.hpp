#include <iostream>
#include <vector>
#include "complex.hpp"

using namespace std;

namespace noa{

    template<typename T>
    class Node{
        public:
        Node* father;
        vector<Node*> kids; // maby & instade *
        T value;
        bool flag = false;
        int color = 0;
        int level = 0;
        int index = 0;
        int place = 0;
        int k = 2;

        Node(){
            father = nullptr;
        }

        Node(T v){
            father = nullptr;
            value = v;
        }

        Node(T v, Node* f){
            father = f;
            value = v;
        }

        // ~Node() {
        //     //cout << "start delete" << to_string(value)  << endl;
        //     if(!kids.empty()){
        //         for (int i = kids.size()-1; i>=0; i--) {
        //             //cout << "going to " << to_string(kids[i]->value)  << endl;
        //             string x = to_string(kids[i]->value);
        //             delete kids[i]; // Delete each child node
        //             //cout << "back from " << x  << endl;
        //         }
        //     }
        //     kids.clear();
        // }

        int newKid(Node* kid){
            int index = kids.size();
            kids.push_back(kid);
            return index;
        }

        void myFather(Node* f){
            father = f;
        }

        int getKidsNum(){
            return kids.size();
        }

        void setLevel(){
            level = father->level+1; 
        }

        void setK(int key){
            k = key;
        }

        void setIndex(int i){
            index = i;
        }

        int getLevel(){
            return level;
        }

        int getFatherLevel(){
            if(father ==nullptr){
                return level;
            }
            return father->getLevel();
        }


        bool wasThere(){
            return flag;
        }

        int getColor(){
            return color;
        }

        void setColor(int c){
            color = c;
        }

        string get_value(){
            //cout <<"get value" <<endl;
            flag = true;
            color = 1;
            return to_string(value);
        }

        void removeFromTree(){
            //cout << "remove from tree" << endl;
            father = nullptr;
            kids.clear();
        }

        void setNode(){
            flag = false;
            color = 0;
        }

        int getMyIndex(){
            return index;
        }

        void setPlace(int k){
            if(father == nullptr){
                place = 1;
            }
            else{
                place = ((k * father->getPlace())-k+1+index);
            }
        }

        int getPlace(){
            return place;
        }
        
        int getFatherPlace(){
            if(father == nullptr){
                return place;
            }
            return father->getPlace();
        }
        
    };
}

