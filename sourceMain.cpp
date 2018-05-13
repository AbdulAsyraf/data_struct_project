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

void display(){
    if (a.numEle() != 0 || b.numEle() != 0 || c.numEle() != 0 || d.numEle() != 0 || e.numEle() != 0 || f.numEle() != 0){
        cout << "CODE\tTYPE\tQTY\tNAME\n\n";
        if (a.numEle() != 0){
            a.show();
        }
        if (b.numEle() != 0){
            b.show();
        }
        if (c.numEle() != 0){
            c.show();
        }
        if (d.numEle() != 0){
            d.show();
        }
        if (e.numEle() != 0){
            e.show();
        }
        if (f.numEle() != 0){
            f.show();
        }
    }
}

void save(){
    remove("stockAtt.txt");
    remove("stockName.txt");
    if (a.numEle() != 0){
        a.save();
    }
    if (b.numEle() != 0){
        b.save();
    }
    if (c.numEle() != 0){
        c.save();
    }
    if (d.numEle() != 0){
        d.save();
    }
    if (e.numEle() != 0){
        e.save();
    }
    if (f.numEle() != 0){
        f.save();
    }
}

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

void managerAdd(){
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
    
    save();
    display();

    
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
    display();
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
                sold << type << "\t" << quantity << "\t";
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
                sold << type << "\t" << quantity << "\t";
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
                sold << type << "\t" << quantity << "\t";
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
                sold << type << "\t" << quantity << "\t";
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
                sold << type << "\t" << quantity << "\t";
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
                sold << type << "\t" << quantity << "\t";
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

void managerUpd(){
    int code, quantity;
    string type;
    ifstream read("sold.txt", ios::in);
    if (read){
        while (!read.eof()){    
            read >> code >> type >> quantity;
            if (type == "TOY")
                a.updateQuant(code, quantity);
            else if (type == "GRO")
                b.updateQuant(code, quantity);
            else if (type == "CLO")
                c.updateQuant(code, quantity);
            else if (type == "TLT")
                d.updateQuant(code, quantity);
            else if (type == "STA")
                e.updateQuant(code, quantity);
            else if (type == "MIS")
                f.updateQuant(code, quantity);
        }
        read.close();
        remove("sold.txt");
        save();
        display();
        cout << "End of Day update is done!\n";
    }
    else{
        cout << "There are no updates for today\n";
        cout << "No updates are needed\n";
    }
}

void managerRes(){
    int code, quantity;
    string wish;
    bool finish = false;
    
    while(!finish){
        cout << "Please enter the  code of the item to restock\n";
        cin >> code;
        cout << "Please enter the amount to restock\n";
        cin >> quantity;
        if (a.addQuant(code, quantity)){
            cout << "Success\n";
        }
        else if (b.addQuant(code, quantity)){
            cout << "Success\n";
        }
        else if (c.addQuant(code, quantity)){
            cout << "Success\n";
        }
        else if (d.addQuant(code, quantity)){
            cout << "Success\n";
        }
        else if (e.addQuant(code, quantity)){
            cout << "Success\n";
        }
        else if (f.addQuant(code, quantity)){
            cout << "Success\n";
        }
        else{
            cout << "Entry not found\n";
        }
        cout << "Do you wish to restock more?\n";
        cout << "1 - Yes\n";
        cout << "Anything else - No\n";
        cin >> wish;
        if (wish != "1"){
            finish = true;
        }

    }
    save();
    display();
}

void manager(){
    int job = 0;
    cout << "Welcome Stock Keeper\nWhat will you do today?\n";
    cout << "1 - View current inventory\n";
    cout << "2 - Restock the inventory\n";
    cout << "3 - Run End of Day inventory update\n";
    cout << "4 - Add new item\n";
    do{
        cin >> job;
    }while (job != 1 &&
            job != 2 &&
            job != 3 &&
            job != 4);
    
    switch (job){
        case 1:
            display();
            break;
        case 2:
            display();
            managerRes();
            break;
        case 3:;
            managerUpd();
            break;
        case 4:
            display();
            managerAdd();
            break;
    }
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
    cin.ignore();
    getchar();
    return 0;
}