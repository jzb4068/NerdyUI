//
//  UISlider+NERChainable.h
//  NerdyUI
//
//  Created by admin on 2016/12/21.
//  Copyright © 2016年 nerdycat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NERDefs.h"

#define Slider  [UISlider new]

@interface UISlider (NERChainable)


/**
 * value, this value will be pinned to min/max.
 * It's better to set minVal/maxVal before setting val.
 * Usages: .val(50)
 */
NER_SLIDER_PROP(Float)      val;

/**
 * minimumValue
 * Usages: .minVal(0)
 */
NER_SLIDER_PROP(Float)      minVal;
/**
 * maximumValue
 * Usages: .maxVal(100)
 */
NER_SLIDER_PROP(Float)      maxVal;

/**
 * Setting minimumTrack with color or image.
 * Usages: 
    .minTrack(@"red"), .minTrack(@"255,0,0")
    .minTrack(Img(@"minImage")), minTrack(@"minImage")
 */
NER_SLIDER_PROP(Object)     minTrack;

/**
 * Setting maximumTrack with color or image.
 * Usages: 
    .maxTrack(@"red"), .maxTrack(@"255,0,0")
    .maxTrack(Img(@"maxImage")), maxTrack(@"maxImage")
 */
NER_SLIDER_PROP(Object)     maxTrack;

/**
 * Setting thumb with color or image.
 * Usages:
    .thumb(@"red"), .thumb(@"255,0,0")
    .thumb(Img(@"thumbImage")), thumb(@"thumbImage")
 */
NER_SLIDER_PROP(Object)     thumb;

/**
 * Setting highlighted thumb with color or image.
 * Usages:
    .highThumb(@"red"), .highThumb(@"255,0,0")
    .highThumb(Img(@"thumbImage")), highThumb(@"thumbImage")
 */
NER_SLIDER_PROP(Object)     highThumb;

/**
 * Setting track height.
 * Usages: .trackHeight(3)
 */
NER_SLIDER_PROP(Float)      trackHeight;

/**
 * Customize the thumb image’s drawing rectangle.
 * Usages:
    .thumbInsets(10)                     top/left/bottom/right = 10
    .thumbInsets(10, 20)                 top/bottom = 10, left/right = 20
    .thumbInsets(10, 20, 30),            top = 10, left/right = 20, bottom = 30
    .thumbInsets(10, 20, 30, 40)         top = 10, left = 20, bottom = 30, right = 40
 */
NER_SLIDER_PROP(Insets)     thumbInsets;

/**
 * Value did change callback.
 * Use UIControlEventValueChanged event internally.
 * It support two kind of arguments:
    1) a callback block
    2) a target/action pair
 
 * Usages: 
    .onChange(^{}), .onChange(^(CGFloat value){}), onChange(^(CGFloat value, UISlider *slider){})
    .onChange(self, @selector(sliderValueDidChange) / @selector(sliderValueDidChange:))
 */
NER_SLIDER_PROP(Callback)   onChange;

//continuous = NO
- (instancetype)discrete;

#define thumbInsets(...)    thumbInsets(NER_NORMALIZE_INSETS(__VA_ARGS__))

@end