#pragma once

#include <YRPP.h>

class ConnManClassVtbl;
class CommBufferClass;
class GlobalHeaderType;
class CommHeaderType;

class ConnectionClass
{
public:
	ConnManClassVtbl* vtable;
	CommBufferClass* Queue;
	int __resends;
	int __numlost;
	int __percentlost;
	int __missedoverall;
	int __missedmagic;
	DWORD MaxPacketLen;
	GlobalHeaderType* PacketBuf;
	WORD MagicNum;
	DWORD RetryDelta;
	DWORD MaxRetries;
	DWORD Timeout;
	int NumRecNoAck;
	int NumRecAck;
	int NumSendNoAck;
	int NumSendAck;
	int LastSeqID;
	int LastReadID;
};
static_assert(sizeof(ConnectionClass) == 0x4C);

class SendQueueType
{
public:
	int Flags;
	int FirstTime;
	int LastTime;
	int SendCount;
	int BufLen;
	CommHeaderType* Buffer;
	int ExtraLen;
	int ExtraBuffer;
	__int16 owntalk_20;
};
static_assert(sizeof(SendQueueType) == 0x24);
