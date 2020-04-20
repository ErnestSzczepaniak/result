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

class Status::Memory : public Status
{
    /**
     * @class	Status::Memory
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

}; /* class: Status::Memory */

/* ---------------------------------------------| Memory::Unaligned access |--------------------------------------------- */

class Status::Memory::Unaligned_access : public Status::Memory
{
    /**
     * @class	Status::Memory::Unaligned_access
     * @brief	
     * @details	
    **/
public:
    Unaligned_access(const char * details = nullptr, const Location & location = Location::current())
        : Status::Memory("Unaligned access", details, location) {}
    ~Unaligned_access() {}
};

/* ---------------------------------------------| Memory::Invalid access |--------------------------------------------- */

class Status::Memory::Invalid_access : public Status::Memory
{
    /**
     * @class	Status::Memory::Invalid_access
     * @brief	
     * @details	
    **/
public:
    Invalid_access(const char * details = nullptr, const Location & location = Location::current())
        : Status::Memory("Invalid access", details, location) {}
    ~Invalid_access() {}
};

/* ---------------------------------------------| Memory::Low |--------------------------------------------- */

class Status::Memory::Low : public Status::Memory
{
    /**
     * @class	Status::Memory::Low
     * @brief	
     * @details	
    **/
public:
    Low(const char * details = nullptr, const Location & location = Location::current())
        : Status::Memory("Low", details, location) {}
    ~Low() {}
};

/* ---------------------------------------------| Memory::Not_enought |--------------------------------------------- */

class Status::Memory::Not_enought : public Status::Memory
{
    /**
     * @class	Status::Memory::Not_enought
     * @brief	
     * @details	
    **/
public:
    Not_enought(const char * details = nullptr, const Location & location = Location::current())
        : Status::Memory("Not enought", details, location) {}
    ~Not_enought() {}
};

/* ---------------------------------------------| Memory::Leak |--------------------------------------------- */

class Status::Memory::Leak : public Status::Memory
{
    /**
     * @class	Status::Memory::Leak
     * @brief	
     * @details	
    **/
public:
    Leak(const char * details = nullptr, const Location & location = Location::current())
        : Status::Memory("Leak", details, location) {}
    ~Leak() {}
};

/* ---------------------------------------------| Memory::Corruption |--------------------------------------------- */

class Status::Memory::Corruption : public Status::Memory
{
    /**
     * @class	Status::Memory::Corruption
     * @brief	
     * @details	
    **/
public:
    Corruption(const char * details = nullptr, const Location & location = Location::current())
        : Status::Memory("Corruption", details, location) {}
    ~Corruption() {}
};

/* ---------------------------------------------| Memory::Overflow |--------------------------------------------- */

class Status::Memory::Overflow : public Status::Memory
{
    /**
     * @class	Status::Memory::Overflow
     * @brief	
     * @details	
    **/
public:
    Overflow(const char * details = nullptr, const Location & location = Location::current())
        : Status::Memory("Overflow", details, location) {}
    ~Overflow() {}
};

#endif /* define: status_memory_h */