// Generated by Apple Swift version 3.1 (swiftlang-802.0.53 clang-802.0.42)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if defined(__has_attribute) && __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import AVFoundation;
@import Foundation;
#endif

#import "/Users/nattapon.r/Projects/projects/webrtc-rn-demo/node_modules/react-native-incall-manager/ios/RNInCallManager/RNInCallManager-Bridging-Header.h"

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class RCTBridge;
@class UIDevice;
@class AVAudioSession;
@class AVAudioPlayer;
@protocol NSObject;
@class NSNumber;
@class NSOperationQueue;

SWIFT_CLASS_NAMED("RNInCallManager")
@interface RNInCallManager : NSObject <AVAudioPlayerDelegate>
@property (nonatomic, strong) RCTBridge * _Null_unspecified bridge;
@property (nonatomic, strong) UIDevice * _Null_unspecified currentDevice;
@property (nonatomic, strong) AVAudioSession * _Null_unspecified audioSession;
@property (nonatomic, strong) AVAudioPlayer * _Null_unspecified mRingtone;
@property (nonatomic, strong) AVAudioPlayer * _Null_unspecified mRingback;
@property (nonatomic, strong) AVAudioPlayer * _Null_unspecified mBusytone;
@property (nonatomic, copy) NSURL * _Null_unspecified defaultRingtoneUri;
@property (nonatomic, copy) NSURL * _Null_unspecified defaultRingbackUri;
@property (nonatomic, copy) NSURL * _Null_unspecified defaultBusytoneUri;
@property (nonatomic, copy) NSURL * _Null_unspecified bundleRingtoneUri;
@property (nonatomic, copy) NSURL * _Null_unspecified bundleRingbackUri;
@property (nonatomic, copy) NSURL * _Null_unspecified bundleBusytoneUri;
@property (nonatomic) BOOL isProximitySupported;
@property (nonatomic) BOOL proximityIsNear;
@property (nonatomic) BOOL isProximityRegistered;
@property (nonatomic) BOOL isAudioSessionInterruptionRegistered;
@property (nonatomic) BOOL isAudioSessionRouteChangeRegistered;
@property (nonatomic) BOOL isAudioSessionMediaServicesWereLostRegistered;
@property (nonatomic) BOOL isAudioSessionMediaServicesWereResetRegistered;
@property (nonatomic) BOOL isAudioSessionSilenceSecondaryAudioHintRegistered;
@property (nonatomic, strong) id <NSObject> _Nullable proximityObserver;
@property (nonatomic, strong) id <NSObject> _Nullable audioSessionInterruptionObserver;
@property (nonatomic, strong) id <NSObject> _Nullable audioSessionRouteChangeObserver;
@property (nonatomic, strong) id <NSObject> _Nullable audioSessionMediaServicesWereLostObserver;
@property (nonatomic, strong) id <NSObject> _Nullable audioSessionMediaServicesWereResetObserver;
@property (nonatomic, strong) id <NSObject> _Nullable audioSessionSilenceSecondaryAudioHintObserver;
@property (nonatomic, copy) NSString * _Nonnull incallAudioMode;
@property (nonatomic, copy) NSString * _Nonnull incallAudioCategory;
@property (nonatomic, copy) NSString * _Null_unspecified origAudioCategory;
@property (nonatomic, copy) NSString * _Null_unspecified origAudioMode;
@property (nonatomic) BOOL audioSessionInitialized;
@property (nonatomic, readonly) BOOL automatic;
@property (nonatomic) NSInteger forceSpeakerOn;
@property (nonatomic, copy) NSString * _Null_unspecified recordPermission;
@property (nonatomic, copy) NSString * _Null_unspecified cameraPermission;
@property (nonatomic, copy) NSString * _Nonnull media;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)start:(NSString * _Nonnull)media auto:(BOOL)auto_ ringbackUriType:(NSString * _Nonnull)ringbackUriType;
- (void)stop:(NSString * _Nonnull)busytoneUriType;
- (void)turnScreenOn;
- (void)turnScreenOff;
- (void)updateAudioRoute;
- (BOOL)checkAudioRoute:(NSArray<NSString *> * _Nonnull)targetPortTypeArray :(NSString * _Nonnull)routeType SWIFT_WARN_UNUSED_RESULT;
- (void)getIsWiredHeadsetPluggedIn:(SWIFT_NOESCAPE void (^ _Nonnull)(id _Nullable))resolve reject:(SWIFT_NOESCAPE void (^ _Nonnull)(NSString * _Nullable, NSString * _Nullable, NSError * _Nullable))reject;
- (BOOL)isWiredHeadsetPluggedIn SWIFT_WARN_UNUSED_RESULT;
- (void)audioSessionSetMode:(NSString * _Nonnull)audioMode :(NSString * _Nonnull)callerMemo;
- (void)setFlashOnEnable:(BOOL)enable brightness:(NSNumber * _Nonnull)brightness;
- (void)setKeepScreenOn:(BOOL)enable;
- (void)setSpeakerphoneOn:(BOOL)enable;
- (void)setForceSpeakerphoneOn:(NSInteger)flag;
- (void)setMicrophoneMute:(BOOL)enable;
- (void)storeOriginalAudioSetup;
- (void)restoreOriginalAudioSetup;
- (void)checkProximitySupport;
- (void)startProximitySensor;
- (void)stopProximitySensor;
- (void)startAudioSessionNotification;
- (void)stopAudioSessionNotification;
- (void)startAudioSessionInterruptionNotification;
- (void)stopAudioSessionInterruptionNotification;
- (void)startAudioSessionRouteChangeNotification;
- (void)stopAudioSessionRouteChangeNotification;
- (void)startAudioSessionMediaServicesWereLostNotification;
- (void)stopAudioSessionMediaServicesWereLostNotification;
- (void)startAudioSessionMediaServicesWereResetNotification;
- (void)stopAudioSessionMediaServicesWereResetNotification;
- (void)startAudioSessionSilenceSecondaryAudioHintNotification;
- (void)stopAudioSessionSilenceSecondaryAudioHintNotification;
- (id <NSObject> _Nonnull)startObserve:(NSString * _Nonnull)name object:(id _Nullable)object queue:(NSOperationQueue * _Nullable)queue block:(void (^ _Nonnull)(NSNotification * _Nonnull))block SWIFT_WARN_UNUSED_RESULT;
- (void)stopObserve:(id _Nullable)_observer name:(NSString * _Nullable)name object:(id _Nullable)object;
- (void)startRingback:(NSString * _Nonnull)_ringbackUriType;
- (void)stopRingback;
- (BOOL)startBusytone:(NSString * _Nonnull)_busytoneUriType SWIFT_WARN_UNUSED_RESULT;
- (void)stopBusytone;
- (void)startRingtone:(NSString * _Nonnull)ringtoneUriType ringtoneCategory:(NSString * _Nonnull)ringtoneCategory;
- (void)stopRingtone;
- (void)getAudioUriJS:(NSString * _Nonnull)audioType fileType:(NSString * _Nonnull)fileType resolve:(SWIFT_NOESCAPE void (^ _Nonnull)(id _Nullable))resolve reject:(SWIFT_NOESCAPE void (^ _Nonnull)(NSString * _Nullable, NSString * _Nullable, NSError * _Nullable))reject;
- (NSURL * _Nullable)getRingbackUri:(NSString * _Nonnull)_type SWIFT_WARN_UNUSED_RESULT;
- (NSURL * _Nullable)getBusytoneUri:(NSString * _Nonnull)_type SWIFT_WARN_UNUSED_RESULT;
- (NSURL * _Nullable)getRingtoneUri:(NSString * _Nonnull)_type SWIFT_WARN_UNUSED_RESULT;
- (NSURL * _Nullable)getSysFileUri:(NSString * _Nonnull)target SWIFT_WARN_UNUSED_RESULT;
- (void)audioPlayerDidFinishPlaying:(AVAudioPlayer * _Nonnull)player successfully:(BOOL)flag;
- (void)audioPlayerDecodeErrorDidOccur:(AVAudioPlayer * _Nonnull)player error:(NSError * _Nullable)error;
- (void)audioPlayerBeginInterruption:(AVAudioPlayer * _Nonnull)player;
- (void)debugAudioSession;
- (void)checkRecordPermission:(SWIFT_NOESCAPE void (^ _Nonnull)(id _Nullable))resolve reject:(SWIFT_NOESCAPE void (^ _Nonnull)(NSString * _Nullable, NSString * _Nullable, NSError * _Nullable))reject;
- (void)_checkRecordPermission;
- (void)requestRecordPermission:(RCTPromiseResolveBlock _Nonnull)resolve reject:(SWIFT_NOESCAPE void (^ _Nonnull)(NSString * _Nullable, NSString * _Nullable, NSError * _Nullable))reject;
- (void)checkCameraPermission:(SWIFT_NOESCAPE void (^ _Nonnull)(id _Nullable))resolve reject:(SWIFT_NOESCAPE void (^ _Nonnull)(NSString * _Nullable, NSString * _Nullable, NSError * _Nullable))reject;
- (void)_checkCameraPermission;
- (void)requestCameraPermission:(RCTPromiseResolveBlock _Nonnull)resolve reject:(SWIFT_NOESCAPE void (^ _Nonnull)(NSString * _Nullable, NSString * _Nullable, NSError * _Nullable))reject;
- (NSString * _Nonnull)_checkMediaPermission:(NSString * _Nonnull)targetMediaType SWIFT_WARN_UNUSED_RESULT;
- (void)debugApplicationState;
@end

#pragma clang diagnostic pop
