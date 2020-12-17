# Survey Form App with Flask

[![Heroku](https://heroku-badge.herokuapp.com/?app=survey-app-flask)](https://survey-app-flask.herokuapp.com)

This web application presents an user interface created using Bootstrap 4 to the user and expects user inputs. It also has a route that uses DataTables  wherein the user can view all form submissions.

![Form](./screenshots/form.png)

![Data](./screenshots/dataView.png)

If the user has not filled out all of the required fields, client-side JavaScript handles form validation.

![Client-side Validation](./screenshots/clientValidation.png)

Even in the case that an user disables JavaScript using Developer Tools, the server-side validation logic takes care of that.

![Disabling JavaScript](./screenshots/disablingJS.png)

![Server-side Validation](./screenshots/serverValidation.png)
