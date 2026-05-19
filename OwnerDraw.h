#pragma once

// Westwood owner draw and dialog hell

#include <Helpers/CompileTime.h>

#include <Dictionary.h>
#include <Unsorted.h>

enum class WWControlType : int
{
	Button = 0,
	Edit = 1,
	Static = 2,
	ComboBox = 3,
	ListBox = 4,
	Unknown5 = 5,
	Progress = 6,
	TrackBar = 7,
	ScrollBar = 8,
	Hotkey = 9,
	SysTab = 10,
	ColorTextInput = 11
};

struct WWControlData
{
	char data[0x200];
};
static_assert(sizeof(WWControlData) == 0x200, "WWControlData size mismatch");

enum WWControlMessage
{
	WW_RECALCLAYOUT = 0x497,
	WW_SETTEXTCOLOR = 0x498,
	WW_SETIMAGE = 0x49C,
	WW_SETHASIMAGE = 0x49D,
	WW_SETGDIPROPS = 0x49E,
	WW_GETGDIPROPS = 0x49F,
	WW_GETHWND = 0x4A0,
	WW_BRINGTOTOP = 0x4A9,
	WW_SETACTIVEIMAGE = 0x4AA,
	WW_SETFILLCOLOR = 0x4B1,
	WW_SETTEXTW = 0x4B2,
	WW_GETTEXTW = 0x4B3,
	WW_SETTEXTA = 0x4B4,
	WW_GETTEXTA = 0x4B5,
	WW_SETHASTEXT = 0x4CE,
	WW_SETUNKNOWNPROP30 = 0x4D1,
	WW_RESETANIMTIMER = 0x4D3,
	WW_SETUNKNOWNPROP50 = 0x4EB,
	WW_STATIC_STOPANIM = 0x4D4,
	WW_STATIC_SETANIMFRAME = 0x4D5,
	WW_STATIC_GETANIMFRAME = 0x4D6,
	WW_STATIC_SETANIMFRAMENOTIFYHWND = 0x4D7,
	WW_STATIC_SETCURRENTMOVIEBYINDEX = 0x4DF,
	WW_STATIC_PAUSEMOVIE = 0x4E0,
	WW_STATIC_CONTINUEMOVIE = 0x4E1,
	WW_STATIC_DETACHMOVIE = 0x4E2,
	WW_STATIC_SETLOOPMOVIE = 0x4E3,
	WW_STATIC_SETCURRENTMOVIEBYNAME = 0x4E4,
	WW_STATIC_REVEALTEXTS = 0x4EE,
	WW_STATIC_BLITMOVIE = 0x4F0,
};

class OwnerDraw
{
public:
	using HwndProcDict = Dictionary<HWND, WNDPROC>;
	struct MsgInProcessGuard
	{
		HWND Hwnd;
		bool InProcess;
	};
	using MsgInProcessDict = Dictionary<UINT, MsgInProcessGuard>;
	using HwndControlDataDict = Dictionary<HWND, WWControlData>;

	DEFINE_REFERENCE(HwndProcDict, DialogProcs, 0xAC1B48); // Windows control's default window procedures 
	DEFINE_REFERENCE(HwndProcDict, SubclassProcs, 0xAC18C0); // Custom subclass procedures for owner-draw controls, 
	DEFINE_REFERENCE(MsgInProcessDict, MessageProcessedGuard, 0xAC18C0); // generic OwnerDraw::WindowProc preventing a message being processed multiple times
	DEFINE_REFERENCE(HwndControlDataDict, ControlData, 0xAC1B00); // Control data

	// WWControlType::Button
	DEFINE_REFERENCE(WNDPROC, CheckBoxButtonHandler, 0x6163A0);
	DEFINE_REFERENCE(WNDPROC, GroupBoxButtonHandler, 0x61E700);
	DEFINE_REFERENCE(WNDPROC, AutoRadioButtonHandler, 0x616980);
	DEFINE_REFERENCE(WNDPROC, OwnerDrawButtonHandler, 0x612B70);
	// WWControlType::Edit
	DEFINE_REFERENCE(WNDPROC, EditHandler, 0x614190);
	DEFINE_REFERENCE(WNDPROC, NewEditHandler, 0x614B30);
	// WWControlType::Static
	DEFINE_REFERENCE(WNDPROC, StaticHandler, 0x6153E0);
	// WWControlType::ComboBox
	DEFINE_REFERENCE(WNDPROC, ComboBoxHandler, 0x617250);
	// WWControlType::ListBox
	DEFINE_REFERENCE(WNDPROC, ListBoxHandler, 0x618D40);
	// WWControlType::Progress
	DEFINE_REFERENCE(WNDPROC, ProgressHandler, 0x61D6D0);
	// WWControlType::TrackBar
	DEFINE_REFERENCE(WNDPROC, TrackBarHandler, 0x61D950);
	// WWControlType::ScrollBar
	DEFINE_REFERENCE(WNDPROC, ScrollBarHandler, 0x61C690);
	// WWControlType::Hotkey
	DEFINE_REFERENCE(WNDPROC, HotkeyHandler, 0x61ECA0);
	// WWControlType::SysTab
	DEFINE_REFERENCE(WNDPROC, SysTabHandler, 0x6137D0);
	// WWControlType::ColorTextInput
	DEFINE_REFERENCE(WNDPROC, ColorTextInputHandler, 0x612A60);

	DEFINE_REFERENCE(WNDPROC, DefaultHandler, 0x610CA0); // Generic handler which call the handles above


};
