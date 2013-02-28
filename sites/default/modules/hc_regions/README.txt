This module provides the region functionality for SMME.
A region is currently defined as a continent (America - Europe - Asia), to represent the three HQ's of SMME: Phoenix AZ, Brussels, Dubai.

This region module does a few things:

- it adds a $_SESSION['user_location'] variable. First, by using the ip2country-module. This session variable can be overriden
  by using the "region_selection" block, also provided by this module
- it alters the default views for training courses/packages. By default, only the courses for the current selected region are shown
  to users
- it alters the view mode and Add to Cart form for specific products (currently team packages in Europe & Asia), in that way that the 
  prices are not shown
  
# http://drupal.org/node/1259914