var url = "TEserver.php";

function getPortfolio(username, callback) {
    $.ajax({
        dataType: 'json',
        type: "POST",
        url: url,
        data: { command: "getPortfolio", user: username }
    }).done(function(rtn) {
        callback(rtn);
    });
}

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

function searchBySymbol(symbol, callback) {

	$.ajax({
		dataType: 'json',
		type: "POST",
		url: url,
		data: { command: "searchBySymbol", symbol: symbol }
		})
		.done(function( rtn ) {
			if(typeof rtn.error == 'undefined')
			{
				//alert('Company: ' + rtn.quotes.quote.description);
                callback(rtn);
			} else {
                callback(false);
                return false;
            }

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
	var buyContainer = $('#buy_container');

    var showRegisterForm = function()
    {
        loginForm.slideUp("slow", function() {
            loginForm.find("#username").val("");
            loginForm.find("#password").val("");
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
            registerForm.find("#username").val("");
            registerForm.find("#email").val("");
            registerForm.find("#password").val("");
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
        var username = loginForm.find("#username").val();
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

    var checkLogin = function()
    {
        if (typeof localStorage['uid'] === 'undefined'
            && window.location.href.indexOf("login.html") < 0)
        {
            window.location.replace("login.html");
        }
        else if (typeof localStorage['uid'] !== 'undefined'
            && window.location.href.indexOf("index.html") < 0)
        {
            window.location.replace("index.html");
        }
 
        //Place anything you want to happen when the page loads in this function
        window.onload = function() {
            $('#user_welcome').html("Welcome, " + localStorage['name']);
            
        };
    }

    checkLogin();

    registerForm.hide();
    loginError.hide();
	buyContainer.hide();

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

    /*
     * stuff for the index.html
     */

    var lockMenu = false;

    var cover = $(".cover");
    var menuClosed = $("#menu-closed");
    var menuOpened = $("#menu-opened");
    var searchButton = $("#search");
    var logoutButton = $("#logout");
    var contentArea = $("#content");
    var lockMenuButton = $("#lock-menu");
    var searchBar = $("#symbol1");

    var portfolioButton = $("#portfolio");
    var buyButton = $("#buy");
    var sellButton = $("#sell");
	var buySearchButton = $('#search_buy');
	var buySymbol = $('#symbol_buy');
	var buyNumStock = $('#buy_num_stock');
	var buyTotal = $('#buy_total');
	var buyCurrentPriceVisible = $('#buy_current_price_visible');
	var buyCurrentPriceHidden = $('#buy_current_price');
	var buyStock = $('#buyStock');
    var loading = contentArea.find(".loading");
    var stockInfoArea = contentArea.find(".stock-info");
    var openMenuButton = menuClosed.find("span");
    var closedMenuButton = menuOpened.find("span");

    var buyWindow = $("#buy-window");
    var sellWindow = $("#sell-window");

    var showMenu = function()
    {
        menuOpened.animate({left: 0}, 200);
    }

    var closeMenu = function()
    {
        menuOpened.animate({left: "-1000px"}, 200);
    }

    menuOpened.css("left", "-1000px");
    contentArea.hide();
    stockInfoArea.hide();
    loading.hide();
    cover.hide();
    buyWindow.hide();
    sellWindow.hide();
    stockInfoArea.find("error").hide();
    searchBar.focus();

    $("#portfolio-content").children("#error").hide();
    $("#portfolio-content").hide().animate({"margin-top": "-1000px"});

    openMenuButton.on("mouseover", function() {
        showMenu();
    });

    menuOpened.on("mouseleave", function() {
        closeMenu();
    });

    searchBar.bind("enterKey", function() {
        searchButton.click();
    });
	
	buySymbol.bind("enterKey2", function() {
        buySearchButton.click();
    });

    searchBar.keyup(function(e) {
        if (e.keyCode == 13)
        {
            $(this).trigger("enterKey");
        }
    });
	
	buySymbol.keyup(function(e) {
        if (e.keyCode == 13)
        {
            $(this).trigger("enterKey2");
            e.Handled = true;
        }
    });
	
	buyStock.on('click', function() {
		$.ajax({
			dataType: 'json',
			type: "POST",
			url: url,
			async: false,
			data: { command: "buy", symbol: buySymbol.val(), amount: buyNumStock.val(), user: localStorage['uid'], price: buyCurrentPriceHidden.val() }
		})
		.done(function(rtn) {
			if(typeof rtn.error == 'undefined')
			{
				if(rtn.success)
					alert('Successfull purchase.');
				else
					alert('Purchase failed.');
			} 
		});
	});
	
	buySearchButton.on('click', function() {
		$.ajax({
			dataType: 'json',
			type: "POST",
			url: url,
			data: { command: "getStockPrice", symbol: buySymbol.val() }
		})
		.done(function(rtn) {
			if(typeof rtn.error == 'undefined')
			{
				buyCurrentPriceVisible.html('Current Price: $'+rtn.price);
				buyCurrentPriceHidden.val(rtn.price);
				buyContainer.show();
			} 
		});
	});
	
	buyNumStock.on('change', function() {

		var price = buyCurrentPriceHidden.val()*buyNumStock.val();
		buyTotal.html('Total: $'+(price));

		$.ajax({
					dataType: 'json',
					type: "POST",
					url: url,
					async: false,
					data: { command: "canIAfford", user: localStorage['uid'], price: price }
				})
				.done(function(rtn) {

					if(typeof rtn.error == 'undefined')
					{
						if (rtn.afford)
						{
							buyTotal.addClass('text-success');
							buyTotal.removeClass('text-danger');
							buyStock.removeAttr("disabled");
						} else {
							buyTotal.addClass('text-danger');
							buyTotal.removeClass('text-success');
							buyStock.attr('disabled', 'disabled');
						}
					} 

				});
	});

    searchButton.on("click", function() {

        stockInfoArea.find("#error").hide();
        stockInfoArea.find("table").hide(); 
        stockInfoArea.find("h1").hide();
        stockInfoArea.find("h3").hide();
        contentArea.show();
        loading.show();

        if (!($('#symbol1').val()))
        {
            loading.hide();
            stockInfoArea.show();
            stockInfoArea.find("#error").fadeIn();
            return;
        }

        searchBySymbol($('#symbol1').val(), function(rtn) {
            loading.hide();
            stockInfoArea.show();
            if (!rtn)
            {
                stockInfoArea.find("#error").fadeIn();
            }
            else
            {
                stockInfoArea.find("h1").html(rtn.quotes.quote.description).fadeIn();
                stockInfoArea.find("h3").html(rtn.quotes.quote.symbol).fadeIn();
                stockInfoArea.find("#exchange-cell").html(rtn.quotes.quote.exch);
                stockInfoArea.find("#closing-price-cell").html(rtn.quotes.quote.close);
                stockInfoArea.find("#daily-net-change-cell").html(rtn.quotes.quote.change);
                stockInfoArea.find("#percentage-cell").html(rtn.quotes.quote.change_percentage);
                stockInfoArea.find("#volume-cell").html(rtn.quotes.quote.volume);
                stockInfoArea.find("#avg-volume-cell").html(rtn.quotes.quote.average_volume);
                stockInfoArea.find("#high-cell").html(rtn.quotes.quote.high);
                stockInfoArea.find("#low-cell").html(rtn.quotes.quote.low);
                stockInfoArea.find("table").fadeIn();
            }
            //stockInfoArea.html(rtn.quotes.quote.description);
            
            searchBar.val("");
            searchBar.focus();
        });
    });

    logoutButton.on("click", function() {
        logout();
    });

    lockMenuButton.on("click", function() {
        lockMenu = !lockMenu;
        if (lockMenu)
        {
            lockMenuButton.find(".show-menu-text").html("Unlock Menu");
            menuOpened.unbind("mouseleave");
        }
        else
        {
            lockMenuButton.find(".show-menu-text").html("Lock Menu");
            menuOpened.on("mouseleave", function() {
                closeMenu();
            });
        }
    });

    openMenuButton.trigger("mouseover");
    lockMenuButton.trigger("click");

    buyButton.on("click", function() {
        cover.fadeIn();
        buyWindow.show();
        buyWindow.animate({top: "20%"});
    });

    sellButton.on("click", function(e, symbol, shares) {

        if (portfolioButton.html() == "Portfolio")
        {
            portfolioButton.trigger("click");
        }

        if (typeof symbol === 'undefined' || typeof shares === 'undefined')
        {
            $("#portfolio-content").children('#error').fadeIn();
            return;
        }

        cover.fadeIn();

        sellWindow.children("h3").html("Selling " + symbol);
        sellWindow.children("span").html("You have <strong><em>" + shares + "</em></strong> share(s) to sell.");
        sellWindow.show();
        sellWindow.animate({top: "20%"});
    });

    $("#portfolio-content > table > tbody").on("click", ".sell-stock", function(e) {
        var symbol = $(this).parent().children("td").eq(1).html();
        var shares = $(this).parent().children("td").eq(2).html();

        sellButton.trigger("click", [symbol, shares]);
    });

    portfolioButton.on("click", function() {

        $("#portfolio-content").children("#error").hide();

        if ($(this).html() == "Portfolio")
        {
            $("#portfolio-content > table").children("tbody").html("");
            getPortfolio(localStorage['name'], function(rtn) {
                var result = "";
                for (var i = 0; i < rtn.length; i++)
                {
                    result += "<tr>";
                    result += "<td class=\"sell-stock\"><span class=\"glyphicon glyphicon-trash\" aria-hidden=\"true\"></span></td>";
                    result += "<td>" + rtn[i][1] + "</td>";
                    result += "<td>" + rtn[i][2] + "</td>";
                    result += "<td>" + rtn[i][3] + "</td>";
                    result += "</tr>";
                }
                $("#portfolio-content > table").children("tbody").html(result);

            });
            $("#search-content").animate({"margin-top": "-1000px"}, function() {
                $(this).hide(); 
                portfolioButton.html("Search");
                $("#portfolio-content").show().animate({"margin-top": "0"})
            });
        }
        else if ($(this).html() == "Search")
        {
            $("#portfolio-content").animate({"margin-top": "-1000px"}, function() {
                $(this).hide(); 
                portfolioButton.html("Portfolio");
                $("#search-content").show().animate({"margin-top": "0"})
            });
        }
    });

    cover.on("click", function() {
        buyWindow.animate({top: "-1000px"}, function() {
            buyWindow.hide();
            cover.fadeOut();
        });
        sellWindow.animate({top: "-1000px"}, function() {
            sellWindow.hide();
            cover.fadeOut();
        });
    });


});
