#ifndef PHD_BASETYPES
#define PHD_BASETYPES

//#define POST_PACKED __attribute__((packed)) 
#define POST_PACKED

#define __flash
#define sprintf_P sprintf
#define strcat_P strcat
#define CALLBACK    __stdcall
#define __no_init

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

typedef char int8_t;
typedef short int16_t;
typedef long int32_t;

typedef unsigned char intu8;
typedef unsigned short intu16;
typedef unsigned long intu32;
typedef unsigned long long intu64;

typedef char int8;
typedef short int16;
typedef long int32;


#define FALSE false
#define TRUE true


typedef uint64_t EUI64_t;

typedef uint64_t BcTime_t;


#endif  /* !PHD_BASETYPES */
