<?php

//개발,실서버정보 case by 설정
switch ($_SERVER['HTTP_HOST']){

	//development Sever Setting
	case 'dev.magtoo.com' :
	case 'dev.innobirds.com' :
	case 'dev.innobirds.com:440' :

    	/* APP 설정시 변경할 값들 */
        // APP ID 정의
        
		
        //페북_LIB_TEST
        define('APP_ID', '1450098915235682');
        
        
        define('PAGE_ID', '180008148821816');
        
        // APP SCREET CODE 정의
        define('APP_SECRET', '57af942f67c03a4477070048189a8e29');
              
        // APP URL 정의
        define('APPS_URL', 'https://apps.facebook.com/dev_hero');
        
		//TAB , MOBILE URL
        define('TAB_URL', 'https://www.facebook.com/jhpark15/app_'.APP_ID);
        define('MOBILE_URL', 'http://dev.innobirds.com/jhpark/facebook_lib/mobile.php');
		
        // 앱의 권한 정의
        define('PERMS', 'user_likes'); //기본적인 권한(수정 하지말것)

        
        
        // TEST DB 계정 설정
        define('DB_HOST', 'localhost');
        define('DB_NAME', 'test');
        define('DB_USER', 'test');
        define('DB_PASS', 'inno1!');

        define('USER_TABLE', 'jhpark_userinfo'); //기본적인 권한(수정 하지말것)
        
        //페이스북 공유 Config
        define('FB_NAME','페이스북네임');
        define('FB_PICTURE','280.png');
        define('FB_CAPTION','페이스북 CAPTION');
        
        
        //트위터 Config
        define('TW_MSG','트위터 메시지 입니다.');
        define('TW_URL','https://apps.facebook.com/dev_hero');
        
        //카카오톡 Config
        define('KT_MSG','카카오 메세지입니다.!ㅋㅋ');
        define('KT_URL','https://apps.facebook.com/dev_hero');
        define('KT_APPID','http://dev.innobirds.com/jhpark/facebook_lib/');
        define('KT_APPNAME','카카오앱네임');
        
        //카카오스토리 Config
        define('KS_POST','http://dev.innobirds.com/jhpark/facebook_lib/');//INDEX 페이지
        define('KS_APPNAME','카스앱네임');
        define('KS_TITLE','카카오스토리제목');
        define('KS_DESC','카카오스토리DESC');
        define('KS_IMAGEURL','kakao_280.png');
        
        
        
    	/* APP 설정 end */
		break;	       
    case 'm3.magtoo.com' :
    case 'web3.magtoo.com' :
    case 'web3.innobirds.com' : 

		break;
	case 'localhost' :
		break;
}
?>