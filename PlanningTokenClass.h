#pragma once

#include <AbstractClass.h>
#include <ASMMacros.h>
#include <EventClass.h>

class TechnoClass;

class PlanningBranchClass
{
public:
	EventClass Packet;
	PROTECTED_PROPERTY(BYTE, align_6F);
	int MemberCount;
	int MemberIndex;
};
static_assert(sizeof(PlanningBranchClass) == 0x78);
static_assert(offsetof(PlanningBranchClass, MemberCount) == 0x70);

class PlanningMemberClass
{
public:
	TechnoClass* Owner;
	EventClass* Packet;
	int field_8;
	char field_C;
	PROTECTED_PROPERTY(BYTE, align_D[3]);
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
	//===== Functions ===========================================================
	//===========================================================================

	// Runs the game's constructor over already-allocated storage.
	static PlanningNodeClass* Construct(void* pMemory, int field18)
	{
		return reinterpret_cast<PlanningNodeClass* (__thiscall*)(void*, int)>(0x633CC0u)(pMemory, field18);
	}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DynamicVectorClass<PlanningMemberClass*> PlanningMembers;
	int field_18;
	bool field_1C;
	PROTECTED_PROPERTY(BYTE, align_1D[3]);
	DynamicVectorClass<PlanningBranchClass*> PlanningBranches;
	EventClass Packet;
	PROTECTED_PROPERTY(BYTE, align_A7);
	int field_A8;
	int field_AC;
	int BranchNumber;
	int field_B4;
};
static_assert(sizeof(PlanningNodeClass) == 0xB8);
static_assert(offsetof(PlanningNodeClass, Packet) == 0x38);
static_assert(offsetof(PlanningNodeClass, field_A8) == 0xA8);

class PlanningTokenClass
{
public:
	DEFINE_REFERENCE(DynamicVectorClass<PlanningTokenClass*>, Array, 0xAC4C78u)

	// Planning packets queued up for execution, drained by the event handler.
	DEFINE_REFERENCE(DynamicVectorClass<EventClass*>, PendingEvents, 0xAC4B48u)

	// Units that currently own a planned route.
	DEFINE_REFERENCE(DynamicVectorClass<TechnoClass*>, ActiveRouteOwners, 0xAC4C40u)

	// Route count per HouseClass::ID, indices >= 24 are ignored by the game.
	DEFINE_ARRAY_REFERENCE(int, [24], HouseRouteCounts, 0xAC4B84u)

	//===========================================================================
	//===== Functions ===========================================================
	//===========================================================================

	// PlanningManager::End - deletes every token, clears the route bookkeeping
	// and leaves planning mode.
	static void ClearAll()
		{ JMP_STD(0x6370B0u); }

	// Runs the game's constructor over already-allocated storage.
	static PlanningTokenClass* Construct(void* pMemory, TechnoClass* pOwnerUnit)
	{
		return reinterpret_cast<PlanningTokenClass* (__thiscall*)(void*, TechnoClass*)>(0x635F20u)(pMemory, pOwnerUnit);
	}

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
static_assert(offsetof(PlanningTokenClass, CurrentEvent) == 0x1D);
static_assert(offsetof(PlanningTokenClass, field_8C) == 0x8C);
