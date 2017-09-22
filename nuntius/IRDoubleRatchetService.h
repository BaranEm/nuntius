/*
 The MIT License (MIT)
 Copyright © 2017 Ivan Rodriguez. All rights reserved.

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or substantial
 portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#import <Foundation/Foundation.h>

@class IRCurve25519KeyPair;

@interface IRDoubleRatchetService : NSObject

@property (nonatomic, strong, readonly) NSData * _Nonnull rootKey;

#pragma mark - Setup Ratchet

//Restore state

- (void)setupWithRatchetState:(NSDictionary<NSString *, NSString *> * _Nullable)doubleRatchetState;

//Setup for sending

- (void)setupRatchetForSendingWithSharedKey:(NSData * _Nonnull)sharedKey
                           andDHReceiverKey:(IRCurve25519KeyPair * _Nonnull)DHReceiverKey;

//Setup for receiving

- (void)setupRatchetForReceivingWithSharedKey:(NSData * _Nonnull)sharedKey
                               andDHSenderKey:(IRCurve25519KeyPair * _Nonnull)DHSenderKey;

#pragma mark - Encrypt

- (NSData * _Nullable)encryptData:(NSData * _Nonnull)plaintext
                            error:(NSError * _Nullable * _Nullable)error;

#pragma mark - Decrypt

- (NSData * _Nullable)decryptData:(NSData * _Nonnull)cipherdata
                            error:(NSError * _Nullable * _Nullable)error;

#pragma mark - State

- (NSDictionary<NSString *, NSString *> * _Nonnull)doubleRatchetState;

@end
