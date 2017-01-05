#!/usr/bin/php
<?PHP
	function get_pages($name)
	{
		$read = fopen($argv[1], 'r');
		$page = "";
		while (!feof($read))
		{
			$line = trim(fgets($read));
			$page = $line;
		}
		fclose($read);
		$pattern = ' /<(.*?)title=[\"|\']+(.*?)[\"|\']+(.*?)>(.*?)<\/(.*?)>/i';
		echo preg_replace_callback($pattern, 'get_link', $page);
		while ($read && !feof($read))
			$page = fgets($read);
		$page = preg_replace_callback("//");
		function get_link($link)
		{
			return '<'.$link[1].'title="'.strtoupper($link[2]).'"'.$link[3].'>'.strtoupper($link[4]).'</'.$link[5].'>';
		}
		if (isset($argv[1])
			get_pages($argv[1]);
?>
