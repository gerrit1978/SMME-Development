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
 
function hedgecomm_preprocess_entity(&$vars) {

  if ($vars['elements']['#bundle'] == 'field_block') {
    $entity_id = $vars['elements']['field_block_title']['#object']->item_id;
    
    $vars['attributes_array']['id'] = "text_block_" . $entity_id;
    
    $block_wrapper = entity_metadata_wrapper('field_collection_item', $entity_id);
    $highlight_field = $block_wrapper->field_block_highlight->value();
    if ($highlight_field) {
      $vars['classes_array'][] = "highlighted";
    }
	}
}

function hedgecomm_views_mini_pager($vars) {
  global $pager_page_array, $pager_total;

  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];

  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  if ($pager_total[$element] > 1) {

    $li_previous = theme('pager_previous', 
      array(
      'text' => "Previous&nbsp;<i class='icon-circle-arrow-left'></i>", 
      'element' => $element, 
      'interval' => 1, 
      'parameters' => $parameters,
    )
    );
    if (empty($li_previous)) {
      $li_previous = "<div class='blog-pager-inactive'>Previous&nbsp;<i class='icon-circle-arrow-left'></i></div>";
    }

    $li_next = theme('pager_next', 
      array(
      'text' => "<i class='icon-circle-arrow-right'></i>&nbsp;Next", 
      'element' => $element, 
      'interval' => 1, 
      'parameters' => $parameters,
    )
    );

    if (empty($li_next)) {
      $li_next = "<div class='blog-pager-inactive'><i class='icon-circle-arrow-right'></i>&nbsp;Next</div>";
    }

    $items[] = array(
      'class' => array('pager-previous'), 
      'data' => $li_previous,
    );


    $items[] = array(
      'class' => array('pager-next'), 
      'data' => $li_next,
    );
    return theme('item_list', 
      array(
      'items' => $items, 
      'title' => NULL, 
      'type' => 'ul', 
      'attributes' => array('class' => array('pager')),
    )
    );
  }
}


function hedgecomm_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($_GET['q'], array('query' => $query));
  return '<a' . drupal_attributes($attributes) . '>' . $text . '</a>';

}