jQuery(document).ready(function($) {

  // dynamically show/hide coupon code field or other text
  $('#edit-submitted-complete-session').change(function() {
    if ($(this).val() == 'choose_your_own_dates') {
      $('#webform-component-complete--right--coupon-code-markup').hide();
      $('#webform-component-complete--right--coupon-code').hide();
      $('#webform-component-complete--right--contact-markup').show();
    } else {
      $('#webform-component-complete--right--coupon-code-markup').show();
      $('#webform-component-complete--right--coupon-code').show();
      $('#webform-component-complete--right--contact-markup').hide();
    }
  });

  // handle webform validation and submission in simple_dialog
	$("form#webform-client-form-67").find('#edit-submit').live("click", function(e){
	  e.preventDefault();
		var urlform = $("form#webform-client-form-67").attr('action'); 
		$.ajax({  
			type: "POST",  
			url: urlform,  
			data: $("form#webform-client-form-67").serialize(),  
			success: function (data) { 
			    
			    if (($(data).find(".messages.error").length) > 0) {
			      $('#webform-component-error').html('Error: Please fill in all the required fields.');
			    } else {
			      $('#webform-component-error').hide();
			      $('#webform-component-required').hide();
			      $('#edit-actions').hide();
						$('#webform-component-complete').html($(data).find("#zone-content"));
			    }
			    
			
//  				$('#simple-dialog-container').html($(data).find("#zone-content"));

//				$('#simple-dialog-container').fadeOut("fast", function() {
//  				$('#simple-dialog-container').html($(data).find("#zone-content")).fadeIn();
//				});

			}
		});
		return false;
	});

/*
	$("form#webform-client-form-67").find('#edit-submitted-submit-button').live("click", function(e){
	  e.preventDefault();
		var urlform = $("form#webform-client-form-67").attr('action'); 
		$.ajax({  
			type: "POST",  
			url: urlform,  
			data: $("form#webform-client-form-67").serialize(),  
			success: function (data) { 
			    
			    if (($(data).find(".messages.error").length) > 0) {
			      $('#webform-component-error').html('Error: Please fill in all the required fields.');
			    } else {
			      $('#webform-component-error').hide();
			      $('#edit-actions').hide();
						$('#webform-component-complete').html($(data).find("#zone-content"));
			    }
			}
		});
		return false;
	});
*/





});