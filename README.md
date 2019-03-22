# Lua/400

Port of Lua for the IBM i platform in the ILE subsystem.

![ILE Lua screenshot](https://raw.githubusercontent.com/friedkiwi/lua400/master/img/ile_lua.png)


## Installation

No binary releases are available yet, see *Compilation* below.

## Compilation

1. Upload the source tree to your IBM i machine using e.g. SFTP
2. Edit the Makefile to contain the path for the source
3. Issue `make library` to create the LUA library to store the objects and *PGM
4. Issue `make` to build LUA/LUA
5. ???
6. PROFIT!


## `midrange` namespace

This version of Lua includes a `midrange` namespace with OS/400 specific functionality. 

This is a work-in-progress to allow easier interaction with ILE and IBM i

## Sample code

TODO: write sample code and document how to use it.
