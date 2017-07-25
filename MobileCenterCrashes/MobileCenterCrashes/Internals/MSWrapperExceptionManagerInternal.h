#import "MSWrapperExceptionManager.h"

@class MSWrapperException;
@class MSPLCrashReport;

@interface MSWrapperExceptionManager ()

/**
 * Delete all wrapper exception files on disk.
 */
+ (void)deleteAllWrapperExceptions;

/**
 * Find the PLCrashReport with a matching process id to the MSWrapperException that
 * was last saved on disk, and update the filename to the report's UUID.
 */
+ (void) correlateLastSavedWrapperExceptionToReport:(NSArray<MSPLCrashReport*> *)reports;

/**
 * Delete a wrapper exception with a given UUID.
 */
+ (void) deleteWrapperExceptionWithUUID:(NSString *)uuid;

/**
 * Delete a wrapper exception with a given UUID.
 */
+ (void) deleteWrapperExceptionWithUUIDRef:(CFUUIDRef)uuidRef;

/**
 * Load a wrapper exception with a given UUID.
 */
+ (MSWrapperException *) loadWrapperExceptionWithUUIDRef:(CFUUIDRef)uuidRef;

@end
