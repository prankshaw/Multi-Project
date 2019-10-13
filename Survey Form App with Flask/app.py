"""
Controller Logic for the application
"""

import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """
    disable caching
    """
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    """
    redirect users to survey form
    """
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    """
    respond with the survey form
    """
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    """
    receive details from form
    """
    failure = []
    if not request.form.get("name"):
        failure.append("Please enter your name.")
    if not request.form.get("email"):
        failure.append("Please enter your email.")
    if not request.form.get("phone"):
        failure.append("Please enter your phone number.")
    if not request.form.get("gender"):
        failure.append("Please enter your gender.")
    if not request.form.get("choice"):
        failure.append("Please enter your choice.")
    else:
        with open("survey.csv", "a") as file:
            """
            write files to the CSV file
            """
            f = csv.writer(file)
            f.writerow(
                (request.form.get("name"),
                 request.form.get("email"),
                 request.form.get("phone"),
                 request.form.get("gender"),
                 request.form.get("choice"))
            )
        return redirect("/sheet")
    return render_template("error.html", failure=failure)


@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("survey.csv", "r") as file:
        """
        read data from the CSV file
        """
        f = csv.reader(file)
        return render_template("sheet.html", data=list(f))
