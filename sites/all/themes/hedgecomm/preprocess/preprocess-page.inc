<?php

/**
 * @file
 * Preprocess page variables
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_page(&$vars) {

  // currently: all page titles disabled! NEH!
  $vars['title'] = "";


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
  
  /** LANDING PAGE DETAIL **/
  if (isset($vars['node']) && $vars['node']->type == 'landing_page') {
    $vars['title'] = "";
  }

  /** MAIN TEAM PAGE **/
  if (arg(0) == 'team') {
    $vars['title'] = "";
  }

  
  /** TEAM DETAIL PAGE **/
  if (isset($vars['node']) && $vars['node']->type == 'team_member') {
    $vars['title'] = "";
  }
  

  /** BOOK A COURSE PAGE **/
  if (arg(0) == 'book-a-course') {
    $vars['title'] = "";
  }
  
  /** CONTACT PAGE **/
  if (isset($vars['node']) && $vars['node']->nid == 66) {
    $vars['title'] = "";
  }

  /** TEAM PAGE **/
  if (isset($vars['node']) && $vars['node']->nid == 83) {
    $vars['title'] = "";
  }
  
  /** NEWS PAGE **/
  if (arg(0) == 'news') {
    $vars['title'] = "";
  }
  
}