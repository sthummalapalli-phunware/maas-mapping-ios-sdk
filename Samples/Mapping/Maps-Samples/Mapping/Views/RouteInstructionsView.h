//
//  PWRouteInstructionsView.h
//  PWMapKit
//
//  Created on 5/21/16.
//  Copyright © 2016 Phunware. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <PWMapKit/PWMapKit.h>

/**
 *  PWRouteInstructionViewDelegate protocol definition.
 */
@protocol RouteInstructionViewDelegate <NSObject>
@optional
/**
 *  This delegate is called when the route instruction has changed in the PWRouteInstructionsView instance.
 *
 *  @param route       A reference to the current PWRoute object.
 *  @param instruction A PWRouteInstruction reference to the new instruction that has changed in the view.
 */
- (void)route:(PWRoute *)route didChangeRouteInstruction:(PWRouteInstruction *)instruction;
@end

/**
 *  The PWRouteInstructionsView class allows the display of a calculated PWRoute instructions on the map view.
 */
@interface RouteInstructionsView : UIView

/**---------------------------------------------------------------------------------------
 * @name Properties
 *  ---------------------------------------------------------------------------------------
 */

/**
 *  The receiver’s delegate.
 */
@property (nonatomic) id<RouteInstructionViewDelegate> delegate;

/**
 *  A reference to the route object of the PWRouteInstructionsView instance.
 */
@property (nonatomic) PWRoute *route;

/**---------------------------------------------------------------------------------------
 * @name Instance Methods
 *  ---------------------------------------------------------------------------------------
 */

/**
 *  Creates a PWRouteInstructionsView instance for the given route.
 *
 *  @param route A PWRoute reference.
 *
 *  @return Returns a PWRouteInstructionsView instance.
 */
- (instancetype)initWithRoute:(PWRoute *)route;

/**
 *  Invalidates PWRouteInstructionsView layout.
 */
- (void)invalidateLayout;

@end
