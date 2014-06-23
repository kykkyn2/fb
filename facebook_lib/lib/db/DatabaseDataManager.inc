<?php
class DatabaseDataManager {
	protected $host;
	protected $name;
	protected $user;
	protected $pass;

	protected $connection;
	protected $close_flag;
	
	private static $singleton;  

	protected function __construct() {
		$this -> connect();
		$this -> db_open();
	}
	
	protected function connect(){
		
		$this -> host = DB_HOST;
		$this -> name = DB_NAME;
		$this -> user = DB_USER;
		$this -> pass = DB_PASS;
	}
	
	public function getInstance() {
		if(!isset(DatabaseDataManager::$singleton)){
			DatabaseDataManager::$singleton= new DatabaseDataManager;
		}   
		return DatabaseDataManager::$singleton;  
     }

	protected function db_open() {
		// 데이터베이스가 열려 있지 않는 경우 데이터베이스 커넥션을 연결한다.
		if (empty($this -> connection)) {
			$this -> db_access();

			$this -> connection = mysql_connect($this -> host, $this -> user, $this -> pass);

			if (!$this -> isConnection()) {
				return false;
			}

			if (!mysql_select_db($this -> name)) {
				$this -> db_handle_error();
				return false;
			}
		}

		return true;
	}

	protected function db_access() {
		$this -> user = trim($this -> user );
		$this -> pass = trim($this -> pass);
	}

	protected function isConnection() {
		if ($this -> connection) {
			return true;
		} else {
			$this -> db_handle_error();
			return false;
		}
	}

	protected function db_close() {
		if ($this -> connection)
			mysql_close($this -> connection);
	}

	protected function db_handle_error($query = null) {
		$message = "Invalid query: " . mysql_error() . "\n";
		if ($query) {
			$message .= "query: " . $query;
		}
		error_log($message);
	}

	public function execSqlOneRow($sQuery) {
		mysql_set_charset("utf8");
		if ($this -> isConnection()) {
			$oResult = mysql_query($sQuery);
			if ($oResult) {
				return mysql_fetch_assoc($oResult);
			} else {
				$this -> db_handle_error($sQuery);
			}
		}
		return false;
	}

	public function execSqlOneCol($sQuery) {
		mysql_set_charset("utf8");
		if ($this -> isConnection()) {
			$oResult = mysql_query($sQuery);
			if ($oResult) {
				$aRow = mysql_fetch_row($oResult);
				return $aRow[0];
			} else {
				$this -> db_handle_error($sQuery);
			}
		}
		return false;
	}

	public function execSqlLists($sQuery) {
		mysql_set_charset("utf8");
		if ($this -> isConnection()) {
			$aReturn = "";
			$oResult = mysql_query($sQuery);
			if ($oResult) {
				$nI = 0;
				while ($aRow = mysql_fetch_assoc($oResult)) {
					#array_push($aReturn,$aRow);
					$aReturn[$nI] = $aRow;
					$nI++;
				}
				return $aReturn;
			} else {
				$this -> db_handle_error($sQuery);
			}
		}
		return false;
	}

	public function execSqlUpdate($sQuery, $bReturnResult = false) {
		//mysql_set_charset("utf8");
		
		if ($this -> isConnection()) {
			$aReturn = "";
			$oResult = mysql_query($sQuery);
			//echo "mysql query : ".$sQuery;
			
			if ($oResult) {
				return true;
			} else {
				$this -> db_handle_error($sQuery);
			}
		}
		
		return false;
	}

	public function execSQL($aQuery) {
		
		if (!is_array($aQuery)) {
			return false;
		}
		if (isset($aQuery['insert']) && isset($aQuery['table']) ) {
			
			$sQuery = $this -> BuildInsertSQL($aQuery);
			return $this -> execSqlUpdate($sQuery);
		}
		if (isset($aQuery['update']) && isset($aQuery['table']) && isset($aQuery['where'])) {
			$sQuery = $this -> BuildUpdateSQL($aQuery);
			return $this -> execSqlUpdate($sQuery);
		}
		if (isset($aQuery['select']) && isset($aQuery['table']) ) {
			$sQuery = $this -> BuildSelectSQL($aQuery);
			
			return $this -> execSqlLists($sQuery);
		}

		return false;
	}
	
	/**
	 * insertSQL을 만들어서 삽입
	 *
	 * @param	Stirng DB명
	 * @param	Array 삽입할 key와 값들
	 */
	protected function BuildInsertSQL(&$aQuery) {
		$fields = array_map('mysql_real_escape_string', array_values($aQuery['insert']));
		$keys = array_keys($aQuery['insert']);
		$table = $aQuery['table'];
		$sQuery = 'INSERT INTO `' . $table . '` (`' . implode('`,`', $keys) . '`) VALUES (\'' . implode('\',\'', $fields) . '\')';
		return $sQuery;
	}

	protected function BuildUpdateSQL(&$aQuery) {
		$fields = $aQuery['update'];
		$wheres = $aQuery['where'];
		$table = $aQuery['table'];
		$keys = array();
		$wehreKeys = array();
		
		foreach ($fields as $key => $value) {
			array_push($keys, '`'.$key.'`=\''.mysql_real_escape_string($value).'\'');
		}
		foreach ($wheres as $key => $value) {
			array_push($wehreKeys, '`'.$key.'`=\''.mysql_real_escape_string($value).'\'');
		}
		
		$sQuery = 'UPDATE `' . $table . '` SET '.implode(',', $keys).' WHERE ('.implode(') AND (', $wehreKeys).')';
		return $sQuery;
	}
	
	protected function BuildSelectSQL(&$aQuery) {
		$query = 'SELECT ';
		if(count($aQuery['select']) == 0) {
			$query .= '*';
		} else {
			$query .= '`'.implode('`,`', $aQuery['select']).'`';
		}
		$query .= ' FROM `'.$aQuery['table'].'`';
		if(isset($aQuery['where'])){
			if(count($aQuery['where']) != 0) {
				$wehreKeys = array();
				foreach ($aQuery['where'] as $key => $value) {
					array_push($wehreKeys, '`'.$key.'`=\''.mysql_real_escape_string($value).'\'');
				}
				$query .= ' WHERE ('.implode(') AND (', $wehreKeys).')';
			}
		}
		if(isset($aQuery['order'])){
			if(count($aQuery['order']) != 0) {
				$orderKeys = array();
				foreach ($aQuery['order'] as $key => $value) {
					array_push($orderKeys, '`'.$key.'` '.mysql_real_escape_string($value));
				}
				$query .= ' ORDER BY '.implode(', ', $orderKeys);
			}
		}
		if(isset($aQuery['limit'])){
			if($aQuery['limit']) {
				$query .= ' LIMIT '.$aQuery['limit'];
			}
		}
		return $query;
	}
}


/**
 * 예문
 */

/*
include_once 'datamgr/DatabaseDataManager.inc';

$aDBconnect = array(
	'host' => 'localhost',
	'name' => 'test',
	'user' => 'root',
	'pass' => 'ci2413!'
);
		
$oDB = new DatabaseDataManager($aDBconnect);

$sQuery = "SELECT * FROM hana_lpga_user WHERE uid='100002631885608'";
$result = $oDB->execSqlOneRow($sQuery);

$oDB->execSQL(array(
	'table' => 'gee_user',
	'insert' => array(
		'user_id' => '100000829417043',
		'username' => '동형현',
		'profile_url' => 'http://www.facebook.com/profile.php?id=100000829417043',
		'profile_image_url' => 'http://profile.ak.fbcdn.net/hprofile-ak-snc4/23088_100000829417043_6783_q.jpg',
		'gender' => 'male'
	)
));

$oDB->execSQL(array(
	'table' => 'gee_user',
	'update' => array(
		'user_id' => '100000829417043',
		'username' => '동형현',
		'profile_url' => 'http://www.facebook.com/profile.php?id=100000829417043',
		'profile_image_url' => 'http://profile.ak.fbcdn.net/hprofile-ak-snc4/23088_100000829417043_6783_q.jpg',
		'gender' => 'male'),
	'where' => array(
		'user_id' => '100000829417043'
	)
));

$oDB->execSQL(array(
	'table' => 'gee_user',
	'select' => array(
		'user_id',
		'username',
		'profile_url',
		'profile_image_url',
		'gender'),
	'where' => array(
		'user_id' => '100000829417043',
		'gender' => 'male'
	),
	'order' => array(
		'user_id' => 'desc',
		'gender' => 'asc'
	),
	'limit' => '1'
));
*/
?>