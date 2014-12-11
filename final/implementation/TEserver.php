<?php
if(!isset($_REQUEST['command']))
	die('No command set');

header('Content-Type: application/json');
	
#$sql = new MySQLi('localhost', 'dev', 'dev', 'test');
$sql = new MySQLi('localhost', 'hbl20', 'tmppass1', 'hbl20');

switch($_REQUEST['command'])
{
	case 'test':
		echo json_encode(array('text' => 'This is a test of the AJAJ Server'));
		break;
	case 'authenticate':
		$user = $_REQUEST['user'];
		
		$q = $sql->query("SELECT COALESCE((SELECT `id` FROM `Customer` WHERE `name` = '{$user}'), '-1') AS `id`;"); 
		$result = $q->fetch_assoc();
		
		echo json_encode(array('uid' => $result['id']));
		break;
	case 'searchBySymbol':
		$rtn = getCurl("https://sandbox.tradier.com/v1/markets/quotes?symbols={$_REQUEST['symbol']}");
		
		if (strstr($rtn, 'unmatched_symbols'))
			echo json_encode(array('error' => 'Unknown symbol'));
		else
			echo $rtn;
		break;
	case 'getStockPrice':
		echo json_encode(array('price' => getCurrentPrice($_REQUEST['symbol'], 'buy')));
		break;
	case 'canIAfford':
		$user = $_REQUEST['user'];
		$price = $_REQUEST['price'];
		
		$afford = canIAfford($user, $price);
		
		echo json_encode(array('afford' => $afford));
		break;
	case 'buy':
		$user = $_REQUEST['user'];
		$symbol = strtoupper($_REQUEST['symbol']);
		$amount = $_REQUEST['amount'];
		$price = $_REQUEST['price'];
		$total = round($amount*$price, 2);
		$now = date('Y-m-d H:i:s');
		
		$afford = canIAfford($user, $total);
		
		if ($afford)
		{
			$q = $sql->query("SELECT COALESCE((SELECT `shares` FROM `Portfolio` WHERE `cid` = '{$user}' AND `stock` = '{$symbol}'), '-1') AS `shares`;");
			$result = $q->fetch_assoc();
			
			if($result['shares'] == -1)
				$q = $sql->query("INSERT INTO `Portfolio` VALUES ('{$user}', '{$symbol}', '{$amount}', '{$total}');");
			else
				$q = $sql->query("UPDATE `Portfolio` SET `shares` = `shares` + '{$amount}', `purchase_price` = `purchase_price` + '{$total}' WHERE `cid` = '{$user}' AND `stock` = '{$symbol}';");
			$q = $sql->query("INSERT INTO `Transactions` VALUES ('{$user}', '{$symbol}', '{$amount}', '{$total}', '{$now}');");
			$q = $sql->query("UPDATE `Customer` SET `balance` = `balance` - '{$total}' WHERE `id` = '{$user}';");
		}
		
		echo json_encode(array('success' => $afford));
		break;
    case 'getPortfolio':

		$user = $_REQUEST['user'];

        $query = $sql->query(
            "select * from `Portfolio` `P` inner join `Customer` `C` " .
            "where `C`.`id` = `P`.`cid` AND `C`.`name` = '{$user}';");
        $result = $query->fetch_all();

        echo json_encode($result);

        break;
	case 'sellCheck':
	
		$user = $_REQUEST['user'];
		$amount = $_REQUEST['amount'];
		$symbol = strtoupper($_REQUEST['symbol']);
		echo json_encode(array('afford' => $afford));
		
		break;
		
	case 'sell':
		$user = $_REQUEST['user'];
		$symbol = strtoupper($_REQUEST['symbol']);
		$amount = $_REQUEST['amount'];
		$price = $_REQUEST['price'];
		$total = round($amount*$price, 2);
		$now = date('Y-m-d H:i:s');	

		$canSell = sellCheck($user, $amount, $symbol);
		
		if ($canSell)
		{
			$q = $sql->query("SELECT COALESCE((SELECT `shares` FROM `Portfolio` WHERE `cid` = '{$user}' AND `stock` = '{$symbol}'), '-1') AS `shares`;");
			$result = $q->fetch_assoc();
			
			if($result['shares'] != -1)
				$q = $sql->query("UPDATE `Portfolio` SET `shares` = `shares` - '{$amount}' WHERE `cid` = '{$user}' AND `stock` = '{$symbol}';");
				$q = $sql->query("INSERT INTO `Transactions` VALUES ('{$user}', '{$symbol}', '{$amount}', '{$now}');");
				$q = $sql->query("UPDATE `Customer` SET `balance` = `balance` + '{$total}' WHERE `id` = '{$user}';");
		}
		
		echo json_encode(array('success' => $canSell));
		break;
		
	case 'getSellPrice':
		echo json_encode(array('price' => getCurrentPrice($_REQUEST['symbol'], 'sell')));
		break;
}

$sql->close();




# The Pluto admin does not have PHP's native curl functions enabled. This function uses the command-line cURL and returns the result
function getCurl($url, $json = true) # json, return json. !json, return assoc. array
{
	exec("curl -H \"Accept: application/json\" -H \"Authorization: Bearer wh9CdQDwJTr6hDrXQuqrKzP0Ayy3\" \"{$url}\"", $rtn);
	return ($json ? $rtn[0] : json_decode($rtn[0], true));
}

# Not the current price
function getCurrentPrice($symbol, $buysell)
{
	if($buysell == 'sell')
		$data = getCurl("https://sandbox.tradier.com/v1/markets/history?symbol={$symbol}&interval=daily&start=2014-12-05&end=2014-12-06", false);
	else
		$data = getCurl("https://sandbox.tradier.com/v1/markets/history?symbol={$symbol}&interval=daily&start=2014-11-05&end=2014-11-06", false);
	return $data['history']['day']['close'];
}

function canIAfford($user, $price)
{
	global $sql;
	
	$q = $sql->query("SELECT `balance` FROM `Customer` WHERE id = '{$user}';"); 
	$result = $q->fetch_assoc();
	return ($result['balance'] > $price ? true : false);
}

function sellCheck($user, $amount, $symbol)
{
	$q = $sql->query("SELECT shares FROM 'portfolio' WHERE 'cid' = {$user} AND 'stock' LIKE '{$symbol}';")
	$result = $q->fetch_assoc();
	return ($result['shares'] > $amount ? true : false);
}

?>
