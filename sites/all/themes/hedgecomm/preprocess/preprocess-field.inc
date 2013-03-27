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
      $field_name == 'field_team_video_description' ||
      $field_name == 'field_global_region') {
    $firstname = "";
    if (arg(0) == 'node' && is_numeric(arg(1))) {
      $node = node_load(arg(1));
      
      // get firstname
      $firstname_field = field_get_items('node', $node, 'field_team_firstname');
      if (isset($firstname_field[0]['value'])) {
	      $firstname = $firstname_field[0]['safe_value'];
      }
    }
    
    switch ($field_name) {
      case 'field_team_about':
      default: 
        $label = t('About @title', array('@title' => $firstname));
        break;
      case 'field_team_certifications':
        $label = t('Certifications Held by @title', array('@title' => $firstname));
        break;
      case 'field_team_accreditations':
        $label = t('Instructor Accreditations Held by @title', array('@title' => $firstname));
        break;
      case 'field_team_video_description':
        $label = t('@title in action', array('@title' => $firstname));
        break;
      case 'field_global_region':
        $label = t('Where in the World is @title', array('@title' => $firstname));
    }
    
    $vars['label'] = $label;
  }
  
  // google map output for region field on team members
  if ($field_name == 'field_global_region' && isset($vars['element']['#bundle']) && $vars['element']['#bundle'] == 'team_member') {
    $node = $vars['element']['#object'];
    $region_field = field_get_items('node', $node, 'field_global_region');
    
    // define markers, see http://www.svennerberg.com/2012/03/adding-multiple-markers-to-google-maps-from-json/
    $markers = array();
    $markers_json = array();
    $output_markers = "";

    $markers['NA'] = array(
      'title' => 'SMME America',
      'lat' => '33.31130',
      'lng' => '-111.97722',
      'description' => '<strong>SMME America</strong><br />4809 East Thistle Landing Drive #100<br />Phoenix, AZ 85044, United States<br />(480) 285-1652',
    );
    $markers['AS'] = array(
      'title' => 'SMME Asia',
      'lat' => '25.10205',
      'lng' => '55.16095',
      'description' => '<strong>SMME Asia</strong><br />Knowledge Village, Block 12, Office F-07 <br />Dubai, United Arab Emirates<br />+971 4 882 4453',
    );
    $markers['EU'] = array(
      'title' => 'SMME Europe',
      'lat' => '50.84925',
      'lng' => '4.73648',
      'description' => '<strong>SMME Europe</strong><br />Interleuvenlaan 62<br />3001 Heverlee, Belgium<br />+32 (0)16 39 47 94',
    );
    
    // all three regions?
    if (is_array($region_field) && count($region_field) == 3) {
      $vars['center_lat'] = "50.84925";
      $vars['center_long'] = "4.73648";
      $vars['zoom'] = 1;
      $markers_json = json_encode(array($markers['NA'], $markers['AS'], $markers['EU']));
      $vars['output_json'] = $markers_json;
    }
    
    if (is_array($region_field) && count($region_field) == 1) {
      if ($region_field[0]['value'] == 'AS') {
        $vars['center_lat'] = "25.10205";
        $vars['center_long'] = "55.16095";
        $vars['zoom'] = 12;
	      $markers_json = json_encode(array($markers['AS']));
	      $vars['output_json'] = $markers_json;
      }
      
      if ($region_field[0]['value'] == 'EU') {
        $vars['center_lat'] = "50.84925";
        $vars['center_long'] = "4.73648";
        $vars['zoom'] = 12;
	      $markers_json = json_encode(array($markers['EU']));
	      $vars['output_json'] = $markers_json;
      }
      
      if ($region_field[0]['value'] == 'NA') {
        $vars['center_lat'] = "33.31130";
        $vars['center_long'] = "-111.97722";
        $vars['zoom'] = 12;
	      $markers_json = json_encode(array($markers['NA']));
	      $vars['output_json'] = $markers_json;
      }
    }
    
    if (is_array($region_field) && count($region_field) == 2) {
      $regions = array();
      foreach($region_field as $item) {
        $regions[$item['value']] = $item['value'];
      }

      if (isset($regions['AS']) && isset($regions['EU'])) {
        $vars['center_lat'] = "50.84925";
        $vars['center_long'] = "4.73648";
        $vars['zoom'] = 1;
	      $markers_json = json_encode(array($markers['AS'], $markers['EU']));
	      $vars['output_json'] = $markers_json;
      }

      if (isset($regions['AS']) && isset($regions['NA'])) {
        $vars['center_lat'] = "50.84925";
        $vars['center_long'] = "4.73648";
        $vars['zoom'] = 1;
	      $markers_json = json_encode(array($markers['AS'], $markers['NA']));
	      $vars['output_json'] = $markers_json;
      }

      if (isset($regions['EU']) && isset($regions['NA'])) {
        $vars['center_lat'] = "50.84925";
        $vars['center_long'] = "4.73648";
        $vars['zoom'] = 1;
	      $markers_json = json_encode(array($markers['NA'], $markers['EU']));
	      $vars['output_json'] = $markers_json;
      }

    }
    
  }

}