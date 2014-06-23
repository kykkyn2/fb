<?php
Class FB {
	protected $oFB;


	private $oDB;

	/**
	 * @param $oFB 페이스북의 오브젝트
	 */
	public function __construct($oFB) {
		$this -> oFB = $oFB;
		$this -> oDB = new DataAccessObjects();
	}


	/**
	 * 사용자 정의 함수 이름.
	 * @return String or Bool or array or json.....
	 */
	public function sampleName() {
		return false;
	}
	

}
?>