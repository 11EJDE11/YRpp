#pragma once

#include <AbstractClass.h>
#include <EventClass.h>

class TechnoClass;

class PlanningBranchClass
{
public:
	EventClass Packet;
	int MemberCount;
	int MemberIndex;
};
static_assert(sizeof(PlanningBranchClass) == 0x78);

class PlanningMemberClass
{
public:
	TechnoClass* Owner;
	EventClass* Packet;
	int field_8;
	char field_C;
};
static_assert(sizeof(PlanningMemberClass) == 0x10);

class PlanningNodeClass
{
public:
	DEFINE_REFERENCE(DynamicVectorClass<PlanningNodeClass*>, Unknown1, 0xAC4B30u)
	DEFINE_REFERENCE(DynamicVectorClass<PlanningNodeClass*>, Unknown2, 0xAC4C18u)
	DEFINE_REFERENCE(DynamicVectorClass<PlanningNodeClass*>, Unknown3, 0xAC4C98u)

	DEFINE_REFERENCE(bool, PlanningModeActive, 0xAC4CF4u)

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DynamicVectorClass<PlanningMemberClass*> PlanningMembers;
	int field_18;
	bool field_1C;
	DynamicVectorClass<PlanningBranchClass*> PlanningBranches;
	EventClass Packet;
	int field_A8;
	int field_AC;
	int BranchNumber;
	int field_B4;
};
static_assert(sizeof(PlanningNodeClass) == 0xB8);

class PlanningTokenClass
{
public:
	DEFINE_REFERENCE(DynamicVectorClass<PlanningTokenClass*>, Array, 0xAC4C78u)

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	TechnoClass* OwnerUnit;
	DynamicVectorClass<PlanningNodeClass*> PlanningNodes;
	bool field_1C;
	EventClass CurrentEvent;

	int field_8C;
	int ClosedLoopNodeCount;
	int StepsToClosedLoop;
	bool field_98;
	bool field_99;
};
static_assert(sizeof(PlanningTokenClass) == 0x9C);
