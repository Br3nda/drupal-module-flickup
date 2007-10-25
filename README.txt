Drupal Module: Flickr Upload

This is a simple module to upload images to Flickr and show them with your content

Author
======
Jose A. Reyero, drupal at reyero dot net
Development Seed, http://www.developmentseed.org

Flickr Upload module features:
==============================
- Allows uploading images to Flickr from your site.
- Images can be linked to nodes using per content type settings.
- Tags can be configured globally or using node parameters.

Requirements
============
- Drupal 5
- Drupal's Flickr module, http://drupal.org/project/flickr
- phpFlickr, http://phpflickr.com/

Installation
============
1. Place the module with all its files under sites/all/modules/flickrup
2. Download phpFlickr from http://phpflickr.com/ 
   and place it in a 'phpFlickr' subfolder in the module directory

Configuration
=============
- Enable the module in: Administer > Site building > Modules
- Set the module settings in: Administer > Site configuration > Flickr Upload
* In adition to your normal flickr settings this module needs a Flickr authentication token with write permissions for your account. 
  If you don't know how to get one, follow the steps here: http://phpflickr.com/tools/auth
- Enable uploads for your content types in: Administer > Content > Content types

Module overview: 
http://www.developmentseed.org/blog/2007/oct/24/unlimited-images-your-content-drupal-and-flickr

Notes
=====
- The images are uploaded first to the web server, then from there to your Flickr account. 
  This may have some important performance impact on the web server, so please review carefully the module settings for production servers.
- This module uses phpFlickr http://phpflickr.com/, to interact with the Flickr API
- For cleaning up the tags this module uses some pathauto variables, see flickrup_cleanstring()

 