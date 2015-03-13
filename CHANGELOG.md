#PWMapKit Changelog

##v2.4.0 (Friday, March 13th, 2015)

* Added the ability to enable and disable annotation zoom levels. See the `annotationZoomLevelsEnabled` property on `PWMapView` for more information.
* Added the ability for users to add and remove `PWBuildingAnnotation` objects to and from the map view. NOTE: When adding or removing annotations, only `annotationID` equality will be checked.
* Fixed a bug where inaccessible routes were sometimes returned for accessible-only requests.
* Fixed a bug where routing between two points on the same floor would sometimes return a route that spanned multiple floors.
* Fixed a bug where setting `showsIndoorUserLocation` on `PWMapView to ‘NO’ would not hide the blue dot.
* Fixed a bug where toggling route snapping tolerance would not resume route snapping when reenabled.
* Added the ability to stop loading a building. See `stopLoadingBuilding` method on `PWMapView` for more information.
* Fixed a bug where memory for the routing graph wasn't being released when the `PWMapView` instance was being deallocated. 
* Fixed a bug where building assets would get ‘stuck’ while the user’s blue dot continued to move during a route across multiple floors (with a valid indoor location).
* Added a flag to `PWBuildingAnnotationProtocol`, `occlusionEnabled`. This flag determines whether the annotation label for a given annotation will be occluded by other labels. If `occlusionEnabled` is set to `NO`, the annotation label will **always** be visible.
* `PWMapView` now correctly calls the delegate callback ` -mapView:didChangeIndoorUserTrackingMode:`.
* Added options that allow routing from any point of interest, user location or dropped pin annotation to any other point of interest, user location or dropped pin annotation (in other words, any type of route endpoint is now allowed on either end of the route). See `PWDirections` and `PWDirectionsWaypointProtocol` for more information.
* Enhanced routing functionality now uses a synchronous directions request interface. The former asynchronous request/response model is still supported but will be deprecated. 
* Renamed `PWBuildingOverlayDelegate` to `PWBuildingOverlayDelegateProtocol`.
* Deprecated the old indoor location manager registration interface in favor of a more simply named method with accompanying unregister method. 
* Removed the `-setCurrentFloor:` PWMapView property mutator declaration and removed the `readonly` attribute of the property. 

##v2.3.1 (Monday, March 2nd, 2015)
* Fixed bug where when routing across multiple floors with a valid indoor location the build asset would get 'stuck' while the blue dot continued to move.
* Updated `PWRouteOverlayRenderer` initializer to accept a building overlay as part of initialization: `- (instancetype)initWithRouteOverlay:(PWRouteOverlay *)overlay buildingOverlay:(PWBuildingOverlay *)buildingOverlay`

##v2.3.0 (Thursday, January 29th, 2015)
* Added new "blue dot smoothing" functionality to provide a better user location tracking experience.
* Added `blueDotSmoothingEnabled` boolean property to `PWMapView` for turning blue dot smoothing on and off.
* Added `routeSnappingTolerance` enumeration property to `PWMapView` for turning off route snapping or setting a different tolerance.
* Added a **temporary** iOS 8 mapping zoom level workaround that will be removed as soon as Apple fixes their zoom level inadequacies.  Using the zoom level is explicit (not based on user-specified zoom scale) and is changed using the `-toggleZoomWorkaround` method.  The property `isUsingZoomWorkaround` indicates the current state of use of this workaround.  When in use, the workaround draws building assets at 4x their usual size and points of interest are repositioned accordingly.
* Added KVO notifications to the `PWMapView` property `indoorUserTrackingMode`.
* Added a `buildingAnnotations` property on `PWMapView` that contains all points of interest for the current building.
* Added `showBuildingAnnotation:animated:` method that focuses the map view to the provided annotation with optional animation. NOTE: This method will not work for object copies of POIs obtained from the building manager or elsewhere.  In order to find an annotation by identifier, name, or other property, simply search the `buildingAnnotations` property.  This method will automatically change floors on the map if necessary.  It will also zoom in to the maximum zoom level.
* `PWMapView` now honors the `maxZoomLevel` parameter for `PWBuildingAnnotation` objects
* You no longer need to manage the annotation image at the application level. `PWBuildingAnnotationView` now manages caching and loading of the annotation image internally.
* Building floors are now ordered in ascending order based on the `floorLevel` value.
* The `PWMapView` now only loads annotations for the current floor. The previous behavior was to load all building annotations and show/hide as necessary. `mapView.annotations` will now only return annotations for the current floor. If you would like to use all building annotations please use the `buildingAnnotations` property.
* You can now switch to `PWIndoorUserTrackingModeFollowWithHeading` while in routing mode. Note that the default indoor user tracking mode is still `PWIndoorUserTrackingModeFollow`.
* Consolidated all cached mapping data into one cache directory under `Library/Caches`.
* Mapping data cache expiration bumped to 24 hours. It was previously incorrectly set to 1.75 hours.
* Cleaned up public interfaces, removing extraneous and non-functional methods.
* Floor change no longer breaks the current indoor user tracking mode. See Wiki for additional details on user tracking behavior.
* Many bug fixes and performance enhancements
* Small updates to sample code

##v2.2.0 (Friday, October 31st, 2014)
* Promoting BETA 2 to GA candidate

##v2.2.0 BETA 2 (Wednesday, October 29th, 2014)
* Fixed issue where `imageURL` property on a PWBuildingAnnotation would sometimes return `nil`
* Fixed issue where POI icon image would not display on first load under certain memory constrained conditions
* Updated sample app to resolve to some routing centering issues

##v2.2.0 BETA (Monday, October 27th, 2014)
* `PWAnnotation` (protocol) renamed to `PWAnnotationProtocol`
* Added `PWAnnotationType`
* `PWBuilding`
* No longer conforms to NSCopying
* No longer conforms to NSSecureCoding
* Atomicized and write-protected properties
* Formalized building and campus identifier types
* `PWBuildingAnnotation` (protocool) renamed to `PWBuildingAnnotationProtocol`
* `PWBuildingFloor`
* Atomicized and write-protected properties
* Formalized building and campus identifier types
* `PWBuildingFloorReference`
* No longer conforms to NSCopying
* No longer conforms to NSSecureCoding
* Atomicized and write-protected properties
* `PWBuildingFloorResource`
* No longer conforms to NSCopying
* No longer conforms to NSSecureCoding
* Atomicized and write-protected properties
* `PWBuildingManager`
* Added method for fetching annotation types: `-(void)getBuildingAnnotationTypesWithCompletion:(PWBuildingAnnotationTypesHandler)completion`
* `PWBuildingOverlay`
* Atomicized properties
* `PWMapView`
* Added `-(void)willAppear` and `-(void)didAppear`. These properties should be used in conjunction with `UIViewController` methods.
* `PWMapViewDelegate` (protocol) renamed to `PWMapViewDelegateProtocol`
* `PWRouteStep`
* Added `annotations` property

##v2.1.2 (Tuesday, October 7th, 2014)
 * Fixed issue where building annotation callout view displaying would cause strange behavior on iOS 8
 * Small bug fixes and optimiziations

##v2.1.1 (Friday, September 18th, 2014)
 * General availability for native mapping SDK. See README.md for integration details.

##v2.1.1 BETA (Friday, August 15th, 2014)
 * Added support for labels in PWBuildingAnnotationView
 * Added support for real-time dynamic label occlusion
 * Added support for Phunware zoom levels. See POI details in MaaS portal to configure.

##v2.1.0 BETA (Friday, August 1st, 2014)
 * Removed location providers from PWMapKit and added to PWLocation SDK.
 * PWMapKit now has a dependency on PWLocation
 * Several bug fixes related to map positioning

##v2.0.3 BETA (Friday, July 10th, 2014)
 * Fixed crashing issue with `registerLocationManagerForIndoorLocationUpdates` method.
 * Fixed issue where multiple navigation annotations were appearing on the map view when scrolling
 * Fixed crashing issue in sample related to route view controller

##v2.0.2 BETA (Thursday, July 9th, 2014)
 * Native mapping beta release

##v1.0.0 (Wednesday, January 1st, 2014)
 * Initial release