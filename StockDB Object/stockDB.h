#ifndef STOCKDB_H
#define STOCKDB_H
#include <iostream>
#include <string>
#include "stock.h"
#define stockNode stockNodeIsA

using namespace std;

class stockDB
{
public:
	stockDB();
    bool load(string);
    void print();
    void print_rev();
    bool save(string="");
    void insert_front(stockNode *);
    void insert_inorder(stockNode *);
    void insert_inorder2pt(stockNode *);

private:
    stockNode * head;
    stockNode * tail;
    int		length;
    string	dbFileName;
};

#endif
