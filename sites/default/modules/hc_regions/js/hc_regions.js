jQuery(document).ready(function($) {
	$('#edit-change-region').change(function() {
	  alert('Region will be changed');
		$('#hc-regions-select-region-form').submit();
	});
});
