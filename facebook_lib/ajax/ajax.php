<?php include_once '../lib/init.inc';?>
<?php

	$aReturn = array("status" => 500, "data" => "");	
	
	$type = $_REQUEST['type'];
	
	switch ($type) {
		
		case 'userInfoInsert' : // 사용자 정보 DB 저장
			
			$param = $_REQUEST['param'];
			
			if( $param['useruid'] == "" || $param['useruid'] == null ){
				$param['useruid'] = $oFacebook->getUser();
			}
			
			$userCheck = $oDB -> userDataCheck($param['useruid']);
			
			if ( $userCheck[0][cnt] == 0 ) {
			
				$result = $oDB -> userInfoDBInsert($param);
			
				if( $result ) {
					$aReturn = array("status" => 200, "data" => "ok");
				} else {
					$aReturn = array("status" => 500, "data" => "DB INSERT ERROR!!!");
				}
			}
			
			break;
		
		default:
			break;
	}
	
	echo json_encode($aReturn);
?>