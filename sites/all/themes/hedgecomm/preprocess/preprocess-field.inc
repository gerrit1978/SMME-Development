<?php

/**
 * @file
 * Preprocess field variables (and labels)
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_field(&$vars) {

/*
  $vars['highlight_array'] = array();

  // load taxonomy term for catalog subject pages
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $tid = arg(2);
    $term_wrapper = entity_metadata_wrapper('taxonomy_term', $tid);
    $term_name = $term_wrapper->name->value();
  }

  $field_name = $vars['element']['#field_name'];
 
  // highlight blocks 
  if ($field_name == 'field_block') {
    $vars['highlight_array'] = array();
  
    foreach ($vars['items'] as $delta => $item) {
	    $field_collection_items = $item['entity']['field_collection_item'];
	    foreach ($field_collection_items as $field_collection_id => $field_collection_item) {
        $field_collection_wrapper = entity_metadata_wrapper('field_collection_item', $field_collection_id);
        $highlighted = $field_collection_wrapper->field_block_highlight->value();
        $vars['highlight_array'][$delta] = "";
        if ($highlighted) {
          $vars['highlight_array'][$delta] = "highlighted";
        } 
	    }
    }
  }
*/
  
}