//
//  HorizontalTableView.h
//  Scroller
//
//  Created by Martin Volerich on 5/22/10.
//  Copyright 2010 Martin Volerich - Bill Bear Technologies. All rights reserved.
//

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>

#import <UIKit/UIKit.h>

@class HorizontalTableView;

@protocol HorizontalTableViewDelegate

- (NSInteger)numberOfColumnsForTableView:(HorizontalTableView *)tableView;
- (UIView *)tableView:(HorizontalTableView *)tableView viewForIndex:(NSInteger)index;
- (CGFloat)columnWidthForTableView:(HorizontalTableView *)tableView;

@optional
- (void)tableView:(HorizontalTableView *)tableView viewTapped:(UIView*)view;
- (void)tableView:(HorizontalTableView *)tableView viewAtIndexTapped:(NSInteger)index;
@end

@interface HorizontalTableView : UIView <
UIGestureRecognizerDelegate>{
	NSMutableArray *_pageViews;
	UIScrollView *_scrollView;
	NSUInteger _currentPageIndex;
	NSUInteger _currentPhysicalPageIndex;
    
    NSInteger _visibleColumnCount;
    NSNumber *_columnWidth;
    
    id _delegate;
    
    NSMutableArray *_columnPool;
    
    BOOL _showsScrollIndicators;
}

@property (assign) IBOutlet id<HorizontalTableViewDelegate> delegate;

- (void)refreshData;
- (UIView *)dequeueColumnView;
- (void)setShowsScrollIndicators:(BOOL)showIndicator;
- (void)prepareView;
- (UIView *)viewForPhysicalPage:(NSUInteger)pageIndex;

@end
