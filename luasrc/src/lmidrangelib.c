static int midrange_printversion (lua_State *L) {
  printf("LUA/400 version %s (based on lua %s)\n", LUA400_VERSION, LUA_RELEASE);
  return 0;
}

static const luaL_Reg midrangelib[] = {
  {"printversion",     midrange_printversion},
  {NULL, NULL}
};

/* }====================================================== */



LUAMOD_API int luaopen_midrange (lua_State *L) {
  luaL_newlib(L, midrangelib);
  return 1;
}
