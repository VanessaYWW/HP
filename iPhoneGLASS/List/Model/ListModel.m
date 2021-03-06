//
//  ListModel.m
//  iPhoneGLASS
//
//  Created by 尤维维 on 16/5/31.
//  Copyright © 2016年 Yizhu. All rights reserved.
//

#import "ListModel.h"
#import "NSDate+YZBim.h"

@implementation ListModel


+(ListModel *)modelWithDict:(NSDictionary *)dict {
    
    ListModel *model = [[ListModel alloc]init];
    model.name = dict[@"name"];
    model.thick = dict[@"category"];
    model.number = dict[@"stockIn"]?[dict[@"stockIn"] integerValue]:0;
    model.totalNumber = dict[@"count"]?[dict[@"count"] integerValue]:0;
    model.date = dict[@"createdAt"];
    model.width = [NSString stringWithFormat:@"%@",dict[@"width"]];
    model.height = [NSString stringWithFormat:@"%@",dict[@"length"]];
    model.billnumber = dict[@"billnumber"]?dict[@"billnumber"]:@"";
//    model.wind = [dict[@"wind"] boolValue];
//    model.color = dict[@"color"];
    model.glassID = dict[@"_id"];
//    model.userID = dict[@"_id"];
    if (dict[@"marker"]) {
        model.mark = dict[@"marker"];
    }
    if (dict[@"finish"]) {
        model.isFinish = [dict[@"finish"] boolValue];
    }else{
        model.isFinish = false;
    }
    model.deliverymans = dict[@"deliveryman"];
    model.sendTo = dict[@"sendTo"]?[dict[@"sendTo"] integerValue]:0;
    
    return model;
}

- (BOOL)isFinish {
    return _isFinish || (self.totalNumber == self.number);
}

@end
