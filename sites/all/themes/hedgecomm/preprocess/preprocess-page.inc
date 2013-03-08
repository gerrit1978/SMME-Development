<?php

/**
 * @file
 * Preprocess page variables
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_page(&$vars) {

  /** HOMEPAGE **/
  if (drupal_is_front_page()) {
    $vars['title'] = "";
  }

	/** MAIN CATALOG PAGE **/
  if (arg(0) == 'catalog') {
    $vars['title'] = "";
  }
  
  
  /** CATALOG PAGE "SUBJECT" (e.g. ITIL) **/
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $vars['title'] = "";
  }
  
  /** COURSE DETAIL PAGE **/
  if (isset($vars['node']) && $vars['node']->type == 'course') {
    $vars['title'] = "";
  }
}