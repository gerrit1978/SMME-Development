(function ($) {

  Drupal.behaviors.catalogHover = {
    attach: function (context, settings) {
      $('li.catalog-item a', context).hover(function () {
        console.log('hover');
        $(this).parent().parent().parent().parent().addClass('hover');
      }, function() {
        console.log('out');
        $(this).parent().parent().parent().parent().removeClass('hover');
      });
    }
  };

})(jQuery);