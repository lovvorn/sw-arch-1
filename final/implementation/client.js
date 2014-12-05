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
			} else
				alert('User \'' + $('#username').val() + '\' not found');
			
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
    var splashPage = $("#splash-page");
    var loginForm = $("#login-form");
    var registerForm = $("#register-form");
    var registerButton = loginForm.find("strong");
    var loginButton = registerForm.find("strong");

    var showRegisterForm = function()
    {
        loginForm.slideUp("slow", function() {
            loginForm.hide();
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

    registerForm.hide();

    registerButton.on("click", function() {
        showRegisterForm();
    });

    loginButton.on("click", function() {
        showLoginForm();
    });

});
