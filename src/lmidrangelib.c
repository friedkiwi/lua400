#include "lprefix.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include <xxfdbk.h>
#include <recio.h>


static int midrange_printversion (lua_State *L) {
  printf("LUA/400 version %s (based on lua %s)\n", LUA400_VERSION, LUA_RELEASE);
  return 0;
}

static int record_open(lua_State *L) {
  const char *filename = luaL_checkstring(L, 1);
  const char *mode = luaL_checkstring(L, 2);

  _RFILE * fp;
  
  fp = _Ropen(filename, mode);
  printf("pointer: %x\n", fp);
  lua_pushlightuserdata(L, &fp);
  if (fp == NULL)
  {
    luaL_error(L, "Could not open record file");
    return 0;
  }
  return 1;
}

static int record_acquire(lua_State *L) {
  //if (lua_islightuserdata(L, 1) == 0) {
  //  luaL_error(L, "first parameter must be an opened record");
  //  return 0;
  //}

  _RFILE *fp = lua_touserdata(L, 1);
  const char * device = luaL_checkstring(L, 2);
  printf("pointer: %x\n", fp);
  _Racquire(fp, (char *) device);
  
  return 0;
}

static int record_format(lua_State *L) {
  printf("record format stub\n");
  return 0;
}

static int record_write(lua_State *L) {
  printf("record write stub\n");
  return 0;
}

static int record_read_n(lua_State *L) {
  printf("record read_n stub\n");
  return 0;
}

static int record_close(lua_State *L) {
  printf("record close stub\n");
  return 0;
}


static const luaL_Reg midrangelib[] = {
  {"printversion",     midrange_printversion},
  {NULL, NULL}
};

static const luaL_Reg recordlib[] = {
  {"open",  record_open},
  {"acquire",  record_acquire},
  {"format",  record_format},
  {"write",  record_write},
  {"read_n",  record_read_n},
  {"close",  record_close},
  {NULL, NULL}
};



LUAMOD_API int luaopen_record (lua_State *L) {
  luaL_newlib(L, recordlib);
  return 1;
}

LUAMOD_API int luaopen_midrange (lua_State *L) {
  luaL_newlib(L, midrangelib);
  return 1;
}
