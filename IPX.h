#pragma once

// The four-byte network number and six-byte node (MAC) address that together
// identify a machine on an IPX network. Westwood declared these as raw array
// typedefs; they are wrapped in structs here so they can be used as members
// without decaying to pointers.
struct NetNumType
{
	unsigned char Value[4];
};
static_assert(sizeof(NetNumType) == 4);

struct NetNodeType
{
	unsigned char Value[6];
};
static_assert(sizeof(NetNodeType) == 6);

class IPXAddressClass
{
public:
	unsigned char NetworkNumber[4];
	unsigned char NodeAddress[6];
	// YR carries UDP/IP endpoints in this struct as well as real IPX
	// addresses, so the trailing two bytes are only meaningful in IP mode.
	unsigned char field_A[2];
};
static_assert(sizeof(IPXAddressClass) == 12);
