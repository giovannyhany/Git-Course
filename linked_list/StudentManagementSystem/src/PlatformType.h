/*
 * PlatformType.h
 *
 *  Created on: Sep 10, 2024
 *      Author: Giovanny
 */

#ifndef PLATFORMTYPE_H_
#define PLATFORMTYPE_H_

#define Platform_64 (64)
#define Platform_32 (32)
#define Platform_16 (16)
#define Platform_8 	(8)

#define PlatformInUse (64)

#if PlatformInUse==Platform_64
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


#elif PlatformInUse==Platform_32
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

#elif PlatformInUse==Platform_16
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

#elif PlatformInUse==Platform_8
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;

typedef float float32;

#endif

#endif /* PLATFORMTYPE_H_ */
