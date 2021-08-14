/** @file error.h
 *
 * @brief This file defines functions for transferring error messages from
 * Fejix to the user code.
 *
 * Fejix is NOT supposed to free memory if runtome errors occur.
 */


#ifndef FJH_ERROR
#define FJH_ERROR

#include "common.h"

/** @return The message of the last error occured in the current thread
 * (or NULL if it was cleared)
 *
 * Fejix functions do not tend to clear last error if they succeed.
 *
 * @note Check the return values of functions to detect an error occurence
 *
 */
const char* FJ_GetLastError(void);

/// Sets the last error message to NULL
void FJ_ClearLastError(void);

/// Sets the message returned by #FJ_GetLastError
void FJ_SetError(const char *error_description);

/** Used in functions that return some value that can be invalid so that user's
 * code can detect the error, otherwise the #FJ_SetError is useless
 */
#define FJ_ERROR(message, ret) \
    { FJ_SetError(message); return ret; }

/// Returns NULL
#define FJ_ERRORN(message) FJ_ERROR(message, NULL)

/// Returns 1
#define FJ_ERROR1(message) FJ_ERROR(message, 1)


/// If condition is false, then FJ_ERROR(message, ret)
#define FJ_ASSERT(condition, message, ret) \
     { if (!(condition)) FJ_ERROR(message, ret); }

#define FJ_ASSERTN(condition, message) FJ_ASSERT(condition, message, NULL)

#define FJ_ASSERT1(condition, message) FJ_ASSERT(condition, message, 1)

#endif // FJH_ERROR
