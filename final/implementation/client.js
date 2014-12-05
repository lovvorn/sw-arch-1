var url = "TEserver.php";

function authenticate(username) {
	$.ajax({
		dataType: 'json',
		type: "POST",
		url: url,
		data: { command: "authenticate", user: username }
		})
		.done(function( rtn ) {
			if(rtn.uid != -1)
			{
				localStorage['uid'] = rtn.uid;
				localStorage['name'] = username;
				window.location.replace("index.html");
			} else {
                return false;
            }
	});
}

function logout() {
	delete localStorage['uid'];
	delete localStorage['name'];
	window.location.replace('index.html');
}

function searchBySymbol(symbol) {
	$.ajax({
		dataType: 'json',
		type: "POST",
		url: url,
		data: { command: "searchBySymbol", symbol: symbol }
		})
		.done(function( rtn ) {
			if(typeof rtn.error == 'undefined')
			{
				alert('Company: ' + rtn.quotes.quote.description);
			} else
				alert('Error');
			
	});
}

$(document).ready(function() {

    "use strict";

    var splashPage = $("#splash-page");
    var loginForm = $("#login-form");
    var registerForm = $("#register-form");
    var registerPageButton = loginForm.find("strong");
    var loginPageButton = registerForm.find("strong");
    var loginButton = loginForm.find("button");
    var loginError = loginForm.find(".alert");

    var showRegisterForm = function()
    {
        loginForm.slideUp("slow", function() {
            loginForm.hide();
            loginError.hide();
            registerForm.slideDown("slow", function() {
                registerForm.show()
            });
        });
    }

    var showLoginForm = function()
    {
        registerForm.slideUp("slow", function() {
            registerForm.hide();
            loginForm.slideDown("slow", function() {
                loginForm.show()
            });
        });
    }

    var showLoginError = function()
    {
        loginError.fadeIn("slow");
    }

    var attemptLogin = function()
    {
        var username = loginForm.find("#username");
        loginError.hide();

        if (!authenticate(username))
        {
            showLoginError();
        }
        else
        {
            window.location.replace('index.html');
        }
    }

    registerForm.hide();
    loginError.hide();

    registerPageButton.on("click", function() {
        showRegisterForm();
    });

    loginPageButton.on("click", function() {
        showLoginForm();
    });

    loginButton.on("click", function(e) {
        e.preventDefault();
        attemptLogin();
    });
});
