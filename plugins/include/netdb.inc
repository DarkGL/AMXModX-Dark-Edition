/* NetDB  module functions for AMX Mod X
   by ahtoh, Apr 05 2007
   (C)Copyrighted under the GNU General Public License, Version 2
 */

#if defined _netdb_included
  #endinput
#endif
#define _netdb_included

#if AMXX_VERSION_NUM >= 175
 #pragma reqlib netdb
 #if !defined AMXMODX_NOAUTOLOAD
  #pragma loadlib netdb
 #endif
#else
 #pragma library netdb
#endif

#define NI_MAXHOST  1025
#define NI_MAXSERV    32

//IP address can contain ports, the ports will be stripped out

// netdb_gethostbyaddr - Get the Internet host name corresponding to a given IP address
native netdb_gethostbyaddr(const ip[], host[], len);

// netdb_gethostbyname - Get the IP address corresponding to a given Internet host name
native netdb_gethostbyname(const host[], ip[], len);

// thr_gethostbyaddr - Get the Internet host name corresponding to a given IP address
//public handler(threadId)
native thr_gethostbyaddr(const handler[], const ip[], host[], len, threadId=0);
