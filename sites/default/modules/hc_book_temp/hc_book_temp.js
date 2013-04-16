(function ($) {

/*
  Drupal.behaviors.webformButton = {
    attach: function(context, settings) {
      var currentHtml = $('#webform-client-form-67 #edit-actions').html();
      if (currentHtml) {
        var newHtml = currentHtml.replace('input', 'button') + "Blah";
        $('#webform-client-form-67 #edit-actions').html(newHtml);
      }
//      $('#webform-client-form-67 #edit-actions #edit-submit').attr('value', '<i class="icon-arrow-right"></i>');
    }
  }
*/

  Drupal.behaviors.customSelect = {
    attach: function (context, settings) {
      var selector1 = $('.not-logged-in #webform-client-form-67 #webform-component-attendees .form-select');
      var selector2 = $('.not-logged-in #webform-client-form-67 #webform-component-session .form-select');
      if (selector1) {
        selector1.uniform();
      }
      if (selector2) {
        selector2.uniform();
      }
    }
  }


  Drupal.behaviors.webformAjax = {
    attach: function (context, settings) {

      $('#webform-component-error').hide();

      $('.ui-dialog .webform-client-form #submit-button button').click(function(e) {
        var errors = 0;
        $('.webform-client-form .required').each(function() {
          var value = $(this).attr('value');
          if (value == "undefined" || value.length < 1) {
            errors += 1;
          }
        });
        if (errors > 0) {
          $('#webform-component-error').fadeOut("fast", function() {
            $(this).html('Please fill in all required fields.').fadeIn("fast");
          });
          e.preventDefault();
          return false;
        }
      });

    }
  };
  
  
/*
  Drupal.behaviors.ownDate = {
    attach: function (context, settings) {
      $('#edit-submitted-left-session').change(function() {
        if ($(this).val() == 'other') {
          $('#choose-date-wrapper').show();
        } else {
          $('#choose-date-wrapper').hide();        
        }
      });
    }
  };
*/
  Drupal.behaviors.ownDate = {
    attach: function (context, settings) {
      $('#edit-submitted-session').change(function() {
        if ($(this).val() == 'choose_your_own_dates') {
          $('#webform-component-right--coupon-code-markup').hide();
          $('#webform-component-right--coupon-code').hide();
          $('#webform-component-right--contact-markup').show();
        } else {
          $('#webform-component-right--coupon-code-markup').show();
          $('#webform-component-right--coupon-code').show();
          $('#webform-component-right--contact-markup').hide();
        }
      });
    }
  }  

})(jQuery);