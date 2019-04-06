// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import <Foundation/Foundation.h>

#import "MSAuthTokenContextDelegateV2.h"
#import "MSAuthTokenHistoryInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface MSAuthTokenContextV2 : NSObject

/**
 * The current auth token info.
 */
@property(nonatomic, copy) MSAuthTokenHistoryInfo *currentAuthTokenInfo;

/**
 * The auth token history that contains auth token and timestamp as an item.
 */
@property(nonatomic) NSMutableArray<MSAuthTokenHistoryInfo *> *authTokenHistory;

/**
 * Collection of channel delegates.
 */
@property(nonatomic) NSHashTable<id<MSAuthTokenContextDelegateV2>> *delegates;

/**
 * Get singleton instance.
 */
+ (instancetype)sharedInstance;

/**
 * Add delegate.
 *
 * @param delegate Delegate.
 */
- (void)addDelegate:(id<MSAuthTokenContextDelegateV2>)delegate;

/**
 * Remove delegate.
 *
 * @param delegate Delegate.
 */
- (void)removeDelegate:(id<MSAuthTokenContextDelegateV2>)delegate;

/**
 * Start auth token context.
 *
 * @discussion This method should be called by a service that sets auth token. Service could be started with delay, auth token context will
 * maintain temporary auth token until the service calls this method.
 */
- (void)start;

/**
 * Notify a log is enqueued.
 *
 * @discussion This method will remove temporary flag from current auth token info to handle auth token for the log in case Identity isn't
 * started yet but there is a valid auth token info in the history.
 */
- (void)logEnqueued;

/**
 * Set current auth token and account id.
 *
 * @param authToken token to be added to the storage.
 * @param accountId account id to be added to the storage.
 * @param expiresOn expiration date of a token.
 */
- (void)setAuthToken:(nullable NSString *)authToken withAccountId:(nullable NSString *)accountId expiresOn:(nullable NSDate *)expiresOn;

/**
 * Refresh current auth token if it expires soon.
 */
- (void)refreshCurrentAuthToken;

@end

NS_ASSUME_NONNULL_END
