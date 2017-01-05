<?php
	class NightsWatch implements IFighter
	{
		private $_array;
		
		public function recruit($some)
		{
			if ($some instanceof IFighter)
				$this->_array[] = $some;
		}
		public function fight()
		{
			foreach($this->_array as $key=>$value)
				$value->fight();
		}
	}
?>
