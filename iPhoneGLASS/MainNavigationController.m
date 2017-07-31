//
//  MainNavigationController.m
//  GTiPhone
//
//  Created by 尤维维 on 2017/6/7.
//  Copyright © 2017年 尤维维. All rights reserved.
//

#import "MainNavigationController.h"
#import "UITabBarController+YZBim.h"

@interface MainNavigationController ()

@end

@implementation MainNavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated
{
    [super pushViewController:viewController animated:animated];
//    YZLog(@"%zd",self.childViewControllers.count);
    BOOL visible = self.childViewControllers.count < 2;
    [viewController.tabBarController setTabBarVisible:visible animated:NO completion:nil];
}

- (UIViewController *)popViewControllerAnimated:(BOOL)animated
{
    UIViewController *vc = [super popViewControllerAnimated:animated];
    BOOL visible = self.childViewControllers.count < 2;
    [vc.tabBarController setTabBarVisible:visible animated:NO completion:nil];
    return vc;
}

@end