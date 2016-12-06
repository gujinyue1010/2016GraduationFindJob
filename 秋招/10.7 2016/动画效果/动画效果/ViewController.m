//
//  ViewController.m
//  动画效果
//
//  Created by NetEase on 16/10/31.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    // Do any additional setup after loading the view, typically from a nib.
    
    UIView  *view =[[UIView alloc]initWithFrame:CGRectMake(100, 100, 100, 100)];
    
    view.backgroundColor =[UIColor redColor];
    
    [self.view addSubview:view];
    
    [self heartbeatView:view duration:100];
    
}



-(void)heartbeatView:(UIView *)view duration:(CGFloat)fDuration

{
    
    [[self class] heartbeatView:view duration:fDuration maxSize:1.4f durationPerBeat:0.5f];
    
}

+(void)heartbeatView:(UIView *)view duration:(CGFloat)fDuration maxSize:(CGFloat)fMaxSize durationPerBeat:(CGFloat)fDurationPerBeat

{
    
    if (view && (fDurationPerBeat > 0.1f))
        
    {
        
        CAKeyframeAnimation *animation = [CAKeyframeAnimation animationWithKeyPath:@"transform"];
        
        
        
        CATransform3D scale1 = CATransform3DMakeScale(0.8, 0.8, 1);
        
//        CATransform3D scale2 = CATransform3DMakeScale(fMaxSize, fMaxSize, 1);
//        
//        CATransform3D scale3 = CATransform3DMakeScale(fMaxSize - 0.3f, fMaxSize - 0.3f, 1);
//        
//        CATransform3D scale4 = CATransform3DMakeScale(1.0, 1.0, 1);
        
        
        
        NSArray *frameValues = [NSArray arrayWithObjects:
                                
                                [NSValue valueWithCATransform3D:scale1],
                                
//                                [NSValue valueWithCATransform3D:scale2],
//                                
//                                [NSValue valueWithCATransform3D:scale3],
//                                
//                                [NSValue valueWithCATransform3D:scale4],
                                
                                nil];
        
        
        
        [animation setValues:frameValues];
        
        
        
        NSArray *frameTimes = [NSArray arrayWithObjects:
                               
                               [NSNumber numberWithFloat:0.05],
                               
                               [NSNumber numberWithFloat:0.2],
                               
                               [NSNumber numberWithFloat:0.6],
                               
                               [NSNumber numberWithFloat:1.0],
                               
                               nil];
        
        [animation setKeyTimes:frameTimes];
        
        
        
        animation.fillMode = kCAFillModeForwards;
        
        animation.duration = fDurationPerBeat;
        
        animation.repeatCount = fDuration/fDurationPerBeat;
        
        
        
        [view.layer addAnimation:animation forKey:@"heartbeatView"];
        
    }
    else
    {
    }
}

    
@end
