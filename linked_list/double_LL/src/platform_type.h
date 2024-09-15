/*
 * platform_type.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Giovanny
 */

#ifndef PLATFORM_TYPE_H_
#define PLATFORM_TYPE_H_

#define PLATFORM_8 	(8)
#define PLATFORM_16 (16)
#define PLATFORM_32 (32)
#define PLATFORM_64 (64)
#define PLATFORM_USED (64)

#if (PLATFORM_USED==PLATFORM_64)
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif (PLATFORM_USED==PLATFORM_32)
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif (PLATFORM_USED==PLATFORM_16)
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif(PLATFORM_USED==PLATFORM_8)
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef float float32;

#endif

#endif /* PLATFORM_TYPE_H_ */
