<?php

/**
 * @file
 * Preprocess page variables
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_page(&$vars) {

  if (arg(0) == 'catalog') {
    $vars['title'] = "";
  }

}