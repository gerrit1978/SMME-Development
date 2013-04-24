<?php

/**
 * TODO: move this to a preprocess function
 */
 
// get nid from current course
if (arg(0) == 'node' && is_numeric(arg(1))) {
  $course_nid = arg(1);
}

$user_location = $_SESSION['user_location'];
$continent_code = $user_location['continent_code'];

if (is_array($view->result)) {
  foreach ($view->result as $key => $row) {

    // find product price
    $product_id = $row->product_id;
    $variation_wrapper = entity_metadata_wrapper('commerce_product', $product_id);
    $variation_price = $variation_wrapper->commerce_price->value();
    
    $variation_price_int = intval($variation_price['amount']);
    $variation_price_corrected = $variation_price_int / 100;

    $default_price = 0;
    $highlight_class = "";

    switch ($continent_code) {
      case 'EU':
        $result = db_query("SELECT d.field_course_header_block_pr_eu_value FROM field_data_field_course_header a, field_data_field_course_header_blocks b, field_data_field_course_header_block_type c, 
          field_data_field_course_header_block_pr_eu d 
         WHERE a.entity_id =:course_nid and a.field_course_header_revision_id = b.entity_id 
         AND b.field_course_header_blocks_revision_id = c.entity_id 
         AND b.field_course_header_blocks_revision_id = d.entity_id
         AND c.field_course_header_block_type_value = 'price';", array(':course_nid' => $course_nid));

         foreach ($result as $row) {
           $default_price = $row->field_course_header_block_pr_eu_value;
         }
        break;
        case 'NA':
          $result = db_query("SELECT d.field_course_header_block_pr_usa_value FROM field_data_field_course_header a, field_data_field_course_header_blocks b, field_data_field_course_header_block_type c, 
            field_data_field_course_header_block_pr_usa d 
           WHERE a.entity_id =:course_nid and a.field_course_header_revision_id = b.entity_id 
           AND b.field_course_header_blocks_revision_id = c.entity_id 
           AND b.field_course_header_blocks_revision_id = d.entity_id
           AND c.field_course_header_block_type_value = 'price';", array(':course_nid' => $course_nid));

           foreach ($result as $row) {
             $default_price = $row->field_course_header_block_pr_usa_value;
           }
          break;
        case 'AS':
          $result = db_query("SELECT d.field_course_header_block_pr_as_value FROM field_data_field_course_header a, field_data_field_course_header_blocks b, field_data_field_course_header_block_type c, 
            field_data_field_course_header_block_pr_as d 
           WHERE a.entity_id =:course_nid and a.field_course_header_revision_id = b.entity_id 
           AND b.field_course_header_blocks_revision_id = c.entity_id 
           AND b.field_course_header_blocks_revision_id = d.entity_id
           AND c.field_course_header_block_type_value = 'price';", array(':course_nid' => $course_nid));

           foreach ($result as $row) {
             $default_price = $row->field_course_header_block_pr_as_value;
           }
          break;
        
    }
    
    // now check if default price differs from product price
    if (($default_price > 0) && ($default_price != $variation_price_corrected)) {
      
      // add highlight class for row
      $classes_array[$key] .= " highlighted";
      
      // regenerate output
      $path = drupal_get_path('module', 'commerce_extra_price_formatters');
      require_once($path . "/includes/extra_functions.inc");
      
      $price_formatted = commerce_extra_price_no_decimal_currency_format($variation_price['amount'], $variation_price['currency_code']);
      
      $current_path = current_path();
      $variation_link = "<a rel='resizable:false;position:[center,60]' class='simple-dialog' name='block-system-main' href='/book-this-course?nid=" . $course_nid . "&pid=" . $product_id . "&redirect=" . $current_path . "'><i class='icon-ok'></i>&nbsp;" . t('Book It') . "</a>";
      
      $rows[$key] = "<span class='course-row'>"
        . "<span class='location'>" . $variation_wrapper->field_public_course_location->value() . "</span>"
        . "<span class='date'>" . $variation_wrapper->field_public_course_date_format->value() . "</span>"
        . "</span>"
        . "<span class='price'><span class='xtra-small'>" . t('Discount!') . "</span>" . $price_formatted . "</span>"
        . "<span class='book'>" . $variation_link . "</span>";
      
    }
    

    
  }
}


/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php print $list_type_prefix; ?>
    <?php foreach ($rows as $id => $row): ?>
      <li class="<?php print $classes_array[$id]; ?>"><?php print $row; ?></li>
    <?php endforeach; ?>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>
