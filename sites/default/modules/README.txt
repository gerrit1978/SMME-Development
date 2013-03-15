The following custom modules have been implemented:

1. hc_blocks
This module provides a number of blocks: 
- header block for subject (taxonomy) page
- navigation block for subject (taxonomy) page
- header block for course (node) page
- testimonials for course (node) page


2. hc_subscribe
This module provides functionality for subscribing for a newsletter. Currently, Campaign Monitor is supported.


3. hc_regions
This module provides the region-selection functionality, and adds a session variable containing the region (EU - US - ASIA) the user
is surfing from. This module also provides the region-selection block.


4. hc_subject
This module alters the "taxonomy page". Normally the list of nodes belonging to a particular taxonomy term (i.e. the "subject", e.g. ITIL),
is hardcoded in taxonomy_term_page(). This function is rewritten in this module for a more flexible node list.


5. hc_team
This module provides a custom view mode, "team page" for the team page nodes in the view (only showing the image).