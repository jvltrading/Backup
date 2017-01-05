#!/usr/bin/php
<?PHP
	if ($argc == 2)
	{
		date_default_timezone_set('Europe/Paris');
		$date = explode(" ", $argv[1]);
		$month = array(01 => "janvier", 02 => "février", 03 => "mars", 04 => "avril", 05 => "mai", 06 => "juin", 07 => "juillet", 08 => "août", 09 => "septembre", 10 => "octobre", 11 => "novembre", 12 => "décembre");
		$day = array(1 => "lundi", 2 => "mardi", 3 => "mercredi", 4 => "jeudi", 5 => "vendredi", 6 => "samedi", 7 =>"dimanche");
		if (count($date) != 5 || preg_match("/^[1-9]$|0[1-9]|[1-2][0-9]|3[0-1]$/", $date[1], $date[1]) === 0 || preg_match("/^[0-9]{4}$/", $date[3], $date[3]) === 0 || preg_match("/^([0-1][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $date[4], $date[4]) === 0)
		{
			echo "Wrong Format\n";
			exit();
		}
		$date[0] = array_search(lcfirst($date[0]), $day); 	//lcfirst returns string with 1st char lowercased if alpha;
		$date[2] = array_search(lcfirst($date[2]), $month);
		if ($date[0] === false || $date[2] === false)
		{
			echo "Wrong Format1\n";
			exit();
		}
		$time = mktime($date[4][1], $date[4][2], $date[4][3], $date[2], $date[1][0], $date[3][0]);
		if (date( "N", $time) == $date[0])
			echo $time."\n";
		else
			echo "Wrong Format2\n";
	}
	else
	{
		echo "Wrong Format3\n";
		exit();
	}
?>
