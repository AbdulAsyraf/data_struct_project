#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

//TOY GRO CLO TLT STA MIS

Linked a, b, c, d, e, f;        //global object declaration

string getName(){
    string name;
    cin.ignore();
    cout << "Please enter the name of the product: ";
    getline(cin, name);
    return name;
}

int search(){
    int code;
    cout << "Please enter the item code: ";
    cin >> code;
    return code;
}

int getQuant(){
    int quantity;
    cout << "Please enter the quantity: ";
    cin >> quantity;
    return quantity;
}

void read(){
    int code, quantity;
    string type, name;

    if (a.checkFile()){         //all objects uses same file so only one check is needed
        ifstream inFile1("stockAtt.txt");
        ifstream inFile2("stockName.txt");
        while (!inFile1.eof() && !inFile2.eof()){
            inFile1 >> code >> type >> quantity;
            getline(inFile2, name);
            if (type == "TOY")
                a.addNode(code, quantity, type, name);
            else if (type == "GRO")
                b.addNode(code, quantity, type, name);
            else if (type == "CLO")
                c.addNode(code, quantity, type, name);
            else if (type == "TLT")
                d.addNode(code, quantity, type, name);
            else if (type == "STA")
                e.addNode(code, quantity, type, name);
            else if (type == "MIS")
                f.addNode(code, quantity, type, name);
    }
    inFile1.close();
    inFile2.close();
    }
}

void manager(){
    int code, quantity;
    bool finish = false;
    string type, name, userIn;
    char userChar[4];

    srand(time(NULL));

    while(!finish){
        finish = false;
        cout << "Please enter the category (TOY GRO CLO TLT STA MIS) or q if done: ";
        cin >> userChar;
        for (int i = 0; i < 4; i++)
            userChar[i] = toupper(userChar[i]);
        userIn = string(userChar);
        code = rand() % 100000;
        if (userIn == "TOY"){
            name = getName();
            quantity = getQuant();
            a.addNode(code, quantity, userIn, name);
        }
        else if (userIn == "GRO"){
            name = getName();
            quantity = getQuant();
            b.addNode(code, quantity, userIn, name);
        }
        else if (userIn == "CLO"){
            name = getName();
            quantity = getQuant();
            c.addNode(code, quantity, userIn, name);
        }
        else if (userIn == "TLT"){
            name = getName();
            quantity = getQuant();
            d.addNode(code, quantity, userIn, name);
        }
        else if (userIn == "STA"){
            name = getName();
            quantity = getQuant();
            e.addNode(code, quantity, userIn, name);
        }
        else if (userIn == "MIS"){
            name = getName();
            quantity = getQuant();
            f.addNode(code, quantity, userIn, name);
        }
        else if (userIn == "Q"){
            finish = true;
        }
    }


    remove("stockAtt.txt");
    remove("stockName.txt");

    cout << "CODE\tTYPE\tQTY\tNAME\n\n";
    if (a.numEle() != 0){
        a.save();
        a.show();
    }
    if (b.numEle() != 0){
        b.save();
        b.show();
    }
    if (c.numEle() != 0){
        c.save();
        c.show();
    }
    if (d.numEle() != 0){
        d.save();
        d.show();
    }
    if (e.numEle() != 0){
        e.save();
        e.show();
    }
    if (f.numEle() != 0){
        f.save();
        f.show();
    }

    //system("pause");
}

void cashier(){
    char in[4];
    string type;
    int code, quantity;
    bool check;
    bool finish = false;
    ofstream sold("sold.txt", ios::out | ios::app);

    cout << "Welcome Sales Manager\n";
    do{
        cout << "Please enter the category (TOY GRO CLO TLT STA MIS) or q when done: ";
        cin >> in;
        for (int i = 0; i < 4; i++)
            in[i] = toupper(in[i]);
        type = string(in);
        if (type == "TOY"){
            code = search();
            check = a.search(code);
            if(check){
                quantity = getQuant();
                sold << quantity << "\t";
            }
            else{
                cout << "Invalid code entered!\n";
            }
        }
        else if (type == "GRO"){
            code = search();
            check = b.search(code);
            if(check){
                quantity = getQuant();
                sold << quantity << "\t";
            }
            else{
                cout << "Invalid code entered!\n";
            }
        }
        else if (type == "CLO"){
            code = search();
            check = c.search(code);
            if(check){
                quantity = getQuant();
                sold << quantity << "\t";
            }
            else{
                cout << "Invalid code entered!\n";
            }
        }
        else if (type == "TLT"){
            code = search();
            check = d.search(code);
            if(check){
                quantity = getQuant();
                sold << quantity << "\t";
            }
            else{
                cout << "Invalid code entered!\n";
            }
        }
        else if (type == "STA"){
            code = search();
            check = e.search(code);
            if(check){
                quantity = getQuant();
                sold << quantity << "\t";
            }
            else{
                cout << "Invalid code entered!\n";
            }
        }
        else if (type == "MIS"){
            code = search();
            check = f.search(code);
            if(check){
                quantity = getQuant();
                sold << quantity << "\t";
            }
            else{
                cout << "Invalid code entered!\n";
            }
        }
        else if (type == "Q"){
            finish = true;
        }
    }while(!finish);

    sold.close();
}

int main(){

    int choice = 0;
    read();
    cout << "Welcome to SuperMarket Inventory Management System\n";
    
    do{
        cout << "Who are you?\nEnter 1 for cashier or 2 for stock keeper: ";
        cin >> choice;
    }while(choice != 1 && choice != 2);
    switch(choice){
        case 1:
            cashier();
            break;
        case 2:
            manager();
            break;
    }
}