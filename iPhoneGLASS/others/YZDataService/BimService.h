//
//  BimService.h
//  BIM
//
//  Created by Dion Chen on 15/5/12.
//  Copyright (c) 2015年 Pu Mai. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AFNetworkingHelper.h"
#import "Global.h"
//#import "Utils.h"

@interface BimService : NSObject

@property (atomic, strong) NSString *address;

+ (BimService *)instance;

- (NSString *)baseAPI;

#pragma mark - requestTask
// 取消所有下载
+ (void)cancelRequestTask;
// 暂停所有下载
+ (void)pauseRequestTask;
// 继续所有下载
+ (void)resumeRequestTask;

/**
 下载文件

 @param fileId 文件id
 @param destination 本地存放路径
 @param cacheDestination 本地临时路径
 @param progress 进度回调
 @param range 是否断点
 @return SHXPromise
 */
- (SHXPromise *)getFile:(NSString *)fileId destination:(NSString *)destination cacheDestination:(NSString *)cacheDestination progress:(TProgress)progress range:(BOOL)range;

// 取消文件下载
- (void)cancelFile:(NSString *)fileId;
// 暂停文件下载
- (void)pauseFile:(NSString *)fileId;
// 继续文件下载
- (void)resumeFile:(NSString *)fileId;

#pragma mark image file get & post
// 获取图片网络地址
- (NSString *)getImageUrlString:(NSString *)pictureId;
/**获取图片SD*/
- (SHXPromise *)getImageByPictureId:(NSString *)pictureId projectId:(NSString *)projectId progress:(void (^)(NSInteger receivedSize, NSInteger expectedSize))progress;
// 上传本地图片
- (SHXPromise *)postPictures:(NSArray *)picPathArray projectID:(NSString *)projectID;

// 测试
- (SHXPromise *)test;

// 获取所有用户
- (SHXPromise *)getAllUsers;

// 注册新用户
- (SHXPromise *)registNewUser:(NSString *)name phone:(NSString *)phone pwd:(NSString *)pwd admin:(BOOL)admin jsPermission:(BOOL)permission;

// 更新用户
- (SHXPromise *)updateUser:(NSString *)userId newDict:(NSDictionary *)newDict;

// 删除用户
- (SHXPromise *)deleteUser:(NSString *)userId;

// 登录
- (SHXPromise *)load:(NSString *)phone pwd:(NSString *)pwd;

// 查询数据
- (SHXPromise *)getListSkip:(NSUInteger)skip limit:(NSUInteger)limit searchDict:(NSDictionary *)searchDict;

// 获取用户下单日期
- (SHXPromise *)getAllDate:(NSString *)name;

- (SHXPromise *)getAllClient;
- (SHXPromise *)getAllThick;

// 更新数据
- (SHXPromise *)updateGlassInfo:(NSString *)glassId newDict:(NSDictionary *)newDict;

// 删除数据
- (SHXPromise *)deleteGlasses:(NSArray *)glassIds;
- (SHXPromise *)deleteGlass:(NSString *)glassId;

@end
