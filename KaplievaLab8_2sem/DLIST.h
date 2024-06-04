#pragma once
#include "DNODE.h"


struct DLIST
{
private:
	ptrDNODE head, tail;
	//size_t size;
public:
	DLIST() { head = nullptr, tail = nullptr; }
	//DLIST(std::ifstream& file);
	//DLIST(std::ifstream& file1);
	void first_node(TInfo elem);
	bool empty();
	void create_by_order(std::ifstream& file, std::function<bool(int, int)> compare);
	void insert(ptrDNODE& ptr, TInfo elem);
	void insert_after(ptrDNODE ptr, TInfo elem);
	void insert_before(ptrDNODE ptr, TInfo elem);
	void remove_after(const ptrDNODE& ptr);
	void remove_before(const ptrDNODE& ptr);
	void remove(ptrDNODE& ptr);
	void print();
	~DLIST();
	ptrDNODE get_head();
	ptrDNODE get_tail();
	TInfo get_elem(const ptrDNODE ptr);
	//void sort(ptrDNODE begin, ptrDNODE right, std::function<bool(TInfo, TInfo)> compare);

};
