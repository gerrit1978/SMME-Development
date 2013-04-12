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
  

})(jQuery);