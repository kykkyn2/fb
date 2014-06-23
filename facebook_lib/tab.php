<?php include_once 'lib/init.inc';?>
<?php

	//페이지 LIKE 유무 확인
	$signed_request = $oFacebook->getSignedRequest();
	$isFan 			= $signed_request["page"]["liked"];
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" lang="ko" xml:lang="ko">
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />	
	<title>FB SAMPLE</title>
</head>
<body style="overflow:hidden;">
	<div id="fb-root"></div>
	<?php //if(!$isFan){?>
		<div class="unlike" style="display:none;">
			<img src="common/images/unlike.png" alt="좋아요 누르고 1분만 투자하면 공감소통 준비완료">		
		</div>
	<?php //}else{?>
		<!-- 좋아요 했을때 -->
		<input type="button" value="이벤트 시작하기" id="event_start">
		<input type="button" value="테스트" id="test_start">
		
	<?php //}?>
	<script>
		var sAccessToken = ""; // access token 변수
		var sUID = "";
		var oFBParam = {
			apikey : '<?php echo APP_ID;?>', // APP ID
			tabUrl :'<?php echo TAB_URL;?>', // TAB URL
			appsUrl : '<?php echo APPS_URL;?>', // TAB URL
			redirecturl : '<?php echo TAB_URL;?>', // REDIRECT URL
			perms : '<?php echo PERMS;?>', // Permissions
			oauth : true, // OAuth 2.0 사용 여부
			type : 'PC', // 페이지 타입 (PC, MOBILE)
			fan : '<?php echo $isFan?>'	//페이지 좋아요 유무
		};

		var snsParam = {
			tw_msg : '<?php echo TW_MSG ?>',
			tw_url : '<?php echo TW_URL ?>',
		}
	</script>
	<script charset="UTF-8" type="text/javascript" src="common/util/jquery-1.8.0.min.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/js/facebook.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/js/function.js"></script>
	<!-- <script charset="UTF-8" type="text/javascript" src="common/js/tab.js"></script> -->
	<script charset="UTF-8" type="text/javascript" src="common/js/inno.0.0.1.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/js/sns.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/js/script.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/util/kakao.link.js"></script>

</body>
</html>