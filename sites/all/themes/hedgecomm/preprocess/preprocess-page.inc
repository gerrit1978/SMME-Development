<?php

/**
 * @file
 * Preprocess page variables
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_page(&$vars) {

	/** MAIN CATALOG PAGE **/
  if (arg(0) == 'catalog') {
    $vars['title'] = "";
  }
  
  
  /** CATALOG PAGE "SUBJECT" (e.g. ITIL) **/
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $vars['title'] = "";
    $term_wrapper = entity_metadata_wrapper('taxonomy_term', arg(2));
    if (isset($term_wrapper->field_catalog_bg_color)) {
      $field_catalog_bg_color = $term_wrapper->field_catalog_bg_color->value();
      // Doe hier nog iets mee in de page (uit te zoeken wat)
    }

  }
  

}