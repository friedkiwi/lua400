#!/bin/bash

cat luasrc/src/{luaconf.h,lua.h,llimits.h,lzio.h,lopcodes.h,lobject.h,lparser.h,ltm.h,ldo.h,lstate.h,lua400.h,lapi.h,lauxlib.h,lcode.h,lctype.h,ldebug.h,lfunc.h,lgc.h,llex.h,lmem.h,lprefix.h,lstring.h,ltable.h,lualib.h,lundump.h,lvm.h} > processed/lua_header.h
cat luasrc/src/*.c > processed/lua_source.c

cat processed/lua_header.h processed/lua_source.c | awk '!/include\ "/' > processed/ilelua.c

#cat $LUA_SRC | awk '!/include\ "/'  > ../../processed/lua_preproc.c


