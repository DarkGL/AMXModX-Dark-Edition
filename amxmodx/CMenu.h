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

#ifndef MENUS_H
#define MENUS_H

// *****************************************************
// class MenuMngr
// *****************************************************

class MenuMngr
{
	struct MenuIdEle
	{
		String name;
		AMX* amx;
		MenuIdEle* next;
		
		int id;
		static int uniqueid;
		
		MenuIdEle(const char* n, AMX* a, MenuIdEle* m) : name(n), amx(a), next(m)
		{
			id = ++uniqueid;
		}
	} *headid;

public:
		class iterator;
private:

	class MenuCommand 
	{
		friend class iterator;
		friend class MenuMngr;

		CPluginMngr::CPlugin *plugin;
		int menuid;
		int keys;
		int function;
		int is_new_menu;
		
		MenuCommand* next;
		MenuCommand(CPluginMngr::CPlugin *a, int mi, int k, int f, bool new_menu=false);
	public:
		inline int getFunction() { return function; }
		inline CPluginMngr::CPlugin* getPlugin() { return plugin; }
		inline bool matchCommand(int m, int k)
		{
			return ((m == menuid) && (keys & k));
		}
	} *headcmd;
	
public:
	MenuMngr() : m_watch_iter(end())
		{ headid = NULL; headcmd = NULL; }
	~MenuMngr();

	// Interface

	int findMenuId(const char* name, AMX* a = 0);
	int registerMenuId(const char* n, AMX* a);
	void registerMenuCmd(CPluginMngr::CPlugin *a, int mi, int k, int f, bool from_new_menu=false);
	void clear();

	class iterator
	{
		friend class MenuMngr;
		MenuCommand* a;
	public:
		iterator(MenuCommand*aa) : a(aa) {}
		iterator& operator++() { a = a->next; return *this; }
		bool operator==(const iterator& b) const { return a == b.a; }
		bool operator!=(const iterator& b) const { return !operator==(b); }
		operator bool () const { return a ? true : false; }
		MenuCommand& operator*() { return *a; }
	};
	
	inline iterator begin() const { return iterator(headcmd); }
	inline iterator end() const { return iterator(0); }

	MenuMngr::iterator SetWatchIter(MenuMngr::iterator iter);
	inline MenuMngr::iterator GetWatchIter() { return m_watch_iter; }
private:
	MenuMngr::iterator m_watch_iter;
};

extern MenuMngr g_menucmds;

#endif //MENUS_H
