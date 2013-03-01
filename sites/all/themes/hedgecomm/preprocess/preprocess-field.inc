<?php

/**
 * @file
 * Preprocess field variables (and labels)
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_field(&$vars) {

  // load taxonomy term for catalog subject pages
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $tid = arg(2);
    $term_wrapper = entity_metadata_wrapper('taxonomy_term', $tid);
    $term_name = $term_wrapper->name->value();
  }

  $field_name = $vars['element']['#field_name'];

  if ($field_name == 'field_catalog_what') {
		$vars['label'] = t('What is @subject?', array('@subject' => $term_name));
  }

  if ($field_name == 'field_catalog_where') {
		$vars['label'] = t('Where does @subject come from?', array('@subject' => $term_name));  
  }

  if ($field_name == 'field_catalog_who') {
		$vars['label'] = t('Who is @subject for?', array('@subject' => $term_name));  
  }
}