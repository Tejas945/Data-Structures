#include <fstream>
#include <iostream>
#include <string>
#include "stockDB.h"

using namespace std;

stockDB::stockDB() {
	head = tail = NULL;
	length = 0;
}

bool stockDB::load(string fn)
{
	ifstream	fin;
	fin.open(fn.c_str());
	if (fin.fail()) return(false);
	while(!fin.eof()){
		stockNode *sp = new stockNode();
		fin >> *sp;
//		insert_front(sp);
//		insert_inorder(sp);
		insert_inorder2pt(sp);

	}
	fin.close();
	return(true);
}

void stockDB::print()
{
	cout << "== print DB\n";
	stockNode *p = head;
	while (p != NULL) {
		cout << *p;
		p = p->next;
	}
}

void stockDB::print_rev()
{
	cout << "== print_rev\n";
	stockNode *p = tail;
	while (p != NULL) {
		cout << *p;
		p = p->prev;
	}
}

bool stockDB::save(string fn)
{
	if (fn.empty()) fn=dbFileName;
	ofstream	fout(fn.c_str());
	if (fout.fail()) return(false);
	stockNode *p = head;
	while (p != NULL) {
		fout << *p;
		p = p->next;
	}
	fout.close();
	return(true);
}

void stockDB::insert_front(stockNode *p)	// insert front
{
	if (length == 0) {
		p->prev = p->next = NULL;
		head = tail = p;
		length++;
		return;
	}
	p->next = head;
	p->prev = NULL;
	p->next->prev = p;
	head = p;
	length++;
}

void stockDB::insert_inorder(stockNode *p)
{
	if (length == 0) {
		p->prev = p->next = NULL;
		head = tail = p;
		length++;
		return;
	}
	// find a larger node and insert before it
	stockNode * temp = head;
	while (temp != NULL) {
		if (*temp < *p)		temp = temp->next;
		else {
			// insert before temp
			p->next = temp;  //fwd link
			if (head==temp) head = p;  else temp->prev->next = p; // first node case
			p->prev = temp->prev; temp->prev = p;  //bkwd link
			length++;
			return;
		}
	}
	// nobody is larger, insert at end
	p->next = NULL; 	p->prev = tail;
	tail->next = p; tail = p;	length++;
}

void stockDB::insert_inorder2pt(stockNode *p)
{
	if (length == 0) {
		p->prev = p->next = NULL;
		head = tail = p;
		length++;
		return;
	}
	// find a larger node and insert before it
	stockNode *current=head, *behind=NULL;
	while (current != NULL) {
		if (*current < *p)	{
			behind = current;  current = current->next;
		}
		else {
			// insert before current
			p->next = current;  //fwd link
			if (behind==NULL) head = p;  else behind->next = p; // first node case
			p->prev = current->prev; current->prev = p;  //bkwd link
			length++;
			return;
		}
	}
	// nobody is larger, insert at end
	p->next = NULL; 	p->prev = tail;
	tail->next = p; tail = p;	length++;
}

void stockDBtest(){
	stockDB	port1;
	port1.load("frankDB.txt");
	port1.print();
	port1.save("test.txt");
	port1.print_rev();
}

