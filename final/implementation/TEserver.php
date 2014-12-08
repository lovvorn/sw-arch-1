<?php
if(!isset($_REQUEST['command']))
	die('No command set');

header('Content-Type: application/json');
	
$sql = new MySQLi('localhost', 'dev', 'dev', 'test');
//$sql = new MySQLi('localhost', 'hbl20', 'tmppass1', 'hbl20');

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
	case 'buyStock':
	
		break;
}

$sql->close();




# The Pluto admin does not have PHP's native curl functions enabled. This function uses the command-line cURL and returns the result
function getCurl($url, $json = true) # json, return json. !json, return assoc. array
{
	exec("curl -H \"Accept: application/json\" -H \"Authorization: Bearer wh9CdQDwJTr6hDrXQuqrKzP0Ayy3\" {$url}", $rtn);
	return ($json ? $rtn[0] : json_decode($rtn[0], true));
}
?>
