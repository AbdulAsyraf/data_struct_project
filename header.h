#pragma once
#include <string>

using namespace std;

class Linked{
    private:
        int numItem;
        struct Node{
            Node *link;
            int code, quantity;
            string type, name;
        };
        Node *pHead;
        Node *pTail;
        Node *pCurr;

    public:
        Linked();
        ~Linked();
        bool checkFile();
        void getInput(int);    //gets user input and calls addNode()
        void addNode(int, int, string, string);  //add data types of all the Node stuff
        int numEle();       //returns numItem
        void show();        //displays contents of list
        void save();        //saves list
        bool search(int);
};