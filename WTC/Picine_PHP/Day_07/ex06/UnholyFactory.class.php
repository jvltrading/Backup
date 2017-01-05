<?php
	class UnholyFactory
	{
		private $soldier = array();
		public function absorb($a)
		{
			if (get_parent_class($a))
			{
				if (isset($this->soldier[$a->getName()]))
				{
					print("(Factory already absorbed a fighter of type ". $a->getName() . ")" . PHP_EOL);
				}
				else
				{
					print("(Factory absorbed a fighter of type " . $a->getName() . ")" . PHP_EOL);
					$this->soldier[$a->getName()] = $a;
				}
			}
			else
				print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
		}
		public function fabricate($a)
		{
			if (array_key_exists($a, $this->soldier))
			{
				print("(Factory fabricates a fighter of type ".$a.")".PHP_EOL);
				return (clone $this->soldier[$a]);
			}
			print("(Factory hasn't absorbed any fighters of type ".$a.")" . PHP_EOL);
			return NULL;
		}
	}
?>
