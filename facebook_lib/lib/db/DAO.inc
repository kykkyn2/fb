<?php
include_once 'DatabaseDataManager.inc';

class DataAccessObjects extends DatabaseDataManager {
	/**
	 * @ object 데이터베이스의 정보를 담고 있을 객체
	 */
	private $oDB;
	private $TABLE_NAME;
	
	public function __construct(){
		parent::__construct();
		$this -> oDB = DatabaseDataManager::getInstance();

		$this->USER_TABLE = USER_TABLE;    
	}
	
	//사용자 정보가 DB에 있는지 확인
	public function userDataCheck($uid){
	      
		if($uid == '' || $uid == 0){
		    
			return 0;
		}
		
		$sQuery = " SELECT COUNT(user_uid) AS cnt FROM ".$this->USER_TABLE." WHERE user_uid = ".$uid;
		
		return $this->execSqlLists($sQuery);        
	}
	
	//사용자 정보 DB 저장
	public function userInfoDBInsert($aData){
	    
		if(!empty($aData)){
			
			mysql_query("SET NAMES 'utf8'");
			
			$sQuery = "INSERT INTO ".$this->USER_TABLE." ( ";
			$sQuery = $sQuery." user_uid, user_id, user_name, user_gender, link , user_photo_url, device ,ip, regdate) ";
			$sQuery = $sQuery." values( ";
			$sQuery = $sQuery." '".$aData['useruid']."', '".$aData['name']."', '".$aData['username']."', '".$aData['gender']."', ";
			$sQuery = $sQuery." '".$aData['link']."', '".$aData['user_photo_url']."', '".$aData['device'];
			$sQuery = $sQuery."', '".$_SERVER['REMOTE_ADDR']."', '".date('Y-m-d H:i:s')."'";
			$sQuery = $sQuery." ) ";                
			
			
			return $this->execSqlUpdate($sQuery);	   
		}else{
			return 0;
		}        
	
	}
	
}
?>
