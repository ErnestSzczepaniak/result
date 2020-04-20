#ifndef _status_memory_h
#define _status_memory_h

/**
 * @file	status_memory.h
 * @author	en2
 * @date	19-04-2020
 * @brief	
 * @details	
**/

#include "status.h"

/* ---------------------------------------------| Memory |--------------------------------------------- */

class Memory : public Status
{
    /**
     * @class	Memory
     * @brief	
     * @details	
    **/
public:
    Memory(const char * brief, const char * details, const Location & location) : Status("Memory", brief, details, location) {}
    ~Memory() {}

    class Unaligned_access;
    class Invalid_access;
    class Low;
    class Not_enought;
    class Leak;
    class Corruption;
    class Overflow;

}; /* class: Memory */

/* ---------------------------------------------| Memory::Unaligned access |--------------------------------------------- */

class Memory::Unaligned_access : public Memory
{
    /**
     * @class	Memory::Unaligned_access
     * @brief	
     * @details	
    **/
public:
    Unaligned_access(const char * details = nullptr, const Location & location = Location::current())
        : Memory("Unaligned access", details, location) {}
    ~Unaligned_access() {}
};

/* ---------------------------------------------| Memory::Invalid access |--------------------------------------------- */

class Memory::Invalid_access : public Memory
{
    /**
     * @class	Memory::Invalid_access
     * @brief	
     * @details	
    **/
public:
    Invalid_access(const char * details = nullptr, const Location & location = Location::current())
        : Memory("Invalid access", details, location) {}
    ~Invalid_access() {}
};

/* ---------------------------------------------| Memory::Low |--------------------------------------------- */

class Memory::Low : public Memory
{
    /**
     * @class	Memory::Low
     * @brief	
     * @details	
    **/
public:
    Low(const char * details = nullptr, const Location & location = Location::current())
        : Memory("Low", details, location) {}
    ~Low() {}
};

/* ---------------------------------------------| Memory::Not_enought |--------------------------------------------- */

class Memory::Not_enought : public Memory
{
    /**
     * @class	Memory::Not_enought
     * @brief	
     * @details	
    **/
public:
    Not_enought(const char * details = nullptr, const Location & location = Location::current())
        : Memory("Not enought", details, location) {}
    ~Not_enought() {}
};

/* ---------------------------------------------| Memory::Leak |--------------------------------------------- */

class Memory::Leak : public Memory
{
    /**
     * @class	Memory::Leak
     * @brief	
     * @details	
    **/
public:
    Leak(const char * details = nullptr, const Location & location = Location::current())
        : Memory("Leak", details, location) {}
    ~Leak() {}
};

/* ---------------------------------------------| Memory::Corruption |--------------------------------------------- */

class Memory::Corruption : public Memory
{
    /**
     * @class	Memory::Corruption
     * @brief	
     * @details	
    **/
public:
    Corruption(const char * details = nullptr, const Location & location = Location::current())
        : Memory("Corruption", details, location) {}
    ~Corruption() {}
};

/* ---------------------------------------------| Memory::Overflow |--------------------------------------------- */

class Memory::Overflow : public Memory
{
    /**
     * @class	Memory::Overflow
     * @brief	
     * @details	
    **/
public:
    Overflow(const char * details = nullptr, const Location & location = Location::current())
        : Memory("Overflow", details, location) {}
    ~Overflow() {}
};

#endif /* define: status_memory_h */