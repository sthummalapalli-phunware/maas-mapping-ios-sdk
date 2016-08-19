//
//  PWBuildingManager.h
//  PWMapKit
//
//  Copyright (c) 2015 Phunware. All rights reserved.
//

@class PWBuilding;

/**
 Load building block
 `building` The building info
 `annotations` The list of annotation in this building
 `resources` The related resource for this building
 `error` The error message when it's failed to load the building
 */
typedef void (^PWLoadBuildingHandler)(PWBuilding *building, NSArray *annotations, NSArray *resources, NSError *error);

/**
 Building loaded notification block
 `building` The building info was loaded
 `error` The error message when it's failed to load the building
 */
typedef void (^PWBuildingHandler)(PWBuilding *building, NSError *error);

/**
 Annotation loaded notification block
 `annotations` The list of annotation in this building
 `error` The error message when it's failed to load the annotations
 */
typedef void (^PWBuildingAnnotationsHandler)(NSArray *annotations, NSError *error);

/**
 Building resources loaded notification block
 `resources` The list of resources in this building
 `error` The error message when it's failed to load the annotations
 */
typedef void (^PWBuildingResourcesHandler)(NSArray *resources, NSError *error);

/**
 Building annotation types loaded notification block
 `types` The list of annotation type in this building
 `error` The error message when it's failed to load the annotation types
 */
typedef void (^PWBuildingAnnotationTypesHandler)(NSArray *types, NSError *error);

/**
 The `PWBuildingManager` object provides a simple interface for fetching building data and resources. All data and assets fetched by this object are cached on the device.
 */

@interface PWBuildingManager : NSObject

/**
 Returns the shared instance of the `PWBuildingManager` class.
 @return The shared instance of the `PWBuildingManager` class.
 */
+ (instancetype)sharedManager;

/**
 Attempts to load a building with the specified building identifier. This method will seek to load the building annotations and resources.
 @param buildingID The specified building identifier.
 @param completion A block that takes the following parameters:
 
 - *building*: The requested building object.
 - *annotations*: The building annotations.
 - *resources*: The building resources as an array of `PWMapDocument` objects.
 - *error*: If the building fetch completed successfully, this parameter is `nil`; otherwise, this parameter holds an error object that describes the error.
 @discussion This building identifier is provided by Phunware and can be found in the Location area of the MaaS portal.
 */
- (void)loadBuildingWithIdentifier:(NSInteger)buildingID completion:(PWLoadBuildingHandler)completion;

/**
 Initiates a fetch for the building object. If the building object is not cached locally, this will result in a network request.
 @param buildingID The specified building identifier.
 @param completion A block that takes the following parameters:
 
 - *building*: The requested building object.
 - *error*: If the building fetch completed successfully, this parameter is `nil`; otherwise, this parameter holds an error object that describes the error.
 @discussion This building identifier is provided by Phunware and can be found in the Location area of the MaaS portal.
 */
- (void)getBuildingWithBuildingID:(NSInteger)buildingID completion:(PWBuildingHandler)completion;

/**
 Initiates a fetch for the building annotations. If the building annotations are not cached locally, this will result in a network request.
 @param buildingID The building identifier.
 @param completion A block that takes the following parameters:
 
 - *annotations*: The building annotations.
 - *error*: If the building fetch completed successfully, this parameter is `nil`; otherwise, this parameter holds an error object that describes the error.
 @discussion This building identifier is provided by Phunware and can be found in the Location area of the MaaS portal.
 */
- (void)getBuildingAnnotationsWithBuildingID:(NSInteger)buildingID completion:(PWBuildingAnnotationsHandler)completion;

/**
 Initiates a fetch for the building resources. If the building resources are not cached locally, this will result in a network request.
 @param building The specified building object.
 @param completion A block that takes the following parameters:
 
 - *resources*: The building resources as an array of `PWMapDocument` objects.
 - *error*: If the building fetch completed successfully, this parameter is `nil`; otherwise, this parameter holds an error object that describes the error.
 @discussion This building identifier is provided by Phunware and can be found in the Location area of the MaaS portal.
 */
- (void)getResourcesForBuilding:(PWBuilding *)building completion:(PWBuildingResourcesHandler)completion;

/**
 Initiates a fetch for the anotation types. If the annotation types are not cached locally, this will result in a network request.
@param completion A block that takes the following parameters:

 - *types*: The annotation types as an array of `PWAnnotationType` objects.
 - *error*: If the annotation type fetch completed successfully, this parameter is `nil`; otherwise, this parameter holds an error object that describes the error.
 */
- (void)getBuildingAnnotationTypesWithCompletion:(PWBuildingAnnotationTypesHandler)completion;

/**
 Clears the device cache of all mapping data. This will clear all associated building objects, floor objects and floor assets from the device.
 */
- (void)clearCache;

@end