#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include "smims.h"

using namespace std;

Info::Info()
{
    numItem = 0;
    pHead = NULL;
    pTail = NULL;
    pCurr = NULL;
}

Info::~Info() {}

void Info::addEntry()
{
    char dummy[4];
    string d;
    bool yeah;
    Node *pNew = new Node;
    do{    
        yeah = true;
        cout << "Please enter the category of the item (TOY, GRO, CLO, TLT, STA, MIS): ";
        cin >> dummy;
        for (int u = 0; u < 4; u++)
            dummy[u] = toupper(dummy[u]);
        d = string(dummy);
        if (d == "TOY" || d == "GRO" || d == "CLO" || d == "TLT" || d == "STA" || d == "MIS")
        {
            yeah = false;
            pNew->type = d;
        }
    }while (yeah);
    pNew->code = rand()%10000;
    cout << "Please enter the name of the product: ";
    cin.ignore();
    getline(cin, pNew->name);
    pNew->link = pHead;
    pHead = pNew;
    if (numItem == 0)
        pTail = pNew;
    numItem++;
}

void Info::showList()
{
    pCurr = pHead;
    while (pCurr != pTail->link)
    {
        cout << setw(5) << setfill('0') << pCurr->code;
        cout << "\t" << pCurr->type << "\t" << pCurr->name << endl;
        pCurr = pCurr->link;
    }
}

void Info::saveList()
{
    ofstream write("stock.txt");
    pCurr = pHead;
    for (int i = 0; i < numItem; i++)
    {
        write << setw(5) << setfill('0') << pCurr->code;
        write << "\t" << pCurr->type << "\t" << pCurr->name << endl;
        pCurr = pCurr->link;
    }
    write.close();
}