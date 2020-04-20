#ifndef _status_memory_h
#define _status_memory_h

/**
 * @file	status_memory.h
 * @author	en2
 * @date	20-04-2020
 * @brief	
 * @details	
**/

#include "status.h"

namespace status::memory
{

/* ---------------------------------------------| info |--------------------------------------------- */

class Unaligned_access : public Status
{
public:
    Unaligned_access(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Memory", "Unaligned_access", details, location) {}
    ~Unaligned_access() {}
}; /* Unaligned_access:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Invalid_access : public Status
{
public:
    Invalid_access(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Memory", "Invalid_access", details, location) {}
    ~Invalid_access() {}
}; /* Invalid_access:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Low : public Status
{
public:
    Low(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Memory", "Low", details, location) {}
    ~Low() {}
}; /* Low:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Not_enought : public Status
{
public:
    Not_enought(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Memory", "Not_enought", details, location) {}
    ~Not_enought() {}
}; /* Not_enought:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Leak : public Status
{
public:
    Leak(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Memory", "Leak", details, location) {}
    ~Leak() {}
}; /* Leak:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Corruption : public Status
{
public:
    Corruption(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Memory", "Corruption", details, location) {}
    ~Corruption() {}
}; /* Corruption:  */

/* ---------------------------------------------| info |--------------------------------------------- */

class Overflow : public Status
{
public:
    Overflow(const char * details = nullptr, const Location & location = Location::current()) 
    : Status("Memory", "Overflow", details, location) {}
    ~Overflow() {}
}; /* Overflow:  */

}; /* namespace: status::memory */

#endif /* define: status_memory_h */