<?php
//DB 관련
include_once 'db/DatabaseDataManager.inc';
include_once 'db/DAO.inc';

//Facebook SDK
include_once 'src/facebook.php';

//Default Include(전역함수 선언 등)
include_once 'init_url.inc';
include_once 'secret.inc';

//FACEBOOK PHP LIB LOAD
$oFacebook = new Facebook( array('appId' => APP_ID, 'secret' => APP_SECRET));

//DB LOAD
$oDB = new DataAccessObjects();

?>
