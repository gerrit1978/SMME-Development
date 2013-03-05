<?php
/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
 
function hedgecomm_preprocess_field_collection_item(&$vars) {
 exit('hier');
}
 
function hedgecomm_preprocess_entity(&$vars) {

  if ($vars['elements']['#bundle'] == 'field_block') {
    $entity_id = $vars['elements']['field_block_title']['#object']->item_id;
    $block_wrapper = entity_metadata_wrapper('field_collection_item', $entity_id);
    $highlight_field = $block_wrapper->field_block_highlight->value();
    if ($highlight_field) {
      $vars['classes_array'][] = "highlighted";
    }
	}
}