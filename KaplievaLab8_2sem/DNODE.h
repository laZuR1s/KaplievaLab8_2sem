#pragma once
#include "STRUCT.h"
#include <Windows.h>
#include <functional>
#include <string>

using TInfo = BUS*;
struct DNODE
{
	TInfo info;
	DNODE* next, * prev;

	DNODE(TInfo info, DNODE* ptr = nullptr, DNODE* prev = nullptr) :
		info(info), next(ptr), prev(prev) {};
	~DNODE() { next = nullptr; prev = nullptr; }

};
using ptrDNODE = DNODE*;