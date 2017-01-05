#!/usr/bin/php
<?PHP
	if (count($argv) != 4)
		echo "Incorrect Parameters\n";
	else
	{
		$num1 = trim($argv[1]);
		$op = trim($argv[2]);
		$num2 = trim($argv[3]);
		if ($op == "+")
			$res = $num1 + $num2;
		else if ($op == "-")
			$res = $num1 - $num2;
		else if ($op == "*")
			$res = $num1 * $num2;
		else if ($op == "/")
			$res = $num1 / $num2;
		else if ($op == "%")
			$res = $num1 % $num2;
		echo $res."\n";
	}
?>
