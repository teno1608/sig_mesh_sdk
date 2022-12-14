/********************************************************************************************************
 * @file     LibTools.h 
 *
 * @brief    for TLSR chips
 *
 * @author	 telink
 * @date     Sep. 30, 2010
 *
 * @par      Copyright (c) 2010, Telink Semiconductor (Shanghai) Co., Ltd.
 *           All rights reserved.
 *           
 *			 The information contained herein is confidential and proprietary property of Telink 
 * 		     Semiconductor (Shanghai) Co., Ltd. and is available under the terms 
 *			 of Commercial License Agreement between Telink Semiconductor (Shanghai) 
 *			 Co., Ltd. and the licensee in separate contract or the terms described here-in. 
 *           This heading MUST NOT be removed from this file.
 *
 * 			 Licensees are granted free, non-transferable use of the information in this 
 *			 file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided. 
 *           
 *******************************************************************************************************/
//
//  LibTools.h
//  TelinkSigMeshLib
//
//  Created by 梁家誌 on 2018/10/12.
//  Copyright © 2018年 Telink. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LibTools : NSObject

/**
 把NSString转成可写入蓝牙设备的Hex Data

 @param string 原始字符串数据
 @return 返回data
 */
+ (NSData *)nsstringToHex:(NSString *)string;

/**
 NSData 转  十六进制string
 
 @return NSString类型的十六进制string
 */
+ (NSString *)convertDataToHexStr:(NSData *)data;

///NSData字节翻转
+ (NSData *)turnOverData:(NSData *)data;

/**
 计算2000.1.1 00:00:00 到现在的秒数
 
 @return 返回2000.1.1 00:00:00 到现在的秒数
 */
+ (NSInteger )secondsFrome2000;

/// 返回手机当前时间的时区
+ (NSInteger)currentTimeZoon;

+ (NSString *)getNowTimeTimestamp;

+ (NSString *)getNowTimeTimestampFrome2000;

/// 返回当前时间字符串格式："yyyy-MM-dd HH:mm:ss"
+ (NSString *)getNowTimeTimeString;

/// 返回当前时间字符串格式："YYYY-MM-ddThh:mm:ssZ"，eg: @"2018-12-23T11:45:22-08:00"
+ (NSString *)getNowTimeStringOfJson;

/// 返回json中的SigStepResolution对应的毫秒数，只有四种值：100,1000,10000,600000.
+ (NSInteger)getSigStepResolutionInMillisecondsOfJson:(SigStepResolution)resolution;

+ (NSData *)createNetworkKey;

+ (NSData *)initAppKey;

+ (NSData *)createRandomDataWithLength:(NSInteger)length;

+ (NSData *)initMeshUUID;

+ (long long)NSDataToUInt:(NSData *)data;

/// 返回带冒号的mac
+ (NSString *)getMacStringWithMac:(NSString *)mac;

/// NSData转Uint8
+ (UInt8)uint8FromBytes:(NSData *)fData;

/// NSData转Uint16
+ (UInt16)uint16FromBytes:(NSData *)fData;

/// NSData转Uint32
+ (UInt32)uint32FromBytes:(NSData *)fData;

/// NSData转Uint64
+ (UInt64)uint64FromBytes:(NSData *)fData;

/// 16进制NSString转Uint8
+ (UInt8)uint8From16String:(NSString *)string;

/// 16进制NSString转Uint16
+ (UInt16)uint16From16String:(NSString *)string;

/// 16进制NSString转Uint32
+ (UInt32)uint32From16String:(NSString *)string;

/// 16进制NSString转Uint64
+ (UInt64)uint64From16String:(NSString *)string;

+ (UInt16)getVirtualAddressOfLabelUUID:(NSString *)string;

/// D7C5BD18-4282-F31A-0CE0-0468BC0B8DE8 -> D7C5BD184282F31A0CE00468BC0B8DE8
+ (NSString *)meshUUIDToUUID:(NSString *)uuid;

/// D7C5BD184282F31A0CE00468BC0B8DE8 -> D7C5BD18-4282-F31A-0CE0-0468BC0B8DE8
+ (NSString *)UUIDToMeshUUID:(NSString *)meshUUID;

/// xxxx -> 0000xxxx-0000-1000-8000-008505f9b34fb or xxxxxxxx -> xxxxxxxx-0000-1000-8000-008505f9b34fb
+ (NSString *)change16BitsUUIDTO128Bits:(NSString *)uuid;

/// SDK的版本号
+ (NSString *)getSDKVersion;

+ (float)floatWithdecimalNumber:(double)num;

+ (double)doubleWithdecimalNumber:(double)num;

+ (NSString *)stringWithDecimalNumber:(double)num;

+ (NSDecimalNumber *)decimalNumber:(double)num;

+ (UInt8)lightnessToLum:(UInt16)lightness;
+ (UInt16)lumToLightness:(UInt8)lum;
+ (UInt8)tempToTemp100:(UInt16)temp;
+ (UInt16)temp100ToTemp:(UInt8)temp100;
///（四舍五入，保留两位小数）
+ (float)roundFloat:(float)price;

/// 通过周期对象SigPeriodModel获取周期时间，单位为秒。
+ (double)getIntervalWithSigPeriodModel:(SigPeriodModel *)periodModel;

/// 通过周期对象SigPeriodModel获取周期时间，单位为秒。
+ (SigStepResolution)getSigStepResolutionWithSigPeriodModel:(SigPeriodModel *)periodModel;

#pragma mark - JSON相关

/**
 *  字典数据转换成JSON字符串（没有可读性）
 *
 *  @param dictionary 待转换的字典数据
 *  @return JSON字符串
 */
+ (NSString *)getJSONStringWithDictionary:(NSDictionary *)dictionary;
 
/**
 *  字典数据转换成JSON字符串（有可读性）
 *
 *  @param dictionary 待转换的字典数据
 *  @return JSON字符串
 */
+ (NSString *)getReadableJSONStringWithDictionary:(NSDictionary *)dictionary;
 
/**
 *  字典数据转换成JSON数据
 *
 *  @param dictionary 待转换的字典数据
 *  @return JSON数据
 */
+ (NSData *)getJSONDataWithDictionary:(NSDictionary *)dictionary;

/**
*  NSData数据转换成字典数据
*
*  @param data 待转换的NSData数据
*  @return 字典数据
*/
+(NSDictionary *)getDictionaryWithJSONData:(NSData*)data;

/**
*  JSON字符串转换成字典数据
*
*  @param jsonString 待转换的JSON字符串
*  @return 字典数据
*/
+ (NSDictionary *)getDictionaryWithJsonString:(NSString *)jsonString;

#pragma mark - CRC相关

unsigned short crc16 (unsigned char *pD, int len);

+ (UInt32)getCRC32OfData:(NSData *)data;

#pragma mark - AES相关

//加密
int aes128_ecb_encrypt(const unsigned char *inData, int in_len, const unsigned char *key, unsigned char *outData);

//解密
int aes128_ecb_decrypt(const unsigned char *inData, int in_len, const unsigned char *key, unsigned char *outData);

#pragma mark - base64加解密

/******************************************************************************
 函数名称 : + (NSString *)base64StringFromText:(NSString *)text
 函数描述 : 将文本转换为base64格式字符串
 输入参数 : (NSString *)text    文本
 输出参数 : N/A
 返回参数 : (NSString *)    base64格式字符串
 备注信息 :
 ******************************************************************************/
+ (NSString *)base64StringFromText:(NSString *)text;

/******************************************************************************
 函数名称 : + (NSString *)textFromBase64String:(NSString *)base64
 函数描述 : 将base64格式字符串转换为文本
 输入参数 : (NSString *)base64  base64格式字符串
 输出参数 : N/A
 返回参数 : (NSString *)    文本
 备注信息 :
 ******************************************************************************/
+ (NSString *)textFromBase64String:(NSString *)base64;

+ (NSString *)textFromBase64String:(NSString *)base64 password:(NSString *)password;

#pragma mark - 正则表达式相关

+ (BOOL)validateUUID:(NSString *)uuidString;

+ (BOOL)validateHex:(NSString *)uuidString;

#pragma mark - UTF-8相关

+ (NSArray <NSNumber *>*)getNumberListFromUTF8EncodeData:(NSData *)UTF8EncodeData;

+ (NSData *)getUTF8EncodeDataFromNumberList:(NSArray <NSNumber *>*)numberList;

#pragma mark - 文件相关

+ (NSArray <NSString *>*)getAllFileNameWithFileType:(NSString *)fileType;
+ (NSData *)getDataWithFileName:(NSString *)fileName fileType:(NSString * _Nullable )fileType;

@end

NS_ASSUME_NONNULL_END
