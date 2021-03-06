//
//  HomeCollectionCell.h
//  iPhoneGLASS
//
//  Created by 尤维维 on 2017/7/31.
//  Copyright © 2017年 Yizhu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ListModel.h"

@interface HomeCollectionCell : UICollectionViewCell<UITableViewDelegate, UITableViewDataSource>

@property(nonatomic, strong) UITableView *tableView;

@property(nonatomic, strong) NSDate *date;

@property (nonatomic, strong) NSArray *items;

@end
