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
	$str = implode(" ", $argv);
	$tab = ft_split($str);
	unset($tab[0]);
	sort($tab);
	$n = count($tab);
	$i = 0;
	while ($i < $n)
	{
		echo $tab[$i]."\n";
		if ($i < $n - 1)
			echo "";
		$i++;
	}
?>
