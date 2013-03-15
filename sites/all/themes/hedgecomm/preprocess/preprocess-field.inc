<?php

/**
 * @file
 * Preprocess field variables (and labels)
 */

/**
 * Implements THEME_preprocess_HOOK
 */
function hedgecomm_alpha_preprocess_field(&$vars) {

  $field_name = $vars['element']['#field_name'];

  // change labels for team page
  if ($field_name == 'field_team_about' || 
      $field_name == 'field_team_certifications' || 
      $field_name == 'field_team_accreditations' || 
      $field_name == 'field_team_video_description') {
    if (arg(0) == 'node' && is_numeric(arg(1))) {
      $node = node_load(arg(1));
      $title = $node->title;
    }
    
    switch ($field_name) {
      case 'field_team_about':
      default: 
        $label = t('About @title', array('@title' => $title));
        break;
      case 'field_team_certifications':
        $label = t('Certifications for @title', array('@title' => $title));
        break;
      case 'field_team_accreditations':
        $label = t('Accreditations for @title', array('@title' => $title));
        break;
      case 'field_team_video_description':
        $label = t('@title in action', array('@title' => $title));
    }
    
    $vars['label'] = $label;
  }

}