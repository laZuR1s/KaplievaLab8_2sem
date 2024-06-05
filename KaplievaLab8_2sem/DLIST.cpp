#include "DLIST.h"

//DLIST::DLIST(std::ifstream& file)
//{
//	TInfo bus = new BUS(file);
//	first_node(bus);
//	while (!file.eof())
//	{
//		bus = new BUS(file);
//		insert_after(tail, bus);
//	}
//	file.close();
//}

//DLIST::DLIST(std::ifstream& file)
//{
//	TInfo bus = new BUS(file);
//	first_node(bus);
//	auto find_place = [this](TInfo elem) ->ptrDNODE
//		{
//			ptrDNODE p = head;
//			while (p && strcmp((*(p->info)).get_firm(), (*elem).get_firm())>=0)
//				p = p->next;
//			return p;
//		};
//	ptrDNODE place{};
//	while (!file.eof())
//	{
//		bus = new BUS(file);
//		place = find_place(bus);
//		if (place)
//			insert_before(place, bus);
//		else
//			insert_after(tail, bus);
//	}
//	file.close();
//}

void DLIST::create_by_order(std::ifstream& file, std::function<bool(int, int)> compare)
{
	TInfo bus = new BUS(file);
	first_node(bus);
	auto find_place = [this, compare](TInfo elem) -> ptrDNODE
		{
			ptrDNODE p = head;
			while (p && compare((*(p->info)).get_region(), (*elem).get_region())&& strcmp(p->info->get_firm(), (*elem).get_firm())!=0)
			{
				p = p->next;
			}
			return p;
		};
	ptrDNODE place{};
	while (!file.eof())
	{
		bus = new BUS(file);
		place = find_place(bus);
		if (place)
			insert_before(place, bus);
		else
			insert_after(tail, bus);
		//person->print();
	}
	file.close();
}

void DLIST::first_node(TInfo elem)
{
	head = new DNODE(elem);
	tail = head;
}

bool DLIST::empty()
{
	return head == nullptr;
}

void DLIST::insert_after(ptrDNODE ptr, TInfo elem)
{
	ptrDNODE p = new DNODE(elem, ptr->next, ptr);
	if (ptr == tail)
		tail = p;
	else
		ptr->next->prev = p;
	ptr->next = p;
}


void DLIST::insert_before(ptrDNODE ptr, TInfo elem)
{
	ptrDNODE p = new DNODE(elem, ptr, ptr->prev);
	if (ptr == head)
		head = p;
	else
		ptr->prev->next = p;
	ptr->prev = p;
}

void DLIST::insert(ptrDNODE& ptr, TInfo elem)
{
	if (empty())
	{
		head = new DNODE(elem);
		tail = head;
		/*ptr = head;*/
	}
	else
	{
		if (tail->next == ptr)
		{
			tail->next = new DNODE(elem);
			tail->next->prev = tail;
			tail = tail->next;
		}
		else
		{
			ptrDNODE p = ptr->prev;
			ptr->prev = new DNODE(elem);
			ptr->prev->next = ptr;
			if (ptr == head) head = head->prev;
			else
			{
				p->next = ptr->prev;
				p->next->prev = p;
			}
		}
	}
}
void DLIST::remove_after(const ptrDNODE& ptr)
{
	ptrDNODE p = ptr->next;
	if (p == tail)
		tail = p->prev;
	else
		p->next->prev = p->prev;
	p->prev->next = p->next;
	delete p;
}

void DLIST::remove_before(const ptrDNODE& ptr)
{
	ptrDNODE p = ptr->prev;
	if (p == head)
		head = p->next;
	else
		p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
}

void DLIST::remove(ptrDNODE& ptr)
{
	ptrDNODE p = ptr;
	if (ptr == head)
	{
		head = p->next;
		ptr = head;
		if (p->next)
			p->next->prev = nullptr;
	}
	else
	{
		if (ptr == tail)
		{
			tail = p->prev;
			ptr = tail;
			if (p->prev)
				p->prev->next = nullptr;
		}
		else
		{
			ptr = ptr->next;
			p->next->prev = p->prev;
			p->prev->next = nullptr;
		}
	}
	delete p;
}

void DLIST::print()
{
	ptrDNODE p = head;
	while (p)
	{
		p->info->print();
		p = p->next;

	}
	std::cout << '\n';
}

DLIST::~DLIST()
{
	while (!empty())
		remove(head);
}

ptrDNODE DLIST::get_head()
{
	return head;
}

ptrDNODE DLIST::get_tail()
{
	return tail;
}

TInfo DLIST::get_elem(const ptrDNODE ptr)
{
	return ptr->info;
}
