(function ($) {

  Drupal.behaviors.catalogHover = {
    attach: function (context, settings) {
      $('li.catalog-item', context).hover(function () {
        $(this).addClass('hover');
      }, function() {
        $(this).removeClass('hover');
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
        if (entityId > 0) {
	        var selector = "#text_block_" + entityId;
	      } else {
	        var selector = ".catalog-subject-roadmap";
	      }
        var offset = $(selector).offset();
        $('html,body').animate({scrollTop: offset.top}, 1000, "easeInOutExpo");
      });
    }
  }

  Drupal.behaviors.textBlocksTopLink = {
    attach : function(context, settings) {
      $('.field-collection-item-field-block').append('<a href="#" class="to-top to-top-block">Top&nbsp;<i class="arrow-up"></i></a>');
    }
  }

  Drupal.behaviors.toTop = {
    attach: function(context, settings) {
      $('a.to-top').click(function(e){
        e.preventDefault();
        $('html, body').animate({scrollTop: 0}, 1000, "easeInOutExpo");
		    return false;
      });
    }
  }
  
  Drupal.behaviors.testimonials = {
    attach: function(context, settings) {
      $('ul.testimonials').carouFredSel({
        scroll : {
          timeoutDuration: 10000,
          duration: 750,
          fx: "fade",
          items: "3"
        }
      });
    }
  }
  
  Drupal.behaviors.retina = {
    attach: function(context, settings) {
      var retina = window.devicePixelRatio >= 2;
      
      if (retina) {
        // images for catalog subject page
        if ($('body').hasClass('context-catalog')) {
	        var subject_header_image = $('#block-hc-blocks-catalog-subject-header .image img').attr('src');
	        var subject_header_retina_image = subject_header_image.replace('subject_header_default', 'subject_header_retina');
	        $('#block-hc-blocks-catalog-subject-header .image img').attr('src', subject_header_retina_image);
  	    }
      } 
    }
  }
  

})(jQuery);