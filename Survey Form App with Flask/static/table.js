/**
 * Front-end Code for /sheet route
 */

// wait for DOM to finish loading
$(document).ready(() => {
    // initialise DataTable
    $("#table").DataTable({
        searching: false,
        paging: false,
        info: false
    });
});
