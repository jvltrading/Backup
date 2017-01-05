<?PHP
	session_start();
	include ("/File to include needed here/");
	if (!isset($_GET['id']) || ($_GET['id']) === "")
		header('Location: index.php');
	$query = "SELECT * FROM `/This is the market area/` WHERE `id` = " . mysql_real_escape_string(htmlspecialchars($_GET["id"])) . ";";
	$result = mysqli_query($con, $query);
	if (mysql_num_rows($result) > 0)
	{
		$row = mysqli_fetch_array($result);
		echo $row["price"];
		$_SESSION["basket"]["total"] += $row["proce"];
		array_push($_SESSION["basket"], $row);
		header('Location: index.php');
	}
	else
		header('Location: index.php');
?>
