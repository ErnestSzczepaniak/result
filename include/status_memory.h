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

class Status::Memory : public Status
{
public:
    Memory(const char * brief) : Status("Memory", brief) {}
    ~Memory() {}

    class Unaligned_access;
    class Invalid_access;
    class Low;
    class Not_enought;
    class Leak;
    class Corruption;
    class Overflow;

}; /* class: Status::Memory */

class Status::Memory::Unaligned_access : public Status::Memory
{
public:
    Unaligned_access() : Status::Memory("Unaligned access") {}
    template<typename ... T>
    Unaligned_access(const char * format, T ... ts) : Status::Memory("Unaligned access")
    {
        _format(format, ts ...);
    }
    ~Unaligned_access() {}
};

// class Status::Memory::Invalid_access : public Status::Memory
// {
// public:
//     Invalid_access(const char * details = nullptr) : Status::Memory("Invalid access", details) {}
//     ~Invalid_access() {}
// };

// class Status::Memory::Low : public Status::Memory
// {
// public:
//     Low(const char * details = nullptr) : Status::Memory("Low", details) {}
//     ~Low() {}
// };

// class Status::Memory::Not_enought : public Status::Memory
// {
// public:
//     Not_enought(const char * details = nullptr) : Status::Memory("Not enought", details) {}
//     ~Not_enought() {}
// };

// class Status::Memory::Leak : public Status::Memory
// {
// public:
//     Leak(const char * details = nullptr) : Status::Memory("Leak", details) {}
//     ~Leak() {}
// };

// class Status::Memory::Corruption : public Status::Memory
// {
// public:
//     Corruption(const char * details = nullptr) : Status::Memory("Corruption", details) {}
//     ~Corruption() {}
// };

// class Status::Memory::Overflow : public Status::Memory
// {
// public:
//     Overflow(const char * details = nullptr) : Status::Memory("Overflow", details) {}
//     ~Overflow() {}
// };

#endif /* define: status_memory_h */