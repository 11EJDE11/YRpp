#pragma once

#include <YRPP.h>

struct TheirSync
{
	DEFINE_ARRAY_REFERENCE(TheirSync, [8], Array, 0xAFA358)

	int frame;
	int __send;
	int __recv;
	int timing_C;
	int __router_resp;
	int timing_14;
};
static_assert(sizeof(TheirSync) == 0x18);
