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
}