/**
 * Front-end Code for /form route
 */

// wait for DOM to finish loading
$(document).ready(() => {
    // find all elements to be validated
    var forms = document.getElementsByClassName("needs-validation");
    // add validation logic to those elements
    var validation = Array.prototype.filter.call(forms, form => {
        form.addEventListener(
            "submit",
            event => {
                if (form.checkValidity() === false) {
                    // prevent form submission
                    event.preventDefault();
                    event.stopPropagation();
                }
                form.classList.add("was-validated");
            },
            false
        );
    });
});
