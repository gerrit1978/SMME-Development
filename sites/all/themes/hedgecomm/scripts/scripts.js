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

  Drupal.behaviors.bookCourseNav = {
    attach: function (context, settings) {
      $('#block-hc-blocks-book-a-course-navigation ul li').click(function(e) {
        e.preventDefault();
        $('#block-hc-blocks-book-a-course-navigation ul li').removeClass('active');
        $(this).addClass('active');
        var entityId = $(this).data('naventityid');
        var selector = "#subject-title" + entityId;
        var offset = $(selector).offset();
        $('html,body').animate({scrollTop: offset.top}, 1000, "easeInOutExpo");
      });
    }
  }

  Drupal.behaviors.courseNodeNav = {
    attach: function (context, settings) {
      $('#block-hc-blocks-course-node-navigation ul li').click(function(e) {
        e.preventDefault();
        $('#block-hc-blocks-course-node-navigation ul li').removeClass('active');
        $(this).addClass('active');
        var entityId = $(this).data('naventityid');
        if (entityId > 0) {
	        var selector = "#text_block_" + entityId;
	      } else {
	        var selector = ".block-public-course-dates";
	      }
        var offset = $(selector).offset();
        $('html,body').animate({scrollTop: offset.top}, 1000, "easeInOutExpo");
      });
    }
  }



  Drupal.behaviors.textBlocksTopLink = {
    attach : function(context, settings) {
      $('.field-collection-item-field-block').append("<a class='to-top to-top-block' href='#'>Top&nbsp;<i class='icon-arrow-up'></i></a>");
    }
  }

  Drupal.behaviors.toTop = {
    attach: function(context, settings) {
      $('a.to-top-block').click(function(e){
        e.preventDefault();
        var offset = $('.inline-navigation').offset();
        $('html, body').animate({scrollTop: offset.top}, 1000, "easeInOutExpo");
		    return false;
      });
    }
  }

  Drupal.behaviors.toTopBook = {
    attach: function(context, settings) {
      $('a.to-top-book').click(function(e){
        e.preventDefault();
        var offset = $('#block-hc-blocks-book-a-course-navigation').offset();
        $('html, body').animate({scrollTop: offset.top}, 1000, "easeInOutExpo");
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
  
  Drupal.behaviors.homepageCarrousel = {
    attach: function(context, settings) {
    
	    function animateBalloon($, i) {

	      var numberOfQuestions = $('ul.questions').children().length;
	    
	      // define next ball00n
        if (i == (numberOfQuestions - 1)) {
          newI = 0;
        } else {
          newI = i+1;
        }
	    
        // animation function here
        var selector = "ul.questions li.question" + i;
        var selectorBalloon = "ul.questions li.question" + i + " .question-wrapper";
        var selectorNext = "ul.questions li.question" + newI;
        var selectorBalloonNext = "ul.questions li.question" + newI + " .question-wrapper";
        var selectorBalloonNextTriangle = "ul.questions li.question" + newI + " .triangle";
        var selectorHandNext = "ul.questions li.question" + newI + " .hand";
        var randomNumber=Math.floor(Math.random()*(11));
        var backgroundHandNext = randomNumber * 32;
        var backgroundHandNextString = backgroundHandNext + "px bottom";
        var randomNumber2 = Math.floor(Math.random()*(numberOfQuestions + 1));
        var backgroundHandNextRotation = randomNumber2;
        var backgroundHandNextRotationString = "rotate(" + backgroundHandNextRotation + "deg)";
        if (backgroundHandNext >= 160) {
          var backgroundHandNextImage = "url(/sites/all/themes/hedgecomm/img/hand_swapped.jpg)";
          $(selectorBalloonNextTriangle).addClass('reversed');
        } else {
          var backgroundHandNextImage = "url(/sites/all/themes/hedgecomm/img/hand.jpg)";        
          $(selectorBalloonNextTriangle).removeClass('reversed');
        }
/*
        var randomNumber3 = Math.floor(Math.random()*100);
        if ((randomNumber3 % 2) == 0) {
          
        } else {
          var backgroundHandNextImage = "url(/sites/all/themes/hedgecomm/img/hand.jpg)";
        }
*/

        $(selectorBalloon).delay("1000").fadeOut("slow", function() {
          $(selectorBalloonNext).fadeOut("0", function() {
            $(selectorHandNext).css({
              backgroundImage: backgroundHandNextImage,
              backgroundPosition: backgroundHandNextString,
              transform: backgroundHandNextRotationString
            });
	          $(selector).animate({
	            bottom: "-500px"
	          }, "slow", "easeInOutExpo", function() {
	            $(selectorNext).animate({
	              bottom: "0"
	            }, "slow", "easeInOutExpo", function() {
	              $(selectorBalloonNext).fadeIn("slow");
	            });
	          });
          });
        });


	      window.setTimeout(function() { 
	        animateBalloon($, newI) 
	      }, 6000)
			}

      if ($('body').hasClass('front')) {
        window.setTimeout(function() {
          animateBalloon($, 0);      
        }, 3000);
      }
    }
  }

  Drupal.behaviors.retina = {
    attach: function(context, settings) {
      var retina = window.devicePixelRatio >= 2;
      
      if (retina) {
        // images for catalog subject page
        if ($('body').hasClass('context-catalog')) {
          var current_image = $('.retina-check img').attr('src');
          if (current_image) {
            var retina_image = current_image.replace('subject_header_default', 'subject_header_retina');
            $('.retina-check img').attr('src', retina_image);
          }
        
/*
 *
 * Disabled: problem with this function is the fact that different headers are different blocks. Currently solved with giving
 * the "retina-check" to each header block. CAVEAT: what if other images are placed in a block…
 *
 *
 */
/*
 
 
	        var subject_header_image = $('#block-hc-blocks-catalog-subject-header .image img').attr('src');
	        if (!subject_header_image) subject_header_image = $('#block-views-header-visuals-block .visual img').attr('src');
	        alert(subject_header_image);
	        if (subject_header_image) {
		        var subject_header_retina_image = subject_header_image.replace('subject_header_default', 'subject_header_retina');
  		      $('#block-hc-blocks-catalog-subject-header .image img').attr('src', subject_header_retina_image);		        
	        } else {
	          alert('geen replace van image');
	        }

*/

  	    }
      } 
    }
  }
  
/*
 * Currently disabled: solved by using tables 
 *
  Drupal.behaviors.courseBorder = {
    attach: function(context, settings) {
      $('.view-courses-per-subject ul.courses li.course .course-title').each(function() {
        var height = $(this).height();
        var variationsHeight = $(this).parent().parent().find('.variations').height();
        if (variationsHeight < height) {
	        $(this).find('li.onsite .col1').css('height', height);
	      }
      });
    }
  }
*/


})(jQuery);