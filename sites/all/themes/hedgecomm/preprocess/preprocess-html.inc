<?php

/**
 * @file
 * Preprocess html variables
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_html(&$vars) {

  /** ADD COLOR TO BODY CLASSES FOR COURSES **/
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node_wrapper = entity_metadata_wrapper('node', arg(1));
    if ($node_wrapper->type->value() == 'course') {
      $color_field = $node_wrapper->field_color->value();
      if (isset($color_field->name)) {
        $vars['attributes_array']['class'][] = $color_field->name;
      }
    }
  }
  
  /** ADD COLOR TO BODY CLASSES FOR SUBJECT PAGES (Taxonomy Term) **/
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $term_wrapper = entity_metadata_wrapper('taxonomy_term', arg(2));
    $color_field = $term_wrapper->field_color->value();
    if (isset($color_field->name)) {
      $vars['attributes_array']['class'][] = $color_field->name;
    }
  }
  
  /** ADD COLOR TO BODY CLASSES FOR LANDING PAGES **/
    if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node_wrapper = entity_metadata_wrapper('node', arg(1));
    if ($node_wrapper->type->value() == 'landing_page') {
      $color_field = $node_wrapper->field_color->value();
      if (isset($color_field->name)) {
        $vars['attributes_array']['class'][] = $color_field->name;
      }
    }
  }
  
  if (arg(0) == 'deals') {
    $vars['attributes_array']['class'][] = "green1";  
  }

  if (arg(0) == 'goodies') {
    $vars['attributes_array']['class'][] = "yellow1";  
  }
  
  if (arg(0) == 'node' && arg(1) == 40) {
    $vars['attributes_array']['class'][] = "blue1";    
  }

  
  /** PAGE TITLES **/
  if (arg(0) == 'book-a-course') {
    $vars['head_title'] = t("Book a Course at SMME");
  }
  if (arg(0) == 'team') {
    $vars['head_title'] = t("Meet the Team at SMME");  
  }
  if (arg(0) == 'catalog') {
    $vars['head_title'] = t("Training Catalog at SMME");  
  }
  if (arg(0) == 'news') {
    $vars['head_title'] = t("Blog at SMME");  
  }
  
  if (drupal_is_front_page()) {
    $vars['head_title'] = "SMME - Your IT Management Training Partner";
  }
  
  /** APPLE TOUCH ICON **/
/*
  $appleIcon_default = array(
    '#tag' => 'link', '#attributes' => array('href' => '/sites/all/themes/hedgecomm/img/apple/apple_touch_icon_a.png', 'rel' => 'apple-touch-icon'),
  );
  $appleIcon_a = array(
    '#tag' => 'link', '#attributes' => array('href' => '/sites/all/themes/hedgecomm/img/apple/apple_touch_icon_a.png', 'rel' => 'apple-touch-icon', 'sizes' => '72x72'),
  );
  $appleIcon_b = array(
    '#tag' => 'link', '#attributes' => array('href' => '/sites/all/themes/hedgecomm/img/apple/apple_touch_icon_b.png', 'rel' => 'apple-touch-icon', 'sizes' => '114x114'),
  );
  $appleIcon_c = array(
    '#tag' => 'link', '#attributes' => array('href' => '/sites/all/themes/hedgecomm/img/apple/apple_touch_icon_c.png', 'rel' => 'apple-touch-icon', 'sizes' => '144x144'),
  );

  drupal_add_html_head($appleIcon_default, 'apple-touch-icon');  
  drupal_add_html_head($appleIcon_a, 'apple-touch-icon');
  drupal_add_html_head($appleIcon_b, 'apple-touch-icon');
  drupal_add_html_head($appleIcon_c, 'apple-touch-icon');     
*/
}