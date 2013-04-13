(function ($) {

  Drupal.behaviors.webformAjax = {
    attach: function (context, settings) {

      $('#webform-component-intro').hide();

      $('.ui-dialog .webform-client-form .form-submit').click(function(e) {
        var errors = 0;
        $('.webform-client-form .required').each(function() {
          var value = $(this).attr('value');
          if (value == "undefined" || value.length < 1) {
            errors += 1;
          }
        });
        if (errors > 0) {
          $('#webform-component-intro').fadeOut("fast", function() {
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