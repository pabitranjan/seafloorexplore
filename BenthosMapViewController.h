//
//  BenthosMapViewController.h
//  SeafloorExplore
//
//  Modified from Brad Larson's Molecules Project in 2011-2012 for use in The SeafloorExplore Project
//
//  Copyright (C) 2012 Matthew Johnson-Roberson
//
//  See COPYING for license details
//  
//  Molecules
//
//  The source code for Molecules is available under a BSD license.  See COPYING for details.
//
//  Created by Brad Larson on 6/30/2008.
//
//  This controller manages the root table of models that are stored on the device

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <MapKit/MapKit.h>

#import "BenthosRootViewController.h"
#import "BenthosFolderViewController.h"
#import "BenthosDownloadController.h"
#import "BenthosDetailViewController.h"
#import "MapAnnotation.h"

@interface BenthosMapViewController : UIViewController <MKMapViewDelegate>
{
	NSMutableArray *models;
	BenthosRootViewController *delegate;
	NSString *selectedModel;
	UIColor *tableTextColor;
    MKMapView *mapView;
	sqlite3 *database;
    BOOL firstView;
    NSMutableArray *decompressingfiles;

}
@property(readwrite,retain) NSMutableArray *decompressingfiles;

@property(nonatomic,retain) MKMapView *mapView;

//@property(readwrite,retain)     MapAnnotation *selectedAnnotation;
@property(nonatomic,assign)     BOOL firstView;

@property(nonatomic,retain) NSString *selectedModel;


@property(readwrite,assign) BenthosRootViewController *delegate;
@property(readwrite,assign) sqlite3 *database;
@property(readwrite,retain) NSMutableArray *models;

// Initialization and teardown
- (id)init:(NSInteger)indexOfInitialModel withModels:(NSMutableArray*) mol_list;
- (void)mapView:(MKMapView *)mapView didSelectAnnotationView:(MKAnnotationView *)view;
//-(void)selectInitialAnnotation ;
- (void)showDetails:(id)sender;
-(void) doAnnotation;
-(void)recenterMap;
- (IBAction)displayModelDownloadView;
- (IBAction)switchBackToGLView;
- (void)reSelectAnnotationIfNoneSelected:(id<MKAnnotation>)annotation;
-(void)selectInitialAnnotation ;
-(void)updatePins;

//- (void)modelDidFinishDownloading:(NSNotification *)note;

@end
