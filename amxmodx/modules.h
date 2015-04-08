/* AMX Mod X
*
* by the AMX Mod X Development Team
*  originally developed by OLO
*
*
*  This program is free software; you can redistribute it and/or modify it
*  under the terms of the GNU General Public License as published by the
*  Free Software Foundation; either version 2 of the License, or (at
*  your option) any later version.
*
*  This program is distributed in the hope that it will be useful, but
*  WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
*  General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software Foundation,
*  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
*  In addition, as a special exception, the author gives permission to
*  link the code of this program with the Half-Life Game Engine ("HL
*  Engine") and Modified Game Libraries ("MODs") developed by Valve,
*  L.L.C ("Valve"). You must obey the GNU General Public License in all
*  respects for all of the code used other than the HL Engine and MODs
*  from Valve. If you modify this file, you may extend this exception
*  to your version of the file, but you are not obligated to do so. If
*  you do not wish to do so, delete this exception statement from your
*  version.
*/

#ifndef __MODULES_H__
#define __MODULES_H__

#include "amx.h"

#undef DLLEXPORT
#if defined(_WIN32)
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __attribute__((visibility("default")))
	#define WINAPI
#endif

#undef C_DLLEXPORT
#define C_DLLEXPORT extern "C" DLLEXPORT

#define RELOAD_MODULE 0
#define STATIC_MODULE 1

typedef enum
{
	Player_Name,		//String
	Player_Ip,			//String
	Player_Team,		//String
	Player_Ingame,		//bool
	Player_Authorized,	//bool
	Player_Vgui,		//bool
	Player_Time,		//float
	Player_Playtime,	//float
	Player_MenuExpire,	//float
	Player_Weapons,		//struct{int,int}[32]
	Player_CurrentWeapon,	//int
	Player_TeamID,			//int
	Player_Deaths,			//int
	Player_Aiming,			//int
	Player_Menu,			//int
	Player_Keys,			//int
	Player_Flags,			//int[32]
	Player_Newmenu,			//int
	Player_NewmenuPage,		//int
}  PlayerProp;

int CheckModules(AMX *amx, char error[128]);
bool LoadModule(const char *shortname, PLUG_LOADTIME now, bool simplify=true, bool noFileBail=false);
const char *StrCaseStr(const char *as, const char *bs);

class Debugger;
Debugger *DisableDebugHandler(AMX *amx);
void EnableDebugHandler(AMX *amx, Debugger *pd);

bool DirExists(const char *dir);
const char* GetFileName(AMX *amx);

inline cell FloatToCell(float input)
{
	REAL output = input;
	return *(cell *)&output;
}

#endif // __MODULES_H__
