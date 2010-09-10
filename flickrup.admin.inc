<?php
/**
 * Menu/form callback. Settings form
 */
function flickrup_admin_settings() {
  $form['flickr_api_token'] = array(
    '#type' => 'textfield',
    '#title' => t('API Auth token'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_api_token', ''),
    '#description' => t('API Auth Token from Flickr with \'write\' permission'),
  );    
  $form['flickr_global_tag'] = array(
    '#type' => 'textfield',
    '#title' => t('Global Flickr tags'),
    '#required' => TRUE,
    '#default_value' => variable_get('flickr_global_tag', ''),
    '#description' => t('Enter space separated global tags to apply to all the uploads from this site.'),
  );
  $form['flickrup_remove'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete photos from Flickr when they are removed from a node'),
    '#default_value' => variable_get('flickrup_remove', ''),
  );
  
  // Upload options
  $form['upload'] = array('#type' => 'fieldset', '#title' => t('Upload options'));
  $form['upload']['flickr_upload_fields'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of upload fields'),
    '#default_value' => variable_get('flickr_upload_fields', 1),
    '#description' => t('Enter the number of image fields for the upload form. Be warned that this may have an important impact on server performance. The minimum number is 1'),
  );
  $form['upload']['flickr_upload_public'] = array(
    '#type' => 'radios',
    '#title' => t('Upload mode'),
    '#options' => array(t('Private'), t('Public')),
    '#default_value' => variable_get('flickr_upload_public', 1),
    '#description' => t('Select whether you want your uploaded images to be private or public'),
  );
  $form['upload']['flickr_upload_async'] = array(
    '#type' => 'checkbox',
    '#title' => t('Asynchronous uploading'),
    '#default_value' => variable_get('flickr_upload_async', 0),
    '#description' => t('Enable asynchronous uploading to Flickr to speed up the page request. This should be faster but we won\'t be able to control whether the Flickr upload has worked or not.'),
  );
  $form['upload']['flickr_upload_delete'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete images from server'),
    '#default_value' => variable_get('flickr_upload_delete', 0),
    '#description' => t('Delete images from the web server after uploading them to Flickr. This is currently not compatible with asynchronous uploading.'),
  );
  // Check whether the picture directory exists:
  $picture_path = file_create_path(variable_get('flickr_picture_path', 'flickr'));
  file_check_directory($picture_path, 1, 'flickr_picture_path');
  
  // Image file settings
  $form['pictures'] = array('#type' => 'fieldset', '#title' => t('Photos'));
  
  $form['pictures']['flickr_picture_path'] = array('#type' => 'textfield', '#title' => t('Photo image path'), '#default_value' => variable_get('flickr_picture_path', 'flickr'), '#size' => 30, '#maxlength' => 255, '#description' => t('Subdirectory in the directory %dir where pictures will be stored.', array('%dir' => file_directory_path() .'/')));
  
  $form['pictures']['flickr_picture_dimensions'] = array('#type' => 'textfield', '#title' => t('Photo maximum dimensions'), '#default_value' => variable_get('flickr_picture_dimensions', '800x600'), '#size' => 15, '#maxlength' => 10, '#description' => t('Maximum dimensions for pictures, in pixels.'));
  
  $form['pictures']['flickr_picture_file_size'] = array('#type' => 'textfield', '#title' => t('Photo maximum file size'), '#default_value' => variable_get('flickr_picture_file_size', '1000'), '#size' => 15, '#maxlength' => 10, '#description' => t('Maximum file size for pictures, in kB.'));
 
  $form['flickr_node_view'] = array(
    '#type' => 'radios',
    '#title' => t('Show images for nodes'),
    '#options' => array(
      'none' => t('Do not show'), 
      'body' => t('Show in the node body'), 
      'tab' => t('Show in a different tab')
     ),
    '#default_value' => variable_get('flickr_node_view', 'tab'),
    '#description' => t('Select whether you want to display images with the content they were uploaded for.'),
  );
  return system_settings_form($form);  
}
