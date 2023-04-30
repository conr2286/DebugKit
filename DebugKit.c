/*
 * DebugKit.c
 *
 * Small family of debugging tools, suitable for use with small, embedded
 * systems (e.g. Arduino).
 *
 *  Created on: Apr 25, 2023
 *      Author: jconrad
 */
#include <unistd.h>

#include "DebugKitTraceFlags.h"

//Define the debug bit field variables
struct DK_TRACE_FLAGS dkTraceBits;



