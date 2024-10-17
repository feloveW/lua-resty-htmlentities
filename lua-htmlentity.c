#define LUA_LIB
#include <lauxlib.h>
#include <lualib.h>
#include <string.h>
#include <stdlib.h>
#include "entities.c"

static int ldecode(lua_State* L)
{
	size_t sz = 0;
	const char* src = luaL_checklstring(L, 1, &sz);
	if (sz<=0)
		luaL_error(L,"input cannot empty");
	char* dest = (char*)malloc(sz+1);
	memset(dest,0,sz+1);
	entities_decode_html(dest,src,sz);
	dest[sz+1]='\0';
	int len=strlen(dest);
	lua_pushlstring(L,dest,len);
	free(dest);
	return 1;
}

LUAMOD_API int
luaopen_htmlentity(lua_State* L)
{
	struct luaL_Reg lib[] = {
		{"decode", ldecode},
		{NULL, NULL} };
	luaL_newlib(L, lib);
	return 1;
}