
#ifndef lua400_h
#define lua400_h

#define LUA_MIDRANGELIBNAME "midrange"
LUAMOD_API int luaopen_midrange (lua_State *L);
#define LUA_RECORDLIBNAME "record"
LUAMOD_API int luaopen_record (lua_State *L);

#endif
