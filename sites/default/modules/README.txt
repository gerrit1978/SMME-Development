The following custom modules have been implemented:

1. hc_backoffice
This module provides backoffice support.
Currently, only one block is provided, linking to the different "manage content" pages.

2. hc_blocks
This module provides a number of blocks: 
 * - header block for subject (taxonomy) page
 * - inline navigation block for subject (taxonomy) page
 * - roadmap block for subject (taxonomy) page (divided according to subject divisions vocabulary)
 * - header block for course (node) page
 * - roadmap "product variations" (public dates) for course (node) page
 * - testimonial block for course (node) page
 * - header block for team (node) page
 * - testimonial block for trainer (node) page
 * - inline navigation block for book a course page
 * - inline navigation block for course (node) page
 * - generic title block which only contains the page title
 * - header block for landing pages
 * - testimonials for landing pages (based on course node)
 * - custom pager for blog views

3. hc_blog
Alters the output of some Views fields for the blog

4. hc_book_calendar
This module performs some queries for sorting (and filtering on region) the courses on the "Book a Course" page

5. hc_booking_form
A temporary module providing 3 forms (one for each region) that allows users to book a course (by e-mail). Will be
disabled when full commerce functionality is operational.

6. hc_contact
A small module which alters the contact form (About Us) page for using a <button> instead of <input type="submit">

7. hc_course_roadmap
Small module that adds a "Choose Your Own" date to the "public courses" view (course detail node page).
This module also adds a class to the individual <li> of the view, in case a course is in promotion

8. hc_currency
Alters the currency format for Euros, to use point as thousands separator.

9. hc_regions
This module provides the region-selection functionality, and adds a session variable containing the region (EU - US - ASIA) the user
is surfing from. This module also provides the region-selection block.

10. hc_subject
This module alters the "taxonomy page". Normally the list of nodes belonging to a particular taxonomy term (i.e. the "subject", e.g. ITIL),
is hardcoded in taxonomy_term_page(). This function is rewritten in this module for a more flexible node list.

11. hc_subscribe
This module provides functionality for subscribing for a newsletter. Currently, Campaign Monitor is supported.

12. hc_team
This module provides a custom view mode, "team page" for the team page nodes in the view (only showing the image). This is deprecated,
since now a thumbnail field is added, and this image is used instead of the header image.