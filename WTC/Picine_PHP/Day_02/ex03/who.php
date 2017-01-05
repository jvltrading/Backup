#!/usr/bin/php
<?PHP
	$out = "";
	$ret = 0;
	exec("who", $out, $ret);
	foreach($out as $line)
		echo $line."\n";
?>
