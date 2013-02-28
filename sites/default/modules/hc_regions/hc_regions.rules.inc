<?php

/**
* Implementation of hook_rules_condition_info().
*/
function hc_regions_rules_condition_info() {
  return array(
    'hc_regions_surfing_from_usa' => array(
      'group' => 'HC Region',
      'label' => t('User is surfing from USA'),
      'module' => 'hc_regions',
    ),
    'hc_regions_surfing_from_europe' => array(
      'group' => 'HC Region',
      'label' => t('User is surfing from Europe'),
      'module' => 'hc_regions',
    ),
    'hc_regions_surfing_from_asia' => array(
      'group' => 'HC Region',
      'label' => t('User is surfing from Asia'),
      'module' => 'hc_regions',
    ),
    
  );
}




/**
 * Callback functions for rules
 */
function hc_regions_surfing_from_usa() {

	$user_location = $_SESSION['user_location'];
	
	if (isset($user_location['continent_code']) && $user_location['continent_code'] == 'NA') {
	  return TRUE;
	}
	
	return FALSE;

}


function hc_regions_surfing_from_europe() {

	$user_location = $_SESSION['user_location'];
	
	if (isset($user_location['continent_code']) && $user_location['continent_code'] == 'EU') {
	  return TRUE;
	}
	
	return FALSE;

}


function hc_regions_surfing_from_asia() {

	$user_location = $_SESSION['user_location'];
	
	if (isset($user_location['continent_code']) && $user_location['continent_code'] == 'AS') {
	  return TRUE;
	}
	
	return FALSE;

}