/*
 * VARCem	Virtual ARchaeological Computer EMulator.
 *		An emulator of (mostly) x86-based PC systems and devices,
 *		using the ISA,EISA,VLB,MCA  and PCI system buses, roughly
 *		spanning the era between 1981 and 1995.
 *
 *		This file is part of the VARCem Project.
 *
 *		Platform support defintions for Win32.
 *
 * Version:	@(#)win.h	1.0.10	2018/05/03
 *
 * Authors:	Fred N. van Kempen, <decwiz@yahoo.com>
 *		Miran Grca, <mgrca8@gmail.com>
 *		Sarah Walker, <tommowalker@tommowalker.co.uk>
 *
 *		Copyright 2017,2018 Fred N. van Kempen.
 *		Copyright 2016-2018 Miran Grca.
 *		Copyright 2008-2018 Sarah Walker.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free  Software  Foundation; either  version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is  distributed in the hope that it will be useful, but
 * WITHOUT   ANY  WARRANTY;  without  even   the  implied  warranty  of
 * MERCHANTABILITY  or FITNESS  FOR A PARTICULAR  PURPOSE. See  the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the:
 *
 *   Free Software Foundation, Inc.
 *   59 Temple Place - Suite 330
 *   Boston, MA 02111-1307
 *   USA.
 */
#ifndef PLAT_WIN_H
# define PLAT_WIN_H


#ifdef __cplusplus
extern "C" {
#endif

#include "resource.h"		/* local resources */
#include "../ui/ui_resource.h"	/* common resources */


/* Class names and such. */
#define MUTEX_NAME		L"VARCem.BlitMutex"
#define CLASS_NAME		L"VARCem.MainWindow"
#define FS_CLASS_NAME		L"VARCem.FullScreen"
#define MENU_NAME		L"MainMenu"
#define SB_MENU_NAME		L"StatusBarMenu"
#define ACCEL_NAME		L"MainAccel"

/* Application-specific window messages. */
#define WM_PAUSE		WM_USER
#define WM_LEAVEFULLSCREEN	WM_USER+1
#define WM_RESETD3D		WM_USER+2
#define WM_SAVESETTINGS		WM_USER+3
#define WM_SHOWSETTINGS		WM_USER+4


/* Status bar definitions. */
#define SB_HEIGHT		16		/* for 16x16 icons */
#define SB_PADDING		1		/* 1px of padding */


extern HINSTANCE	hInstance;
extern HICON		hIcon[512];
extern HWND		hwndMain,
			hwndRender;

extern LCID		lang_id;

extern int		status_is_open;

extern DWORD		filterindex;


/* Internal platform support functions. */
#ifdef USE_CRASHDUMP
extern void	InitCrashDump(void);
#endif
extern HICON	LoadIconEx(PCTSTR name);
extern void	keyboard_getkeymap(void);
extern void	keyboard_handle(LPARAM lParam, int infocus);
extern void     win_mouse_init(void);
extern void     win_mouse_close(void);

/* Internal dialog functions. */
extern void	dialog_center(HWND hdlg);
extern int	dlg_file_ex(HWND hwnd, const wchar_t *filt,
			    const wchar_t *ifn, wchar_t *fn, int save);
#ifdef EMU_DEVICE_H
extern uint8_t	dlg_devconf(HWND hwnd, device_t *device);
#endif
extern uint8_t	dlg_jsconf(HWND hwnd, int joy_nr, int type);

/* Platform support functions. */
extern void	plat_set_language(int id);
extern int	get_vidpause(void);
extern int	fdd_type_icon(int type);

/* Emulator start/stop support functions. */
extern void	plat_start(void);
extern void	plat_stop(void);

/* Platform UI support functions. */
extern int	ui_init(int nCmdShow);
extern void	ui_menu_update(void);
extern void	ui_show_cursor(int);

#ifdef __cplusplus
}
#endif


#endif	/*PLAT_WIN_H*/
