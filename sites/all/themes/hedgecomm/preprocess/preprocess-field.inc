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
        $label = t('Where in the world is @title?', array('@title' => $firstname));
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
      'title' => 'SMME USA',
      'lat' => '33.31130',
      'lng' => '-111.97722',
      'description' => '<strong>SMME USA</strong><br />4809 E Thistle Landing Dr, Ste 100<br />Phoenix, AZ 85044<br/>United States<br />480-285-1652',
    );
    $markers['AS'] = array(
      'title' => 'SMME Middle East',
      'lat' => '25.10205',
      'lng' => '55.16095',
      'description' => '<strong>SMME Middle East</strong><br />Office F07, Block 12<br />Dubai Knowledge Village<br />United Arab Emirates<br />971-4-882-4453',
    );
    $markers['EU'] = array(
      'title' => 'SMME Europe',
      'lat' => '50.84925',
      'lng' => '4.73648',
      'description' => '<strong>SMME Europe</strong><br />Interleuvenlaan 62<br />3001 Heverlee<br />Belgium<br />32-16-39-47-94',
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
  
  // add course details for landing page
  if ($field_name == 'field_land_page_intro_desc') {
    if (arg(0) == 'node' && is_numeric(arg(1))) {
      // require price formatting file
      $path = drupal_get_path('module', 'commerce_extra_price_formatters');
      require_once($path . "/includes/extra_functions.inc");
    
      $landing_page_nid = arg(1);
      $landing_page_wrapper = entity_metadata_wrapper('node', $landing_page_nid);

      // get course title
      $course_field = $landing_page_wrapper->field_landing_page_course->value();
      $course_title = $course_field->title;
      
      $variation_wrapper = entity_metadata_wrapper('commerce_product', $landing_page_wrapper->field_landing_page_course_varia->value());
      $variation_location = $variation_wrapper->field_public_course_location->value();
      $variation_date = $variation_wrapper->field_public_course_date_format->value();
      
      $variation_price = $variation_wrapper->commerce_price->value();
      $variation_price_amount = intval($variation_price['amount']);
      $variation_price_formatted = commerce_extra_price_no_decimal_currency_format($variation_price_amount, $variation_price['currency_code']);

      $price_reduced = $landing_page_wrapper->field_landing_page_reduced_price->value();
      
      $output = "<h3>" . $course_title . "</h3>"
        . "<div class='large'>" . $variation_location . " - " . $variation_date . " - <span class='original'>" . $variation_price_formatted . "</span> <span class='reduced'>" . $price_reduced . "</span>";
      
    }
    $vars['items'][] = array(
      '#prefix' => '<div class="extra">',
      '#markup' => $output,
      '#suffix' => '</div>'
      
    );
  }
  
  // add automated contact links to landing page
  if ($field_name == 'field_landing_page_call_action') {
  
    if (arg(0) == 'node' && is_numeric(arg(1))) {
      $landing_page_nid = arg(1);
      $landing_page_wrapper = entity_metadata_wrapper('node', $landing_page_nid);
      
      $coupon = $landing_page_wrapper->field_landing_page_coupon->value();
      
      $course_wrapper = $landing_page_wrapper->field_landing_page_course->value();
      $course_nid = $course_wrapper->nid;
      
      $course_variation_wrapper = $landing_page_wrapper->field_landing_page_course_varia->value();
      $product_id = $course_variation_wrapper->product_id;
   	  $link = "<a rel='resizable:false;position:[center,60]' class='simple-dialog' name='block-system-main' href='/book-this-course?nid=" . $course_nid . "&pid=" . $product_id . "&coupon=" . $coupon . "'>Book this</a>";

    }

	  foreach ($vars['items'] as $item) {
	    $markup = $item['#markup'];
	    $markup_changed = str_replace("[BOOK_LINK]", $link, $markup);
	    $vars['items'] = array(
	      '#markup' => $markup_changed,
	    );
	  }

  }


}