#!/usr/bin/php
<?PHP
	function multiexpose($check, $s)
	{
		$str_rep = str_replace($check, $check[0], $s);
		$ret = explode($check[0], $str_rep);
		return ($ret);
	}
	if (count($argv) != 2)
		echo "Incorrect Parameters.\n";
	else
	{
		$delimeters = array("+", "-", "*", "/", "%");
		$str = multiexpose($delimeters, $argv[1]);

		if (count($str) != 2 || !ctype_digit(trim($str[0])) || !ctype_digit(trim($str[1])))
		{
			echo "Syntax Error\n";
			exit();
		}
		else if(strstr($argv[1], '+'))
			print (trim($str[0])) + (trim($str[1]));
		else if (strstr($argv[1], '-'))
			print (trim($str[0])) - (trim($str[1]));
		else if (strstr($argv[1], '*'))
			print (trim($str[0])) * (trim($str[1]));
		else if (strstr($argv[1], '/'))
			print (trim($str[0])) / (trim($str[1]));
		else if (strstr($argv[1], '%'))
			print (trim($str[0])) % (trim($str[1]));
		else
			echo "Syntax Error";
	}
	echo "\n";
?>
