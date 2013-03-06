(function ($) {

  Drupal.behaviors.catalogHover = {
    attach: function (context, settings) {
      $('li.catalog-item a', context).hover(function () {
        $(this).parent().parent().parent().addClass('hover');
      }, function() {
        $(this).parent().parent().parent().removeClass('hover');
      });
    }
  };
  
  Drupal.behaviors.subjectNav = {
    attach: function (context, settings) {
      $('#block-hc-blocks-catalog-subject-navigation ul li').click(function(e) {
        e.preventDefault();
        $('#block-hc-blocks-catalog-subject-navigation ul li').removeClass('active');
        $(this).addClass('active');
        var entityId = $(this).data('naventityid');
        var selector = "#text_block_" + entityId;
        var offset = $(selector).offset();
        $('html,body').animate({scrollTop: offset.top}, 1000, "easeInOutExpo");
      });
    }
  }
  

})(jQuery);