#include "header.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Linked::Linked(){
    numItem = 0;
    pHead = NULL;
    pTail = NULL;
}

Linked::~Linked(){}

bool Linked::checkFile(){
    ifstream inFile1("stockAtt.txt");
    ifstream inFile2("stockName.txt");
    if (inFile1 && inFile2)
        return true;
    else
        return false;
}

void Linked::getInput(int code){        //obsolete
    //addNode(code);
}

void Linked::addNode(int code, int quantity, string type, string name){
    Node *pNew = new Node;
    pNew->code = code;
    pNew->type = type;
    pNew->name = name;
    pNew->quantity = quantity;
    pNew->link = NULL;
    if (pHead == NULL){
        pHead = pNew;
        pTail = pNew;
    }
    else{
        pTail->link = pNew;
        pTail = pNew;
    }
    
    numItem++;
}

int Linked::numEle(){
    return numItem;
}

void Linked::show(){
    Node *pCurr = new Node;
    pCurr = pHead;
    //for (int i = 0; i < numItem; i++){      //numItem iterator method
    while(pCurr != NULL){                   //end of list check method
        cout << setw(5) << setfill('0') << pCurr->code << "\t";        //edit as required
        cout << pCurr->type << "\t" << pCurr->quantity << "\t" << pCurr->name << endl;
        pCurr = pCurr->link;
    }
}

void Linked::save(){
    ofstream outFile1("stockAtt.txt", ios::out | ios::app);
    ofstream outFile2("stockName.txt", ios::out | ios::app);
    Node *pCurr = new Node;
    pCurr = pHead;

    while (pCurr != NULL){
        static int l = 0;
        if (l != 0){
            outFile1 << endl;
            outFile2 << endl;
        }
        outFile1 << pCurr->code << "\t" << pCurr->type << "\t" << pCurr->quantity;
        outFile2 << pCurr->name;
        pCurr = pCurr->link;
        l++;
    }

    outFile1.close();
    outFile2.close();
}

bool Linked::search(int code){
    Node *pCurr = new Node;
    pCurr = pHead;
    ofstream oF("sold.txt", ios::out | ios::app);

    while (pCurr != NULL){
        if (pCurr->code == code){
            oF << pCurr->code << "\t";
            return true;
        }
        else{
            pCurr = pCurr->link;
        }
    }
    oF.close();
    return false;
}

void Linked::updateQuant(int code, int quantity){
    Node *pCurr = new Node;
    pCurr = pHead;
    while (pCurr != NULL){
        if (pCurr->code == code){
            pCurr->quantity = pCurr->quantity - quantity;
            break;
        }
        else
            pCurr = pCurr->link;
    }
}

bool Linked::addQuant(int code, int quantity){
    Node *pCurr = new Node;
    pCurr = pHead;
    while (pCurr != NULL){
        if (pCurr->code == code){
            pCurr->quantity = pCurr->quantity + quantity;
            return true;
        }
        else{
            pCurr = pCurr->link;
        }
    }
    return false;
}