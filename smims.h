#pragma once
#include <string>

class Info
{
    private:
        struct Node
        {
            int code, count;
            //char type[4];
            std::string name, type;
            Node *link;
        };
        int numItem;
        Node *pHead;
        Node *pTail;
        Node *pCurr;

    public:
        Info();
        ~Info();
        void readExisting();
        void getEntry(int, std::string, std::string);
        void addEntry();
        void saveList();
        void showList();
};