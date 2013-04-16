The following custom modules have been implemented:

1. hc_blocks
This module provides a number of blocks: 
- header block for subject (taxonomy) page
- navigation block for subject (taxonomy) page
- header block for course (node) page
- testimonials for course (node) page

2. hc_book_calendar
This module performs some queries for sorting (and filtering on region) the courses on the "Book a Course" page

3. hc_book_temp
A temporary module providing 3 forms (one for each region) that allows users to book a course (by e-mail). Will be
disabled when full commerce functionality is operational.

4. hc_contact
A small module which alters the contact form (About Us) page for using a <button> instead of <input type="submit">

5. hc_regions
This module provides the region-selection functionality, and adds a session variable containing the region (EU - US - ASIA) the user
is surfing from. This module also provides the region-selection block.

6. hc_subject
This module alters the "taxonomy page". Normally the list of nodes belonging to a particular taxonomy term (i.e. the "subject", e.g. ITIL),
is hardcoded in taxonomy_term_page(). This function is rewritten in this module for a more flexible node list.

7. hc_subscribe
This module provides functionality for subscribing for a newsletter. Currently, Campaign Monitor is supported.

8. hc_team
This module provides a custom view mode, "team page" for the team page nodes in the view (only showing the image).