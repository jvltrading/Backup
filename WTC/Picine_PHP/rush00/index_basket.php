<?PHP
	session_start();
	if(!isset($_SESSION["basket"]))
		$_SESSION["basket"] = array("total" => 0);
?>
