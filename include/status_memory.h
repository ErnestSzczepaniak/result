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
    Memory(const char * brief, const char * details = nullptr) : Status("Memory", brief, details) {}
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
    Unaligned_access(const char * details = nullptr) : Status::Memory("Unaligned access", details) {}
    template<typename ... T> Unaligned_access(const char * format, T ... ts) : Status::Memory("Unaligned access") {_format_custom_details(format, ts...);}
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
    Invalid_access(const char * details = nullptr) : Status::Memory("Invalid access", details) {}
    template<typename ... T> Invalid_access(const char * format, T ... ts) : Status::Memory("Invalid access") {_format_custom_details(format, ts...);}
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
    Low(const char * details = nullptr) : Status::Memory("Low", details) {}
    template<typename ... T> Low(const char * format, T ... ts) : Status::Memory("Low") {_format_custom_details(format, ts...);}
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
    Not_enought(const char * details = nullptr) : Status::Memory("Not enought", details) {}
    template<typename ... T> Not_enought(const char * format, T ... ts) : Status::Memory("Not enought") {_format_custom_details(format, ts...);}
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
    Leak(const char * details = nullptr) : Status::Memory("Leak", details) {}
    template<typename ... T> Leak(const char * format, T ... ts) : Status::Memory("Leak") {_format_custom_details(format, ts...);}
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
    Corruption(const char * details = nullptr) : Status::Memory("Corruption", details) {}
    template<typename ... T> Corruption(const char * format, T ... ts) : Status::Memory("Corruption") {_format_custom_details(format, ts...);}
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
    Overflow(const char * details = nullptr) : Status::Memory("Overflow", details) {}
    template<typename ... T> Overflow(const char * format, T ... ts) : Status::Memory("Overflow") {_format_custom_details(format, ts...);}
    ~Overflow() {}
};

#endif /* define: status_memory_h */