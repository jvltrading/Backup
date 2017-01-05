#!/usr/bin/php
<?PHP
	function ft_split($s)
	{
		$s = trim($s);
		$split = explode(" ", $s);
		$split = array_filter($split);
		$split = array_values($split);
		return ($split);
	}
	if ($argc != 2)
		return;
	$tab = ft_split($argv[1]);
	$n = count($tab);
	$i = 0;
	while ($i < $n)
	{
		echo $tab[$i];
		if ($i < $n - 1)
			echo " ";
		$i++;
	}
	echo "\n";
?>
