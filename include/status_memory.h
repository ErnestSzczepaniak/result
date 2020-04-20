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

status_class(Memory, Access_violation);
status_class(Memory, Alignment_violation);
status_class(Memory, Low);
status_class(Memory, Not_enought);
status_class(Memory, Leak);
status_class(Memory, Corruption);
status_class(Memory, Overflow);

}; /* namespace: status::memory */

#endif /* define: status_memory_h */