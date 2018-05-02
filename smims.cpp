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
    string yada;
    int c = 0;
    ifstream inFile("stock.txt");
    while(getline(inFile, yada))
    {
        //cout << "reading\n";
        //getline(inFile, yada);
        c++;
        //cout << c << " items\n";
    }
    inFile.close();
    numItem = c;
    cout << numItem << " items in read\n";
    pHead = NULL;
    pTail = NULL;
    pCurr = NULL;
}

Info::~Info() {}

void Info::readExisting()
{
    int code;
    string type, name;
    ifstream inFile("stock.txt");
    for (int i = 0; i < numItem; i++)
    {
        //Node *pNew = new Node;
        //if (i != 0)
        //{    
            inFile >> code >> type;
            getline(inFile, name);
            //name.substr(1).append(name.substr(0, 1));
            name = name.substr(1, name.size() -1);
            //pNew->link = pHead;
            //pHead = pNew;
            getEntry(code, type, name);
            //cout << "Added\n";
        //}
        //else
        //{
        //    pHead = pNew;
        //    pTail = pNew;
        //}
    }
    inFile.close();
}

void Info::addEntry()
{
    char dummy[4];
    string t, n;
    bool yeah;
    srand(time(NULL));
    //Node *pNew = new Node;
    do{    
        yeah = true;
        cout << "Please enter the category of the item (TOY, GRO, CLO, TLT, STA, MIS): ";
        cin >> dummy;
        for (int u = 0; u < 4; u++)
            dummy[u] = toupper(dummy[u]);
        t = string(dummy);
        if (t == "TOY" || t == "GRO" || t == "CLO" || t == "TLT" || t == "STA" || t == "MIS")
        {
            yeah = false;
            //pNew->type = t;
        }
    }while (yeah);
    //pNew->code = rand()%10000;
    cout << "Please enter the name of the product: ";
    cin.ignore();
    getline(cin, n);
    int code = rand()%10000;
    getEntry(code, t, n);
    /*pNew->link = pHead;
    pHead = pNew;
    if (numItem == 0)
        pTail = pNew;*/
    numItem++;
}

void Info::getEntry(int code, string type, string name)
{
    Node *pNew = new Node;
    pNew->code = code;
    pNew->type = type;
    pNew->name = name;
    pNew->link = pHead;
    pHead = pNew;
    if (numItem == 0)
        pTail = pNew;
    //numItem++;
}

void Info::showList()
{
    int code;
    string type, name;
    /*pCurr = pHead;
    while (pCurr != pTail)
    {
        cout << setw(5) << setfill('0') << pCurr->code;
        cout << "\t" << pCurr->type << "\t" << pCurr->name << endl;
        pCurr = pCurr->link;
    }*/
    ifstream inFile("stock.txt");
    for (int i = 0; i < numItem; i++)
    {
        inFile >> code >> type;
        getline(inFile, name);
        cout << setw(5) << setfill('0') << code; 
        cout << " " << type << " " << name << endl;
    }
}

void Info::saveList()
{
    ofstream write("stock.txt");
    pCurr = pHead;
    for (int i = 0; i < numItem; i++)
    {
        write << setw(5) << setfill('0') << pCurr->code;
        write << " " << pCurr->type << " " << pCurr->name << endl;
        pCurr = pCurr->link;
    }
    write.close();
}