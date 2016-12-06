//
//  ViewController.m
//  UICollectionViewTestios7.0
//
//  Created by NetEase on 16/10/24.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#import "ViewController.h"
#import "MineViewControllerCell.h"

@interface ViewController ()<UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

@property (nonatomic, strong) UICollectionView *collectionView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self initCollectionView];
}


- (void)initCollectionView
{
    //1.创建布局
    UICollectionViewFlowLayout *flowLayout = [[UICollectionViewFlowLayout alloc]init];
    flowLayout.minimumInteritemSpacing = 0;
    flowLayout.minimumLineSpacing = 0;
    
    //2.初始化collectionView
    
    CGRect frame = CGRectMake(0, 100, self.view.frame.size.width, self.view.frame.size.height);
    self.collectionView = [[UICollectionView alloc]initWithFrame:frame collectionViewLayout:flowLayout];
    
    //3.注册collectionViewCell
    [self.collectionView registerClass:[MineViewControllerCell class] forCellWithReuseIdentifier:@"cellId"];
    
    
    //5.设置代理
    self.collectionView.delegate = self;
    self.collectionView.dataSource = self;
    self.collectionView.backgroundColor = [UIColor clearColor];
    
    [self.view addSubview:self.collectionView];
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return 6;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    MineViewControllerCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"cellId" forIndexPath:indexPath];
    
    return cell;
}

//设置section头视图的大小
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout referenceSizeForHeaderInSection:(NSInteger)section
{
    return CGSizeMake(320, 80);
}

//设置每个item的尺寸
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath
{
    CGFloat width = 320 / 3;
    return CGSizeMake(320, 110);
}
@end
