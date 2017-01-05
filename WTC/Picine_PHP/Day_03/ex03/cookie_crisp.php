#!/usr/bin/php
<?PHP
switch($_GET['action'])
{
		case("create"):
			if ($_GET['name'] && $_GET['value'])
				setcookie($_GET['name'], $_GET['value']);
			break;
		case("read"):
			if ($_GET['name'] && $_COOKIE[$_GET['name']] && !$_GET['value'])
				echo $_COOKIE[$_GET['name']]."\n";
			break;
		case("erase"):
			if ($_GET['name'] && !$_GET['value'])
				setcookie($_GET['name'], '', 1);
			break;
}
?>
