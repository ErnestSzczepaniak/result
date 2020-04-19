#ifndef _status_h
#define _status_h

/**
 * @file	status.h
 * @author	en2
 * @date	19-04-2020
 * @brief	
 * @details	
**/

class Status
{
    /**
     * @class	Status
     * @brief	
     * @details	
    **/
   static constexpr auto size_details = 64;

public:
    Status();
    Status(const char * category, const char * brief);
    ~Status();

    const char * category() const;
    const char * brief() const;
    const char * details() const;

    operator bool();   
    bool operator==(const Status & other);

    class Memory;

protected:
    template<typename ...T>
    void _format(const char * format, T ... ts);

private:
    const char * _category;
    const char * _brief;
    char _details[size_details];

}; /* class: Status */

template<typename ...T>
void Status::_format(const char * format, T ... ts)
{
    
}

#include "status_memory.h"
#include "status_driver.h"


#endif /* define: status_h */