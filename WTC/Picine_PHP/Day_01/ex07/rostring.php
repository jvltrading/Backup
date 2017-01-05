#!/usr/bin/php
<?PHP
	function ft_split($s)
	{
		$s = eregi_replace("[ ]+", " ", $s);
		$ret = explode(" ", $s);
		return ($ret);
	}
	if (is_string($argv[1]) == false)
		return;
	$str = ft_split($argv[1]);
	$first = array_shift($str);
	array_push($str, $first);
	$i = 0;
	$n = count($str);
	while ($i < $n)
	{
		echo $str[$i];
		if (is_string($str[$i + 1]))
			echo " ";
		$i++;
	}
	echo "\n";
?>
