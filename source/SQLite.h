#pragma once
#include <windows.h>
#include <string>
#include <stdexcept>
// Read-only access to SQLite supplied with Windows 10/11.
struct SQLite {
  HMODULE dll; void* db=nullptr; void* stmt=nullptr;
  int (__stdcall *open)(const char*,void**,int,const char*);
  int (__stdcall *close)(void*);
  int (__stdcall *prepare)(void*,const char*,int,void**,const char**);
  int (__stdcall *step)(void*);
  int (__stdcall *finalize)(void*);
  int (__stdcall *columns)(void*);
  const char* (__stdcall *name)(void*,int);
  const unsigned char* (__stdcall *text)(void*,int);
  double (__stdcall *number)(void*,int);
  SQLite(const std::string& path) {
    dll=LoadLibraryW(L"winsqlite3.dll"); if(!dll)throw std::runtime_error("winsqlite3.dll is required");
#define API(field, symbol) field=reinterpret_cast<decltype(field)>(GetProcAddress(dll,symbol));if(!field)throw std::runtime_error(symbol)
    API(open,"sqlite3_open_v2");API(close,"sqlite3_close");API(prepare,"sqlite3_prepare_v2");API(step,"sqlite3_step");
    API(finalize,"sqlite3_finalize");API(columns,"sqlite3_column_count");API(name,"sqlite3_column_name");API(text,"sqlite3_column_text");API(number,"sqlite3_column_double");
#undef API
    if(open(path.c_str(),&db,1,nullptr))throw std::runtime_error("Cannot open SQLite database: "+path);
  }
  void query(const std::string& sql){if(stmt)finalize(stmt);stmt=nullptr;if(prepare(db,sql.c_str(),-1,&stmt,nullptr))throw std::runtime_error("SQL: "+sql);}
  bool next(){int r=step(stmt);if(r!=100&&r!=101)throw std::runtime_error("SQLite step failed");return r==100;}
  std::string value(int i){auto s=text(stmt,i);return s?reinterpret_cast<const char*>(s):"";}
  ~SQLite(){if(stmt)finalize(stmt);if(db)close(db);if(dll)FreeLibrary(dll);}
};

