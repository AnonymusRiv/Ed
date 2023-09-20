/**
 * @file dos_detector.hpp
 */
#pragma once

#include "system.hpp"


/**
 * @brief Run the DOS dectection algorithm.
 * @arg log is the system's log.
 * @arg max_acc is the number max of accesses per hour allowed.
 * @arg m is the initial size of the hash table.
*/
void dos_detector(Log &log, int max_acc, size_t m);
